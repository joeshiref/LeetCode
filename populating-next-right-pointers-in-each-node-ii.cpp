/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node * BFS(Node* source)
    {
        queue<Node*>q;
        Node *cur=source;
        q.push(cur);
        int sz=q.size();
        Node*ans=cur;
        for(; !q.empty(); sz=q.size())
        {
            while(sz--)
            {
                cur=q.front();
                q.pop();
                if(!sz)
                    cur->next=NULL;
                else
                    cur->next=q.front();
                if(cur->left!=NULL)
                    q.push(cur->left);
                if(cur->right!=NULL)
                    q.push(cur->right);
            }
        }
        return ans;
    }
    
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        return BFS(root);
    }
};