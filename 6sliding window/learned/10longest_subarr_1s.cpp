//lc 1493

//ek zero krege remove
//par sab one hai and ek bhi zero nhi toh ek one remove hojayega

//m1
// zeros ka indexes store krke 
// har zero k liye ans nikalke sabka max lelo
//-> current zero ke liye uske left aur right zero ke beech mein no of elements - 1(for remove curr zero) krlo

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>idx;
        for(int i=0;i<n;i++){
            if(nums[i]==0) idx.push_back(i);
        }

        int s=idx.size();

        if(s==0||s==1) return n-1; //sab 1 hai ya ek hi zero hai

        int ans=0;
        for(int i=0;i<s;i++){
            int next0=i+1<s?idx[i+1]:n;
            int prev0=i-1>=0?idx[i-1]:-1;
            int count=next0-prev0-2; //curr zero removed
            ans=max(count,ans);
        }
        return ans;
    }
};

//m2 sliding window
// ans = longest subarray length with at most one zero - 1(for remove)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int n=nums.size();
       int cnt0=0;
       int i=0;
       int j=0;
       int ans=0;
       while(j<n){
        if(nums[j]==0) cnt0++;
        while(cnt0>1){
            if(nums[i]==0) cnt0--;
            i++;
        }
        int length=j-i;//ek element removed
        ans=max(ans,length);
        j++;
       }

       return ans;
    }
};