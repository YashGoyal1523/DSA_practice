//lc 2425

// if nums1 = [a1, a2] and nums2 = [b1, b2], then:
// nums3 = [a1 ^ b1, a1 ^ b2, a2 ^ b1, a2 ^ b2]
// Our task is to calculate the XOR of all elements in nums3. This can be expressed as:
// result = (a1 ^ b1) ^ (a1 ^ b2) ^ (a2 ^ b1) ^ (a2 ^ b2)
//now
// XOR is commutative
// Each element of nums1 appears n2 times in the calculation (where n2 is the size of nums2).
// Each element of nums2 appears n1 times in the calculation (where n1 is the size of nums1).
//so
// result = (a1 ^ a1 ^ ... repeated n2 times) ^ (a2 ^ a2 ^ ... repeated n2 times) ^     (b1 ^ b1 ^ ... repeated n1 times) ^ (b2 ^ b2 ^ ... repeated n1 times)
//now
// XOR with itself results in 0: a ^ a = 0
// XOR with 0 results in the same number: a ^ 0 = a
//so
//if nums 2 length is even,each element in nums1 appears even times in final result.....each element ki saari appearances cut jaayegi pairs banke
// If nums2 length is odd, each element in nums1 appears odd times in final result ...each element ke saare apearances pairs banke cut jaayege and ek apearance rhjayega
//if nums 1 length is even,each element in nums2 appears even times in final result.....each element ki saari appearances cut jaayegi pairs banke
// If nums1 length is odd, each element in nums2 appears odd times in final result.. each element ke saare appearances pairs banke cut jaayege and ek apearance rhjayega



class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // Initialize XOR results for both arrays
        int xor1 = 0;
        int xor2 = 0;

        // Get lengths of both arrays
        int len1 = nums1.size();
        int len2 = nums2.size();

        // If nums2 length is odd, each element in nums1 appears odd times in final result
        // each element ke saare pairs banke cut jaayege and ek apearance rhjayega
        if (len2 % 2 != 0) {
            for (int num : nums1) {
                xor1 ^= num;
            }
        }

        // If nums1 length is odd, each element in nums2 appears odd times in final result
        // each element ke saare pairs banke cut jaayege and ek apearance rhjayega
        if (len1 % 2 != 0) {
            for (int num : nums2) {
                xor2 ^= num;
            }
        }

        // Return XOR of both results
        return xor1 ^ xor2;
    }
};