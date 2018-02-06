import java.util.Random;
import java.util.Scanner;

public class BS {
	public static int size = 1000;
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		Random rand = new Random();

		int[] array = new int[size];
		int index, querry;

		for (int i = 0; i < size ; i++) {
			array[i] = rand.nextInt(size) + 1;
		}
		
		bubble_sort(array);

		System.out.println("The sorted, randomly generated arrar is :");
		for (int i = 0; i < size ; i++ ) {
			System.out.print(array[i] +  ", ");
		}

		while (true){
			System.out.println("\nEnter Querry: ");
			querry = input.nextInt();
			index = binary_search(array, querry);
			System.out.println(index);
		
		}

	}

	public static int binary_search(int array[], int querry){
		int min = 0, max = size - 1, split, index = -1;
		while (min <= max) {
			split = (min + max) / 2;
			if (array[split] == querry) {
				index = split;
				max = split -1; 
			}
			else if (array[split] < querry) {
				min = split + 1;
			}
			else {
				max = split - 1;
			}
		}

		return index;
	}

	public static void bubble_sort(int array[]) {
		int swaps = 0;
		for (int j = 1; j < size ; j++ ) {
			swaps = 0;
			for (int i = 0; i < size -j; i++) {
				if (array[i+1] < array [i]){
					array[i+1] = array[i] + array[i+1];
					array[i] = array[i+1] - array[i];
					array[i+1] = array[i+1] - array[i];
					swaps++;
				}
			}
			if (swaps==0) {break;}
		}
	}


}