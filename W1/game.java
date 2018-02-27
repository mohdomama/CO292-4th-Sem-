import java.util.Scanner;

public class game {
	public static int size;
	
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter range of the input: ");
		size = input.nextInt();

		int[] array = new int[size];
		int index, querry;

		for (int i = 0; i < size ; i++ ) {
			array[i] = i + 1;
		}
		binary_search(array);

	}

	public static void binary_search(int array[]){
		Scanner input = new Scanner(System.in);
		int min = 0, max = size - 1, split, comparisons = 0;
		int response;
		while (true) {

			split = (min + max) / 2;
			System.out.println("Is your number \n1 Greater \n2 Less \n3 Equal \nas comapared to "+ array[split]);
			comparisons++;
			response = input.nextInt();
			if (response == 3) {
				System.out.println("Found with number of comparisons: "+ comparisons);
				break;
			}
			else if (response == 1) {
				min = split + 1;
			}
			else {
				max = split - 1;
			}
			if (min>max){
				System.out.println("NOT FOUND");
				break;
			}
		}
		System.out.println("Number of comparisons: " + comparisons);

		
	}
}