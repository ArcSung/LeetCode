#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
private:
    void BFD(vector<vector<char>>& board, vector<vector<int>> &dp, int m, int n, int i, int j){
        if(i < 0 || i > m - 1 || j < 0 || j > n - 1) return;
        
        if(dp[i][j] == 1 || board[i][j] == 'X') return;
        
        dp[i][j] = 1;
        
        BFD(board, dp, m, n, i - 1, j);
        BFD(board, dp, m, n, i + 1, j);
        BFD(board, dp, m, n, i, j - 1);
        BFD(board, dp, m, n, i, j + 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        if(!board.size() || !board[0].size())
            return;
        
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int j = 0; j < n; j++){
            BFD(board, dp, m, n, 0, j);
            BFD(board, dp, m, n, m - 1, j);
        }
        
        for(int i = 1; i < m - 1; i++){
            BFD(board, dp, m, n, i, 0);
            BFD(board, dp, m, n, i, n - 1);
        }

        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(board[i][j] == 'O' && dp[i][j] == 0) board[i][j] = 'X';
            }
        }
    }
};

int main(void){

    Solution sl;
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};

    sl.solve(board);

    return 0;
}
