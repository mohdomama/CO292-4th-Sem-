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

	void inset_at_pos(int value, int pos){
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

};

int main(){
	List list;
	list.insert_at_begin(0);
	list.insert_at_begin(1);
	list.insert_at_begin(2);
	list.insert_at_begin(3);
	list.insert_at_begin(4);
	list.insert_at_end(1);
	list.insert_at_end(2);
	list.insert_at_end(3);
	list.insert_at_end(4);
	list.print();
	list.inset_at_pos(7, 10);
	list.print();
	list.delete_at_end();
	list.delete_at_begin();
	list.print();

	return 0;
}