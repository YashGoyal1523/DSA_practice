//lc 1980

// pichle ques( lc 1415 : kth lexicographical string) dekh ke similar approach banaya

class Solution {
    public:
    
        void solve(int &found,int &index,vector<string>& nums,int n,string &curr,string &result){
            if(found) return;
            if(curr.length()==n){
                if(index==nums.size()||curr!=nums[index]){
                    result=curr;
                   found=true;
                }
                index++;
                return;
            }
            for(char ch='0';ch<='1';ch++){
            //do
            curr.push_back(ch);
            //explore
            solve(found,index,nums,n,curr,result);
            //undo
            curr.pop_back();
            }
        }
    
    
    
        string findDifferentBinaryString(vector<string>& nums) {
            int n=nums[0].size();
           sort(nums.begin(),nums.end());
           string result="";
           string curr="";
           int index=0;
           int found=false;
           solve(found,index,nums,n,curr,result);
           return result; 
        }
    };