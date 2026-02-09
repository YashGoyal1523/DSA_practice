//lc 2294

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int cnt=1;
        int prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]-prev>k){
                cnt++;
                prev=nums[i];
            }
        }
        return cnt;
    }
};