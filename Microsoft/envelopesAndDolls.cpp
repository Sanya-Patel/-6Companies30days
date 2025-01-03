class Solution {
public:
    int solve(vector<vector<int>>& env, int prev, int i)
    {
        if(i==env.size())
        {
            return 0;
        }
        int include=INT_MIN;
        if(prev==-1 || env[prev][0]<env[i][0] && env[prev][1]<env[i][1])
        {
            include=1+solve(env,i,i+1);
        }
        int exclude=0+solve(env,prev,i+1);

        return max(include,exclude);
    }
    int solveMem(vector<vector<int>>&env, int prev, int i, vector<vector<int>>&dp)
    {
        if(i==env.size())
        {
            return 0;
        }
        if(dp[prev+1][i]!=-1)
        {
            return dp[prev+1][i];
        }
        int include=INT_MIN;
        if(prev==-1 || env[prev][0]<env[i][0] && env[prev][1]<env[i][1])
        {
            include=1+solveMem(env,i,i+1,dp);
        }
        int exclude=0+solveMem(env,prev,i+1,dp);

        return dp[prev+1][i]=max(include,exclude);
    }
    static bool comp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0]; 
    }
    int solveBS(vector<vector<int>>&nums)
    {
        sort(nums.begin(),nums.end(),comp);
        if(nums.size()==0)
        {
            return 0;
        }
        vector<int>ans;
        ans.push_back(nums[0][1]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i][1]>ans.back())
            {
                ans.push_back(nums[i][1]);
            }
            else
            {
                int index=lower_bound(ans.begin(),ans.end(),nums[i][1])-ans.begin();
                ans[index]=nums[i][1];
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort(envelopes.begin(),envelopes.end());
        // return solve(envelopes,-1,0);

        // vector<vector<int>>dp(envelopes.size()+1,vector<int>(envelopes.size(),-1));
        // return solveMem(envelopes,-1,0,dp);

        return solveBS(envelopes);
        
    }
};