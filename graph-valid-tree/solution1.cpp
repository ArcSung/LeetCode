#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <queue> 
#include <vector> 
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> g(n, vector<int>());
        vector<bool> v(n, false);
        for (auto a : edges) {
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
        }
        if (!dfs(g, v, 0, -1)) return false;
        for (auto a : v) {
            if (!a) return false;
        }
        return true;
    }
    bool dfs(vector<vector<int>> &g, vector<bool> &v, int cur, int pre) {
        if (v[cur]) return false;
        v[cur] = true;
        for (auto a : g[cur]) {
            if (a != pre) {
                if (!dfs(g, v, a, cur)) return false;
            }
        }
        return true;
    }
};

int main(void){
    Solution sl;
    vector<pair<int, int>> edges;
    edges.push_back(pair<int, int> {0, 1});
    edges.push_back(pair<int, int> {1, 2});
    edges.push_back(pair<int, int> {2, 3});
    edges.push_back(pair<int, int> {1, 3});
    edges.push_back(pair<int, int> {1, 4});

    int ret = sl.validTree(5, edges);

    printf("ret:%d\n", ret);

    return ret;
}
