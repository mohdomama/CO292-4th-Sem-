#include <iostream>
#include <stdlib.h>


using namespace std;

struct node{
public:
	int value;
	node *next;
};

class List{
private:
	node *Head = NULL;
	node *Tail = NULL;

public:
	node* create_node(int value){
		node *new_node = new node;
		new_node -> value = value;
    	new_node -> next = NULL;
    	return new_node;
	}

	void print(){
		node *temp = Head;
		if (temp == NULL) {return;}
		else{
			cout << temp->value << " -- ";
			temp = temp->next;
			while (temp!=Head){
				cout << temp->value << " -- ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	void insert_at_begin(int value){
    	node *new_node = create_node(value);

    	if (Head==NULL) {Head = new_node; Head->next = Head; Tail = Head; }
    	else{
    		new_node -> next = Head;
    		Tail -> next = new_node;
    		Head = new_node;
    	}
	}

	void insert_at_end(int value){
    	node *new_node = create_node(value);

    	if (Head==NULL) {Head = new_node; Head->next = Head; Tail = Head; }
    	else{
    		Tail -> next = new_node;
    		new_node -> next = Head;
    		Tail = new_node;
    	}
	}

	void delete_at_begin(){
		if (Head==NULL) {cout << "Underflow!" << endl; return;}
		else if (Head == Tail) {
			Head = NULL;
			Tail = NULL;
		}
		else {
			Tail -> next = Head -> next;
			Head = Tail -> next;
		}
	}

	void delete_at_end(){
		if (Head==NULL) {cout << "Underflow!" << endl; return;}
		else if (Head == Tail) {
			Head = NULL;
			Tail = NULL;
		}
		else {
			node *temp = Head;
			while(temp -> next != Tail) {
				temp = temp -> next;
			}
			temp -> next = Tail -> next;
			Tail = temp;
		}
	}
};

int main(){
	List list;
	int option, value;
	while (1) {
		cout << "0) Exit" << endl;
		cout << "1) Insert at beginning" << endl;
		cout << "2) Insert at end" << endl;
		cout << "3) delete_at_begin" << endl;
		cout << "4) delete_at_end" << endl;
		cout << "5) Print List" << endl;

		cin >> option;
		
		switch (option){
			case 0: return 0;

			case 1: {
				cout << "Enter value to be inseted at beginning:" << endl;
				cin >> value;
				list.insert_at_begin(value);
				break;
			}
			case 2: {
				cout << "Enter value to be inseted at end:" << endl;
				cin >> value;
				list.insert_at_end(value);
				break;
			}
			case 3: {
				list.delete_at_begin();
				break;
			}
			case 4: {

				list.delete_at_end();
				break;
			}
			case 5: {

				list.print();
				break;
			}
		}
	}

	


	return 0;
}