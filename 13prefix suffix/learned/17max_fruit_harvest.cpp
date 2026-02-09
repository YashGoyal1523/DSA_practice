//lc 2106

// https://youtu.be/9biz4kxyVh8?si=xBvl-wYUlUrve1H1

//move right full
//move left full
//move left then right
//move right then left



//Approach (Binary Search and prefix sum)
//T.C : O(n+klogn)
//S.C : O(n)
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> prefixSum(n);
        vector<int> indices(n);

        // Build prefix sum and extract indices
        for (int i = 0; i < n; i++) {
            indices[i]   = fruits[i][0];
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        int maxFruits = 0;


        for (int d = 0; d <= k / 2; d++) {

            // Move d left and then right
            // (note : when d=0 -> completely right move case)
            
            int remain = k - 2 * d;
            int i   = startPos - d;
            int j  = startPos + remain;

            int left  = lower_bound(indices.begin(), indices.end(), i) - indices.begin();
            int right = upper_bound(indices.begin(), indices.end(), j) - indices.begin() - 1;

            if(left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFruits = max(maxFruits, total);
            }

             // Move d right and then left 
             // (note : when d=0 -> completely left move case)

            // remain=k-2*d;             
            i  = startPos - remain;
             j  = startPos + d;
            
             left  = lower_bound(indices.begin(), indices.end(), i) - indices.begin();
             right = upper_bound(indices.begin(), indices.end(), j) - indices.begin() - 1;

            if(left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFruits = max(maxFruits, total);
            }

        }
        

        return maxFruits;
    }
};
