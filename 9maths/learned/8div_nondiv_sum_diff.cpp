//lc 2894

// div by m : m,2m,3m,4m,....km = m(1+2+3+...+k)

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalsum=n*(n+1)/2;
        int k=n/m;
        int divsum=m*(k*(k+1)/2);
        int nondivsum=totalsum-divsum;

        return nondivsum-divsum;
    }
};