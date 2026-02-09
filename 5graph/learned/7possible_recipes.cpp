//lc 2115

// toposort


class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            unordered_map<string,vector<string>>adj;
            unordered_map<string,int>indegree;
            for(int i=0;i<ingredients.size();i++){
                string recipe=recipes[i];
                for(auto ingredient:ingredients[i]){
                    adj[ingredient].push_back(recipe);
                    indegree[recipe]++;
                }
            }
            //push indegree 0 wali in queue ie supplies daaldo 
            queue<string>q;
            for(auto supply:supplies){
                q.push(supply);
            }
            
            while(!q.empty()){
                string front=q.front();
                q.pop();
                for(auto nbr:adj[front]){
                    indegree[nbr]--;
                    if(indegree[nbr]==0) q.push(nbr);
                }
            }
            
            vector<string>ans;
            for(int i=0;i<recipes.size();i++){
                if(indegree[recipes[i]]==0) ans.push_back(recipes[i]);
            }
            return ans;
        }
    };