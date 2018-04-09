import java.util.Scanner;
public class MergeSort {
	
	void merge(int[] array, int left, int mid, int right) {
		int l_size = mid - left + 1;
		int r_size = right - mid;

		int[] left_array = new int[l_size];
		int[] right_array = new int[r_size];

		for(int i = 0; i < l_size; i++) {
			left_array[i] = array[left + i];
		}

		for(int i = 0; i < r_size; i++) {
			right_array[i] = array[mid + 1 + i];
		}

		int k = left, i = 0, j = 0;

		while(i < l_size && j < r_size) {
			if (left_array[i] <= right_array[j]) {
				array[k] = left_array[i];
				i++;
			}
			else {
				array[k] = right_array[j];
				j++;
			}
			k++;
		}
		while (i < l_size) {
			array[k] = left_array[i];
			i++; k++;
		}

		while (j < r_size) {
			array[k] = right_array[j];
			j++; k++;
		}

	}

	public void merge_sort(int[] array, int left, int right) {
		if (left < right){
			int mid = (left+right)/2;

			merge_sort(array, left, mid);
			merge_sort(array, mid + 1, right);

			merge(array, left, mid, right);
		}
	}
	
	public static void main(String[] args) {
		int size;
		Scanner input = new Scanner(System.in);
		MergeSort sort = new MergeSort();
		System.out.println("Enter the size of the array:");
		size = input.nextInt();

		int[] array = new int[size];

		System.out.println("Enter the array:");
		for (int i = 0; i < size; i++){
			array[i] = input.nextInt();
		}

		System.out.println("The array you entered is:");
		for (int i = 0; i < size; i++){
			System.out.print(array[i] + " ");
		}

		sort.merge_sort(array, 0, array.length - 1);

		System.out.println("The array after sorting is:");
		for (int i = 0; i < size; i++){
			System.out.print(array[i] + " ");
		}

	}
}