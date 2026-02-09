//lc 216

//take/nottake

//tarika 1
// vector banake {1,2,3,4,5,6,7,8,9}
class Solution {
public:

    void solve(int n,int k,int index,int cnt,  vector<int>&nums,vector<int>temp,vector<vector<int>>&ans){
        if(n<0||cnt>k) return;
        if(n==0) {
            if(cnt==k)
            ans.push_back(temp);
            return;
        }
        if(index==nums.size()) return;

        //take
        temp.push_back(nums[index]);
        solve(n-nums[index],k,index+1,cnt+1,nums,temp,ans);
        temp.pop_back();
        //not take
        solve(n,k,index+1,cnt,nums,temp,ans);

        return;


    }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums={1,2,3,4,5,6,7,8,9};
        vector<int>temp;
        vector<vector<int>>ans;
        int index=0;
        int cnt=0;
        solve(n,k,index,cnt,nums,temp,ans);
        return ans;
        
    }
};


// tarika 2
// no vector , ek variable mein hi handle krna

class Solution {
public:

    void solve(int n,int k,int nums ,int cnt,vector<int>temp,vector<vector<int>>&ans){
        if(n<0||cnt>k) return;
        if(n==0) {
            if(cnt==k)
            ans.push_back(temp);
            return;
        }
        if(nums>9) return;

        //take
        temp.push_back(nums);
        solve(n-nums,k,nums+1,cnt+1,temp,ans);
        temp.pop_back();
        //not take
        solve(n,k,nums+1,cnt,temp,ans);

        return;

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        int nums=1;
        vector<int>temp;
        vector<vector<int>>ans;
        int cnt=0;
        solve(n,k,nums,cnt,temp,ans);
        return ans;
        
    }
};