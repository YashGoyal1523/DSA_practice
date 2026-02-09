// lc 2563

//approach
// x= no of pairs with sum < lower
// y = no of pairs with sum <=upper
// ans= y-x

// m1 two pointer..khud
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long x=0;
        long long y=0;

// < lower
      int i=0;
    int j=nums.size()-1;


        while(i<j){
            if(nums[i]+nums[j]<lower){
                x+=(j-i);
                i++;
            }
            else{
                j--;
            }

        }
// <=upper
        i=0;
        j=nums.size()-1;

           while(i<j){
            if(nums[i]+nums[j]<=upper){
                y+=(j-i);
                i++;
            }
            else{
                j--;
            }

        }

return y-x;
    }
};

// m2 binary search // https://youtu.be/r3EnymXRC9A?si=8b40BhGoRSJzoE8u


// class Solution {
// public:
// long long countFairPairs(vector<int>& nums, int lower, int upper) {
// int n =nums.size();
// sort(begin(nums), end (nums));
// long long result = 0;
// for(int i=0; i < n; i++) {
// int idx = lower_bound(begin(nums) + i + 1, end(nums), lower-nums[i]) -begin(nums); // note: yeh func iterator return krta toh idx ke liye - nums.begin() krlia //Gives the first element idx not less than ie equal or greater than (lower -nums[i]) // yeh chiz linear search ya binary search se kr skte...linear mein tc zyada hojayegi
// int x = idx-1-i;
// idx= upper_bound(begin(nums)+i+1, end(nums), upper-nums[i])-begin(nums);// note: yeh func iterator return krta toh idx ke liye - nums.begin() krlia //Gives the first  element idx greater than (upper -nums[i])  // yeh chiz linear search ya binary search se kr skte...linear mein tc zyada hojayegi
// int y=idx-1-i;
// result += (y-x);
// }
// return result;
// }
// };