
// note: ques : min swaps required for a vector (unique elements) to be sorted
// ans 
// m1 original vector ka  sorted version ka vector lo.....ab origial vector m shuru se traverse kro and har index pe dekho ki iss position pe jo element hona chahie acc to  sorted vector ...vhi hai toh aage bhado and nhi h toh swap it with the element jo iss position pe hona chahie  ....swap count bhadao ....and aage bhado...ese krte jao shuru se end tak traverse krte hue....
int find(vector<int>& original) {
        int swaps = 0;
        vector<int> target = original;
        sort(target.begin(), target.end());

        // Map to track current positions of values in original vector
        unordered_map<int, int> pos;
        for (int i = 0; i < original.size(); i++) {
            pos[original[i]] = i;
        }

      // traverse
        for (int i = 0; i < original.size(); i++) {
            if (original[i] != target[i]) { // iss index pe jo element hona chahie voh nhi h
                int Pos = pos[target[i]]; // jo element hona chahie uski current position in original vector is this
                swap(original[i], original[Pos]); // swap krdo 
                swaps++;
                // position update krdo
                pos[original[Pos]] = Pos;
                pos[original[i]]=i; 
                
            }
        }
        return swaps;
    }
// m2 original vector ka  sorted version ka vector lo.....ab original vector m shuru se traverse kro... and har ek index pe dekho....jo element h agar uski yehi correct position  acc to sorted array toh aage bhado vrna swap it with its correct position..swap count bhadado...then again check on isi index ...if jo element aaya uski correct position yhi h toh aage bhado vrna swap...again check......so on.... do end tak 
 int find(vector<int>& original) {
        int swaps = 0;
        vector<int> target = original;
        sort(target.begin(), target.end());

        // Map to track positions of values in target vector
        unordered_map<int, int> pos;
        for (int i = 0; i < target.size(); i++) {
            pos[target[i]] = i;
        }

      // traverse
      // tarika 1
      int i=0;
      while(i<original.size()){
         if (original[i]!= target[i]) { // element correct position pe nhi h
            int posi=pos[original[i]]; // element ki correct position
            swap(original[i],original[posi]);  // swap
            swaps++;         
      }
      else{ // element correct correct position pe h
        i++;
      }
      }
      // // tarika 2
    //    int i=0;
    //   while(i<original.size()){
    //      while(original[i] != target[i]) {
    //         int posi=pos[original[i]];
    //         swap(original[i],original[posi]);  
    //         swaps++;         
    //   }
      
    //     i++;
      
    //   }
      return swaps;
      }

//lc 2471
// har level ke liye ese kro ki ...uss level ke saare node values vector m store krlo...fir uss original vector ka  sorted version ka vector lo.....ab origial vector m shuru se traverse kro and har index pe dekho ki iss position pe jo element hona chahie acc to sorted vector ...vhi hai  hai toh aage bhado and nhi h toh swap it with the element jo iss position pe hona chahie ....swap count bhadao ....and aage bhado...ese krte jao shuru se end tak traverse krte hue.....ese sabhi levels k  liye krlo and total swap count nikal lo
// use level order traversal to process each level 

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
 int findswaps(vector<int>& original) {
        int swaps = 0;
        vector<int> target = original;
        sort(target.begin(), target.end());

        // Map to track current positions of values in original vector
        unordered_map<int, int> pos;
        for (int i = 0; i < original.size(); i++) {
            pos[original[i]] = i;
        }

      // traverse
        for (int i = 0; i < original.size(); i++) {
            if (original[i] != target[i]) { // iss index pe jo element hona chahie voh nhi h
                int Pos = pos[target[i]]; // jo element hona chahie uski current position in original vector is this
                swap(original[i], original[Pos]); // swap krdo 
                swaps++;
                // position update krdo
                pos[original[Pos]] = Pos;
                pos[original[i]]=i; 
                
            }
        }
        return swaps;
    }
 
    int leveltraversal(TreeNode* root){
        int ansswaps=0;
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
                ansswaps+=findswaps(v);
                v.clear();
               if(!q.empty()) q.push(NULL);
                
            }
        }
    return ansswaps;
    }


    int minimumOperations(TreeNode* root) {
        int ans=leveltraversal(root);
        return ans;
    }
};