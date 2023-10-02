#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE];

void initializeBoard() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = '_';
        }
    }
}

void displayBoard() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return 0;
    }
    if (board[row][col] != '_') {
        return 0;
    }
    return 1;
}

int checkWin() {
    int i;
    // Check rows
    for (i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '_') {
            return 1;
        }
    }
    // Check columns
    for (i = 0; i < SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '_') {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '_')) {
        return 1;
    }
    return 0;
}

int makeMove(int row, int col, char symbol) {
    if (isValidMove(row, col)) {
        board[row][col] = symbol;
        return 1;
    } else {
        return 0;
    }
}

int switchPlayer(int player) {
    if (player == 1) {
        return 2;
    } else {
        return 1;
    }
}

int main() {
    int player = 1;
    int row, col;
    char symbol;
    
    initializeBoard();
    
    while (!checkWin() && player <= SIZE*SIZE) {
        displayBoard();
        
        printf("Player %d's turn\n", player);
        
        if (player == 1) {
            symbol = 'X';
        } else {
            symbol = 'O';
        }
        
        printf("Enter row: ");
        scanf("%d", &row);
        
        printf("Enter column: ");
        scanf("%d", &col);
        
        if (makeMove(row, col, symbol)) {
            player = switchPlayer(player);
        } else {
            printf("Invalid move, try again\n");
        }
    }
    
    displayBoard();
    
    if (checkWin()) {
        printf("Player %d wins!\n", switchPlayer(player));
    } else {
        printf("It's a tie!\n");
    }
    
    return 0;
}
