// lc 2601

// Intuition
// Let's think through a basic approach to solve the problem. We want to make sure that each number in the array stays just a bit larger than the one before it. To do this, we’ll be subtracting the largest possible prime number from each element, but we have to be careful: the prime we subtract should leave the current element just slightly above the previous one.

// In other words, for each element nums[i], we need to find the biggest prime p so that after subtracting p, the new value of nums[i] is still greater than nums[i-1]. Mathematically, that’s nums[i] - p > nums[i-1]. So, p has to be the largest prime that’s smaller than the difference nums[i] - nums[i-1].

// To make this work, we’ll loop through each element in nums. For each one, we’ll look at the difference between it and the previous number. If this difference is zero or negative, it’s impossible to make the sequence strictly increasing, so we can just return false right away. But if the difference is positive, we need to find the largest prime within this range.

// Now, remember a prime number only has two divisors: 1 and itself. To check if a number is prime, we don’t have to test all the way up to that number, we just need to check up to its square root. If we don’t find any divisors up to that point, then the number is prime.

// Once we find this largest prime p, we subtract it from nums[i] and move on to the next element. If we manage to go through the whole array without any issues, we know the sequence is strictly increasing, so we return true.

// Algorithm
// Main Function - primeSubOperation(nums)

// Loop through each element in nums, using the index i from 0 to nums.size() - 1:
// For the first element (i = 0), set bound to nums[0]. For subsequent elements, set bound to nums[i] - nums[i - 1].
// If bound is less than or equal to 0, return false, as it is impossible to create a strictly increasing sequence.
// Initialize largestPrime as 0.
// Starting from bound - 1, iterate downwards until 2 to find the largest prime number less than bound.
// If a prime number is found (using checkPrime), store it in largestPrime and stop the search.
// Subtract largestPrime from nums[i].
// If the loop completes, return true.
// Helper Function - checkPrime(x)

// Loop from 2 to the square root of x:
// If any number divides x evenly, return false (indicating x is not prime).
// If no divisors are found, return true, indicating `x`` is prime.
// Implementation


// bruteforce

class Solution {
public:
    bool checkPrime(int x) {
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                return 0;
            }
        }
        return 1;
    }
    bool primeSubOperation(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int bound;
            // In case of first index, we need to find the largest prime less
            // than nums[0].
            if (i == 0) {
                bound = nums[0];
            } else {
                // Otherwise, we need to find the largest prime, that makes the
                // current element closest to the previous element.
                bound = nums[i] - nums[i - 1];
            }

            // If the bound is less than or equal to 0, then the array cannot be
            // made strictly increasing.
            if (bound <= 0) {
                return 0;
            }

            // Find the largest prime less than bound.
            int largestPrime = 0;
            for (int j = bound - 1; j >= 2; j--) {    // binary search se bhi kr sktee yeh find krna
                if (checkPrime(j)) {
                    largestPrime = j;
                    break;
                }
            }

            // Subtract this value from nums[i].
            nums[i] = nums[i] - largestPrime;
        }
        return 1;
    }
};

// better : store prev prime initially

class Solution {
public:
    bool checkPrime(int x) {
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                return 0;
            }
        }
        return 1;
    }
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());

        // Store the previousPrime array.
        vector<int> previousPrime(maxElement + 1, 0);
        for (int i = 2; i <= maxElement; i++) {
            if (checkPrime(i)) {
                previousPrime[i] = i;
            } else {
                previousPrime[i] = previousPrime[i - 1];
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            int bound;
            // In case of first index, we need to find the largest prime less
            // than nums[0].
            if (i == 0) {
                bound = nums[0];
            } else {
                // Otherwise, we need to find the largest prime, that makes the
                // current element closest to the previous element.
                bound = nums[i] - nums[i - 1];
            }

            // If the bound is less than or equal to 0, then the array cannot be
            // made strictly increasing.
            if (bound <= 0) {
                return 0;
            }

            // Find the largest prime less than bound.
            int largestPrime = previousPrime[bound - 1];

            // Subtract this value from nums[i].
            nums[i] = nums[i] - largestPrime;
        }
        return 1;
    }
};