//lc 3566 (contest se liya)

//check total product of array 
// if  !=target*target return false
// else check for a subset with product target... if milgya then return true else return false

class Solution {
public:

    bool solve(long long target,int index,long long curr,vector<int>& nums){
        if(curr==target) return true;
        if(curr>target||index==nums.size()) return false;

        bool take=solve(target,index+1,curr*nums[index],nums);
        bool nottake=solve(target,index+1,curr,nums);

        return take||nottake;
    }



    bool checkEqualPartitions(vector<int>& nums, long long target) {

        __int128 total=1;
        for(int i=0;i<nums.size();i++){
            total*=nums[i];
            if(total>(__int128)target*target) return false;   // early return
        } 

         if(total!=(__int128)target*target) return false;

        int index=0;
        long long curr=1;
        bool ans=solve(target,index,curr,nums);

        return ans;
    }
};