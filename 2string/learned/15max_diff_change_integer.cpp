//lc 1432

//iska ez version is lc 2566
// usme maxi/mini m leading zeroes allowed h ...isme nhi ... 


// https://youtu.be/bT-xxyXvB3c?si=TBhr3jbF5yYOSRQV

//Approach (replacing with 9 for maximum and carefully minimizing the number using greedy)
//T.C : O(log10(num))
//S.C : O(log10(num))
class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num); //max
        string str2 = str1;  //min

        int idx = str1.find_first_not_of('9');
        if(idx != string::npos) {
            char ch = str1[idx];
            replace(begin(str1), end(str1), ch, '9');
        }

        //We can't directly choose 0th index character and make it 0
        //because qn says we can't have leading zeros
        if(str2[0] != '1') {
                    char ch=str2[0];
                    replace(begin(str2), end(str2), ch, '1');
                }
        else{        
            //str2[0]=='1'
        for(int i = 1; i < str2.length(); i++) {
            char ch = str2[i];
               if(ch != '0' && ch != '1') { // as str2[0]='1'
                //example : 111, even if we skip 1 at str2[0], we see again at str2[1]
                //But we can't change 1 to 0 because it will replace 1 of str2[0] as well
                replace(begin(str2), end(str2), ch, '0');
                break;
            }
        }
        }

       
        return stoi(str1) - stoi(str2);
    }
};
