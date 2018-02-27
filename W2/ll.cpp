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

public:
	node* create_node(int value){
		node *new_node = new node;
		new_node -> value = value;
    	new_node -> next = NULL;
    	return new_node;
	}

	void print(){
		node *temp = Head;
		while (temp!=NULL){
			cout << temp->value << " -- ";
			temp = temp->next;
		}
		cout << " ||" << endl;
	}

	void insert_at_begin(int value){
    	node *new_node = create_node(value);

    	if (Head==NULL) {Head = new_node;}
    	else{
    		new_node -> next = Head;
    		Head = new_node;
    	}
	}

	void insert_at_end(int value){
		node *new_node = create_node(value);

		if (Head==NULL) {Head = new_node;}
		else{
			node *temp = Head;
			while (temp -> next != NULL){
				temp = temp -> next;
			}
			temp -> next = new_node;
		}
	}

	void insert_at_pos(int value, int pos){
		node *new_node = create_node(value);

		if (pos < 1) { cout<<"Invalid position!"<<endl; return; }
		else if (pos==1) { insert_at_begin(value); }
		else{
			node *temp = Head;
			for (int i = 1; i < pos-1 ; i++ ){
				if (temp==NULL){
					cout << "Invalid position!" << endl; 
					return;
				}
				temp=temp->next;
			}
			if (temp==NULL) {cout << "Invalid position!" << endl; return;}
			new_node->next = temp->next;
			temp->next = new_node;
		}
	}

	void delete_at_begin(){
		if (Head==NULL) {cout << "Underflow!" << endl; return;}
		else{
			node *temp = Head;
			Head = Head -> next;
			free(temp);
		}
	}

	void delete_at_end(){
		if (Head==NULL) {cout << "Underflow!" << endl; return;}
		else if (Head->next == NULL) {Head = NULL;}
		else{
			node *temp = Head;
			while ((temp-> next) -> next != NULL){
				temp = temp -> next;
			}

			free (temp->next);
			temp -> next = NULL;
		}
	}

	void delete_at_pos(int pos){
		if (pos < 1) { cout<<"Invalid position!"<<endl; return; }
		else if (pos==1) { delete_at_begin(); }
		else{
			node *temp = Head;
			for (int i = 1; i < pos-1 ; i++ ){
				if (temp==NULL){
					cout << "Invalid position!" << endl; 
					return;
				}
				temp=temp->next;
			}
			if (temp==NULL) {cout << "Invalid position!" << endl; return;}
			if (temp->next == NULL) {cout << "Invalid position!" << endl; return;}
			
			if (temp->next->next == NULL){
				free(temp->next);
				temp->next = NULL;
			}

			else{
				node* temp2 = temp->next;
				temp->next = temp->next->next;
				free(temp2);
			}
		}
	}

};

int main(){
	List list;
	int option, pos, value;
	
	while (1) {
		cout << "1) Insert at beginning" << endl;
		cout << "2) Insert at end" << endl;
		cout << "3) Insert at position" << endl;
		cout << "4) Delete at beginning" << endl;
		cout << "5) Delete at end" << endl;
		cout << "6) Delete at position" << endl;
		cout << "7) Print List" << endl;
		cout << "0) Exit" << endl;
		
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
				cout << "Enter value to be inseted and position:" << endl;
				cin >> value >> pos;
				list.insert_at_pos(value, pos);
				break;
			}
			case 4: {
				list.delete_at_begin();
				break;
			}
			case 5: {
				list.delete_at_end();
				break;
			}
			case 6: {
				cout << "Enter position to be deleted:" << endl;
				cin >> pos;
				list.delete_at_pos(pos);
				break;
			}
			case 7: { 
				list.print();
				break;
			}
			default: {
				cout << "Invalid Input!" << endl;
			}

		}

	}

	return 0;
}