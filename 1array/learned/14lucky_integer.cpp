//lc 1394
//m1
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        int max = INT_MIN;
        for (int i = 0 ; i <arr.size() ; i++){
            freq[arr[i]]++;
        }
    for (auto num : freq){

         if(num.first == num.second)
         {
            if(num.second > max)
            {
                max = num.second;
            }
         }
    }
    if(max>0){
        return max;
    }
    return -1;
    }
};
//m2
class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>v(501);
        for(int i=0;i<arr.size();i++){
            v[arr[i]]++;
        }
        for(int i=500;i>0;i--){
            if(i==v[i]) return i;
        }

        return -1;
    }
};