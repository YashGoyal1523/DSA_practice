//lc 594

//m1 khud
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int cnt=1;
            int mini=nums[i];
            int flag=0;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]==mini) cnt++;
                if(nums[j]-mini==1) {
                    cnt++;
                    flag=1;
                }
                else if(flag){
                    ans=max(cnt,ans);
                    break;
                }
            }
           if(flag) ans=max(cnt,ans);
        }
        
        return ans;
    }
};

//m2 
// https://youtu.be/M-MMjMe0P0U?si=jMfPr0SipS9obZra

//resultant subsequence mein 2 numbers hi hoge : x , x+1 

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;

        int result = 0; //to store maximum subsequence length

        for(int &num : nums) {
            mp[num]++;
        }

        for(int &num : nums) {
            int minNum = num;
            int maxNum = num+1;

            if(mp.count(maxNum)) {
                result = max(result, mp[minNum] + mp[maxNum]);
            }
        }

        return result;
    }
};


