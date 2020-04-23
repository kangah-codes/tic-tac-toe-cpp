#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

char boardList[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char signs[] = {'X', '0'};
char p1[1];
char p2[1];
char p1_sign[1];
char p2_sign[1];
int start;
int turn;

void drawBoard(char arr[]){
	cout << "   |   |      " << endl; 
	cout << " " << arr[6] << " " << "| " << arr[7] << " " << "| " << arr[8] << " " << endl; 
	cout << "___|___|___" << endl; 
	cout << "   |   |      " << endl; 
	cout << " " << arr[3] << " " << "| " << arr[4] << " " << "| " << arr[5] << " " << endl;
	cout << "___|___|___" << endl; 
	cout << "   |   |      " << endl; 
	cout << " " << arr[0] << " " << "| " << arr[1] << " " << "| " << arr[2] << " " << endl; 
	cout << "   |   |      " << endl; 
}

int addToBoard(char arr[], char item, int position){
	if (arr[position] != 'X' || arr[position] != '0'){
		arr[position] = item;
		return 1;
	}else{
		return 0;
	}
}

void checkForWin(char arr[]){
	char temp[] = {};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);++i){
		temp[i] = arr[i];
	}
}

bool allHorizontal(char arr[]){
	return (arr[0] == arr[1] == arr[2] || arr[3] == arr[4] == arr[5] || arr[6] == arr[7] == arr[8]);
}

bool allVertical(char arr[]){
	return (arr[0] == arr[5] == arr[6] || arr[1] == arr[4] == arr[7] || arr[2] == arr[3] == arr[8]);
}

bool allDiagonal(char arr[]){
	return (arr[0] == arr[4] == arr[8] || arr[2] == arr[4] == arr[6]);
}

void startGame(){
	srand ( time(NULL) ); //initialize the random seed

	cout << "Welcome to tic-tac" << endl;
	cout << endl;
	cout << "Rules:\nFirst player to make a horizontal, vertival or diagonal line with their sign wins" << endl;	
	cout << "Player 1 enter their name: ";
	cin >> p1;
	cout << endl;
	cout << "Player 2 enter their name: ";
	cin >> p2;

	p1_sign = signs[rand() % 1];
	if (p1_sign == 'X'){
		p2_sign = '0';
	}else{
		p2_sign = 'X';
	}

	turn = rand()%2;
}


int main(){
	drawBoard(boardList);

	return 0;
}