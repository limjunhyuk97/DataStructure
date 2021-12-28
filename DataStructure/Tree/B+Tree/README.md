# B+ Tree


## 구현된 기능

- 삽입 : insert, insert_dfs
- 삭제 : delete
- 출력 : print_tree
- 특정 범위 출력 : find_range
- root 출력 : print_root


## pseudo code

```py

class Node

    def separate(self, order, k):
		if ‘self’ node is leaf node,
			separate ‘self’ node into ‘left’, ‘right’ node
			copy value which is in the middle of key list to parent node
		else,
			separate ‘self’ node into ‘left’, ‘right’ node [use order, k value]
			move value which is in the middle of key list to parent node
		return self.parent


class BPTree

    def insert_dfs(self, cur, k):
		[use DFS algorithm]
		root = cur
			if ‘cur’ node is leaf node,
				insert k value in ‘key’ and, ‘value’ list
			    if number of values inside ‘cur’ node == tree.order
				    root = cur.separate(node, self.order, k)
			 	    return root
			else,
				insert_dfs(child, k)
				[By comparing ‘k’ value with ‘cur’ node’s key value, do DFS]
			if ‘cur’ is full
				return cur.separate(node, self.order, k)

    def insert(self, k):
			call insert_dfs(root, k)

    def delete(self, node, k):
        [used DFS algorithm]
        if tree is empty,
			print(“Tree is Empty”)
			return False
		if ‘node’ is leaf,
			remove ‘k’ value from leaf
			if there is no k value
			 	return False
		if ‘node’ is non-leaf / child of ‘node’ is leaf,
			if value left in leaf,
				update key list in ‘node’
			else,
				if more than 2 keys under ‘node’,
					do rebalancing under subtree [‘node’ is root]
					update key list of ‘node’
				else,
					if only one key left in tree,
						update root ‘node’ of tree
					else (if there exists sibling of node),
						do rebalancing under subtree
						update key list of ‘node’
						[parent of ‘node’ is root in this case]
						[merging]
			 else [if ‘node’ is non-leaf / child of ‘node’ is also non-leaf],
				if ‘node’ has parent [means ‘node’ is not root of tree],
					if rebalancing necessary,
						do rebalancing under subtree
						update key list of ‘node’
						[parent of ‘node’ is root]
						[merge between ‘node’ and it’s proper sibling]
					else,
						update key list of ‘node’
				else [means ‘node’ is root of tree],
					if only one subtree under ‘node’ [need to update root]
						self.root = node.subtree[0]
						if no subtree under self.root
							self.root.isLeaf = True
					else,
						update key list of ‘node’
			 return True

    def print_tree(self)
			[use BFS algorithm]
		    deq = deque([self.root])
			res = “”
			while deque is not empty,
				cur = deq.popleft()
				store ‘parent node key data – child node key data’ in ‘res’
				push nodes into deq
			print(res)

    def find_range(self, k_from, k_to):
			cur = self.root
			res = “”
			while cur is not leaf,
				traverse into child, considering k_from value
			while data is smaller than k_to:
				linearly search Linked List key data
				[while appending proper data into “res”]
			print(res)
    def find(self, k):
			cur = self.root
			path= “[key values in cur]”
			while cur is not leaf,
				traverse into legitimate leaf node
				path += “[key values in cur]”
			if leaf node has k value,
				print(path)
			else,
				print(“None”)
```


## Test case

<img width="441" alt="스크린샷 2021-12-28 오후 10 57 45" src="https://user-images.githubusercontent.com/59442344/147573700-1334994a-5610-4c66-bf42-d80dac68639f.png">


## [visualization](https://www.cs.usfca.edu/~galles/visualization/BPlusTree.html)