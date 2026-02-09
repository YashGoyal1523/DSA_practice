//lc 1358

// bruteforce
// check all subarrays 



// sliding window

// codestorywithmik 
//similar to lc 3306 (pichla ques) ...bas usme additional constraint tha k ka isme nhi h
// https://youtu.be/wafDgldM9MA?si=1n1oGKtxcS30YCxg
class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n = s.length();
    
            int result = 0;
            
            vector<int> mp(3, 0); //index 0 - a, 1 - b, 2 - c
    
            int i = 0;
            int j = 0;
            while(j < n) {
                char ch = s[j];
                mp[ch-'a']++;
    
                while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0) {
                    result += (n - j);
    
                    mp[s[i] - 'a']--;
                    i++;
                }
    
                j++;
            }
    
            return result;
    
            
        }
    };
    


//striver

// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int cnt=0;
//         int i=0;
       
//         vector<int>lastscene(3,-1); // last scene index //0 index for a , 1->b , 2->c
//         for(int i=0;i<s.size();i++){
//             lastscene[s[i]-'a']=i;
//             if(lastscene[0]!=-1 && lastscene[1]!=-1 && lastscene[2]!=-1 ){ // teeno occur ho chuke
//                   int j=*min_element(lastscene.begin(),lastscene.end());
//                   cnt+=j-0+1;
//             }
//         }
//         return cnt;
//     }
// };
