/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    vector<vector<int>> BFS(Node* root)
    {
        queue<Node*>q;
        vector<vector<int> >ans;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>tmp;
            while(sz--)
            {
                Node* cur = q.front();
                tmp.push_back(cur->val);
                q.pop();
                vector<Node*> children=cur->children;
                for(int i=0;i<children.size();i++)
                    q.push(children[i]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
    
    
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)
            return {};
        return BFS(root);
    }
};