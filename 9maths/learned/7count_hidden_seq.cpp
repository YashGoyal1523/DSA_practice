//lc 2145



// see editorial / mik video / utube video

//if a1,a2,a3,a4.... is satisfying difference condition then a1+k,a2+k,a3+k,....also satisfy the difference condition
//a1 zero leke ek difference condition satisfying sequence banalo
// fir uske min,max value se dekhlo ...given range mein kitne required sequences ban skte

class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int x = 0, y = 0, cur = 0;
            for (int d : differences) {
                cur += d;
                x = min(x, cur);
                y = max(y, cur);
                if (y - x > upper - lower) {
                    return 0;
                }
            }
            return (upper - lower) - (y - x) + 1;
        }
    };