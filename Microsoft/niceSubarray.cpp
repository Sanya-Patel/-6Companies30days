class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        vector<int>pre(n);
        if(nums[0]%2!=0)
        {
            pre[0]=1;
        }
        else
        {
            pre[0]=0;
        }
        int idx=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]%2!=0)
            {
                pre[i]=pre[i-1]+1;
            }
            else
            {
                pre[i]=pre[i-1]+0;
            }
            // if(idx!=0 && pre[i]==k)
            // {
            //     idx=i;
            // }
        }
        unordered_map<int,int>mp;
        // for(int i=0;i<idx;i++)
        // {
        //     mp[pre[i]]++;
        // }
        for(int i=0;i<n;i++)
        {
            if(pre[i]==k)
            {
                ans++;
            }
            if(mp.find(pre[i]-k)!=mp.end())
            {
                ans+=mp[pre[i]-k];
            }
            mp[pre[i]]++;
        }
        return ans;
    }
};