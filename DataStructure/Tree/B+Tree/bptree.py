from collections import deque
import sys


# Node
class Node:
    def __init__(self, keys, subTrees, parent, isLeaf, nextNode, values, beforeNode):
        self.keys = keys
        self.subTrees = subTrees
        self.parent = parent
        self.isLeaf = isLeaf
        self.nextNode = nextNode
        self.beforeNode = beforeNode
        self.values = values

    def separate(self, k, order):
        val_len = len(self.values) if self.isLeaf == True else len(self.keys)
        p_node = self.parent if self.parent is not None else Node([], [self], None, False, None, [], None)
        self_in_p = p_node.subTrees.index(self)
        if self.isLeaf == True:
            right = Node(self.keys[int(val_len / 2):], [], p_node, True, self.nextNode, self.values[int(val_len / 2):], None)
            left = Node(self.keys[:int(val_len / 2)], [], p_node, True, right, self.values[:int(val_len / 2)], None)
            right.beforeNode = left
            if right.nextNode is not None: right.nextNode.beforeNode = right
            left.beforeNode = self.beforeNode
            if left.beforeNode is not None: left.beforeNode.nextNode = left
            flag = False
            for idx in range(len(p_node.keys)):
                if right.keys[0] < p_node.keys[idx]:
                    p_node.keys = p_node.keys[:idx] + [right.keys[0]] + p_node.keys[idx:];
                    flag = True
                    break
            if flag == False: p_node.keys.append(right.keys[0])
            p_node.subTrees = p_node.subTrees[:self_in_p] + [left] + [right] + p_node.subTrees[self_in_p + 1:]
        else:
            mid_key = self.keys[int(val_len / 2)];
            right = Node(self.keys[int(val_len / 2) + 1:], [], p_node, False, None, [], None)
            left = Node(self.keys[:int(val_len / 2)], [], p_node, False, None, [], None)
            for sub in self.subTrees:
                if sub.keys[0] < self.keys[int(len(self.keys)/2)]:
                    left.subTrees.append(sub)
                    sub.parent = left
                else:
                    right.subTrees.append(sub)
                    sub.parent = right
            flag = False
            for idx in range(len(p_node.keys)):
                if mid_key < p_node.keys[idx]:
                    p_node.keys = p_node.keys[:idx] + [mid_key] + p_node.keys[idx:];
                    flag = True
                    break
            if flag == False: p_node.keys = p_node.keys + [mid_key]
            p_node.subTrees = p_node.subTrees[:self_in_p] + [left] + [right] + p_node.subTrees[self_in_p + 1:]
        return p_node


# B+ Tree
class B_PLUS_TREE:
    def __init__(self, order):
        self.order = order
        self.root = None

    def insert_dfs(self, cur, k):
        flag = True;
        root = cur
        if cur.isLeaf == True:
            cur.values.append(k)
            cur.keys.append(k)
            cur.values.sort();
            cur.keys.sort()
            if len(cur.values) == self.order:
                root = cur.separate(k, self.order)
            return root
        for idx in range(len(cur.keys)):
            if k < cur.keys[idx]:
                self.insert_dfs(cur.subTrees[idx], k)
                flag = False
                break
        if flag == True:
            self.insert_dfs(cur.subTrees[len(cur.subTrees) - 1], k)
        if len(cur.keys) == self.order:
            root = cur.separate(k, self.order)
        return root

    def insert(self, k):
        if self.root is None:
            self.root = Node([k], [], None, True, None, [k], None)
            return
        self.root = self.insert_dfs(self.root, k)

    def delete(self, node, k):
        if self.root is None:
            print("Tree is Empty")
            return False
        if node.isLeaf:
            try:
                node.keys.remove(k); node.values.remove(k)
                if not node.keys and node == self.root: self.root = None
                return True
            except ValueError:
                return False
        ## idx : cur 의 subTree 에서의 child 위치
        idx = 0; flag = False
        for idx in range(len(node.keys)):
            if k < node.keys[idx]:
                flag = True
                break
        if not flag : idx += 1
        if not self.delete(node.subTrees[idx], k) : return False
        ## idx : cur 의 subTree 에서의 child 위치
        idx = 0; flag = False
        if len(node.subTrees) == 1 : idx = 0
        else :
            for idx in range(len(node.keys)):
                if k < node.keys[idx]:
                    flag = True
                    break
            if not flag: idx += 1
        ## non-leaf, leaf
        if node.subTrees[idx].isLeaf:
            ## leaf 에 원소가 남은 경우
            if len(node.subTrees[idx].keys) != 0:
                if idx != 0 : node.keys[idx-1] = node.subTrees[idx].keys[0]
            ## leaf 에 원소가 남지 않은 경우
            else :
                key_under_node = 0
                for sub in node.subTrees:
                    key_under_node += len(sub.keys)
                ## node 하위에 2개 이상 key 가 남은 경우 (자체처리 가능)
                if key_under_node >= 2:
                    target = 0; flag = 0; tmp = node.subTrees[idx]
                    if idx == 0 :
                        if len(node.subTrees[1].keys) > 1: target = 1; flag = 1
                    elif idx == len(node.subTrees) - 1:
                        if len(node.subTrees[idx-1].keys) > 1: target = idx - 1; flag = -1
                    else:
                        if len(node.subTrees[idx+1].keys) > 1: target = idx + 1; flag = 1
                        if len(node.subTrees[idx-1].keys) > 1: target = idx - 1; flag = -1
                    if flag != 0:
                        right = None; left = None
                        if flag == -1:
                            right = Node(node.subTrees[target].keys[int((len(node.subTrees[target].keys)+1)/2):], [], node, True, node.subTrees[target].nextNode, node.subTrees[target].values[int((len(node.subTrees[target].values)+1)/2):], None)
                            left = Node(node.subTrees[target].keys[:int((len(node.subTrees[target].keys)+1)/2)], [], node, True, right, node.subTrees[target].values[:int((len(node.subTrees[target].values)+1)/2)], None)
                        else:
                            right = Node(node.subTrees[target].keys[int((len(node.subTrees[target].keys)) / 2):], [], node, True, node.subTrees[target].nextNode, node.subTrees[target].values[int((len(node.subTrees[target].values)) / 2):], None)
                            left = Node(node.subTrees[target].keys[:int((len(node.subTrees[target].keys)) / 2)], [], node, True, right, node.subTrees[target].values[:int((len(node.subTrees[target].values)) / 2)], None)
                        right.beforeNode = left; left.beforeNode = node.subTrees[target].beforeNode
                        node.subTrees = node.subTrees[:target] + [left, right] + node.subTrees[idx + 1:] if target < idx else node.subTrees[:idx] + [left, right] + node.subTrees[target + 1:]
                        node.keys = [node.subTrees[i].keys[0] for i in range(1,len(node.subTrees))]
                    else:
                        node.subTrees.remove(tmp)
                        if tmp.beforeNode is not None : tmp.beforeNode.nextNode = tmp.nextNode
                        if tmp.nextNode is not None : tmp.nextNode.beforeNode = tmp.beforeNode
                        node.keys = [node.subTrees[i].keys[0] for i in range(1,len(node.subTrees))]
                ## node 하위에 key 가 한개만 남은 경우 (자체처리 불가능)
                else :
                    ## 제거 하다가 한개만 남은 경우
                    if node == self.root :
                        tmp = None
                        for tmp in node.subTrees:
                            if len(tmp.keys) == 1:
                                self.root = tmp
                                self.root.parent = None
                                return True
                    ## sibling 들이 있는 경우
                    else :
                        ## node 에서 해당 빈 노드 제거
                        if node.subTrees[idx].nextNode is not None: node.subTrees[idx].nextNode.beforeNode = node.subTrees[idx].beforeNode
                        if node.subTrees[idx].beforeNode is not None : node.subTrees[idx].beforeNode.nextNode = node.subTrees[idx].nextNode
                        del node.subTrees[idx]
                        idx = node.parent.subTrees.index(node)
                        ## idx : parent 에서 현재 subtree 위치
                        sibling = None
                        if idx == 0: sibling = node.parent.subTrees[1]
                        else: sibling = node.parent.subTrees[idx-1]
                        n = None
                        ## n = sibling + node 의 새로운 노드 형성, 연결, key 설정
                        if len(sibling.subTrees) + 1 == 3:
                            if idx == 0: n = Node([key for key in node.keys] + [key for key in sibling.keys], [sub for sub in node.subTrees] + [sub for sub in sibling.subTrees], node.parent, False, None, None, None)
                            else: n = Node([key for key in sibling.keys] + [key for key in node.keys], [sub for sub in sibling.subTrees] + [sub for sub in node.subTrees], node.parent, False, None, None, None)
                            for sub in n.subTrees: sub.parent = n
                            n.parent.subTrees = [n] + n.parent.subTrees[2:] if idx == 0 else n.parent.subTrees[:idx - 1] + [n] + n.parent.subTrees[idx + 1:]
                            for i in range(1,len(n.subTrees)) : n.keys[i-1] = n.subTrees[i].keys[0]
                            n.parent.keys = [n.parent.subTrees[i].keys[0] for i in range(1, len(n.parent.subTrees))] if len(n.parent.subTrees) != 1 else [n.parent.subTrees[0].keys[-1] + 1]
                        else:
                            if idx == 0 :
                                right = Node([], sibling.subTrees[int(len(sibling.subTrees)/2):], node.parent, False, None, None, None)
                                left = Node([], node.subTrees + sibling.subTrees[:int(len(sibling.subTrees)/2)], node.parent, False, None, None, None)
                            else :
                                right = Node([], sibling.subTrees[int((len(sibling.subTrees)-1)/2)+1:] + node.subTrees, node.parent, False, None, None, None)
                                left = Node([], sibling.subTrees[:int((len(sibling.subTrees)-1)/2)+1], node.parent, False, None, None, None)
                            for sub in left.subTrees: sub.parent = left
                            for sub in right.subTrees: sub.parent = right
                            node.parent.subTrees = [left, right] + node.parent.subTrees[2:] if idx == 0 else node.parent.subTrees[:idx - 1] + [left, right] + node.parent.subTrees[idx + 1:]
                            for i in range(1, len(left.subTrees)): left.keys.append(left.subTrees[i].keys[0])
                            for i in range(1, len(right.subTrees)): right.keys.append(right.subTrees[i].keys[0])
                            left.parent.keys = []
                            for i in range(1, len(left.parent.subTrees)):
                                sub = left.parent.subTrees[i]
                                while not sub.isLeaf:
                                    sub = sub.subTrees[0]
                                left.parent.keys.append(sub.keys[0])
        ## non-leaf, non-leaf (node : 현재노드 , 그 자식노드도 non-leaf)
        else:
            ## 쭉 짜내기 (merging) + key 값 변경
            if node.parent is not None:
                if len(node.subTrees) == 1:
                    idx = node.parent.subTrees.index(node)
                    ## sibling 체크
                    sibling = None
                    if idx == 0: sibling = node.parent.subTrees[1]
                    else: sibling = node.parent.subTrees[idx - 1]
                    n = None
                    ## n = sibling + node 의 새로운 노드 형성, 연결, key 설정
                    if idx == 0: n = Node([], [sub for sub in node.subTrees] + [sub for sub in sibling.subTrees], node.parent, False, None, None, None)
                    else: n = Node([], [sub for sub in sibling.subTrees] + [sub for sub in node.subTrees], node.parent, False, None, None, None)
                    for sub in n.subTrees: sub.parent = n
                    n.parent.subTrees = [n] + n.parent.subTrees[2:] if idx == 0 else n.parent.subTrees[:idx - 1] + [n] + n.parent.subTrees[idx + 1:]
                    for i in range(1, len(n.subTrees)):
                        sub = n.subTrees[i]
                        while not sub.isLeaf:
                            sub = sub.subTrees[0]
                        n.keys.append(sub.keys[0])
                    n.parent.keys = [n.parent.subTrees[i].keys[0] for i in range(1, len(n.parent.subTrees))] if len(n.parent.subTrees) != 1 else [n.parent.subTrees[0].keys[-1] + 1]
                else:
                    ## key 값 변경 수행
                    for i in range(len(node.keys)):
                        cur = node.subTrees[i + 1]
                        while not cur.isLeaf:
                            cur = cur.subTrees[0]
                        node.keys[i] = cur.keys[0]
            else:
                if len(node.subTrees) == 1:
                    self.root = node.subTrees[0]
                    self.root.parent = None
                    if self.root.subTrees is None :
                        self.root.isLeaf = True
                else:
                    for i in range(len(node.keys)):
                        cur = node.subTrees[i + 1]
                        while not cur.isLeaf:
                            cur = cur.subTrees[0]
                        node.keys[i] = cur.keys[0]
        return True


    def print_root(self):
        if self.root is None:
            print("Tree is Empty")
            return False
        l = "["
        for k in self.root.keys:
            l += "{},".format(k)
        l = l[:-1] + "]"
        print(l)
        pass

    def print_tree(self):
        if self.root is None:
            print("Tree is Empty")
            return False
        deq = deque([self.root])
        while len(deq) != 0:
            cur = deq.popleft()
            key_list = []
            res = '[' + ','.join([str(a) for a in cur.keys]) + ']'
            for child in cur.subTrees:
                deq.append(child)
                key_list.append(child.keys)
            if key_list:
                res += '-' + ','.join([str(a) for a in key_list])
            if not (cur != self.root and key_list == []):
                print(res.replace(' ', ''))

    def find_range(self, k_from, k_to):
        if self.root is None:
            print("Tree is Empty")
            return False
        cur = self.root
        while cur.isLeaf != True:
            flag = False
            for idx in range(len(cur.keys)):
                if k_from < cur.keys[idx]:
                    cur = cur.subTrees[idx];
                    flag = True
                    break
            if flag == False:
                cur = cur.subTrees[len(cur.subTrees) - 1]
        res = "";
        idx = 0
        while cur.values[idx] <= k_to:
            if cur.values[idx] < k_from:
                idx += 1
            elif k_from <= cur.values[idx] <= k_to:
                res += str(cur.values[idx]) + ','
                idx += 1
            if idx == len(cur.values):
                if cur.nextNode is not None:
                    cur = cur.nextNode
                    idx = 0
                else:
                    break
        if res == "":
            print("invalid range")
        else:
            print(res[:len(res) - 1])

    def find(self, k):
        if self.root is None:
            print("Tree is Empty")
            return False
        cur = self.root
        path = "[" + ','.join([str(a) for a in cur.keys]) + "]"
        while cur.isLeaf != True:
            flag = False
            for idx in range(len(cur.keys)):
                if k < cur.keys[idx]:
                    cur = cur.subTrees[idx];
                    flag = True
                    break
            if flag == False:
                cur = cur.subTrees[len(cur.subTrees) - 1]
            path += "-[" + ','.join([str(a) for a in cur.keys]) + "]"
        idx = 0
        for idx in range(len(cur.values)):
            if cur.values[idx] == k:
                print(path)
                return
        print("NONE")
        return


# main
def main():
    myTree = None

    while (True):
        comm = sys.stdin.readline()
        comm = comm.replace("\n", "")
        params = comm.split()
        if len(params) < 1:
            continue

        print(comm)

        if params[0] == "INIT":
            order = int(params[1])
            myTree = B_PLUS_TREE(order)

        elif params[0] == "EXIT":
            return

        elif params[0] == "INSERT":
            k = int(params[1])
            myTree.insert(k)

        elif params[0] == "DELETE":
            k = int(params[1])
            myTree.delete(myTree.root, k)

        elif params[0] == "ROOT":
            myTree.print_root()

        elif params[0] == "PRINT":
            myTree.print_tree()

        elif params[0] == "FIND":
            k = int(params[1])
            myTree.find(k)

        elif params[0] == "RANGE":
            k_from = int(params[1])
            k_to = int(params[2])
            myTree.find_range(k_from, k_to)

        ## OK
        elif params[0] == "SEP":
            print("————————————")


if __name__ == "__main__":
    main()