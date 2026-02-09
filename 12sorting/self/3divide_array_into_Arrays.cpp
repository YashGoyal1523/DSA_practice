//lc 2966

//Sort the array and try to group each 3 consecutive elements.
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;       
        sort(begin(nums),end(nums));
        int i=0;
        while(i<nums.size()){
           if(nums[i+1]-nums[i]<=k && nums[i+2]-nums[i]<=k) ans.push_back({nums[i],nums[i+1],nums[i+2]});
           else break;
           i+=3;
        }

        if(i==nums.size()) return ans;

        return {};

    }
};