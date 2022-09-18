/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    map<Node*,Node*>dp;
    void buildGraph(Node* source)
    {
        Node* copy = new Node(source->val);
        dp[source]=copy;
        for(auto node:source->neighbors)
        {
            if(dp.find(node)!=dp.end())
                copy->neighbors.push_back(dp[node]);
            else
            {
                buildGraph(node);
                copy->neighbors.push_back(dp[node]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        buildGraph(node);
        return dp[node];
    }
};