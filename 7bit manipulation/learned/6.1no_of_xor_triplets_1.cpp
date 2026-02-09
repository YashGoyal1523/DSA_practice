// lc 3513

class Solution {
    public:
        int noOfBits(int y) {
            int x = (log2(y)) + 1;
            return x; 
        }
    
        int uniqueXorTriplets(vector<int>& nums) {
            int n = nums.size();
    
            if(n==1) {
                return 1 ;
            }
            
            if (n == 2) {
                return 2;
            }
    
            int bits=noOfBits(n);
            
            return 1<<bits ;  //pow(2,bits)
        }
    };