#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main()
{
    srand(time(0)); // Initialize random seed once

    char winner = ' ';

    resetBoard();
    while (winner == ' ' && checkFreeSpaces() > 0)
    {
        printBoard();

        playerMove();
        winner = checkWinner();

        

        computerMove();
        winner = checkWinner();

        if (winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }
    }

    printBoard();
    printWinner(winner);

    return 0;
}

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int checkFreeSpaces()
{
    int freeSpaces = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                freeSpaces++;
            }
        }
    }
    return freeSpaces;
}

void playerMove()
{
    int x, y;

    do
    {
        printf("Enter row # (1-3): ");
        scanf("%d", &x);
        printf("Enter column # (1-3): ");
        scanf("%d", &y);

        x--; // Adjust for 0-based index
        y--;

        if (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != ' ')
        {
            printf("Invalid Move! Try again.\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (1);
}

void computerMove()
{
    int x, y;

    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
}

char checkWinner()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
        {
            return board[0][i];
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
    {
        return board[0][2];
    }

    return ' ';
}

void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("You Win!\n");
    }
    else if (winner == COMPUTER)
    {
        printf("Computer Wins!\n");
    }
    else
    {
        printf("It's a Tie!\n");
    }
}