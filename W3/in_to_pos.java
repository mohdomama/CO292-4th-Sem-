import java.util.Scanner;
import java.util.Stack;
import java.util.Arrays;

class CharStack{
  private Node head;
    private int size; 
 
  private class Node{ 
    Character value;
    Node next;
  }
 
  public CharStack(){
    head = null;
    size = 0;
  }
 
  public boolean isEmpty(){
    return (size == 0);
  }
 
  //Remove item from the beginning of the list.
  public Character pop(){
    Character value = head.value;
    head = head.next;
    size--;
    return value;
  }
 
  public void push(Character value){
    Node temp = head;
    head = new Node();
    head.value = value;
    head.next = temp;
    size++;
  }

  public Character peek(){
  	return head.value;
  }
 
  public int size()
  {
    return size;
  }
}

public class in_to_pos{
	static int check_precedence(Character operator) {
		if (operator == '^' )
			return 3;

		else if (operator == '*' || operator =='/')
			return 2;

		else if (operator == '+' || operator =='-')
			return 1;

		else return -1; 	

	}

	static boolean is_operator(Character ch){
		Character[] operators = new Character[] { '+', '-', '*', '/', '^' };
		return Arrays.asList(operators).contains(ch);
	}
	
	static String convert(String expression){
		String output = new String("");

		//Stack<Character> stack = new Stack<>();
		CharStack stack = new CharStack();

		for (Character ch : expression.toCharArray()){
        	if (is_operator(ch)){
        		while (!stack.isEmpty() && check_precedence(ch) <= check_precedence(stack.peek())){
        			output += stack.pop();
        		}
        		stack.push(ch);

        	}
        	else if (ch == '('){
        		stack.push(ch);


        	}
        	else if (ch == ')'){
        		while (!stack.isEmpty() && stack.peek() != '(')
                    output += stack.pop();
                 
                if (!stack.isEmpty() && stack.peek() != '(')
                    return "Invalid Expression"; // invalid expression                
                else
                    stack.pop();

        	}

        	else {
        		output += ch;
        	}
        		
    	}

    	while (!stack.isEmpty())
            output += stack.pop();

    	return output;
	}

	public static void main(String[] args) {
		CharStack ali = new CharStack();
		Scanner input = new Scanner(System.in);
		System.out.println("Provide infix expression:");
		String line = input.nextLine();
		String output;
		
		output = convert(line);
		System.out.println("\nThe postfix expression is:\n" + output);

	}
}