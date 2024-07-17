class SmallestInfiniteSet {
public:
vector<bool>arr;
int i=0;

    SmallestInfiniteSet() {
        arr=vector<bool>(1001,true);
        i=1;
    }
    
    int popSmallest() {
        int res=i;
        arr[i]=false;
        for(int j=i+1;j<1001;j++){
            if(arr[j]==true){
                i=j;break;
            }
        }



        return res;
    }
    
    void addBack(int num) {
        arr[num]=true;
        if(num<i){
            i=num;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */