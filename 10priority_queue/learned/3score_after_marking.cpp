//lc 2593

class Solution {
public:
    long long findScore(vector<int>& nums) {
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       unordered_map<int,bool>m;
       for(int i=0;i<nums.size();i++){
        pq.push({nums[i],i});
       }
       long long score=0;
       while(!pq.empty()){
        auto top=pq.top();
        int value=top.first;
        int index=top.second;
        pq.pop();
        if(m[index]==false){
            m[index]=true;
            m[index-1]=true;
            m[index+1]=true;
            score+=top.first;
        }
       }
       return score;
    }
};