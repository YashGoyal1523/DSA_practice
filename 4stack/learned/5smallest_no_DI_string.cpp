//lc 2375

//https://youtu.be/rCjwDls-HPk?si=IEt_zWIPTZCUJtUj

// bruteforce

//1234567...(lexicographical smallest) se shuru hojao and check kro kya yeh satisfy karra
// if no then next permutation uthao ...fir check kro
// krte jao jabtak match na mile
// match milte hi vhi ans h ....


class Solution {
    public:
        bool matchesPattern (string &num, string &pattern) { 
    for(int i = 0; i < pattern.length(); i++) { 
    if((pattern [i] == 'I' && num[i] > num [i+1]) || 
    (pattern [i] == 'D' && num[i] < num [i+1])) { 
    return false; 
    } 
    } 
    return true; 
    } 
    string smallestNumber(string pattern) { 
    int n = pattern.length();  
    string num = ""; 
    for(int i = 1; i <= n+1; i++) { 
    num.push_back(i + '0'); 
    } 
    
     do{
        if(matchesPattern(num, pattern)) break;
        } while (next_permutation(num.begin(), num.end()));
    
    return num;
        }
    };


    //STACK
    // ek stack banao
    // ek ek krke 1 se shuru hoke 1,2,3,4... stack m push krte rhege 
    // har no ke baad saath saath  element dekho agar D hai toh aage bhado agar I hai toh stack empty krdo and stack elements ko ans m store krte jao
    // ese krte jao end tak
    // string khatm hone ke baad fir stack empty and ans m store


    class Solution {
        public:
            string smallestNumber(string pattern) { 
        int n = pattern.length(); 
        string num = ""; //(n+1) //index 0 to index n 
        int counter = 1; 
        stack<char> st; 
        for(int i = 0; i <= n; i++) { 
        st.push(counter + '0'); 
        counter++; 
        if(i == n || pattern [i] == 'I') { 
        while(!st.empty()) { 
        num += st.top(); 
        st.pop(); 
        } 
        } 
        } 
        return num;
            }
        };