// lc 3375

// if any element is < k -> -1
// ans= no of distinct elements > k

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int cnt=0;
            vector<int>vis(101);
            for(int i=0;i<nums.size();i++){
                if(nums[i]>k&&!vis[nums[i]]) {
                    cnt++;
                    vis[nums[i]]=1;
                }
                if(nums[i]<k) return -1;
            }
            return cnt;
        }
    };