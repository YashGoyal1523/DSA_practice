// lc 2873 ,2874



// bruteforce 
// o(n3)
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long ans=0;
            int n=nums.size();
            for(int i=0;i<n-2;i++){
                for(int j=i+1;j<n-1;j++){
                    for(int k=j+1;k<n;k++){
                        long long value=(nums[i]-nums[j])*(long long)nums[k];
                        ans=max(ans,value);
                    }
                }
            }
            return ans;
        }
    };



// optimised
//https://youtu.be/UQZEiyIl4ZA?si=tfdlA1OlSZM5IvNl
// prefix suffix 
// o(n)
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            vector<int> leftMax(n);
            vector<int> rightMax(n);
    
            for (int i = 1; i < n; i++) {
                leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
            }
            for(int i = n-2; i >= 0; i--) {
                rightMax[i] = max(rightMax[i+1], nums[i+1]);
            }
    
            long long result = 0;
            for (int j = 1; j < n - 1; j++) {
                result = max(result, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
            }
            return result;
        }
    };
    