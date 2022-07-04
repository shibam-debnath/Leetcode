class KthLargest {
public:
    int size = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    // take pq of size k and whenever size>k pop. this remove all k-1 elements and from k to the largest elements will be present in the stack
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(auto &x : nums){
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */