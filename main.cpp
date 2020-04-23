#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

char boardList[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char signs[] = {'X', '0'};
char p1;
char p2;
char p1_sign;
char p2_sign;
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

bool addToBoard(char arr[], char item, int position){
	if (arr[position] != 'X' && arr[position] != '0'){
		arr[position] = item;
		return true;
	}else{
		return false;
	}
}

void checkForWin(char arr[]){
	char temp[] = {};
	for (int i=0;i<sizeof(arr);++i){
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


void playGame(){
	int moves = 0;
	bool gamePlay = true;
	bool replay = true;
	int loc;
	char buffer[10]; // buffer for storing board location
	if (replay){
		char boardList[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	}

	cout << "Player 1's sign is " << p1_sign << endl;
	cout << "Player 2's sign is " << p2_sign << endl;

	while (gamePlay){
		cout << "It is player " << turn << "'s turn to play" << endl;
		drawBoard(boardList);
		cout << "Which location would player " << turn << " put their sign?" << endl;
		cin >> loc;

		try{
			if (boardList[loc] == itoa(loc, buffer, 10)){
				if (turn == 0){
					// player 1 turn
					if (addToBoard(boardList, p1_sign, loc)){
						turn = 1;
					}
				}else{
					if (addToBoard(boardList, p2_sign, loc)){
						turn = 0;
					}
				}
			}
		}catch (...){
			cout << "That space is already occupied" << endl;
		}
	}
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

	playGame();
}


int main(){
	drawBoard(boardList);

	return 0;
}