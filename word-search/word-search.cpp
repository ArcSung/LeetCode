#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, vector<vector<bool>>& check, int i, int j, int s){
        if(s == word.size() - 1) return true;
        
        if (i < 0 || j < 0 || i >= board[0].size() || j >= board.size() || check[j][i] || board[j][i] != word[s]) return false;

        check[j][i] = true;

        bool res = helper(board, word, check, i, j-1, s+1) 
                 || helper(board, word, check, i, j+1, s+1)
                 || helper(board, word, check, i-1, j, s+1)
                 || helper(board, word, check, i+1, j, s+1);
        check[j][i] = false;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0 || board.size() == 0)
            return false;
        
        vector<vector<bool>> check(board.size(), vector<bool>(board[0].size(), 0));
        for(int j = 0 ; j < board.size(); j++){
            for(int i = 0 ; i < board[0].size(); i++){
                if(helper(board, word, check, i, j, 0)) return true;
            }
        }
        
        return false;
    }
};

int main(void){
    Solution sl;

    vector<vector<char>>board = {{'A', 'B', 'C', 'E'},{'S', 'F', 'E', 'S'},{'A', 'D', 'E', 'E'}};
    //vector<vector<char>>board = {{'F', 'Y', 'C', 'E', 'N', 'R', 'D'}, {'K', 'L', 'N', 'F', 'I', 'N', 'U'},{'A', 'A', 'A', 'R', 'A', 'H', 'R'},{'N', 'D', 'K', 'L', 'P', 'N', 'E'},
    //                            {'A', 'L', 'A', 'N', 'S', 'A', 'P'},{'O', 'O', 'G', 'O', 'T', 'P', 'N'},{'H', 'P', 'O', 'L', 'A', 'N', 'O'}};

    string word = "ABCESEEEFS";
    //string word = "USA";

    bool ret = sl.exist(board, word);

    printf("ret:%d\n", ret);

    return ret;
}
