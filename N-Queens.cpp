#include <iostream>
#include <vector>
using namespace std;

// Function to check if placing a queen at (row, col) is safe
bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < col; i++) { // Check row on the left
        if (board[row][i] == 1) return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) { // Check upper diagonal
        if (board[i][j] == 1) return false;
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--) { // Check lower diagonal
        if (board[i][j] == 1) return false;
    }
    return true;
}

// Recursive function to solve N-Queens and print all solutions
void solveNQueens(vector<vector<int>>& board, int col, int n) {
    if (col >= n) { // All queens placed, print the solution
        for (int i = 0; i < n; i++) { // Rows
            for (int j = 0; j < n; j++) { // Columns
                cout << (board[i][j] == 1 ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) { // Try placing queen in each row of the current column
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1; // Place queen
            solveNQueens(board, col + 1, n); // Continue to next column
            board[i][col] = 0; // Backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));

    solveNQueens(board, 0, n);

    return 0;
}
