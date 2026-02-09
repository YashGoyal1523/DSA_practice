// lc 7
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

//note : 
// int/int gives int
// now 
// n is int
// n%10 gives last digit of n with sign that of n //21%10=1 , -21%10=-1
// n/10 gives output with last digit removed with same sign //21/10=2 (2.1 is 2 in int) , -21/10=-2  (-2.1 is -2 in int)



class Solution {
public:
    int reverse(int x) {

        //-2^31 is int_min and 2^31-1 is int_max. // 2^31 is 2147483648

        int number = 0;

        while (x != 0) {
            int lastdigit = x % 10;

            // Check for overflow before actually multiplying and adding
            if (number > INT_MAX / 10 )
                return 0;
            if (number < INT_MIN / 10 )
                return 0;

            number = number * 10 + lastdigit;
            x /= 10;
        }

        return number;
    }
};