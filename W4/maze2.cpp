#include <iostream>

using namespace std;

typedef enum
{
    wood,
    stone
} material;

struct tile
{
    int x, y;
    bool isWall;
    material type;
};

int nrows;
int ncols;

void printBoard(int x, int y, tile **playground)
{
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            if (i == x && y == j)
            {
                cout << "O";
            }
            else if (playground[i][j].isWall)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

auto movePlayer(int x, int y, tile **playground, char input)
{
    struct res
    {
        int x, y;
    };

    if (input == 'l' && !playground[x][y - 1].isWall)
    {
        y--;
    }
    else if (input == 'r' && !playground[x][y + 1].isWall)
    {
        y++;
    }
    else if (input == 'u' && !playground[x - 1][y].isWall)
    {
        x--;
    }
    else if (input == 'd' && !playground[x + 1][y].isWall)
    {
        x++;
    }
    return res{x, y};
}

int main()
{
    cin >> nrows;
    cin >> ncols;

    int x, y;
    x = ncols / 2;
    y = nrows / 2;

    tile **playground = new tile *[nrows];

    for (int i = 0; i < nrows; i++)
    {
        playground[i] = new tile[ncols];
    }

    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j == 0 || i == (nrows - 1) || (i == 0 && j != 3) || j == (ncols - 1));
            if (playground[i][j].isWall)
            {
                playground[i][j].type = stone;
            }
            else
            {
                playground[i][j].type = wood;
            }
        }
    }

    printBoard(x, y, playground);

    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == 'q')
        {
            return 0;
        }

        auto [rx, ry] = movePlayer(x, y, playground, input[i]);
        x = rx;
        y = ry;
        printBoard(x, y, playground);
    }
    exit(0);
}