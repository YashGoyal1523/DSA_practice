//lc 692

class Solution {
public:
    static bool custcomp(pair<int, string>& a, const pair<int, string>& b){
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        vector<pair<int,string>>v;
        for(auto x:mp){
            v.push_back({x.second,x.first});
        }

        sort(v.begin(),v.end(),custcomp);

        vector<string>ans;
        int i=0;
        while(i<k){
            ans.push_back(v[i].second);
            i++;
        }
        
        return ans;
    }
};