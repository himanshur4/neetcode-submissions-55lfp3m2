class DSU{
    public:
    vector<int>size,parent;
    DSU(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    bool unions(int u,int v){
        int pu=find(u),pv=find(v);
        if(pu==pv) return false;
        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        return true;
    }
    int find(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=find(parent[u]);
    }
};

class Solution {
public:

    bool validTree(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto &e:edges){
            if(!dsu.unions(e[0],e[1])) return false;
        }
        int ct=0;
        for(int i=0;i<n;i++){
            if(dsu.find(i)==i) ct++;
            if(ct>1) return false;
        }
        return true;
    }
};
