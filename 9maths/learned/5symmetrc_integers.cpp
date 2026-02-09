// lc2843


// m1 bruteforce
//T.C : O((high-low+1)*d), where d  = number of digits
//S.C : O(d) for storing string
class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
             int count = 0;
    
            for(int num = low; num <= high; num++) {
                string s = to_string(num);
    
                int l = s.length();
    
                if(l%2 != 0) {
                    continue;
                }
    
                int leftSum = 0;
                int rightSum = 0;
    
                for(int i = 0; i < l/2; i++) {
                    leftSum += s[i] - '0';
                }
    
                for(int i = l/2; i < l; i++) {
                    rightSum += s[i] - '0';
                }
    
                if(leftSum == rightSum) {
                    count++;
                }
            }
    
            return count;
        }
    };

    // m2 optimal

    //given range :[1,10000]
   // possible no of digit in no ->1,2,3,4
   // 1,3 -> not symmetric
   // 2,4 ->to check 
   // 2->if div by 11 then yes
   // 4-> check krlo digits ka sum: if sum of first two digit = sum of last two then yes

   //T.C : O(high-low+1)
//S.C : O(1)
   class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
      int count = 0;
    
            for(int num = low; num <= high; num++) {
                if(num >= 10 && num <= 99 && num % 11 == 0) { //2 digit numbers divisible by 11 are symmetric
                    count++;
                } else if(num >= 1000 && num <= 9999) { //4 digits numbers, check karlo left and right
                    int first  = num/1000;
                    int second = (num/100) % 10;
    
                    int third  = (num / 10) % 10;
                    int fourth = (num % 10);
    
                    if(first+second == third + fourth) {
                        count++;
                    }
                }
            }
    
            return count;
        }
    };
    