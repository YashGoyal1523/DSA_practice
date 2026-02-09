//lc 2359

// approach
// find the shortest distance from both node1 and node2 to all nodes in the graph.
// iterate over dist to all nodes from both and find the node with the minimum max distance.

class Solution {
public:
    void dijkstra(int src,vector<vector<int>>&adj,vector<int>&dist){
        int n=adj.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        dist[src]=0;
        
        while(!pq.empty()){
            auto topnode=pq.top();
            pq.pop();
            int currnode=topnode.second;
            int currdist=topnode.first;

            for(auto nbr:adj[currnode]){
                    if(currdist+1<dist[nbr]){
                    dist[nbr]=currdist+1;
                    pq.push({currdist+1,nbr});
                }
                
            }


        }
        
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)adj[i].push_back(edges[i]);
        }
        vector<int>dist1(n,1e9);
        dijkstra(node1,adj,dist1);
        vector<int>dist2(n,1e9);
        dijkstra(node2,adj,dist2);
       
        int mini=1e9;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(dist1[i]!=1e9&&dist2[i]!=1e9){
            int maxi=max(dist1[i],dist2[i]);
            if(maxi<mini){
                ans=i;
                mini=maxi;
            }
            }
        }
        return ans;
    }
};