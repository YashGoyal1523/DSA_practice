// lc 781
class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int,int>freq;
            int n=answers.size();
            int cnt=0;
            for(int i=0;i<n;i++){
                freq[answers[i]]++;
            }
            for(auto i:freq){
                int val=i.first;
                int fre=i.second;
                
                    // cnt+=((fre/(val+1))*(val+1));
                    // if(fre%(val+1)!=0) cnt+=(val+1);
                     cnt+=(ceil((double)fre/(val+1))*(val+1));
                
            }
            return cnt;
        }
    };