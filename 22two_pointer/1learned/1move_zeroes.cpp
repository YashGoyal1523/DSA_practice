//lc 283

// two pointer


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int j=0;//index storing non zero element
      for(int i=0;i<nums.size();i++){ // i pointer for traversing array
        if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
      }
    }
};