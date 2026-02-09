//lc 2558

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long n=gifts.size();
        priority_queue<long long>pq;
        for(long long i=0;i<n;i++){
            pq.push(gifts[i]);
        }
        while(k--){
            long long top=pq.top();
            pq.pop();
          pq.push(floor(sqrt(top)));
        }
        long long sum=0;
    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
    }
    return sum;
    }
};