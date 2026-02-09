//lc 2200

//m1 map
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        unordered_map<int,int>vis;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                int left=max(0,i-k);
                int right=min(n-1,i+k);
                for(int idx=left;idx<=right;idx++){
                    if(!vis[idx]){
                        ans.push_back(idx);
                        vis[idx]=1;
                    }
                }
            }
        }
        return ans;
    }
};

//m2 
//sc o(1)

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int i = 0;  // available starting pos for selecting index
        int n = nums.size();
        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                int left = max(i, j - k);
               int right = min(n - 1, j + k);
                for (int idx = left; idx <=right; ++idx) {
                    res.push_back(idx);
                }
                i=right+1;
            }
        }
        return res;
    }
};