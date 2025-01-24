vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int d=0,xr=0,r,a=0,m,c=0,x=0,y=0;
        vector<int>v(2);
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            xr^=arr[i];
            d^=(i+1);
        }
        r=xr^d;
        d=r&(-r);
        for(int i=0;i<n;i++)
        {
            if((arr[i]&d)!=0)
            x^=arr[i];
            else
            y^=arr[i];
        }
        for(int t=1;t<=n;t++)
        {
            if((t&d)!=0)
            x^=t;
            else
            y^=t;
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]==x)
            c++;
        }
        if(c==0)
        {
            v[0]=y;
            v[1]=x;
        }
        else
        {
            v[0]=x;
            v[1]=y;
        }
        return v;
    }