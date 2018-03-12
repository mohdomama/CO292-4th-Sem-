import java.util.Scanner;

class Node{
	public int value;
	public Node left, right;

	public Node(int value){
		this.value = value;
		this.left = null;
		this.right = null;
	}
}

class Tree{
	public Node root;
	public Tree(){
		this.root = null;
	}

	public void pre_order(Node node){
		if(node == null){
			return;
		}
		System.out.print(node.value + "  ");
		pre_order(node.left);
		pre_order(node.right);

	}

	public void post_order(Node node){
		if(node == null){
			return;
		}
		post_order(node.left);
		post_order(node.right);
		System.out.print(node.value + "  ");


	}

	public void in_order(Node node){
		if(node == null){
			return;
		}
		in_order(node.left);
		System.out.print(node.value + "  ");
		in_order(node.right);

	}

	public void insert_value(int value, Node node){
		if (value < node.value){
			if (node.left == null){
				node.left = new Node(value);
				return;
			}
			else{
				insert_value(value, node.left);
			}
		}
		else{
			if (node.right == null){
				node.right = new Node(value);
				return;
			}
			else{
				insert_value(value, node.right);
			}
		}


	}
	public void insert(int value){
		if (this.root == null){
			this.root = new Node(value);
		}
		else{
			insert_value(value, this.root);
		}
	}

	public static void main(String[] args) {
		Tree tree = new Tree();
		int option, value;
		Scanner input = new Scanner(System.in);

		while(true){
		    System.out.println("Choose Option:");
		    System.out.println("0) Exit");
		    System.out.println("1) Insert");
		    System.out.println("2) Print Pre Order");
		    System.out.println("3) Print Post Order");
		    System.out.println("4) Print In Order");
		    option = input.nextInt();
		    switch (option){
		      case 1:{
		        System.out.println("Enter value:");
		        value = input.nextInt();
		        tree.insert(value);
		        System.out.println();
		        break;
		      }
		      case 2: {
		        tree.pre_order(tree.root);
		        System.out.println();
		        break;
		      }
		      case 3: {
		        tree.post_order(tree.root);
		        System.out.println();
		        break;
		      }
		      case 4: {
		        tree.in_order(tree.root);
		        System.out.println();
		        break;
		      }
		      case 0: return;
		    }

		}
	}
}