#include <iostream>

using namespace std;

//=========================
// Global Variables
//=========================

char board[3][3];
char currentPlayer = 'X';

//=========================
// Function Prototypes
//=========================

void resetBoard();
void displayBoard();
void playerMove();

//=========================
// Reset Board
//=========================

void resetBoard()
{
    char ch = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ch++;
        }
    }

    currentPlayer = 'X';
}

//=========================
// Display Board
//=========================

void displayBoard()
{
    cout << "\n\n";
    cout << "     TIC TAC TOE\n\n";

    cout << "     " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "    ---+---+---" << endl;
    cout << "     " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "    ---+---+---" << endl;
    cout << "     " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << endl;
}

//=========================
// Player Move
//=========================

void playerMove()
{
    int choice;

    cout << "Player " << currentPlayer << ", Enter Position (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9)
    {
        cout << "\nInvalid Position! Try Again.\n";
        playerMove();
        return;
    }

    if (board[row][col] == 'X' || board[row][col] == 'O')
    {
        cout << "\nPosition Already Taken! Try Again.\n";
        playerMove();
        return;
    }

    board[row][col] = currentPlayer;

    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}
//=========================
// Function Prototypes
//=========================

bool checkWin();
bool checkDraw();
void playGame();

//=========================
// Check Winner
//=========================

bool checkWin()
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    // Main Diagonal
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    // Secondary Diagonal
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

//=========================
// Check Draw
//=========================

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

//=========================
// Play Game
//=========================

void playGame()
{
    bool gameOver = false;

    while (!gameOver)
    {
        displayBoard();

        playerMove();

        displayBoard();

        // currentPlayer changes after every move,
        // so winner is the previous player.
        char winner;

        if (currentPlayer == 'X')
            winner = 'O';
        else
            winner = 'X';

        if (checkWin())
        {
            cout << "\n*****************************";
            cout << "\nPlayer " << winner << " Wins!";
            cout << "\n*****************************\n";

            gameOver = true;
        }
        else if (checkDraw())
        {
            cout << "\n*****************************";
            cout << "\nMatch Draw!";
            cout << "\n*****************************\n";

            gameOver = true;
        }
    }
}
//=========================
// Main Function
//=========================

int main()
{
    char choice;

    cout << "=====================================\n";
    cout << "        TIC TAC TOE GAME\n";
    cout << "=====================================\n";

    do
    {
        resetBoard();

        playGame();

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> choice;

        while (choice != 'Y' && choice != 'y' &&
               choice != 'N' && choice != 'n')
        {
            cout << "Invalid choice! Enter Y or N: ";
            cin >> choice;
        }

    } while (choice == 'Y' || choice == 'y');

    cout << "\n=====================================\n";
    cout << "Thank you for playing Tic Tac Toe!\n";
    cout << "=====================================\n";

    return 0;
}