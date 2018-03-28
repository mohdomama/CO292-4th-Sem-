#include <iostream>
#include <stdio.h>

using namespace std;

void map(int arr[],  char word[] ){
	for (int i = 0; word[i]!='\0'; i++){
		arr[word[i] - 97]++;
	}
}

void initialise(int input[]){
	for (int i =0 ; i < 26; i ++){
		input[i] = 0;
	}
}

int main(){
	
	int input1[26];
	int input2[26];

	char word1[100];
	char word2[100];

	initialise(input1);
	initialise(input2);

	scanf("%s", word1);
	scanf("%s", word2);

	printf("%s %s\n", word1, word2);

	map(input1, word1);
	map(input2, word2);

	int flag = 0;
	for (int i = 0; i < 26; i++){
		if (input1[i] != input2[i]){
			flag = 1;
			break;
		}
	}

	if (flag == 0)
		cout << "YES!" <<endl;
	else
		cout << "NO!" <<endl;





	return 0;
}