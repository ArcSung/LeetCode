#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <queue> 
#include <vector> 
#include <unordered_map>
using namespace std;


class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {    
            vector<vector<int>> graph(numCourses, vector<int>());
            vector<int> in(numCourses);
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
                for (auto a : graph[t]) {
                    --in[a];
                    if (in[a] == 0) q.push(a);
                }
            }
            for (int i = 0; i < numCourses; ++i) {
                if (in[i] != 0) return false;
            }
            return true;
        }
};


int main(void){
    Solution sl;
    vector<vector<int>> pre;
    pre.push_back(vector<int> {3, 0});
    pre.push_back(vector<int> {3, 1});
    pre.push_back(vector<int> {3, 2});
    pre.push_back(vector<int> {4, 3});
    pre.push_back(vector<int> {0, 4});

    int ret = sl.canFinish(5, pre);

    printf("ret:%d\n", ret);

    return ret;
}
