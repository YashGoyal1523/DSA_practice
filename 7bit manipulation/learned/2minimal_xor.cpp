//lc 2429
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt1 = 0;
        int temp = num1;
        // Count the number of set bits in num1
        while (temp > 0) {
            cnt1++;
            temp = temp & (temp - 1);
        }

        int cnt2 = 0;
        temp = num2;
        // Count the number of set bits in num2
        while (temp > 0) {
            cnt2++;
            temp = temp & (temp - 1);
        }

        int ans = 0;
        int extra_one = cnt1 > cnt2 ? cnt1 - cnt2 : 0; // Excess 1 bits to ignore from lsb side
        int zero_to_one = cnt2 > cnt1 ? cnt2 - cnt1 : 0; // Extra 1 bits to add from lsb side

        int i = 0;
        while (num1 > 0 || zero_to_one > 0) {
            int bit = num1 & 1; // Get the least significant bit of num1

            if (bit == 1) {
                if (extra_one == 0) {
                    ans |= (1 << i); // Set the bit in ans
                } else {
                    extra_one--; // Skip this bit
                }
            } else {
                if (zero_to_one > 0) {
                    ans |= (1 << i); // Add an extra 1 bit
                    zero_to_one--;
                }
            }

            i++;
            num1 >>= 1; // Shift num1 to process the next bit
        }

        return ans;
    }
};
