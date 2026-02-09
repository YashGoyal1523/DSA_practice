//lc 1200

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>v;
        sort(begin(arr),end(arr));
        int mini=1e9;
        for(int i=1;i<arr.size();i++){
            int diff=arr[i]-arr[i-1];
            if(diff==mini) v.push_back({arr[i-1],arr[i]});
            if(diff<mini){
                v.clear();
                v.push_back({arr[i-1],arr[i]});
                mini=diff;
            }
        }
        return v;
    }
};