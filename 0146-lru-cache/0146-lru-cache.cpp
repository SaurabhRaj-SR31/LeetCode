class LRUCache {
public:

int n;

list<int>dll;

map<int,pair<list<int>::iterator,int>>mpp;

    LRUCache(int capacity) {
        n=capacity;
    }
    void makerecentlyused(int key){
        dll.erase(mpp[key].first);
        dll.push_front(key);
        mpp[key].first=dll.begin();
    }
    int get(int key) {
        if(mpp.find(key)==mpp.end())return -1;
        makerecentlyused(key);
        return mpp[key].second;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            makerecentlyused(key);
            mpp[key].second=value;
        }
        else{
            dll.push_front(key);
            mpp[key]={dll.begin(),value};
            n--;
        }
        if(n<0){
            mpp.erase(dll.back());
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */