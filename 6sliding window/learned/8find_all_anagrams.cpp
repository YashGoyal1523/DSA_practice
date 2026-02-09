//lc 438


//approach- p ke size jitne size ke har subarray ko check krlo
//to check - dono mein characters with their freq compare krlo ... if same then yes else no

//fixed size sliding window

// tarika 1 : do freq map
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int>ans;

//         if(s.size()<p.size()) return ans;

//         int k=p.size();
//         //freq map of p
//         vector<int>freqp(26,0);
//         for(int i=0;i<k;i++) freqp[p[i]-'a']++;

//         vector<int>freqs(26,0); //freq map of s
//         //first window
//         for(int i=0;i<k;i++) freqs[s[i]-'a']++;
//         if(freqp==freqs) ans.push_back(0);
//        //remaining windows
//         int j=k;
//         while(j<s.size()){
//             // add new element
//             freqs[s[j]-'a']++;
//             // remove old element
//             freqs[s[j-k]-'a']--;
//             //check
//            if(freqp==freqs) ans.push_back(j-k+1);
//            //aage bhado
//            j++;
//         }

//         return ans;

     
//     }
// };

//tarika 2 : ek freq map

class Solution {
public:
bool allzero( vector<int>&freq){
    for(int i=0;i<freq.size();i++){
        if(freq[i]!=0) return false;
    }
    return true;
}
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;

        if(s.size()<p.size()) return ans;

        int k=p.size();
        
        vector<int>freq(26,0);
        for(int i=0;i<k;i++) freq[p[i]-'a']++;

        //first window
        for(int i=0;i<k;i++) freq[s[i]-'a']--;
        if(allzero(freq)) ans.push_back(0);
       //remaining windows
        int j=k;
        while(j<s.size()){
            // new element daalo
            freq[s[j]-'a']--;
            // old element hatao
            freq[s[j-k]-'a']++;
            //check
           if(allzero(freq)) ans.push_back(j-k+1);
           //aage bhado
           j++;
        }

        return ans;

     
    }
};