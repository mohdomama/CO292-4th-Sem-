#include <iostream>
using namespace std;



int main(){
	int m,c, temp;
	int length;
	cout << "Enter the length of the square:" << endl;
	cin >> length;
	cout << "Enter slope and constant of the line:" << endl;
	cin >> m >> c;
	// For Left
	cout << endl;
	cout << "On left" << endl;
	temp = c;
	if (0 <= temp && temp <= length){
		cout << 0 << " " << temp << endl;
	}
	else {
		cout << "Not in Range" << endl;
	}
	cout << endl;
	
	// For Right
	cout << "On Right" << endl;
	temp =m*length + c;
	if (0 <= temp && temp <= length){
		cout << length << " " << temp << endl;
	}
	else {
		cout << "Not in Range" << endl;
	}
	cout << endl;

	// For Top
	cout << "On Top" << endl;

	if (m==0){
		if (c==length){
			temp = 0;
		}
		else{
			temp = -1;
		}
	}
	else{
		temp = (length-c)/m;
	}
	
	if (0 <= temp && temp <= length){
		cout << temp << " " << length << endl;
	}
	else {
		cout << "Not in Range" << endl;
	}
	cout << endl;

	// For Bottom
	cout << "On Bottom" << endl;
	if (m==0){
		if (c==0){
			temp = 0;
		}
		else{
			temp = -1;
		}
	}
	else{
		temp = -c/m;
	}
	
	if (0 <= temp && temp <= length){
		cout << temp << " " << 0 << endl;
	}
	else {
		cout << "Not in Range" << endl;
	}
	cout << endl;

	return 0;
}