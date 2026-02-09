// lc 3306

// bruteforce
// check all substrings

//sliding window
//https://youtu.be/8FP1kkYf2U4?si=TCo6_E2bFE49o5A6

// approach
// invalid window 
//  -all vowel not present OR consonent <k  : j++ (expand)
//  -consonent >k : i++ (shrink) till consanent==k
// valid window 
//  -all vowel present AND consonant==k  : shrink (i++) till valid milri and add (next consanent idx)-j to answer each time

// class Solution {
//     public:
//         bool isVowel(char &ch) {
//             return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
//         }
//         long long countOfSubstrings(string word, int k) {
//             int n = word.length();
    
//             unordered_map<char, int> mp; //to keep count of vowels in a current window
          
//             //Precompute index of just next consonant for each index 
//             vector<int> nextCons(n);
//             int lastConsIdx = n;
//             for(int i = n-1; i >=0; i--) {
//                 nextCons[i] = lastConsIdx;
//                 if(!isVowel(word[i])) { //consonant
//                     lastConsIdx = i;
//                 }
//             }             //  humne yaha toh har index ke liye compute krke rkhliya ki usse next consanent kis index pe h.....kisi bhi index pe dekhna hoga toh seedha nikal lege vector se
//             // iska alter tarika ....saare consanents ka idx store krlo.....fir jab kisi index ke liye next consanent dekhna hoga tab iss index wale vector m binary search se phla idx greater than curr idx nikal lege
//             // precompute tarika better h
    
    
//             int i = 0;
//             int j = 0;
//             long long count = 0;
//             int cons = 0;
//             while(j < n) {
//                 char ch = word[j];
//                 if(isVowel(ch)) {
//                     mp[ch]++;
//                 } else {
//                     cons++;
//                 }
    
                
//                 while(cons > k) { //cons == k chahie
//                     char ch = word[i];
//                     if(isVowel(ch)) {
//                         mp[ch]--;
//                         if(mp[ch] == 0) {
//                             mp.erase(ch);
//                         }
//                     } else {
//                         cons--;
//                     }
//                     i++;
//                 }
    
//                 while(mp.size() == 5 && cons == k) { //valid window
//                     int idx = nextCons[j]; //it will tell me the next consonant after jth index
//                     count += idx - j; //most important part
//                     char ch = word[i];
//                     if(isVowel(ch)) {
//                         mp[ch]--;
//                         if(mp[ch] == 0) {
//                             mp.erase(ch);
//                         }
//                     } else {
//                         cons--;
//                     }
//                     i++;
//                 }
    
//                 j++;
//             }
    
//             return count;
//         }
//     };
    