//lc 3356

//bruteforce : query ke liye range m traverse krke update krna 
// shuru se ek ek krke query uthao and update krke check kro ....jaha miljaye voh ans
// tc : q*(n+n) // tle


//Optimal : difference array technique for range update

//Approach-1 - Linear Query Check  
// phle starting ek query ko check
// fir starting do query ko check
// fir starting teen query ko check
// so on
// jaha milgya vhi ans
//T.C : O(Q * (Q + n)) // tle
//S.C : O(n)
class Solution {
    public:
        int n;
        int Q;
    
        bool checkWithDifferenceArrayTeq(vector<int>& nums, vector<vector<int>>& queries, int k) {
            vector<int> diff(n, 0);
    
            //O(Q)
            for(int i = 0; i <= k; i++) {
                int l = queries[i][0];
                int r = queries[i][1];
                int x = queries[i][2];
    
                diff[l] += x;
                if(r+1 < n)
                    diff[r+1] -= x;
            }
    
            int cumSum = 0;
            //O(n)
            for (int i = 0; i < n; i++) {
                cumSum += diff[i];
    
                diff[i] = cumSum;
    
                if(nums[i] - diff[i] > 0) { //nums[i] 0 nahi ban paya
                    return false;
                }
            }
    
            return true;
    
        }
    
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            n = nums.size();
            Q = queries.size();
    
            //if all zero already return 0
        // int flag=1;
        // for(int i=0;i<n;i++){
        //     if(nums[i]!=0){
        //         flag=0;
        //         break;
        //     }
        // }
        // if(flag) return 0;

            auto lambda = [](int x) {
                return x == 0;
            };
    
            if(all_of(begin(nums), end(nums), lambda)) {
                return 0; //no query required because all are already zero
            }
    
            
            for(int i = 0; i < Q; i++) { //O(Q * (Q + n))
                if(checkWithDifferenceArrayTeq(nums, queries, i) == true) {
                    return i+1;
                }
            }
    
            return -1;
        }
    };
    
//Approach-2 -  Binary Search for Query Check
// binary search se no of queries uthana jisko check krna
//T.C : O(log(Q) * (Q + n))
//S.C : O(n)
    class Solution {
        public:
            int n;
            int Q;
        
            bool checkWithDifferenceArrayTeq(vector<int>& nums, vector<vector<int>>& queries, int k) {
                vector<int> diff(n, 0);
        
                //O(Q)
                for(int i = 0; i <= k; i++) {
                    int l = queries[i][0];
                    int r   = queries[i][1];
                    int x     = queries[i][2];
        
                    diff[l] += x;
                    if(r+1 < n)
                        diff[r+1] -= x;
                }
        
                int cumSum = 0;
                //O(n)
                for(int i = 0; i < n; i++) {
                    cumSum += diff[i];
        
                    diff[i] = cumSum;
        
                    if(nums[i] - diff[i] > 0) { //nums[i] 0 nahi ban paya
                        return false;
                    }
                }
        
                return true;
        
            }
        
            int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
                n = nums.size();
                Q = queries.size();
                
                //if all zero already return 0
        // int flag=1;
        // for(int i=0;i<n;i++){
        //     if(nums[i]!=0){
        //         flag=0;
        //         break;
        //     }
        // }
        // if(flag) return 0;
                auto lambda = [](int x) {
                    return x == 0;
                };
        
                if(all_of(begin(nums), end(nums), lambda)) {
                    return 0; //no query required because all are already zero
                }
        
                int l = 0;
                int r = Q-1;
                int ans = -1;
                while(l <= r) {
                    int mid = l + (r-l)/2;
        
                    if(checkWithDifferenceArrayTeq(nums, queries, mid) == true) {
                        ans = mid+1; //possible answer // 1 indexing ke liye +1
                        r = mid-1; // min chahie toh left dekho
                    } else { 
                         l = mid+1;
                    }
                }
        
                return ans;
            }
        };