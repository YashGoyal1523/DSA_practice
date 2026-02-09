//lc 1863


// recursively traverse all subsequences

class Solution {
    public:
    
        void rec(vector<int>& nums,int xorr,int &sum,int index){
            if(index==nums.size()){
                sum+=xorr;
                return;
            }
    
            //include
                rec(nums,xorr^nums[index],sum,index+1);
    
            //exclude
                rec(nums,xorr,sum,index+1);
    
                return;
    
        }
    
        int subsetXORSum(vector<int>& nums) {
            int sum=0;
            int xorr=0;
            int index=0;
            rec(nums,xorr,sum,index);
            return sum;
    
        }
    };


   
