#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
	int value;
	struct node* next = NULL;
};

class LinkedList {
private:
	struct node* Head;
	int size;

public:
	LinkedList () {
		Head = NULL;
		size = 0;
	}

	void add (int value) {
		struct node* temp = Head;
		struct node* new_node = new node;

		size++;
		new_node->value = value;

		if (Head == NULL) {
			Head = new_node;
		}

		else{
			while (temp->next != NULL) {
				temp = temp->next;
			}

			temp->next = new_node;
		}
	}

	void remove (int value) {
		if (size == 0) {
			cout << "Underflow!" << endl;
			return;
		}

		else {
			struct node* removed = NULL;
			if (Head->value == value) {
				size--;
				removed = Head;
				Head = Head->next;
				free (removed);
				return;
			}

			else {
				struct node* temp = Head;
				while (temp->next->next != NULL) {
					if (temp->next->value == value) {
						size--;
						removed = temp->next;
						temp->next = temp->next->next;
						free (removed);
						return;
					}
				}

				cout << "Element not found!" <<endl;
				return;
			}
		}
	}

	int search (int value) {
		int count = -1;
		struct node* temp = Head;
		if (Head == NULL)
			return -1;
		else {
			while (temp!=NULL) {
				count ++;
				if (temp->value == value)
					return count;
				temp = temp->next;
			}
			return -1;
		}
	}
	void print (){
		struct node* temp = Head;
		while (temp!=NULL) {
			cout << temp->value << " --> "; 
			temp = temp->next;
		}
		cout << "||" <<endl;
	}
};

class HashMap {
private:
	LinkedList* buckets;
	int hash_size;

public:
	HashMap (int hash_size) {
		buckets = new LinkedList[hash_size];
		this->hash_size = hash_size;
	}

	void insert (int key) {
		int hash = hash_function (key);
		buckets[hash].add(key);
	}

	void remove (int key) {
		int hash = hash_function (key);

		buckets[hash].remove(key);
	}

	void print_buckets() {
		for (int i = 0; i < hash_size; i++) {
			cout << "Bucket " << i << " :  ";
			buckets[i].print();
		}
	}

	void search (int key) {
		int hash = hash_function (key);
		int index = buckets[hash].search(key);
		if (index != -1) {
			cout << "Element found in bucket: " << hash << endl;
			cout << "The index of the element is: " << index << endl;

		}
		else {
			cout << "Element not found" << endl;
		}
	}
	int hash_function (int key) {
		int hash = key%hash_size;
		return hash < 0 ? hash + hash_size : hash;
	}

};

int main (int argc, char const *argv[]) {

	int option, key;
	HashMap hash(5);

	while (1) {
		cout << "Enter the option:" << endl;
		cout << "0) Exit" << endl;
		cout << "1) Add key" << endl;
		cout << "2) Remove key" << endl;
		cout << "3) Search key" << endl;
		cout << "4) Print Hash Table" << endl;

		cin >> option;

		switch (option) {
			case 0: {
				return 0;
				break;
			}
			case 1: {
				cout << "Enter key to be inserted:" <<endl;
				cin >> key;
				hash.insert(key);
				break;
			}
			case 2: {
				cout << "Enter value to be inserted:" <<endl;
				cin >> key;
				hash.remove(key);
				break;
			}
			case 3: {
				cout << "Enter value to be searched:" <<endl;
				cin >> key;
				hash.search(key);
				break;
			}
			case 4: {
				hash.print_buckets();
				break;
			}
		}

		cout << "\n" << endl;
	}

	return 0;
}