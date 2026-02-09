//lc 2434

// https://youtu.be/NUMNPFel73Q?si=BBNwklViPcdhMbca
class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();

        vector<char> minCharToRight(n); //you can store index of those characters instead of storing characters

        minCharToRight[n-1] = s[n-1];
        for(int i = n-2; i >= 0; i--) {
            minCharToRight[i] = min(s[i], minCharToRight[i+1]);
        }


        string t = "";
        string paper = "";

        int i = 0; 
        while(i < n) {
            t.push_back(s[i]);

            char minChar = (i+1 < n) ? minCharToRight[i+1] : '/';

            while(!t.empty() &&(minChar=='/'||t.back() <= minChar)) {
                paper += t.back();
                t.pop_back();
            }

            i++;
        }

       

        return paper;
    }
};


// yeh string t ki jagah stack use kr skte....same functionality hi krre