class Solution {
public:
     long long isvalid(pair<int, int>& p1, pair<int, int>& p2, pair<int, int> p3) {
        long long x1 = p1.first;
        long long x2 = p2.first;
        long long x3 = p3.first;
        long long y1 = p1.second;
        long long y2 = p2.second;
        long long y3 = p3.second;
        return (y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>>res;
        sort(begin(trees),end(trees));
        deque<pair<int,int>>lower,upper;
        for(auto &p:trees){
            int l=lower.size();
            int u=upper.size();
            while(l>=2 && isvalid(lower[l-2],lower[l-1],{p[0],p[1]})<0){
                l--;
                lower.pop_back();

            }
            while(u>=2 && isvalid(upper[u-2],upper[u-1],{p[0],p[1]})>0){
                u--;
                upper.pop_back();

            }
            upper.push_back({p[0],p[1]});
            lower.push_back({p[0],p[1]});


        }
        set<pair<int,int>>st;
        for(auto &p:lower){
            st.insert(p);
        }
        for(auto &p:upper){
            st.insert(p);
        }
        for(auto &p:st){
            res.push_back({p.first,p.second});
        }
        return res;
    }
};