#include <iostream>
#include <vector>
using namespace std;

// Function to print the solution
void printBoard(vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Check if it's safe to place the queen at board[row][col]
bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check this row on left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N-Queens problem using backtracking
bool solveNQueens(vector<vector<int>>& board, int col, int n) {
    // If all queens are placed, return true
    if (col >= n)
        return true;

    // Try placing the queen in all rows in this column
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            // Place this queen at board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueens(board, col + 1, n))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution, backtrack
            board[i][col] = 0;
        }
    }

    // If the queen cannot be placed in any row in this column, return false
    return false;
}

// Driver function
int main() {
    int n ;
    // Size of the chessboard
    cout<<"Enter chess board size : ";
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n, 0));

    // Place the first queen at a predefined position (for example, row 0, column 0)
    board[0][0] = 1;

    // Solve the remaining N-Queens problem
    if (solveNQueens(board, 1, n)) {
        printBoard(board, n);  // Print the final solution
    } else {
        cout << "Solution does not exist" << endl;
    }

    return 0;
}