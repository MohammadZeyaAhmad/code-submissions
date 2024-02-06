//Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

class Solution {
public:
    int dis(vector<int> x,vector<int> y){
        return (x[0]-y[0])*(x[0]-y[0])+(x[1]-y[1])*(x[1]-y[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> st;
        st.insert(dis(p1,p2));
        st.insert(dis(p1,p3));
        st.insert(dis(p1,p4));
        st.insert(dis(p2,p3));
        st.insert(dis(p2,p4));
        st.insert(dis(p3,p4));
        if (st.size()==2){
            for (auto val: st){
                if (val==0)return false;
            }
            return true;
        }
        return false;
    }
};
