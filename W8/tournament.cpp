#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

class Pool {
private:
	int *array;
	int size;
public:
	Pool (int size) {
		array = new int[size];
		this->size = size;
		for (int i = 0; i < size; i++) {
			array[i] = 0;
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

	int max () {
		int max = array[0];
		for (int i = 0; i < size; i++) {
			if (array[i] > max)
				max = array[i];
		}
		return max;

	}
	void print () {
		cout << "Points Tally:" <<endl;
		for (int i = 0; i < size; i++) {
			cout << "Team" << i << " : " << array[i] << "  ";
		}
		cout << endl;
	}
	void sort () {
		std::sort( array, array + size);
		std::reverse( array, array + size);
	}
};

int main (int argc, char const *argv[]) {
	srand (time(NULL));
	Pool pool1(5);
	pool1.play();
	//pool1.sort();
	pool1.print();
	return 0;
}