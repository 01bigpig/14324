#include <iostream>
using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
    int r() const { return m_row; }
    int c() const { return m_col; }
private:
    int m_row;
    int m_col;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    // If the start location is equal to the ending location, then we've solved the maze, so return true.
    if (sr == er && sc == ec)
        return true;

    // Mark the start location as visited.
    maze[sr][sc] = 'E';

    // South
    if (sr + 1 < 10 && maze[sr + 1][sc] == '.')
    {
        if (pathExists(maze, sr + 1, sc, er, ec))
            return true;
    }

    // North
    if (sr - 1 >= 0 && maze[sr - 1][sc] == '.')
    {
        if (pathExists(maze, sr - 1, sc, er, ec))
            return true;
    }

    // East
    if (sc + 1 < 10 && maze[sr][sc + 1] == '.')
    {
        if (pathExists(maze, sr, sc + 1, er, ec))
            return true;
    }

    // West
    if (sc - 1 >= 0 && maze[sr][sc - 1] == '.')
    {
        if (pathExists(maze, sr, sc - 1, er, ec))
            return true;
    }

    return false;
}

int main()
{
    char maze[10][10] = {
        { 'X','X','X','X','X','X','X','X','X','X' },
        { 'X','.','.','.','X','.','.','X','.','X' },
        { 'X','.','X','X','X','.','.','.','.','X' },
        { 'X','.','X','.','X','X','X','X','.','X' },
        { 'X','X','X','.','.','.','.','.','.','X' },
        { 'X','.','.','.','X','.','X','X','.','X' },
        { 'X','.','X','.','X','.','.','X','.','X' },
        { 'X','.','X','X','X','X','.','X','.','X' },
        { 'X','.','.','X','.','.','.','X','.','X' },
        { 'X','X','X','X','X','X','X','X','X','X' }
    };
    int sc = 3, sr = 4, ec = 8, er = 1;
    if (pathExists(maze, sr, sc, er, ec))
        cout << "path available" << endl;
    else
        cout << "do not exist" << endl;
    return 0;
}

