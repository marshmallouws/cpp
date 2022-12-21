#include <iostream>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Square **createChessboard(unsigned int n)
{
    Square **board = new Square *[n];

    for (unsigned int i = 0; i < n; i++)
    {
        board[i] = new Square[n];
    }

    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            board[i][j] = {none, nobody};
        }
    }

    return board;
}

// Task 1(b).  Implement this function
void displayChessboard(Square **c, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            if (c[i][j].team == nobody)
            {
                cout << "_";
            }
            else
            {
                if (c[i][j].team == white)
                {
                    c[i][j].piece == rook ? cout << "r" : cout << "b";
                }
                else
                {
                    c[i][j].piece == rook ? cout << "R" : cout << "B";
                }
            }

            if (j != n - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
bool move(Square **c, unsigned int n,
          int r1, int c1, int r2, int c2)
{

    // Check validity of input positions
    if (r1 > n || c1 > n || r2 > n || c2 > n)
    {
        return false;
    }

    // Check if the two squares are different from each other
    if (r1 == r2 && c1 == c2)
    {
        return false;
    }

    // Check if same team or nobody
    if (c[r1][c1].team == c[r2][c2].team)
    {
        return false;
    }

    // Check if there is a piece on first position
    if (c[r1][c1].piece == none)
    {
        return false;
    }

    // Check if the move is rookable
    if (c[r1][c1].piece == rook)
    {
        if (r1 != r2 && c1 != c2)
        {
            return false;
        }
    }
    else
    {
        int rowDiff = abs(r1 - r2);
        int colDiff = abs(c1 - c2);
        if (rowDiff != colDiff)
        {
            return false;
        }
    }

    // Move piece
    c[r2][c2].piece = c[r1][c1].piece;
    c[r2][c2].team = c[r1][c1].team;

    // Remove piece from old position
    c[r1][c1].piece = none;
    c[r1][c1].team = nobody;

    return true;
}

// Task 1(d).  Implement this function
bool threatened(Square **c, unsigned int n,
                int row, int col)
{
    Team team;
    team = c[row][col].team;
    bool threatened;
    threatened = false;

    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            if (c[i][j].team == nobody || c[i][j].team == team)
            {
                continue;
            }

            if (c[i][j].piece == rook)
            {
                if (i == row || j == col)
                {
                    return true;
                }
            }
            else
            {
                int rowDiff = abs(int(i) - row);
                int colDiff = abs(int(j) - col);
                if (rowDiff == colDiff)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// Do not modify
void deleteChessboard(Square **c, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        delete[] c[i];
    }
    delete[] c;
}
