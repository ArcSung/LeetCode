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
        vector<int> roots(n, -1);
        for (auto a : edges) {
            int x = find(roots, a.first), y = find(roots, a.second);
            if (x == y) return false;
            roots[x] = y;
        }
        return edges.size() == n - 1;
    }
    int find(vector<int> &roots, int i) {
        while (roots[i] != -1) i = roots[i];
        return i;
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
