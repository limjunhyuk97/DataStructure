package Method;

import java.util.Arrays;

public class Stack {
	
	int[] arr = new int[100];
	int top = -1;
	
	Stack(){
		Arrays.fill(arr, 0);
		top = -1;
	}
	
	public boolean StackIsEmpty(){
		if(top == -1)
			return true;
		else
			return false;
	}
	
	public void SPush(int num) {
		if(top>99) {
			System.out.println("stack is full");
			return;
		}
		arr[++top] = num;
	}
	
	public int SPop() {
		if(StackIsEmpty()) {
			System.out.println("stack is empty");
			System.exit(1);
		}
		
		return arr[top--];
	}
	
	public int SPeek() {
		if(StackIsEmpty()) {
			System.out.println("stack is empty");
			return 0;
		}
		return arr[top];
	}
}	
