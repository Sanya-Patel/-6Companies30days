class Solution {
public:
    bool isValid(int i,int j,int m,int n,vector<vector<int>>& grid)
    {
        if(i>=0 && i<m && j>=0 && j<n && grid[i][j]==1)
        {
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0,time=0;

        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        if(fresh==0)
        {
            return 0;
        }

        while(!q.empty())
        {
            int sz=q.size();
            while(sz>0)
            {
                auto p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                int xi[4]={1,-1,0,0};
                int yj[4]={0,0,1,-1};
                for(int k=0;k<4;k++)
                {
                    if(isValid(i+xi[k],j+yj[k],m,n,grid))
                    {
                        grid[i+xi[k]][j+yj[k]]=2;
                        q.push({i+xi[k],j+yj[k]});
                        fresh--;
                    }
                }
                sz--;
            }
            time++;
        }
        if(fresh!=0)
        {
            return -1; 
        }
        return time-1;
    }
};