class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>>ans;
        int c;
        
        for(int i=0;i<img.size();i++)
        {
            vector<int>v;
            for(int j=0;j<img[i].size();j++)
            {
                c=1;
                int r=img.size();
                int n=img[i].size();
                int upleft=0;
                if(i-1 >=0 && j-1 >=0)
                {
                    upleft=img[i-1][j-1];
                    c++;
                }
                int up=0;
                if(i-1 >=0 && j >=0)
                {
                    up=img[i-1][j];
                    c++;
                }
                int upright=0;
                if(i-1 >=0 && j+1 < n)
                {
                    upright=img[i-1][j+1];
                    c++;
                }
                int left=0;
                if(i >=0 && j-1 >=0)
                {
                    left=img[i][j-1];
                    c++;
                }
                int right=0;
                if(i >=0 && j+1 < n)
                {
                    right=img[i][j+1];
                    c++;
                }
                int downleft=0;
                if(i+1 < r && j-1 >=0)
                {
                    downleft=img[i+1][j-1];
                    c++;
                }
                int down=0;
                if(i+1 < r && j>=0)
                {
                    down=img[i+1][j];
                    c++;
                }
                int downright=0;
                if(i+1 < r && j+1 < n)
                {
                    downright=img[i+1][j+1];
                    c++;
                }

                int temp=upleft+up+upright+left+right+downleft+down+downright+img[i][j];
                int avg=floor(temp/c);

                v.push_back(avg);

            }
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};