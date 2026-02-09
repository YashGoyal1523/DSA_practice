//lc 2924 find champion 2

// champion will be 0 indegree node

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        
        // Calculate in-degrees
        for (auto& edge : edges) {
            indegree[edge[1]]++;
        }

        int champ = -1;  // Potential champion node
        int count = 0;   // Count of nodes with zero in-degree

        // Find node(s) with zero in-degree
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                count++;
                if (count > 1) return -1;  // More than one node with zero in-degree
                champ = i;                // Candidate for champion
            }
        }

        return champ;
    }
};
