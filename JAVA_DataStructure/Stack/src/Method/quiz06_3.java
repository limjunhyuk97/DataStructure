package Method;

import Method.Stack;
import java.util.Scanner;

public class quiz06_3 {

	public static void main(String[] args) {
		
		int dec;
		Scanner sc = new Scanner(System.in);
		System.out.println("Decimal into binary");
		System.out.print("Decimal number : ");
		dec = sc.nextInt();
		
		Stack stack = new Stack();
		Dec2Bin(dec, stack);
		System.out.print("Binary number : ");
		while(!stack.StackIsEmpty()) {
			System.out.print(stack.SPop());
		}
		
	}
	
	public static void Dec2Bin(int num, Stack stack) {
		if(num / 2 == 1) {
			stack.SPush(num%2);
			stack.SPush(num/2);
			return;
		}
		
		stack.SPush(num%2);
		Dec2Bin(num/2, stack);
	}
}
