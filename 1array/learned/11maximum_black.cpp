// lc 670

// bruteforce - 
// 2 for loop se starting se digit ke liye check krte jao ki usse bada uske right m koi h kya ...jis element ke liye mil jaye vaha swap and ruk jao...last tak dekhlo
// o(n^2) tle

// optimised
// precompute maxelement ahead

// https://youtu.be/6tsqLTvLAf8?si=RPZqqo-UveNjHnnN

// class Solution {
// public:
//     int maximumSwap(int num) {

//         // num ko string banalete
//         string nums=to_string(num);

//         int n=nums.size();
//         vector<int>maxidx(n,-1);//will store index of max element ahead
//         // last element ke liye max ahead vhi hoga toh usi ka index store kro
//         maxidx[n-1]=n-1;
//         // for baaki
//         for(int i=n-2;i>=0;i--){
//             if(nums[i]>nums[maxidx[i+1]]){
//                 maxidx[i]=i;
//             }
//             else{
//                 maxidx[i]=maxidx[i+1];
//             }
//         }

//         // array is ready ab starting se dekhte
       
//         for(int i=0;i<n-1;i++){
//             if(nums[maxidx[i]]>nums[i]){
//                 swap(nums[i],nums[maxidx[i]]);
//                 break;

//             }
//         }
//         int ans=stoi(nums);
//         return ans;
//     }
// };