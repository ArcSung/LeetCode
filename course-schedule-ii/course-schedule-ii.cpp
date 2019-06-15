#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <queue> 
#include <vector> 
#include <unordered_map>
using namespace std;


class Solution {
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in(numCourses);
        vector<int> ret;
        
        for (auto a : prerequisites) {
            graph[a[1]].push_back(a[0]);
            ++in[a[0]];
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
           if (in[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int t = q.front(); q.pop();
            ret.push_back(t);
            for (auto a : graph[t]) {
                --in[a];
                if (in[a] == 0) q.push(a);
            }
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] != 0) return vector<int> {};
        }
        
        return ret;
    }
};


int main(void){
    Solution sl;
    vector<vector<int>> pre;
    pre.push_back(vector<int> {3, 0});
    pre.push_back(vector<int> {3, 1});
    pre.push_back(vector<int> {3, 2});
    pre.push_back(vector<int> {4, 3});

    sl.findOrder(5, pre);

    return ret;
}
