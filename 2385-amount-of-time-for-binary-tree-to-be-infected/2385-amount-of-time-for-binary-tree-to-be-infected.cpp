/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<int> adj[100001];
    void buildGraph(TreeNode* root)
    {
        if(root==NULL)
            return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(left!=NULL)
        {
            adj[root->val].push_back(left->val);
            adj[left->val].push_back(root->val);
        }
        if(right!=NULL)
        {
            adj[root->val].push_back(right->val);
            adj[right->val].push_back(root->val);
        }
        buildGraph(left);
        buildGraph(right);
    }
    int BFS(int source)
    {
        queue<int>q;
        bool vis[100001]={};
        q.push(source);
        int sz,dep=-1;
        while(!q.empty())
        {
            sz=q.size();
            dep++;
            while(sz--)
            {
                int cur = q.front();
                q.pop();
                vis[cur]=true;
                vector<int> vec = adj[cur];
                for(int i=0;i<vec.size();i++)
                {
                    int child=vec[i];
                    cout << child << " ";
                    if(!vis[child])
                    {
                        vis[child]=true;
                        q.push(child);
                    }
                }
            }
        }
        return dep;
    }
    int amountOfTime(TreeNode* root, int start) {
        buildGraph(root);
        return BFS(start);
    }
};