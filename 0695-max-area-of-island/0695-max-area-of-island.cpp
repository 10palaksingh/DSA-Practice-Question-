class disjointset{
    public:
    vector<int>size,parent;
    disjointset(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int findpar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findpar(parent[node]);
    }
    void uns(int u,int v){
        int ul_u=findpar(u);
        int ul_v=findpar(v);
        if(ul_u==ul_v) return;
        if(size[ul_u]<size[ul_v]){
            size[ul_v]+=size[ul_u];
            parent[ul_u]=ul_v;
        }
        else{
            parent[ul_v]=ul_u;
            size[ul_u]+=size[ul_v];
        }
        return;
    }
};
class Solution {
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        disjointset ds(m*n);
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                for(int k=0;k<4;k++){
                    int newr=i+dr[k];
                    int newc=j+dc[k];
                    if(newr>=0&&newc>=0&&newr<m&&newc<n&&grid[newr][newc]==1){
                        int nodeno=i*n+j;
                        int adjn=newr*n+newc;
                        ds.uns(nodeno,adjn);
                    }
                }
            }
        }
        int ans=0;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){  
                if(grid[i][j]==1){
                    int newr=i*n+j;
                    ans=max(ans,ds.size[ds.findpar(newr)]);
                }   
            }
            }  
            return ans;
    }
};