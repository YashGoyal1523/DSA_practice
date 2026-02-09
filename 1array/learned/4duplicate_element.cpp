// lc 287

// range : [1,n] : numbers from 1 to n
// nums.size=n+1
// nums mein n+1 elements hai and with the elements from the range [1,n]  such that all the numbers in nums appear only once except for precisely one number which appears two or more times.

// eg:  size 4:  range [1,3] : nums can be [1,2,3,3]->duplicate 3 , [1,1,1,2]->duplicate 1 , [2,2,2,2]->duplicate 2  etc....... can be anything from (ek number do baar , baaki ek ek baar ) (ek number teen , baaki ek ek baar ) (ek number  chaar , baaki ek ek baar ) ....... to ( ek hi number sab ho)


// m1 : sort (array modify hojayega)
// sort krdege fir shuru se chaalu hojayege check krna ki agar ek element  and usse next  element same h toh yhi ans h

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int ans=-1;
//         for(int i=0;i<nums.size()-1;i++){
//             if(nums[i]==nums[i+1]){
//                 ans= nums[i];
//                 break;
//             }
//         }
//         return ans;
//     } 
// };             tc o(nlogn) sort se  sc o(logn) sort se

// m2 : counting freq  (extra space legi)
// shuru se traverse krte jao and jo element aata jaaye uska count maintain krte jao in hasharray agar kisi ka count >1 hogya toh ans milgya
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//          int n = nums.size();
//          int ans=0;
//         vector<int>a(n+1,0);
//         for (int i = 0; i < n; i++) {
//             a[nums[i]]++;
//             if (a[nums[i]] > 1) {
//                 ans=nums[i];
//                 break;
//             }
//         }

//         return ans;
//     }
// };

// m3 : visit mark 

// 3.1 hash table m mark (extra space legi)

// shuru se traverse krte jao and elements ko visited mark krte jao ek hasharray mein...agar koi element already visited nikla toh this is ans
// map bhi le skte
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n=nums.size();
//         int ans=-1;
//         int arr[n+1];
//         for(int i=0;i<n+1;i++){// sabko unvisited krlete    //      yeh bhi krskte the   vector<int>arr(n+1,0);  no jhanjhat
//             arr[i]=0;
//         }
//         for(int i=0;i<nums.size();i++){//ab traverse krte hue visited mark krte hue chlte
//             if(arr[nums[i]]==1) {
//                 ans=nums[i];
//                 break;
//         }
//         else arr[nums[i]]=1;
//         }
//         return ans;
//     }
// };

// 3.2 usi array mein visited mark krke krna (array modify)
// to mark we will use ....Negative marking method :
// shuru se start hojayege and currelement ki joh value hai ...uss index par jo present h usko neg krdege.....ese ese agar koi mark krne wala  already neg mila toh  currelement is ans..... currelement mein element ka absolute value lete rhege

// class Solution
// {
// public:
//     int findDuplicate(vector<int> &nums)
//     {
//         int ans = -1;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int index = abs(nums[i]);
//             // already visited?
//             if (nums[index] < 0)
//             {
//                 ans = index;
//                 break;
//             }

//             // visited mark
//             nums[index] *= -1;
//         }
//         return ans;
//     }
// };                         tc o(n) sc o(1)


// m4  positioning method   (array modify hoga)

//4.1 element ko uske value wale index par lagana 
//4.1.1
// shuru se start ho
// If nums[i]==i, it means that it is at correct position, then skip, i++;
// otherwise If nums[i]==nums[nums[i]], it means that there is already a value at the correct index, then this value is a duplicated element;
// If none of the above is satisfied, exchange the values of nums[i] and nums[nums[i]] ( correct position par lagado) and aage bhadho
// krte rho jabtak ans na miljata

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//        int ans=0;
//         for (int i = 0; i < nums.size();i++ ) {
//             int n = nums[i];
//             if (n == i) {
//                 continue;
//             } else if (n ==nums[n] ) {
//                 ans= n;
//                  break;
//             } else {
//                 nums[i] = nums[n];
//                 nums[n] = n;         // swap fn bhi use kr skte
//             }
//         }

//         return ans;
//     }                     // tc o(n)  sc o(1)
// }; 

//4.1.2
// agar sab apni correct positions par hoge toh jo duplicate wala hoga voh zero index par milega
// 0 index pakdo and uspe jo element hai usko swap krte rho uss element ki value wale index par jo element h usse ( elements ko apne value wale index par lagate rhna hai  ).....ese krte rho ...ek time aayega jab dono same hojayege tab rukjaoo. .....same milte hi ans milgya ...element return krdo

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
// while(nums[0]!=nums[nums[0]]){
//     swap(nums[0],nums[nums[0]]);
// }
// return nums[0];
//     }
// };                tc o(n)

// 4.2 : index sort : element ko sorted array m jo uski index hoti uspe lagana ) 
//If the array is sorted, the value of each array element is its index+1 ie sorted m element ka index is its value -1
//steps
//shuru se start ho
// If nums[i]==i+1, it means that it is at correct position, then skip, i++;
// otherwise If nums[i]==nums[nums[i]−1], it means that there is already a value at the correct index, then this value is a duplicated element;
// If none of the above is satisfied, exchange the values of nums[i] and nums[nums[i]−1] (correct position par lagado) and firse isi par check kro
// krte rho jabtak ans na miljata

// tc O(n) sc o(1)

// note krna yeh method use kr paayege only if  size of array(no of indexes)= no of numbers in range

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//        int ans=0;
//        int i=0;
//         while(i < nums.size()) {
//             int n = nums[i];
//             if (n == i + 1) {
//                 i++;
//             } 
//           else if (n == nums[n - 1]) {
//                 ans= n;
//                  break;
//             } else {
//                 nums[i] = nums[n - 1];
//                 nums[n - 1] = n;
//             }
//         }

//         return ans;
//     }
// }; 

 // tc o(n)  sc o(1)

// // note for loop bhi use kr skte

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//        int ans=0;
//         for (int i = 0; i < nums.size(); ) {
//             int n = nums[i];
//             if (n == i + 1) {
//                 i++;
//             } else if (n == nums[n - 1]) {
//                 ans= n;
//                  break;
//             } else {
//                 nums[i] = nums[n - 1];
//                 nums[n - 1] = n;
//             }
//         }

//         return ans;
//     }
// };





// // methods ..jisme array no modify and constant space

// way 1 bruteforce : nested loops  :  o(n^2) TLE DEGA 
// starting se ek ek element uthao uske liye baaki array m check kro dobara present h ya nhi voh ....if yes ...ans milgya....rukao
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {

// int ans=0;
// for (int i = 0; i < nums.size(); i++) {
//             for (int j = i + 1; j < nums.size(); j++) {
//                 if (nums[i] == nums[j]) {
//                     ans= nums[i];
//                 }
//             }
// }
//             return ans;
//         }
// };

// way 2 imagine as linked list then slow fast  tc o(n) sc o(1)
// imagine it as a linked list with .....0 index par jo element h uske value ki phli node fir uss value wale index par jo element h uski value ki dusri node ..fir uss value wale index par jo element and so on......agar next wali value already present h toh already wale se hi connect krdena....note: repeating wala milte hi aage nhi bana paayege chahe bache ho abhi ....par koina ans miljayega itne mein ...hume toh repeating element chahie 
// iss list m cycle present hogi with starting point repeating element
// hume starting node of cycle nikalni h
// we use slow fast method to find

// note actual m linked list banake bhi kar skte (banate rho jabtak voh repeating element ka second wala na miljaye ...vooh milte hi phle resent par hi connect krdo and ruk jao)par usme space lelegi toh bina banaye and imagine krke hi krte
// class Solution {
// public:
// int findDuplicate(vector<int>& nums) {
// int slow = nums[0];
// int fast = nums[0];
// do {
// slow = nums[slow];
// fast = nums [nums[fast]];
// } while(slow != fast);
// slow = nums[0];
// while(slow != fast) {
// slow = nums[slow];
// fast = nums[fast];
// }
// return slow;
// }
// };



//way3 : binary search  

// we will find ans from the number array [1,2,…,n] instead of input array
// We will use the binary search algorithm
// start with low at shuru and high at end
// take the number mid in the range [low,high] from number array , count the elements of the array which is less than or equal to mid in the array.
// If cnt is strictly greater than mid  then repeated element is in the interval [low,mid] (using Pigeonhole Principle ) ( k numbers ne agar k se zyada seats le rkhi hai toh pkka number repeat hua h  ).  repeat narrowing in this
// Otherwise, the repeated element is in the interval [mid+1,high]. repeat narrowing in this


// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
           
//         int low = 1;
//         int high = nums.size() - 1;  // high=n // nums.size()=n+1
//         while (low < high) {
//             int mid = low + (high - low) / 2;
//             int cnt = 0;
//             for (int i = 0; i < nums.size(); i++) {
//                 if (nums[i] <= mid) {
//                     cnt++;
//                 }
//             }

//             if (cnt <= mid) {  // then [mid+1,high] m hai ans
//                 low = mid + 1;
//             } else {           // [low,mid-1] mein hai ans
//                 high = mid;
//             }
//         }

//         return low;    //or   // return high;                    
//     }
// };



// way 4:sum : Yeh method applicable sirf uss case m jisme  repeating wala ek baar hi repeat hora .....yaani nums mein range ke sab ek ek baar present hai and ek do baar
//  nums ke elements ka sum lelo , 1 se n ka sem lelo , nums wale m se yeh wala minus krdo to get ans
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//          int sum1=0;
//          for(int i=0;i<nums.size();i++){
//             sum1=sum1+nums[i];
//          }
//          int sum2=0;
//          for(int i=1;i<=nums.size()-1;i++){
//             sum2=sum2+i;
//          }
//          return sum1-sum2;
//     }
// };