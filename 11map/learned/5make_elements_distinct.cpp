
//lc 3396

//m1
class Solution {
    public:
    
    bool check(vector<int>&freq){
        return *max_element(freq.begin(),freq.end())==1;
    }
    
        int minimumOperations(vector<int>& nums) {
            int n=nums.size();
            vector<int>freq(101);
            for(int i=0;i<n;i++){
                freq[nums[i]]++;
            }
            int cnt=0;
            int i=0;
            while(i<n&&!check(freq)){  // jabtak sabki freq 1 na hojaye
                cnt++;
                freq[nums[i]]--;
                if(i+1<n) freq[nums[i+1]]--;
                if(i+2<n) freq[nums[i+2]]--;
                i=i+3;
            }
            return cnt;
        }
    };


    // m2

   // If the repeated element x appears at indices i and j with i<j, then all elements before index i must be removed. This reduces the problem to finding the longest suffix of the array in which all elements are distinct. Since each time it is necessary to remove 3 elements, to remove all elements before index i, i.e., nums[0⋯i], at least ⌈i+1/3⌉=⌊i/3⌋+1 removal operations are required.If the array length is n, we traverse it in reverse order, using seen to record the elements that have already appeared. When we reach the first duplicate element nums[i], it indicates that the element already exists in the current suffix. We then return the minimum number of operations: ⌊i/3⌋+1. If there are no duplicate elements in the array, we return 0.

   class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            vector<bool> seen(101);
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (seen[nums[i]]) {
                    return i / 3 + 1;
                }
                seen[nums[i]] = true;
            }
            return 0;
        }
    };