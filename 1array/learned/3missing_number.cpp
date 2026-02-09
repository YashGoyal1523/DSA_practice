// lc 268

// range : [0,n] : n+1 numbers from 0 to n
// nums.size()=n 
// nums mein n elements present hai with the elements from range [0,n]  such that each number from range is present in nums except one ......yaani nums mein range ka sab ek ek baar present h except one which is not present

// eg:  size 2 : range [0,2] : nums can be [1,2]->missing 0 , [0,1]-> missing 2 , [0,2] ->missing 1


// m1 : har element ka linear search krdo : range se ek ek element uthao and uski searching krdo o(n^2)

// m2 : sort_1  : sort krdo fir starting se chaalu hojao and index value and uss index par element value check krte jao ....if index value is equal to element uss index par toh aage bhado and agar nhi h fir voh index is the ans...agar last tak ans nhi mile fir n is the ans

// class Solution {
// public:
// int missingNumber(vector<int>& nums) {
//     int n=nums.size();
// sort(nums.begin(),nums.end());
// for(int i=0;i<nums.size();i++){
//     if(i!=nums[i]) return i;
// }
// return n;
// }
// };                       tc  o(nlogn)  (sort se)   sc o(n) (sort se)

// m3 : sort_2 : krdo fir phle first element check kro if zero hi h toh ans 0 vrna agar zero h fir aage secoond  se dekhna chaalu krdo  last tak...agar ek curr element ka uske piche element se diff 1 nhi h toh curr element-1 is the ans ... last tak ans nhi mila fir ans is n    
// class Solution {
// public:
// int missingNumber(vector<int>& nums) {
//     int n=nums.size();
// sort(nums.begin(),nums.end());
// if(nums[0]!=0) return 0;
// for(int i=1;i<n;i++){
//     if(nums[i]-nums[i-1]!=1){
//         return nums[i]-1;
//     }
// }
// return n;
// }
// };                 o(nlogn) (sort se)



// m4: sum 
// class Solution {
// public:
// int missingNumber(vector<int>& nums) {
// int sum = 0;
// int n = nums.size();
// for(int index=0; index<n; index++) {
// sum = sum + nums[index];
// }
// int totalSum = ((n)*(n+1))/2;
// int ans = totalSum-sum;
// return ans;
// }
// };                  tc o(n)  sc o(1)

//m5 :  
// jo jo elements present h unko present mark krlo   ..jo rhgya voh ans
// will use hasharray to maintain mark
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//          int n=nums.size();
//         int arr[n+1];
//         for(int i=0;i<=n;i++){
//             arr[i]=0;            // sabko not present mark krlia ek baar        //    yeh bhi krskte the   vector<int>arr(n+1,0);  no jhanjhat
//         }  
//         for(int i=0;i<n;i++){      // ab present mark krte rhte h
//             arr[nums[i]]=1;
//         }
//        int ans; 
//         for(int i=0;i<=n;i++){
//             if(arr[i]!=1){
//                 ans=i;
//                 break;
//             }
//         }
//         return ans;
//     }
// };


// m6 : xor :  (xor of same is 0, xor of anything with 0 is anything) 
//  saare given elements lo and saare range ke  elements lo and ..... (unme unique elemnt nikaldo) ..... unka xor krdo.......twice present kat jyege and jo single present h voh nikal ke aajayega and vhi ans h hamara  

// iske liye sabko ek alag array m daalke fir inka xor krke kar skte par sc o(1) m krne k liye hum krege ki  saare given elements ka xor lelege and saare range walo ka xor lelege  fir unn dono ke reult ka  xor lelege


// class Solution {
// public:
// int missingNumber(vector<int>& nums) {
//   int ans = 0;
// // 1. xor all values of array
// for(int i=0;i<nums.size();++i){
// ans ^=nums[i];
// }
// //2. xor all range items [0, N]
// int n = nums.size();
// for(int i=0;i<=n;i++){
// ans ^=i;
// }
// return ans;
// }
// };     tc o(n) sc o(1)
