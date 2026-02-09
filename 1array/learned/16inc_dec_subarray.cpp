// lc 3105

// bruteforce //n^2

// har element ko starting leke  usse longest possible banake dekhna

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLength = 0;

        // Find longest strictly increasing subarray
        for (int start = 0; start < nums.size(); start++) {
            int currLength = 1;
            for (int pos = start + 1; pos < nums.size(); pos++) {
                // Extend subarray if next element is larger
                if (nums[pos] > nums[pos - 1]) {
                    currLength++;
                } else {
                    // Break if sequence is not increasing anymore
                    break;
                }
            }
            maxLength = max(maxLength, currLength);
        }

        // Find longest strictly decreasing subarray
        for (int start = 0; start < nums.size(); start++) {
            int currLength = 1;
            for (int pos = start + 1; pos < nums.size(); pos++) {
                // Extend subarray if next element is smaller
                if (nums[pos] < nums[pos - 1]) {
                    currLength++;
                } else {
                    // Break if sequence is not decreasing anymore
                    break;
                }
            }
            maxLength = max(maxLength, currLength);
        }

        return maxLength;  // Return the longer of increasing or decreasing
                           // sequences
    }
};


// optimal // n

// uper wale m thodi optimisation
// jis element pe sequence break hora ...uss element se hi restart krnaa

// way 1.1
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        //increasing
        int size=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]) {
                size++;
                ans=max(ans,size);
            }
            else{
                size=1; 
            }
        }
         //decreasing
        size=1;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) {
                size++;
                ans=max(ans,size);
            }
            else{
                size=1; 
            }
        }

        return ans;

    }
};
// way1.2

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        //increasing
        int size=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]) {
                size++;    
            }
            else{
                 ans=max(ans,size);
                size=1; 
            }
        }
        ans=max(ans,size);
         //decreasing
        size=1;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) {
                size++;
                
            }
            else{
                ans=max(ans,size);
                size=1; 
            }
        }
        ans=max(ans,size);

        return ans;

    }
};



// way 2

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int incsize=1;
        int decsize=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]) {
                incsize++;
                decsize=1;
                ans=max(ans,incsize);
            }
            else if(nums[i]<nums[i-1]){
                decsize++;
                incsize=1;
                ans=max(ans,decsize);
            }
            else{
                incsize=1; 
                decsize=1;
            }
        }
        

        return ans;

    }
};