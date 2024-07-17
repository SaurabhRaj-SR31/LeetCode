class SmallestInfiniteSet {
public:
  int cur;
set<int>st;
    SmallestInfiniteSet() {
        cur=1;
    }
    
    int popSmallest() {
        int res;
        if(!st.empty()){
            res=*st.begin();
            
            st.erase(res);
        }else{
            res=cur;
            cur+=1;
        }
        return res;
    }
    
    void addBack(int num) {
        if(num>=cur || st.find(num)!=st.end())return;
        st.insert(num);
      
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */