//lc 3356

// o(n) mein krna h
// range updation required 
// ->difference array technique



class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
       int n=nums.size();
       vector<int>diff(n,0);

       for(int i = 0; i <= queries.size()-1; i++) {
                    int l = queries[i][0];
                    int r   = queries[i][1];
                    int x   = 1;
        
                    diff[l] += x;
                    if(r+1 < n)
                        diff[r+1] -= x;
                }
        
                int cumSum = 0;
               
                for(int i = 0; i < n; i++) {
                    cumSum += diff[i];
        
                    diff[i] = cumSum;
        
                    if(nums[i] - diff[i] > 0) { //nums[i] 0 nahi ban paya
                        return false;
                    }
                }
        
                return true;
        
    }
};