#include <iostream>
#include <stdlib.h>

using namespace std;

class Sort{
private:
	int *array;
	int size;

public:
	void input(){
		cout << "Enter the size of array:" <<endl;
		cin >> size;
		array = (int *) malloc (sizeof(int)*size);
		cout << "Enter the array to be sorted:" <<endl;
		for (int i = 0; i < size; ++i){
			cin >> array[i];
		}
	}

	void print(){
		for (int i = 0; i < size; ++i){
			cout << array[i] << " ";
		}
		cout << endl;
	}

	void quick_sort(int begin, int end){
		if(begin < end){
			int pivot_index = lomuto_partition(begin, end);
			quick_sort(begin, pivot_index - 1);
			quick_sort(pivot_index + 1, end);
		}
	}

	int hoare_partition(int begin, int end){
		int pivot = array[end];
		int i = begin - 1;
		int j = end + 1;
		while (true){
			do{
				j = j - 1;
			}
			while(array[j] > pivot);

			do{
				i = i + 1;
			}
			while(array[i] < pivot);
			if(i < j){
				array[i] = array[j] + array[i];
				array[j] = array[i] - array[j];
				array[i] = array[i] - array[j];
			}
			else{
				return j;
			}
		}
	}

	void swap(int *a, int* b){
		int temp = (*a);
		(*a) = (*b);
		(*b) = (temp);
	}
	
	int lomuto_partition(int begin, int end){
		int pivot = array[end];
		int i = begin - 1;
		for (int j = begin; j < end; j++){
			if (array[j] <= pivot){
				i = i + 1;
				swap(&array[i], &array[j]);
			}
		}
		swap(&array[i+1], &array[end]);
		return (i + 1);
	}

	int get_size(){
		return size;
	}
};

int main(int argc, char const *argv[]){

	Sort array;
	array.input(); 
	array.quick_sort(0, array.get_size() - 1);
	array.print();
	return 0;
}