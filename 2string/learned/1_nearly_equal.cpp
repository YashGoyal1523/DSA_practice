// // Nearly Equal 
// // The Hamming distance between two pairs of strings of equal length is defined to be the number of positions at which they contain different characters. For example, the Hamming distance between strings  "there" and  "shire"  is  2  (their first and third characters are different), while the Hamming distance between  "order" and   "chaos" is  5 , since they differ at every position.  Chef has a string  A of length   N. Chef's favorite string is   B, which has length  M. It is known that  𝑀 ≤ 𝑁 M≤N.  Find the minimum Hamming distance between B and some contiguous substring  of   A that has length  M.  
// //  Input Format
// //   The first line of input will contain a single integer T, denoting the number of test cases. 
// //   Each test case consists of three lines of input. 
// //   The first line of each test case contains two space-separated integers  N and   M  the lengths of strings   A and   B, respectively. The second line contains the string  A, consisting of  N lowercase English letters. The third line contains the string   B, consisting of   M lowercase English letters. Output Format For each test case, output on a new line the minimum possible Hamming distance between   B and some length   M substring of  A.  Constraints 1 ≤ 𝑇 ≤ 100 1≤T≤100 1 ≤ 𝑀 ≤ 𝑁 ≤ 100 1≤M≤N≤100. A and  B contain only lowercase English letters, i.e, the characters 'a' through 'z'.




// //  har ek window of A ko B se check kro and min uthaalo


//     #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;
    
//     while (t--) {
//         int N, M;
//         cin >> N >> M;
//         string A, B;
//         cin >> A >> B;
        
//         int ans = INT_MAX;
        
//         for (int i = 0; i <= N - M; ++i) {  // for different windows in A ... there are N-M+1 windows ...0 se shuru krlia as isko use krege  as starting index of each window 
//             int count = 0;
 //           int x=i;
//             for (int j = 0; j < M; ++j) {   // for traversing in  window of A and traversing in B
//                 if (A[x] != B[j]) {
//                     count++;
//                 }
 //             x++;
//             }
//             ans = min(ans, count);
//         }
        
//         cout << ans << endl;
//     }
    
//     return 0;
// }


// // note yeh logic  ko likhne ka alag tarika

        
// //         for (int i = 0; i <= N - M; ++i) {  // for windows
// //             int count = 0;
// //             for (int j = 0; j < M; ++j) {   // for traversing in  window of A and traversing in B
// //                 if (A[i+j] != B[j]) {
// //                     count++;
// //                 }
// //             }
// //             ans = min(ans, count);
// //         }

// // yeh bhi same kaam krega