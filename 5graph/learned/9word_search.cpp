//lc 79

// dfs

//board ke har element which is matching to first character of word...se dfs krke dekhlo ki word banra ya nhi...kisi se bhi bangya toh true else false

class Solution {
public:

    bool solve(int x,int y,int i,vector<vector<char>>& board, string word,vector<vector<int>>&vis){
        int m=board.size();
        int n=board[0].size();

        if(i==word.size()-1&&word[i]==board[x][y]){
            return true;
        }
        
        
        if(word[i]==board[x][y]){
           vis[x][y]=true;
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};

            for(int idx=0;idx<4;idx++){
                int newx=dx[idx]+x;
                int newy=dy[idx]+y;

                if(newx>=0&&newy>=0&&newx<m&&newy<n&&!vis[newx][newy]){
                   bool ans=solve(newx,newy,i+1,board,word,vis);
                    if(ans) return true;
                }
            
            }
            vis[x][y]=false;
            
        }
       
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        int i=0;
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                if(board[x][y]==word[0]){
                    vector<vector<int>>vis(m,vector<int>(n,0));
                    bool ans=solve(x,y,i,board,word,vis);
                    if(ans) return true;
                }
            }
        }
        
        return false;
    }
};