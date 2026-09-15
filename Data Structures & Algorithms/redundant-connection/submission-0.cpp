class DSU{
    vector<int> parent,rank;
    public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    bool unite(int a,int b){
        int pa=find(a), pb=find(b);
        if(pa==pb)return false;
        if(rank[pa]>=rank[pb]){
            parent[pb]=pa;
            rank[pa]++;
        }else{
            parent[pa]=pb;
            rank[pb]++;
        }
        return true;

    }
};
class Solution {
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        DSU dsu(edges.size());

        for(auto &e : edges){
            if(!dsu.unite(e[0],e[1]))
                return e;
        }

        return {};
    }
};