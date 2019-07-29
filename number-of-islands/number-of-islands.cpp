#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;

class Solution {
private:
    int DFS(vector<vector<char>>& grid, vector<vector<int>>& map, int i, int rm, int j, int cm, int num){
        if(i < 0 || i >= rm || j < 0 || j >= cm)
            return -1;

        if(map[i][j] > 0 || grid[i][j] != '1')
            return -1;
        
        int m = grid.size();
        int n = grid[0].size();
        
        
        map[i][j] = num;
        
        DFS(grid, map, i + 1, rm, j, cm, num);
        DFS(grid, map, i, rm, j + 1, cm, num);
        DFS(grid, map, i - 1, rm, j, cm, num);
        DFS(grid, map, i, rm, j - 1, cm, num);
        
        
        return 0;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        
        if(m == 0)
            return 0;
        
        int n = grid[0].size();
        
        vector<vector<int>> map(m, vector<int>(n, false));
        
        int num = 1;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(DFS(grid, map, i, m, j, n, num) == 0)
                    num++;
            }
        }
        
        return num - 1;
    }
};

int main(int argc, char** args){
    Solution sl;
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','1','1'},
    };

    int ret = sl.numIslands(grid);

    return true;
}
