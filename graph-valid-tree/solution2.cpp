#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <queue> 
#include <vector> 
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> g(n, unordered_set<int>());
        unordered_set<int> s{{0}};
        queue<int> q{{0}};
        for (auto a : edges) {
            g[a.first].insert(a.second);
            g[a.second].insert(a.first);
        }
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (auto a : g[t]) {
                if (s.count(a)) return false;
                s.insert(a);
                q.push(a);
                g[a].erase(t);
            }
        }
        return s.size() == n;
    }
};

int main(void){
    Solution sl;
    vector<pair<int, int>> edges;
    edges.push_back(pair<int, int> {0, 1});
    edges.push_back(pair<int, int> {1, 2});
    edges.push_back(pair<int, int> {2, 3});
    edges.push_back(pair<int, int> {1, 4});

    int ret = sl.validTree(5, edges);

    printf("ret:%d\n", ret);

    return ret;
}
