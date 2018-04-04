#include <iostream>
#include <stdlib.h>
#include <math.h>
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
			
			cout << "After Iteration " << size - i << " :" <<endl;
			print();
			heap_print(array, i + 1);
			cout << endl;
			swap(&array[0], &array[i]);
			max_heapify(0, i);
			
		}
	}

	~Heap(){
		free(array);
	}

	void heap_print(int arr[],int n){
		int temp=n,count=0,h,level=0,i,j=1;
		cout<<"\n\n";
		while(temp>1)
		{
			count++;
			temp=temp/2;
		}
		h=(count--)*5+20;
		while(h-->0)
			cout<<" ";
		
		for(i=0;i<n;i++)
		{
			cout<<arr[i]<<"     ";
			if(j==pow(2,level))
			{
				cout<<"\n\n";
				h=(count--)*5+20;
				while(h-->0)
					cout<<" ";
				j=0;
				level++;
			}
			j++;
					
		}
	}

	void new_print(int arr[], int size){
		int h = 1, num = 0;
		for (int i = 0; i < size; i++){
			int p = h;
			for (int j = h; j < 0; j--){
				for(int k = size - p; k < 0; k++){
					cout << "o ";
				}
				cout << arr[num++];

			}
			h = 2*p;
			cout << endl;

		}
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