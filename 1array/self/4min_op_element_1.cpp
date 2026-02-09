//lc 3191

// shuru se ek ek krke traverse kro ... 0 mile toh usse 3 element flip krdo

class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n=nums.size();
            int cnt=0;
            for(int i=0;i<=nums.size()-3;i++){
                if(nums[i]==0){
                    // flip the bits

                    nums[i]=1;

                   // nums[i+1]=nums[i+1]==0?1:0;
                   nums[i+1]=nums[i+1]^1;

                    // nums[i+2]=nums[i+2]==0?1:0;
                     nums[i+2]=nums[i+2]^1;

                    cnt++;
                }
            }
    
            if (nums[n-1]==1&&nums[n-2]==1) return cnt;
            return -1;
        }
    };