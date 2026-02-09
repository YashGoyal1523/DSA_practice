//lc 347


//m1
//vector mein frequency daalke sort
//O(n log n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>fre;
        for(int i=0;i<nums.size();i++){
            fre[nums[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto x:fre){
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());

        vector<int>ans;
        int idx=v.size()-1;
        for(int i=1;i<=k;i++){
            ans.push_back(v[idx].second);
            idx--;
        }

        return ans;
    }
};


//m2 priority queue
//O(n log k)
class Solution {
public:
    typedef pair<int, int> p;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //min-heap
        priority_queue<p, vector<p>, greater<p>> pq;
        
        //count frequency of each element
        unordered_map<int, int> mp;
        for(int i : nums)
            mp[i]++;
        
        //Push in min-heap and maintain size k
        for(auto it:mp) {
            pq.push({it.second, it.first});
            
            if(pq.size() > k)
                pq.pop();
        }
        
        
        //Pick all elements
        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

//m3 bucket sort


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        for(int &num : nums) {
            mp[num]++;
        }
        
        //index = frequency
        //Value will be elements
        //bucket[i] = elements occuring ith time
        vector<vector<int>> bucket(n+1);
        
        for(auto &it : mp) {
            int element = it.first;
            int freq    = it.second;
            
            bucket[freq].push_back(element);
        }
        
        //Pick k elements from right to left to find k max frequency elements
        vector<int> result;
        for(int i = n; i >= 0; i--) {
            
            if(bucket[i].size() == 0) continue;
            
            while(bucket[i].size() > 0 && k > 0) {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
            
        }
        
        return result;
    }
};