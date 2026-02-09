//lc 525

// Imagine a count variable, which is used to store the relative number of ones and zeros encountered so far while traversing the array. The count variable is incremented by one for every 1 encountered and the same is decremented by one for every 0 encountered.
// We start traversing the array from the beginning. If at any moment, the count becomes zero, it implies that we've encountered an equal number of zeros and ones from the beginning till the current index of the array(i). Not only this, another point to be noted is that if we encounter the same count twice (for any value, not just 0) while traversing the array, it means that the number of zeros and ones are equal between the indices corresponding to the equal count values.

// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
        
//      unordered_map<int,int> mpp; // <number,index>
// mpp[0] = -1;
// int cnt = 0;
// int maxi = 0;
// for(int i = 0; i<nums.size();i++) {
//     if(nums[i]==1) cnt++;
// else cnt--;
// if(mpp.find(cnt)!=mpp.end()) {
//     int previdx=mpp[cnt];
// maxi=max(maxi,i-previdx);
// }
// else mpp[cnt]=i;
// }
// return maxi;
//     }
// };




// note: yhi approach use krke hum count ki jagah sum se bhi kr skte

// https://youtu.be/AcSWGXBu-Xo?si=-QvXiIY5uaV3FZWR

//0 ko treat as -1
// ques becomes -> longest subbarray with sum 0
// lc 560 ques mein yehi aproach used h 


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
     unordered_map<int,int> mpp; // <number,index>
mpp[0] = -1;
int preSum = 0;
int maxi = 0;
for(int i = 0; i<nums.size();i++) {
    if(nums[i]==1) preSum+=1;
else preSum-=1;
if(mpp.find(preSum)!=mpp.end()) {
    int previdx=mpp[preSum];
maxi=max(maxi,i-previdx);
}
else mpp[preSum]=i;
}
return maxi;
    }
};


