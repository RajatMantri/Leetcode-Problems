class Solution {
public:
    int countCoveredBuildings(int m, vector<vector<int>>& b) {
        map<int,int> fx;
        map<int,int> lx;

        map<int,int> fy;
        map<int,int> ly;

        int count=0;

        for(auto&i:b){
            int x=i[0],y=i[1];

            if(fx.count(x)) fx[x]=min(fx[x],y);
            else fx[x]=y;

            if(fy.count(y)) fy[y]=min(fy[y],x);
            else fy[y]=x;

            if(lx.count(x)) lx[x]=max(lx[x],y);
            else lx[x]=y;

            if(ly.count(y)) ly[y]=max(ly[y],x);
            else ly[y]=x;
        }

        for(auto&i:b){
            int x=i[0],y=i[1];

            if(fx[x]<y&&y<lx[x]&&fy[y]<x&&x<ly[y]) count++;
        }
        return  count;
    }
};