//lc 3264

// bruteforce
// pure array m traverse krke min dhund ke modify kro...k baar kro....tc o(n*k)


// min heap
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(k--){
            auto top=pq.top();
            pq.pop();
            int value=top.first*multiplier;
            int index=top.second;
            pq.push({value,index});
        }

        vector<int>ans(n);

        while(!pq.empty()){
            ans[pq.top().second]=pq.top().first;
            pq.pop();
        }
        return ans;
    }
};