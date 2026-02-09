//lc 621

//m1 greedy+heap

// https://youtu.be/rYh-Kkbzsnw?si=6fwab_3o_wWtAmiv

//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      
        unordered_map<char, int> mp;
        
        for(char &ch : tasks) {
            mp[ch]++;
        }

        priority_queue<int> pq; //max heap
        //we want to finish the process which is most occurring (having highest frequency)
        //so that we don't have to finish it in the last with n gaps.
        int time = 0;
        
        for(auto &it : mp) {
            pq.push(it.second);
        }
        
        while(!pq.empty()) {
            vector<int> temp;
            for(int i = 1; i<=n+1; i++) {
                //filling first n+1 characters
                if(!pq.empty()) {
                    int f=pq.top();
                    f--; //finishing one instance of each process
                    temp.push_back(f); 
                    pq.pop();
                }
            }
            
            for(int &freq : temp) {
                if(freq > 0)
                    pq.push(freq);
            }
            
            if(pq.empty()) //all processes finished
                time += temp.size();
            else
                time += (n+1); //we finished n+1 tasks above in the loop
            
        }
        
        return time;
    }
};


// m2 greedy

// https://youtu.be/QDsFBLGL9MM?si=lMBKJhcp52u0RUfm

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        /*
        
        ["A","A","A","B","B","B"], n = 2
        A-3
        b-3
        A _ _ A _ _ A
        Number of chunks     = freq('A')-1 = 2
        Number of idol spots = (Number of chunks)*(n) = 2*2 = 4
            
        Now, we will try to fill these 4 idol spots
        If at the end idol spots is 0, it means all idol spots were enough
        to accomodate all other taks. So, out result will be tasks.size();
        
        If, idol spots are not empty, it means that we need more spaces (equal to idol spots)
        than the tasks.size() to accomodate all tasks.
        So, result = tasks.size() + idol_spots
        
        */
        int s = tasks.size();
      
        int counter[26] = {0};
        for(char &ch : tasks) {
            counter[ch-'A']++;
        }
        
        sort(begin(counter), end(counter));
        
        int chunks      = counter[25]-1;
        int idolSpots   = chunks*n;
        
        for(int i = 24; i>=0 ; i--) {
            idolSpots -= min(chunks, counter[i]);
        }
        
        if(idolSpots > 0)
            return s + idolSpots;
        
        return s;
    }
};