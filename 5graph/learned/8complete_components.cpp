//lc 2685

//m1 bfs/dfs
//saare component store krlo ie har component mein kya kya nodes h voh store krlo
// har component m check kro ki uske har node se no of edges = component ka size -1 h ya nhi , if yes then complete else no
class Solution {
    public:
      void bfs(int src, vector<vector<int>>& adj, vector<int>& vis,vector<vector<int>>&components)
     {
            queue<int> q;
            q.push(src);
            vis[src]=true;
            vector<int>v;
    
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                v.push_back(curr);
    
                for (auto nbr : adj[curr]) {
                    if (!vis[nbr]) {
                        vis[nbr]=true;
                        q.push(nbr);
                    }
                }
            }
           components.push_back(v);
        }
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj(n);  // Initialize adjacency list for 'n' nodes
            vector<int> vis(n, 0);  
            vector<vector<int>>components;
            for (int i = 0; i < edges.size(); i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
            for (int src = 0; src < n; src++) {
                if (!vis[src]) {
                     bfs(src, adj, vis,components);
                }
            }
            int ans=0;
            for(auto i:components){
                bool complete=true;
                for(auto node:i){
                    if(adj[node].size()!=i.size()-1){
                        complete=false;
                        break;
                    }
                }
                if(complete) ans++;
            }
            return ans;
        }
    };

    //m2 dsu by size
    // A connected component is complete if and only if the number of edges in the component is equal to m*(m-1)/2, where m is the number of nodes in the component.
    //https://youtu.be/7b7GbuFMWRw?si=FQYPI-duoRD1G0aX
    class DisjointSet {
        public:
        vector<int>  parent, size;
    
        DisjointSet(int n) {
            
            parent.resize(n + 1);
            size.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
    
        int findUPar(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findUPar(parent[node]);
        }
    
        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };
    class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
           DisjointSet ds(n);
           for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            ds.unionBySize(u,v);
           } 
            //Count the edges for each root
            unordered_map<int, int> mp;
            for(auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int root = ds.findUPar(u);
                mp[root]++; //incrementing for edge count
            }
    
            int result = 0;
            for(int i = 0; i < n; i++) {
                if(ds.findUPar(i) == i) { //ye papa ji hain (root hai)
                    int v = ds.size[i];
                    int e = mp[i];
    
                    if((v*(v-1))/2 == e) {
                        result++;
                    }
                }
            }
    
            return result;
        }
    
        
    };