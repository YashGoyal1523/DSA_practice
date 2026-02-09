//lc 846


//m1 min heap
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<hand.size();i++){
            pq.push(hand[i]);
        }
        while(!pq.empty()){
            int prev=pq.top();
            pq.pop();
            vector<int>temp;
            int cnt=1;
            while(cnt<groupSize){
                if(pq.empty()||pq.top()>prev+1) return false;
                if(pq.top()==prev){
                    temp.push_back(pq.top());
                    pq.pop();
                }
                else {
                    prev=pq.top();
                    pq.pop(); 
                    cnt++;
                }
                
            }
            for(int i=0;i<temp.size();i++){
                pq.push(temp[i]);
            }
        }
        return true;
    }
};


//m2 map
// https://youtu.be/lpVhzcdiHMs?si=XQ0QzoB5p5LbuaP0

//tarika 1
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize) {
            return false;
        }

        map<int, int> mp;
        for(int &handNumber : hand) {
            mp[handNumber]++; 
        }

        while(!mp.empty()) { 

            int curr = mp.begin()->first; 
            mp[curr]--;
                if(mp[curr]==0) {
                    mp.erase(curr);
                }
            curr++;
            for(int cnt = 1; cnt < groupSize; cnt++) {
                
                if(mp[curr] == 0) {
                    return false;
                }
                mp[curr]--;
                if(mp[curr]==0) {
                    mp.erase(curr);
                }
                curr++;
                
            }

        }

        return true;
        
    }
};

//tarika 2

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize) {
            return false;
        }

        map<int, int> mp;
        for(int &handNumber : hand) {
            mp[handNumber]++; //O(nlogn)
        }

        while(!mp.empty()) { //O(n*groupSize)

            int curr = mp.begin()->first; //->second : frequency

            for(int i = 0; i < groupSize; i++) {
                if(mp[curr + i] == 0) {
                    return false;
                }

                mp[curr+i]--;
                if(mp[curr+i] < 1) {
                    mp.erase(curr+i);
                }
            }

        }

        return true;
        
    }
};