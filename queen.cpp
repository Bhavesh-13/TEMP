#include <iostream>
#include <cmath>

int board[20], count;

using namespace std;

void print(int n) {
    int i, j;
    cout << "\n\nSolution " << ++count << ":\n\n";
    for (i = 1; i <= n; i++)
        cout << " " << i;
    for (i = 1; i <= n; i++) {
        cout << "\n\n" << i;
        for (j = 1; j <= n; j++) {
            if (board[i] == j)
                cout << " Q";
            else
                cout << " -";
        }
    }
}

int place(int row, int column) {
    int i;
    for (i = 1; i <= row - 1; i++) {
        if (board[i] == column)
            return 0;
        else if (abs(board[i] - column) == abs(i - row))
            return 0;
    }
    return 1;
}

void queen(int row, int n) {
    int column;
    for (column = 1; column <= n; column++) {
        if (place(row, column)) {
            board[row] = column;
            if (row == n)
                print(n);
            else
                queen(row + 1, n);
        }
    }
}

int main() {
    int n;
    cout << "\n\nEnter number of Queens:";
    cin >> n;
    queen(1, n);
    return 0;
}
