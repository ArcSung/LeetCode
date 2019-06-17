#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
   bool isValidSudoku(vector<vector<char>>& board) {
        //check row
        vector<unordered_set<char>> row_s(9, unordered_set<char>()) ;
        vector<unordered_set<char>> col_s(9, unordered_set<char>());
        vector<unordered_set<char>> grid_s(9, unordered_set<char>());

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char c = board[i][j];
                if(c == '.') continue;
                if(!row_s[i].count(c))
                    row_s[i].insert(c);
                else
                    return false;
                
                if(!col_s[j].count(c))
                    col_s[j].insert(c);
                else
                    return false;
                
                int g = getGrid(i, j);
                if(!grid_s[g].count(c))
                    grid_s[g].insert(c);
                else
                    return false;
            }
        }
        
        return true;
    }

    int getGrid(int i, int j){
        return i / 3 + (j / 3) * 3;
    }
};

int main(void){
    Solution sl;

    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','2','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

    bool ret = sl.isValidSudoku(board);

    printf("%d \n", ret);
}
