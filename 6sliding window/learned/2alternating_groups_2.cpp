//lc 3208


// bruteforce

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            for(int i=0;i<k-1;i++){ // to handle circular // shuru se k-1 elements last m daaldo taaki last window ie last element se shuru hone wale window handle hojaye
                colors.push_back(colors[i]);
            }
            int ans=0;
            for(int i=0;i<=colors.size()-k;i++){
                bool flag=0;
                for(int j=i+1;j<i+k;j++){
                    if(colors[j]==colors[j-1]) {
                        flag=1;
                        break;
                    }
                }
                if(flag==0) ans++;
            }
            return ans;
        }
    };


    //codestorywithmik

    // sliding window
   // https://youtu.be/EZVLzXvaQ2A?si=9zCJ_UHU352vDwTR
   class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
    
            int N = n + (k-1);
            for(int i = 0; i < k-1; i++) {
                colors.push_back(colors[i]); //to handle wrap around (circular array)
            }
    
            int result = 0;
            int i = 0;
            int j = 1; //start from 1 because we have to check index j-1 for checking alterate
            while(j < N) {

            //     if(colors[j] == colors[j-1]) {
            //         i = j; // window firse shuru kro yaha se
            //         j++;
            //     }
    
            //     else if(j - i + 1 == k) { // required window
            //         result++;
            //         i++; // window shift kro ek element se
            //         j++;
            //     }
    
            //    else j++; // alternating milra ...shi hai... aage chlo


                if(colors[j] == colors[j-1]) { //alternating nhi mila
                    i = j; // window firse shuru kro yaha se
                    j++;
                    continue;
                }
                
                //alternating mila
                if(j - i + 1 == k) { // required window
                    result++;
                    i++; // window shift kro ek element se
                }
    
                j++;
            }
    
            return result;
        }
    };

    //another method 
    //https://youtu.be/EZVLzXvaQ2A?si=f0bfzhBDN6Smtk5S
    class Solution {
        public:
            int numberOfAlternatingGroups(vector<int>& colors, int k) {
                for(int i = 0; i < k-1; i++) {
                    colors.push_back(colors[i]); //to handle wrap around (circular array)
                }
        
        
                int result = 0;
        
                int length = 1; //i = 0 index wala element
                int last   = colors[0];
              
                for(int i = 1; i < colors.size(); i++) {
                    if(colors[i] == last) { // not alternating
                        length = 1;
                        last = colors[i];
                        continue;
                    }
                    
                    //alternating mila
                    length++;
        
                    if(length >= k) {
                        result++;
                    }
        
                    last = colors[i];
                }
                return result;
            }
        };