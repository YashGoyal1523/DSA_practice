// lc 2560
//https://youtu.be/YrRvP9720vY?si=wd0MVp8c8KUAaHya
//minimise the maximum -> binary search on answer

// search space for capability : [min of array,max of array]

// binary search se search space m minimum valid wala dhundlo

//valid function - for a given capability value , check if we can find k non consecutive elements such that maximum value among them is that value ie k non consecutive elements valued <= that value , if yes then valid   
//note: its given in ques that it is always possible to steal at least k houses -> koi ghar valued <= capablity value mile toh usme take /not take  nhi lagana and take hi krna
class Solution {
    public:
       
        bool check(int mid,vector<int>& nums, int k){
         int cnt=0;
         int i=0;
         while(i<nums.size()){
            if(nums[i]<=mid){
                cnt++;
                i+=2;
                if(cnt==k) return true;
            }
            else i++;
         }
         return false;
        }
        int minCapability(vector<int>& nums, int k) {
            int l=*min_element(nums.begin(),nums.end());
            int h=*max_element(nums.begin(),nums.end());
            int ans;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(check(mid,nums,k)){
                    ans=mid;
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            return ans;
        }
    };