//lc 2099

class Solution {
public:

    static bool comp(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end(),greater<pair<int,int>>()); // sort in decending by value
        sort(temp.begin(),temp.begin()+k,comp); // sort first k in ascending by index value
        vector<int>ans;
        for(int i=0;i<k;i++){ 
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};