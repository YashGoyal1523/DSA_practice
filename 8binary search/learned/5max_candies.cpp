//lc 2226


// possible no of candies per child : [1,max of array]
// -> search space is [1,max of array]

// m1 
// linearly search space m piche se dekhna shuru kro ...phle valid (this no of candies can be allocated to k children) milta hi ans milgya

// m2 
// search space m binary search se maximum valid value dhundlo (binary search on answer)

// note
// valid function - for a candies per child value , check if we can allocate the candies to k no of students with candies per child equal to that value  , if yes then its valid  

class Solution {
    public:
    
    // bool children( int mid,vector<int> candies,long long k){
    //     long long cnt=0;
    //     int i=0;
    //     while(i<candies.size()){
    //         if(candies[i]>=mid){
    //             candies[i]-=mid;
    //             cnt++;
    //             if(cnt==k) return true;
    //         }
    //         else i++;
    //     }
    //     return false;

    // }    // yeh acha method nhi h ..it is likely to give tle

    // use division instead
        bool children(int mid, const vector<int>& candies,long long k) {
            long long cnt = 0;
            for (int candy : candies) {
                cnt += candy / mid;  // Compute how many full portions can be made
            }
            return cnt>=k;
        }
    

        int maximumCandies(vector<int>& candies, long long k) {
            int l = 1;
            int h = *max_element(candies.begin(), candies.end());  
            int ans = 0;
            
            while (l <= h) {
                int mid = l + (h - l) / 2;
                if (children(mid, candies,k) ) {  
                    ans = mid;  // Store the valid mid
                    l = mid + 1;  // Try to maximize the candy portion size
                } else {
                    h = mid - 1;
                }
            }
            return ans;
        }
    };
    