//lc 1498

//Approach-1 (Produce all subsequences, find min and max and check)
//This will give TLE

//Approach-2 Binary search (khud)
// O(nlog n)
class Solution {
public:

    int MOD=1000000007;

//fast exponetiation
    int pow_2(long long a,int b){
     int ans=1;
    while(b>0){
        if(b&1){ 
            ans=(ans*a)%MOD;
        }
        a=(a*a)%MOD;
        b=b>>1; 
    }
    return ans;
}    

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int mini=nums[i];
             if(mini>target/2) break;
            int maxi=target-mini;
            // Find rightmost index where nums[j] <= maxi
            int index=upper_bound(nums.begin()+i,nums.end(),maxi)-nums.begin()-1;
            //min ko toh lena hi h ...aage wale har ke liye 2 option take ya no take // so
            cnt=(cnt+pow_2(2,index-i))%MOD;
        }
        return cnt;
    }
};

//note: yeh 2^ wala nikalne ke liye precompute krke bhi kr skte

class Solution {
public:

    int MOD=1000000007;

    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        //precompute
        vector<int> pow_2(n);
        pow_2[0] = 1;
         for(int i = 1; i<n; i++) {
            pow_2[i] = (pow_2[i-1] * 2) % MOD;
        }   
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int mini=nums[i];
             if(mini>target/2) break;
            int maxi=target-mini;
            // Find rightmost index where nums[j] <= maxi
            int index=upper_bound(nums.begin()+i,nums.end(),maxi)-nums.begin()-1;
            //min ko toh lena hi h ...aage wale har ke liye 2 option take ya no take // so
            cnt=(cnt+pow_2[index-i])%MOD;
        }
        return cnt;
    }
};

//appraoch-3 two pointer
// https://youtu.be/eGqs55VTP3I?si=duUxtkqYqsu2_d0l
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        
        //1. Sort
        sort(begin(nums), end(nums));
        
        vector<int> power(n);
        power[0] = 1;
        
        for(int i = 1; i<n; i++) {
            power[i] = (power[i-1] * 2) % M;
        }   
        
        //2. l = 0, r = n-1
        int l = 0, r = n-1;
        int result = 0;
        while(l <= r) {
            
            if(nums[l] + nums[r] <= target) {
                int diff = r-l;
                // l wala toh lena hi h .... aage walo ke liye har k liye 2 option take ya no take
                result = (result + power[diff]) % M;
                l++;
            } else {
                r--;
            }
            
        }
        
        return result;
    }
};


//pow() function se nhi hoga..constraints allow nhi krre

