//lc 869

// https://youtu.be/_Y8xqGvZu8M?si=gXhXyoiIWuR5c6En

//Approach (Using sorting)
//T.C : O(dlogd), d = number of digits
//S.C : O(d)
class Solution {
public:
    string getSortedStr(int n) {
        string s = to_string(n);
        sort(begin(s), end(s));
        return s;
    }

    bool reorderedPowerOf2(int n) {
        string s = getSortedStr(n);

        //check all 2 powers and see if it matches with s
        //till 2^29
        for(int p = 0; p <= 29; p++) {
            if(s == getSortedStr(1 << p)) {  //1<<i = 2^i
                return true;
            }
        }

        return false;
    }
};
