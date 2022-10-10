class SmallestInfiniteSet {
public:
    
    set<int> v;
    int start=1;
    SmallestInfiniteSet() {
    }
    
    int popSmallest() {
        // if set has elements means there we have the smallest
        if(v.size()>0){
            int it = *v.begin();
            v.erase(it);
            return it;
        }
        int ret=start;
        start++;
        return ret;
    }
    
    void addBack(int num) {
        if(num<start) v.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */