//lc 1261


//dfs

class FindElements {
    public:
       map<int,bool>m;
        void solve(TreeNode* root,int node){
           if(root==NULL) return;
            m[node]=true;
    
            solve(root->left,node*2+1);
           solve(root->right,node*2+2);
            
        }
        FindElements(TreeNode* root) {
            int node=0;
            solve(root,node);
            
        }
        
        bool find(int target) {
            return m[target];
        }
    };
    