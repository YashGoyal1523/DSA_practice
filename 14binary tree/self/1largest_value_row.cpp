// lc 515


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




   vector<int> leveltraversal(TreeNode* root){
        if(root==NULL) return {};
        vector<int>ans;
        queue<TreeNode*>q;
        vector<int>v;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(node!=NULL){
                v.push_back(node->val);
               if(node->left!=NULL) q.push(node->left);
               if(node->right!=NULL) q.push(node->right);
            }
            else{
                ans.push_back(*max_element(v.begin(),v.end()));
                v.clear();
               if(!q.empty()) q.push(NULL);
                
            }
        }
    return ans;
    }


class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        return leveltraversal(root);
    }
};