//lc 1717 : max score from removing substrings 

// approach: shuru se traverse krte jao and 'ba' milta jaaye ya 'ab' milta jaaye ...remove krte jao and points calculate krte jao
// it is WRONG as it will not give max score in cases when x!=y ie bada chote hai .....chaljayega for x=y

// class Solution {
// public:
//     int maximumGain(string s, int x, int y) {
//         stack<char>st;
//         int i=0;
//         int ans=0;
//         while(i<s.size()){
            
//                 if(!st.empty()&&st.top()=='a'&&s[i]=='b'){
//                     ans=ans+x;
//                     st.pop();
//                     i++;
//                 }
//                 else if(!st.empty()&&st.top()=='b'&&s[i]=='a'){
//                     ans=ans+y;
//                     st.pop();
//                     i++;
//                 }
            
//             else {
//                 st.push(s[i]);
//                 i++;
//             }
//         }
//         return ans;
//     }
// };


// correct aproach- shuru se start hoke phle saare jisme zyada points milre usko hatao fir dobara shuru se start hoke kam points walo ko hatao , agar same points hai toh kisi ko uthalo phle fir baad m dusre ko........ yeh sab cases m shi ans dega.... x,y kuch ho

// eg baba (x>y) :  acc to phla we will get y+y(ba mila hatado  ,y points, fir dobara ba mila fir y toh y+y) and acc to dusra we will get x+y (phle bich wala ab hatayege ,x milgya, fir bachgya ba ab usse hatayege jisse mila y so x+y)....so dusre se shi milra


// class Solution {
// public:
//     int maximumGain(string s, int x, int y) {
       
//       char first,second; 
      
//     if(x>=y){
//         first='a';
//          second='b';
//     }
//     else{
//          first='b';
//          second='a';
//     }
//           int ans=0;
//         stack<char>st;
//         int i=0;
//         // first pass
//         while(i<s.size()){
//                 if(!st.empty()&&st.top()==first&&s[i]==second){
//                     ans=ans+max(x,y);
//                     st.pop();
//                     i++;
//                 }
//             else {
//                 st.push(s[i]);
//                 i++;
//             }
//         }

//         // remaining string  for second pass
//         string t;
//         while(!st.empty()){
//             t.push_back(st.top());
//             st.pop();
//         }
//         reverse(t.begin(),t.end());

//         // second pass
//         i=0;
//         while(i<t.size()){
//                 if(!st.empty()&&st.top()==second&&t[i]==first){
//                     ans=ans+min(x,y);
//                     st.pop();
//                     i++;
//                 }
//             else {
//                 st.push(t[i]);
//                 i++;
//             }
//         }
    

//     return ans;
//     }
// };


// https://youtu.be/WTAjAcjSTqM?si=vjsffMt9jKPQrEbY : for other method for this approach : 1.using stack 2. two pointer
// Using 2. (two pointer wala), you can solve this problem as well - https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/
