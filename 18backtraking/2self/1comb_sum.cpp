//lc 39

//take/ nottake

class Solution {
public:

    void solve(int index,vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0||index==candidates.size()){
            return;
        }
        //take
        temp.push_back(candidates[index]);
        solve(index,candidates,target-candidates[index],ans,temp);
        temp.pop_back();
        //not take
        solve(index+1,candidates,target,ans,temp);
       
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int index=0;
        solve(index,candidates,target,ans,temp);

        return ans;

    }
};