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
    
    unordered_map<TreeNode*,vector<TreeNode*>>adj;
    TreeNode* startNode;
    void buildGraph(TreeNode* root,int start)
    {
        if(root==NULL)
            return;
        if(root->val==start)
            startNode=root;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(left!=NULL)
        {
            adj[root].push_back(left);
            adj[left].push_back(root);
        }
        if(right!=NULL)
        {
            adj[root].push_back(right);
            adj[right].push_back(root);
        }
        buildGraph(left,start);
        buildGraph(right,start);
    }
    int BFS(TreeNode*source)
    {
        queue<TreeNode*>q;
        map<TreeNode*,bool>vis;
        q.push(source);
        int sz,dep=-1;
        while(!q.empty())
        {
            sz=q.size();
            dep++;
            while(sz--)
            {
                TreeNode*cur = q.front();
                cout << cur->val << " ";
                q.pop();
                vis[cur]=true;
                vector<TreeNode*> vec = adj[cur];
                for(int i=0;i<vec.size();i++)
                {
                    TreeNode*child=vec[i];
                    if(!vis[child])
                    {
                        vis[child]=true;
                        q.push(child);
                    }
                }
            }
            cout << endl;
        }
        return dep;
    }
    int amountOfTime(TreeNode* root, int start) {
        buildGraph(root,start);
        return BFS(startNode);
    }
};