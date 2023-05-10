#include <iostream>
#include <vector>

using namespace std;

bool isValid(const vector<int>& board, int row, int col) {
    // Kiểm tra xem vị trí (row, col) có hợp lệ không
    for (int i = 0; i < row; i++) {
        // Kiểm tra cùng cột
        if (board[i] == col)
            return false;
        // Kiểm tra đường chéo chính
        if (abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solveQueens(vector<vector<int>>& solutions, vector<int>& board, int row) {
    int N = board.size();
    if (row == N) {
        // Tìm được một lời giải
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isValid(board, row, col)) {
            board[row] = col;
            solveQueens(solutions, board, row + 1);
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> solutions;
    vector<int> board(n, -1);
    solveQueens(solutions, board, 0);
    return solutions;
}

void printSolution(const vector<int>& solution) {
    int N = solution.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (solution[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int N = 8;  // Số cột và số hàng của bàn cờ
    vector<vector<int>> solutions = solveNQueens(N);
    int numSolutions = solutions.size();
    cout << "Number of solutions: " << numSolutions << endl;
    cout << "Solutions:" << endl;
    for (int i = 0; i < numSolutions; i++) {
        cout << "Solution " << i + 1 << ":" << endl;
        printSolution(solutions[i]);
    }
    return 0;
}
