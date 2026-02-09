//lc 1061

//union by lexicographical order

class Solution {
public:
class DisjointSet {
    vector<int> parent;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        for (int i = 0; i <=n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);  // path compression krli
    }

    void unionlex(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (ulp_u < ulp_v) {
            parent[ulp_v] = ulp_u;
        }
        else { //>
            parent[ulp_u] = ulp_v;
        }
    }
};
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(26);
        for(int i=0;i<s1.size();i++){
            ds.unionlex(s1[i]-'a',s2[i]-'a');
        }
        for(int i=0;i<baseStr.size();i++){
            baseStr[i]=ds.findUPar(baseStr[i]-'a')+'a';
        }

        return baseStr;
    }
};