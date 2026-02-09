// lc 3160

//likhe ka tarika 1
class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            int cnt=0;
            unordered_map<int,int>colorfreq;
            unordered_map<int,int>ballcolor;
            vector<int>ans;
            for(int i=0;i<queries.size();i++){
                int ball=queries[i][0];
                int newcol=queries[i][1];
                int prevcol=ballcolor[ball];
    
                if(prevcol!=0){ // ball is already colored
                    // pichla color hatao
                    colorfreq[prevcol]--;
                    if(colorfreq[prevcol]==0) cnt--;
                    // new color lagao
                    ballcolor[ball]=newcol;
                    if(colorfreq[newcol]==0) cnt++;
                    colorfreq[newcol]++;
                }
                else{ // ball not colored already
                    // new color lagao
                    ballcolor[ball]=newcol;
                    if(colorfreq[newcol]==0) cnt++;
                    colorfreq[newcol]++;
                }
    
    
               ans.push_back(cnt);
            }
    
            return ans;
        }
    };


    //likhne ka tarika 2....better

    class Solution {
        public:
            vector<int> queryResults(int limit, vector<vector<int>>& queries) {
                int cnt=0;
                unordered_map<int,int>colorfreq;
                unordered_map<int,int>ballcolor;
                vector<int>ans;
                for(int i=0;i<queries.size();i++){
                    int ball=queries[i][0];
                    int newcol=queries[i][1];
                    int prevcol=ballcolor[ball];
        
                    if(prevcol!=0){ // ball is already colored
                        //pichla col hatao
                        colorfreq[prevcol]--;
                        if(colorfreq[prevcol]==0) cnt--;
                       
                    }
                     // new color dedo ball ko 
                        ballcolor[ball]=newcol;
                        if(colorfreq[newcol]==0) cnt++;
                        colorfreq[newcol]++;
                    
                   ans.push_back(cnt);
                }
        
                return ans;
            }
        };