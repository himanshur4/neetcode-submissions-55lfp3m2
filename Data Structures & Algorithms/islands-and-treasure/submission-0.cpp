typedef tuple<int,int,int> ti;
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<ti>q;
        int m=grid.size(),n=grid[0].size();
        vector<int>dirs={-1,0,+1,0,-1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j,0});
                }
            }
        }
        while(!q.empty()){
            auto[r,c,dis]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dirs[i],nc=c+dirs[i+1];
                if(nr>=0&&nc>=0&&nr<m&&nc<n&&grid[nr][nc]!=-1&&grid[nr][nc]>dis+1){
                    q.push({nr,nc,dis+1});
                    grid[nr][nc]=dis+1;
                }
            }
        }
    }
};
