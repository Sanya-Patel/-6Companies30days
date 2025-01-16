class Solution {
public:
    struct compare{
        bool operator()(pair<int,string>&a, pair<int,string>&b)
        {
            if(a.first==b.first)
            {
                return a.second>b.second;
            }
            return a.first<b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        map<int,string>mp2;
        for(auto s:words)
        {
            mp[s]++;
        }
        priority_queue<pair<int,string>, vector<pair<int,string>>, compare>pq;
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        vector<string>ans;
        while(k--)
        {
            auto i=pq.top();
            ans.push_back(i.second);
            pq.pop();
        }
        return ans;
    }
};