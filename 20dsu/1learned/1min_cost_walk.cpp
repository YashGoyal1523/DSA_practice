//lc 3108

// a&b <= min(a,b) 

// if u and v are not connected ie not in same component then answer is -1
// if they belong to same component then just do and of all edges of component and that will give the ans



class DisjointSet {
    vector<int> rank , parent;
public:       
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);  // Path compression
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else { 
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisjointSet ds(n); 

        // process edges
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], cost = edges[i][2];
            ds.unionByRank(u, v);
        }

        //And all edges in each component
        vector<int> val(n,~0); //X & 111...111 (all ones) = X
  //By initializing with all bits set , we ensure that when we start ANDing edge weights, the first weight is fully preserved.

         for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], cost = edges[i][2];
            int p=ds.findUPar(u);
            val[p]&=cost;
        }

        // Answer queries
        vector<int> ans;
        for (int i = 0; i < query.size(); i++) {
            int u = query[i][0], v = query[i][1];
            if (ds.findUPar(u) != ds.findUPar(v)) ans.push_back(-1);
            else ans.push_back(val[ds.findUPar(u)]);
        }
        return ans;
    }
};
