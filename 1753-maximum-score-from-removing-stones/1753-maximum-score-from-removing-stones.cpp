class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int moves=0;
        priority_queue<int> pq;
        pq.push(a),pq.push(b),pq.push(c);
        while(pq.size()>1){
            int high = pq.top();
            pq.pop();
            int sec = pq.top();
            pq.pop();
            if((high-1)>0) pq.push(high-1);
            if((sec-1)>0) pq.push(sec-1);
            moves++;
        }
        return moves;
    }
};