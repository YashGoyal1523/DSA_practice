// lc 3514
class Solution {
    public:
        
        int uniqueXorTriplets(vector<int>& nums) {
            if(nums.size()==1) return 1;
            unordered_set<int>st;
            // compute xor between every  pair (i,j) and store them
            for(int i=0;i<nums.size()-1;i++){
                for(int j=i+1;j<nums.size();j++){
                      st.insert(nums[i]^nums[j]);
                }
            }
            // compute xor between third and the pairs stored (k)^(i,j)
            unordered_set<int>st2;
            for(auto ele:st){
                for(int i=0;i<nums.size();i++){
                       st2.insert(ele^nums[i]);
                }
            }
            
            return st2.size();
        }
    };