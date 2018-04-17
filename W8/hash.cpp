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

	void print (){
		struct node* temp = Head;
		while (temp!=NULL) {
			cout << temp->value << " -- "; 
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
			buckets[i].print();
		}
	}

	int hash_function (int key) {
		int hash = key%hash_size;
		return hash;
	}

};

int main (int argc, char const *argv[]) {

	HashMap hash(5);

	hash.insert(1);
	hash.insert(2);
	hash.insert(3);
	hash.insert(4);
	hash.insert(5);
	hash.insert(6);
	hash.print_buckets();

	return 0;
}