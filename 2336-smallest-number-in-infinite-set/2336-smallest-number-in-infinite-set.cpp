class SmallestInfiniteSet {
public:
    
    vector<int> v;
    SmallestInfiniteSet() {
        for(int i =1;i<1001;i++) v.push_back(i);
    }
    
    int popSmallest() {
        sort(v.begin(),v.end());
        auto it = v.begin();
        int res=*it;
        v.erase(it);
        return res;
    }
    
    void addBack(int num) {
        auto it=v.begin();
        it = find(v.begin(),v.end(),num);
        // not found 
        if(it==v.end()){
            v.push_back(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */