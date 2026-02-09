// codechef contest

//https://www.codechef.com/problems/P4_172

// Transform String
// Chef gives you 2 strings 
// A
// A and 
// B
// B. You can perform the following operation on 
// A
// A as many times as you want.

// Remove character 
// A
// i
// A 
// i
// ​
//   from the string 
// A
// A. This has a cost of 
// i
// i which is the index of the element that you are removing.
// Note that cost is always equal to the index in current string and not the original string. Refer to the sample test case for example.

// You have to print the minimum cost of transforming 
// A
// A to 
// B
// B using the above operation. If it is not possible to transform string 
// A
// A to 
// B
// B, print 
// −
// 1
// −1.

// Input Format
// The first line of input will contain a single integer 
// T
// T, denoting the number of test cases.
// Each test case consists of 2 lines of input.
// The first line of each test case contains string 
// A
// A.
// The next line contains string 
// B
// B.
// Output Format
// For each test case, output on a new line the minimum cost of transforming string 
// A
// A to 
// B
// B. If it is not possible to transform string 
// A
// A to string 
// B
// B using above operation, print 
// −
// 1
// −1.



//https://youtu.be/ZEvnwCcAwZE?si=7IftwzuCU4_WwJO8

#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

   unordered_map<int,bool>mp;
   int i=n-1;
   int j=m-1;
   while(i>=0&&j>=0){
       if(a[i]==b[j]) {
           mp[i]=true;
           i--;
           j--;
   }
   else{
       i--;
   }
   }
   
   if(j>=0) {
       cout<<-1<<endl;
       return;
   }
   
   long long ans=0;
   long long cost=1;
   for(int i=0;i<n;i++){
       if(mp[i]!=true){
           ans+=cost;
       }
       else{
           cost++;
       }
   }
   cout<<ans<<endl;
   return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
