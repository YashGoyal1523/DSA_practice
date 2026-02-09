//lc 1233

class Solution {
public:

bool subfolder(string prev,string curr){
    int n=prev.size();
    string prefix=curr.substr(0,n);

    if(prefix==prev&&curr[n]=='/') return true;

    return false;
}

    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>ans;
        ans.push_back(folder[0]);
        string prev=folder[0];
        for(int i=1;i<folder.size();i++){
            if(!subfolder(prev,folder[i])){
                ans.push_back(folder[i]);
                prev=folder[i];
            }
        }

        return ans;

    }
};