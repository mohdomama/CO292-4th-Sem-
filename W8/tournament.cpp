#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

class Pool {
private:
	int *array;
	int *team_name;
	int size;
public:
	Pool (int size) {
		array = new int[size];
		team_name = new int[size];
		this->size = size;

		for (int i = 0; i < size; i++) {
			array[i] = 0;
		}
		for (int i = 0; i < size; i++) {
			team_name[i] = i;
		}
	}

	void assign (int *team1, int* team2, int i, int j) {
		int output = rand()%3;
		if (output == 0) {
			// Team1
			(*team1) += 2;
			cout << "Team" << i << " won!" << endl;
		}
		else if (output == 1) {
			// Team2
			(*team2) += 2;
			cout << "Team" << j << " won!" << endl;
		}
		else {
			// Draw
			(*team1) += 1;
			(*team1) += 1;
			cout << "Draw!" << endl;
		}
	}

	void play () {
		for (int i =0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				cout << "\n\nMatch between Team" << i << " and Team" << j << endl;
				assign(&array[i],&array[j], i, j);
			}
		}
	}

	void victory () {
		int max = array[0];
		int team = 0;
		for (int i = 0; i < size; i++) {
			if (array[i] > max){
				max = array[i];
				team = i;
			}
		}
		cout << "Team" << team << " won with points " << max << endl;

	}
	void print () {
		cout << "\nPoints Tally:" <<endl;
		for (int i = 0; i < size; i++) {
			cout  << array[i] << "  ";
		}
		cout << endl;

		cout << "Team Names: " <<endl;

		for (int j = 0; j < size; j++) {
			//cout << j << endl;
			cout << team_name[j] << "  ";
		}
		cout << endl;
	}
	void sort () {
		for (int j = size -1; j >= 1; j--){
			for (int i = 0; i < j; i++){
				if (array[i] < array[i+1]) {
					swap(array[i], array[i+1]);
					swap(team_name[i], team_name[i+1]);
				}
			}
		}
	}
	void quarter_finals () {
		cout << "Quater Finals" << endl;

		assign (&array[0], &array[1], team_name[0], team_name[1]);
		assign (&array[2], &array[3], team_name[2], team_name[3]);

	}

	void finals () {
		cout << "Finals" << endl;
		
		assign (&array[0], &array[1], team_name[0], team_name[1]);

	}
};

int main (int argc, char const *argv[]) {
	srand (time(NULL));
	Pool pool1(10);
	pool1.play();
	pool1.victory();
	pool1.print();
	pool1.sort();
	pool1.print();

	pool1.quarter_finals();
	pool1.sort();
	pool1.print();

	pool1.finals();
	pool1.sort();
	pool1.print();
	return 0;
}