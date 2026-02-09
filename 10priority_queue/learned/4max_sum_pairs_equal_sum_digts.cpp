//lc 2342

//editorial se nikale h
//m1
class Solution {
    private:
        // Helper function to compute the sum of digits of a number
        int calculateDigitSum(int num) {
            int digitSum = 0;
            while (num > 0) {
                digitSum += num % 10;
                num /= 10;
            }
            return digitSum;
        }
    
    public:
        int maximumSum(vector<int>& nums) {
            vector<pair<int, int>> digitSumPairs;
    
            // Store numbers with their digit sums as pairs
            for (int number : nums) {
                int digitSum = calculateDigitSum(number);
                digitSumPairs.push_back({digitSum, number});
            }
    
            // Sort based on digit sums, and if equal, by number value
            sort(digitSumPairs.begin(), digitSumPairs.end());
    
            int maxPairSum = -1;
    
            // Iterate through the sorted array to find the maximum sum of pairs
            for (int index = 1; index < digitSumPairs.size(); index++) {
                int currentDigitSum = digitSumPairs[index].first;
                int previousDigitSum = digitSumPairs[index - 1].first;
    
                // If two consecutive numbers have the same digit sum
                if (currentDigitSum == previousDigitSum) {
                    int currentSum = digitSumPairs[index].second +
                                     digitSumPairs[index - 1].second;
                    maxPairSum = max(maxPairSum, currentSum);
                }
            }
    
            return maxPairSum;
        }
    };
    //m2 tarika 1
class Solution {
    private:
     
        int calculateDigitSum(int num) {
            int digitSum = 0;
            while (num > 0) {
                digitSum += num % 10;
                num /= 10;
            }
            return digitSum;
        }
    
    public:
        int maximumSum(vector<int>& nums) {
            // Vector to store a min heap for each possible digit sum (0 to 81) // max heap se bhi kr skte // min wale se space kam lagegi // nums[i] <=10^9 so max possible digits sum nums[i] can have is for nums[i]=999999999 ie 82 
            // map mein bhi store kr skte vector ki jagah
            vector<priority_queue<int, vector<int>, greater<int>>> digitSumGroups(82);
    
            int maxPairSum = -1;
    
            // Group numbers by their digit sums, maintaining heap size of 2   // max heap banake krte toh saare daalke last m top 2 lelete
            for (int number : nums) {
                int digitSum = calculateDigitSum(number);
                digitSumGroups[digitSum].push(number);
    
                // Keep only the top 2 largest numbers in the heap
                if (digitSumGroups[digitSum].size() > 2) {
                    digitSumGroups[digitSum].pop();  // Remove the smallest element
                }
            }
    
            // Traverse the vector to find the maximum pair sum for each group
            for (auto& minHeap : digitSumGroups) {
                if (minHeap.size() == 2) {
                    int first = minHeap.top();
                    minHeap.pop();
                    int second = minHeap.top();
                    maxPairSum = max(maxPairSum, first + second);
                }
            }
    
            return maxPairSum;
        }
    };


// tarika 2
class Solution {
    private:
     
        int calculateDigitSum(int num) {
            int digitSum = 0;
            while (num > 0) {
                digitSum += num % 10;
                num /= 10;
            }
            return digitSum;
        }
    
    public:
        int maximumSum(vector<int>& nums) {
            
            map<int,priority_queue<int>> mp;
    
            int maxPairSum = -1;
    
    
            for (int number : nums) {
                int digitSum = calculateDigitSum(number);
                mp[digitSum].push(number);
    
            }
    
            for (auto i : mp) {
                if (i.second.size() >= 2) {
                    int first = i.second.top();
                    i.second.pop();
                    int second = i.second.top();
                    maxPairSum = max(maxPairSum, first + second);
                }
            }
    
            return maxPairSum;
        }
    };




    //m3

    class Solution {
        public:
            int maximumSum(vector<int>& nums) {
                int result = -1;
                // Array to map digit sums to the largest element with that sum
                // (82 to cover all possible sums from 0 to 81)
                int digitMapping[82] = {};
        
                for (int element : nums) {
                    int digitSum = 0;
        
                    // Calculate the digit sum of the current element
                    for (int currValue = element; currValue; currValue /= 10) {
                        int currDigit = currValue % 10;
                        digitSum += currDigit;
                    }
        
                    // Check if there is already an element with the same digit sum
                    if (digitMapping[digitSum] > 0) {
                        // Update the result if the sum of the current and mapped
                        // element is greater
                        result = max(result, digitMapping[digitSum] + element);
                    }
        
                    // Update the mapping to store the larger of the current or previous
                    // element for this digit sum
                    digitMapping[digitSum] = max(digitMapping[digitSum], element);
                }
        
                return result;
            }
        };