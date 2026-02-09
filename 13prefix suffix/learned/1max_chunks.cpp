//lc 769

// notice that for each number in the array, we have two options: we can either include it in the same chunk as the previous number or create a new chunk for it. However, we must consider the limitation that a new chunk at index i can only be created if all the numbers in the current and previous chunks  are smaller than all the numbers in the following chunks . This is equivalent to checking whether:
// max(prefix[0:i))<min(suffix[i:n]).


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixMax(n);
        vector<int> suffixMin(n);

        // Fill the prefixMax array (inc curr)
        prefixMax[0]=arr[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], arr[i]);
        }

        // Fill the suffixMin array (inc curr)
        suffixMin[n-1]=arr[n-1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], arr[i]);
        }

        int chunks = 0;
        for (int i = 0; i < n; i++) {
            // A new chunk can be created
            if (i == 0 || prefixMax[i-1]<suffixMin[i]) chunks++;
        }

        return chunks;
    }
};