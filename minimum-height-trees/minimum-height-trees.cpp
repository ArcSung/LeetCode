#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <queue> 
#include <vector> 
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n <= 1)
            return {0};
        
        vector<unordered_set<int>> graph(n, unordered_set<int>());
        queue<int> q;
        
        for(auto a: edges){
            graph[a[0]].insert(a[1]);
            graph[a[1]].insert(a[0]);
        }
        
        for(int i = 0; i < n; i++)
            if(graph[i].size() == 1)
                q.push(i);
            
        while(n > 2){
            int size = q.size();
            n -= size;
            
            for(int i = 0; i < size; i++){
                int top = q.front(); q.pop();
                for(auto a: graph[top]){
                    graph[a].erase(top);
                    if(graph[a].size() == 1) q.push(a);
                }
            }
        }
        
        vector<int> ret;
        
        while(!q.empty()){
            ret.push_back(q.front());
            q.pop();
        }
        
        return ret;
    }
};

int main(void){
    Solution sl;
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};

    sl.findMinHeightTrees(4, edges);

    return true;
}
