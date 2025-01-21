class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int c=0;
        int i=0,j=0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        while(i<g.size() && j<s.size())
        {
            if(g[i]<=s[j])
            {
                c++;
                j++;
                i++;
            }
            else
            {
                j++;
            }
            // i++;
        }
        return c;
    }
};