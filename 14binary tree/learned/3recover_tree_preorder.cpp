//lc 1028

//https://youtu.be/WN0quIK89F0?si=eWx5tnpDvTDtgijq



//T.C : O(n)
//S.C : O(n) for System Stack used for Recursion
class Solution {
    public:
        int n;
    
        TreeNode* solve( string& traversal, int& i, int depth) {  // i by ref hoga 
            if (i >= n)
                return NULL;
    
            int j = i;
            while (j < n && traversal[j] == '-') {
                j++;
            }
            
            int dash = j-i;
    
            if(depth != dash) {
                return NULL;
            }
    
            i += dash;
    
            int value = 0;
            while (i < n && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }
    
            TreeNode* root = new TreeNode(value);
    
            root->left  = solve(traversal, i, depth + 1);
            root->right = solve(traversal, i, depth + 1);
    
            return root;
        }
    
        TreeNode* recoverFromPreorder(string traversal) {
            n = traversal.length();
            int i = 0;
            int depth=0;
            TreeNode* root=solve(traversal, i, depth);
            return root;
        }
    
    };
    
    