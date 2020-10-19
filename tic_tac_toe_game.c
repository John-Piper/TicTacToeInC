#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXINDEX 10

void printBoard(char arr[10]);

// clears the screen to show updated array of choice
void clrscr();

// switch function to call functions below
bool checkWinner(char arr[10], char letter, int numberSquare);

// single square check for winner
bool checkOne(char arr[10], char letter);
bool checkTwo(char arr[10], char letter);
bool checkThree(char arr[10], char letter);
bool checkFour(char arr[10], char letter);
bool checkFive(char arr[10], char letter);
bool checkSix(char arr[10], char letter);
bool checkSeven(char arr[10], char letter);
bool checkEight(char arr[10], char letter);
bool checkNine(char arr[10], char letter);

// check if there is a valid square left to play
bool placesLeft(char arr[10]);

// checks and selects a valid column
int playerPick(char arr[10], char playerChar);

// main game logic which calls the logic check functions
char mainGame();

// checks move is valid
bool checkMove(char arr[10], int num);

// check if entry is in the range 1-9
bool checkEntry(int input);

int main() {

    int printResult;

    char gameResult = mainGame();

    // checks how the result will be printed at the end of the game
    if (gameResult != 'D') {
        printResult = (gameResult == 'X') ? 1 : 2;
        printf("player %d wins", printResult);
    }
    else {
        printf("Its a draw");
    }
	return 0;
}
// D = draw X = player one wins O = player Two wins
char mainGame() {
    char board[10] = {'0','1','2','3','4','5','6','7','8','9'};
    bool placeLeft = true;
    char playerChar = 'X';
    int indexChange;
    printBoard(board);
    // continues game unless a player gets 3 in a row or all the squares are taken
    while (placeLeft) {
        indexChange = playerPick(board, playerChar);
        board[indexChange] = playerChar;
        clrscr();
        printBoard(board);
        if (checkWinner(board, playerChar, indexChange)) {
            placeLeft = false;
        }
        else if (placesLeft(board) == false) {
            playerChar = 'D';
            placeLeft = false;
        }
        else {
            playerChar = (playerChar == 'X') ? 'O' : 'X';
        }
    }
    return playerChar;
}

// checks and writes the players pick
int playerPick(char arr[10], char letter) {
    int player;
    int choice;
    bool validChoice = false;
    if (letter = 'X') {
        player = 1;
    }
    else {
        player = 2;
    }
    while (validChoice == false) {
        printf("player %d please select a number: ", player);
        scanf("%d", &choice);
        if (checkEntry(choice) == false)
            printf("Invalid number input plase choose again: ");
        else {
            validChoice = checkMove(arr, choice);
                if(validChoice == false) {
                printf("Invalid Move please choose again: ");
            }
        }
    }
    return choice;
}

// prints the updated array in tic tac toe format
void printBoard(char arr[10]) {

    // print title and player headers
    printf("\n\t\tTic Tac Toe\n\n");
    printf("\tplayer 1 (X) = player 2 (O)\n\n\n");

    int index = 1;

    while(index < MAXINDEX) {

        // boarder no num y axis
        printf("\t \t|\t \t|\n");
        // boarder num y axis
        printf("\t%c\t|\t%c\t|\t%c\n", arr[index], arr[index+1], arr[index+2]);
        // boarder no num y axis
        printf("\t \t|\t \t|\n");

        // to avoid an extra x axis line on the grid
        if (index <= 4) {
        // boarder x axis
        printf("________________|_______________|_______________\n");
        }
        index +=3;
    }

    return;
}

// clears the screen to allow updated array
void clrscr()
{
    system("@cls||clear");
}

bool checkMove(char arr[10], int num) {
    bool legalMove = true;
    if (arr[num] == 'X' || arr[num] == 'O') {
        legalMove = false;
    }
    return legalMove;
}

bool checkEntry(int input) {
    bool validInput = false;
    int numArray[9] = {1,2,3,4,5,6,7,8,9};
    for (int i=0; i<9; i++) {
        if (numArray[i] == input) {
            validInput = true;
            break;
        }
    }
    return validInput;
}

bool placesLeft(char arr[10]) {
    bool placeLeft = false;
    for (int i=1; i<MAXINDEX; i++) {
        if (arr[i] != 'X' && arr[i] != 'O') {
            placeLeft = true;
            break;
        }
    }
    return placeLeft;
}

// checks from the current played position if 3 of the same are in a row
bool checkWinner(char arr[10], char letter, int numberSquare) {
    // winner boolean
    bool isWinner;
    // switch to check move is winner
    switch (numberSquare) {
    case 1:
        isWinner = checkOne(arr, letter);
        break;
    case 2:
        isWinner = checkTwo(arr, letter);
        break;
    case 3:
        isWinner = checkThree(arr, letter);
        break;
    case 4:
        isWinner = checkFour(arr, letter);
        break;
    case 5:
        isWinner = checkFive(arr, letter);
        break;
    case 6:
        isWinner = checkSix(arr, letter);
        break;
    case 7:
        isWinner = checkSeven(arr, letter);
        break;
    case 8:
        isWinner = checkEight(arr, letter);
        break;
    case 9:
        isWinner = checkNine(arr, letter);
        break;
    }
    return isWinner;
}

// logic for checking 3 in a row
bool checkOne(char arr[10], char letter) {
    bool isWinner = false;
    if (letter == arr[2] && arr[2] == arr[3] || letter == arr[4] && arr[4] == arr[7] || letter == arr[5] && arr[5] == arr[9]) {
        isWinner = true;
    }
    return isWinner;
}

bool checkTwo(char arr[10], char letter) {
    bool isWinner = false;
    if (letter == arr[5] && arr[5] == arr[8]) {
            isWinner = true;
    }
    return isWinner;
}

bool checkThree(char arr[10], char letter) {
    bool isWinner = false;
    if (letter == arr[1] && arr[1] == arr[2] || letter == arr[5] && arr[5] == arr[7] || letter == arr[6] && arr[6] == arr[9]) {
        isWinner = true;
    }
    return isWinner;
}

bool checkFour(char arr[10], char letter) {
    bool isWinner = false;
    if (letter == arr[5] && arr[5] == arr[6]) {
        isWinner = true;
    }
    return isWinner;
}

bool checkFive(char arr[10], char letter) {
    bool isWinner = false;
    if (letter == arr[1] && arr[1] == arr[9] || letter == arr[2] && arr[2] == arr[8] || letter == arr[3] && arr[3] == arr[7] || letter == arr[4] && arr[4] == arr[6]) {
        isWinner = true;
    }
    return isWinner;
}

bool checkSix(char arr[10], char letter) {
    bool isWinner = false;
    if (letter == arr[4] && arr[4] == arr[5] || letter == arr[3] && arr[3] == arr[9]) {
        isWinner = true;
    }
    return isWinner;
}

bool checkSeven(char arr[10], char letter) {
    bool isWinner = false;
    if (letter == arr[1] && arr[1] == arr[4] || letter == arr[5] && arr[5] == arr[3] || letter == arr[8] && arr[8] == arr[9]) {
        isWinner = true;
    }
    return isWinner;
}

bool checkEight(char arr[10], char letter) {
    bool isWinner = false;
    if (letter == arr[5] && arr[5] == arr[2]) {
        isWinner = true;
    }
    return isWinner;
}

bool checkNine(char arr[10], char letter) {
    bool isWinner = false;
    if (letter == arr[1] && arr[1] == arr[5] || letter == arr[7] && arr[7] == arr[8] || letter == arr[3] && arr[3] == arr[6]) {
        isWinner = true;
    }
    return isWinner;
}


