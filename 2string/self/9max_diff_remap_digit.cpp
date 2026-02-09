//lc 2566

// Try to remap the first non-nine digit to 9 to obtain the maximum number.
// Try to remap the first non-zero digit to 0 to obtain the minimum number.


class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);

        string maxi=s;
        char ch='*';
        for(int i=0;i<s.size();i++){
            if(maxi[i]!='9') {
                ch=maxi[i];
                break;
            }
        }
        for(int i=0;i<s.size();i++){
            if(maxi[i]==ch) {
                maxi[i]='9';
            }
        }
         string mini=s;
         ch=mini[0];  //nums m leading zeroes nhi h toh phla digit hi non zero digit hai
        
        for(int i=0;i<s.size();i++){
            if(mini[i]==ch) {
                mini[i]='0';
            }
        }
        
        return stoi(maxi)-stoi(mini);
    }
};