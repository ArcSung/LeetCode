#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <queue> 
#include <vector> 
#include <unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val) {val = _val;}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;

        unordered_map<Node*, Node*> m;
        queue<Node*> q{{node}};
        Node *clone = new Node(node->val);
        m[node] = clone;

        while (!q.empty()) {
            Node *t = q.front(); q.pop();
            for (Node *neighbor : t->neighbors) {
                if (!m.count(neighbor)) {
                    m[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                m[t]->neighbors.push_back(m[neighbor]);
            }
        }

        return clone;
    }
};


int main(void){
    Solution sl;
    Node a1(1);
    Node a2(2);
    Node a3(3);
    Node a4(4);

    a1.neighbors.push_back(&a2);
    a1.neighbors.push_back(&a4);
    a2.neighbors.push_back(&a1);
    a2.neighbors.push_back(&a3);
    a3.neighbors.push_back(&a2);
    a3.neighbors.push_back(&a4);
    a4.neighbors.push_back(&a1);
    a4.neighbors.push_back(&a3);

    sl.cloneGraph(&a1);

    return true;
}
