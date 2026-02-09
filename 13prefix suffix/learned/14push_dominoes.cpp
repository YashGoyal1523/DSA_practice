// lc 838

class Solution {
    public:
        string pushDominoes(string dominoes) {
            int n = dominoes.size() ;
            vector<int> nearestRight(n,INT_MAX) ;
            vector<int> nearestLeft(n,INT_MAX) ;
    
            if(dominoes[0] == 'R') {
                nearestRight[0] = 0 ;
            }
    
            if(dominoes[n-1] == 'L') {
                nearestLeft[n-1] = n-1 ;
            }
    
            for(int i=1 ; i<n ; i++) {
                if(dominoes[i] == 'R') {
                    nearestRight[i] = i ;
                } else if(dominoes[i] == '.') {
                    nearestRight[i] = nearestRight[i-1] ;
                }
            }
    
            for(int i=n-2 ; i>=0 ; i--) {
                if(dominoes[i] == 'L') {
                    nearestLeft[i] = i ;
                } else if(dominoes[i] == '.') {
                    nearestLeft[i] = nearestLeft[i+1] ;
                }
            }
    
            string ans = "" ;
    
            for(int i=0 ; i<n ; i++) {
                int distLeft = abs(nearestLeft[i]-i) ;
                int distRight = abs(nearestRight[i]-i) ;
    
                if(distLeft < distRight) {
                    ans.push_back('L') ;
                } else if(distLeft > distRight) {
                    ans.push_back('R') ;
                } else {
                    ans.push_back('.') ;
                }
            }
    
            return ans ;
        }
    };