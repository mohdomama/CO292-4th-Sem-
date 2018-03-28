#include <iostream>
#include <stdlib.h>
using namespace std;

class Heap{
private:
	int *array;
	int size;
public:
	Heap(int size){
		array = (int*)malloc(sizeof(int)*size);
		this->size = size;
	}

	void input(){
		cout << "Enter the " << size << " elements of the array:" << endl;
		for (int i = 0; i < size; i++){
			cin >> array[i];
		}

	}

	void print(){
		for (int i = 0; i < size; i++){
			cout << array[i] << "  ";
		} 
		cout << endl;
	}

	void swap(int *n1, int *n2){
		int temp;
		temp = *(n1);
		*n1 = *n2;
		*n2 = temp;
	}

	void build_max_heap(){
		for(int i = (size -1 )/2 ; i >= 0; i--){
			max_heapify(i, size);
		}
	}

	int get_size(){
		return size;
	}

	void max_heapify(int root, int heap_size){
		int left, right;
		int largest = root;
		right = 2*(root+1);
		left = 2*(root+1) - 1;
		if (left < heap_size && array[root] < array[left]){
			largest = left;
		}

		if (right < heap_size && array[root] < array[right]){
			if (array[right] > array[largest]){
				largest = right;
			}
		}

		if (largest != root){
			swap(&array[root], &array[largest]);
			max_heapify(largest, heap_size);
		}
	}

	void heap_sort(){
		build_max_heap();
		for (int i = size -1; i > 0 ; i--){
			print();
			cout << endl;
			swap(&array[0], &array[i]);
			max_heapify(0, i);
		}
	}

	~Heap(){
		free(array);
	}
	
};

int main(int argc, char const *argv[]){
	int size;
	cout << "Enter the size of the array:" << endl;
	cin >> size;

	Heap heap(size);
	heap.input();
	heap.heap_sort();
	cout << "\nThe sorted array is:" << endl;

	heap.print();
	return 0;
}