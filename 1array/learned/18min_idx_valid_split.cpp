//lc 2780



    //observe dominant element of nums array hi dominant element of subarrays hoga
// if nums ka dominant nhi toh not possible aayega

//hashmap
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n=nums.size();
            //finding dominant of nums..using hashmap
            unordered_map<int,int>m;
            int maxf=0;
            int maxi=-1;
            for(int i=0;i<nums.size();i++){
                m[nums[i]]++;
                if(m[nums[i]]>maxf){
                    maxi=nums[i];
                    maxf=m[nums[i]];
                }
            }

            if(maxf<=n/2) return -1;  // early return

            int ans=-1;
            int cnt=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==maxi){
                    cnt++;
                }
                    if(cnt>(i+1)/2 && (maxf-cnt)>(n-i-1)/2){
                        ans=i;
                        break;
                    }
                
            }
            return ans;
        }
    };

    // moore voting
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            // Find the majority element using  moore voting algo
            int x = nums[0], count = 0, xCount = 0, n = nums.size();
            for (auto& num : nums) {
                if (num == x) {
                    count++;
                } else {
                    count--;
                }
                if (count == 0) {
                    x = num;
                    count = 1;
                }
            }
    
            // Count frequency of majority element
            for (auto& num : nums) {
                if (num == x) {
                    xCount++;
                }
            }
    
            if(xCount<=n/2) return -1; // early return
          
            count = 0;
            int ans=-1;
            for (int index = 0; index < n; index++) {
                if (nums[index] == x) {
                    count++;
                }
                int remainingCount = xCount - count;
                if (count * 2 > index + 1 && remainingCount * 2 > n - index - 1) {
                    ans= index;
                    break;
                }
            }
            return ans;
        }
    };