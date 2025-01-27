string encode(string s) {
        // code here
        int n=s.size();
        int c=1;
        string ans="";
        ans=s[0];
        for(int i=0;i<n-1;i++)
        {
            if(s[i+1]==s[i])
            {
                c++;
            }
            else
            {
                ans+=to_string(c);
                c=1;
                ans+=s[i+1];
            }
        }
        ans+=to_string(c);
        return ans;
    }