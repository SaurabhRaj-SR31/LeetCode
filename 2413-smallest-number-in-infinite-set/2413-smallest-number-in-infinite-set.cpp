class SmallestInfiniteSet {
public:priority_queue<int,vector<int>,greater<int>>q;
int cur;
set<int>st;
    SmallestInfiniteSet() {
        cur=1;
    }
    
    int popSmallest() {
        int res;
        if(!q.empty()){
            res=q.top();
            q.pop();
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
        q.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */