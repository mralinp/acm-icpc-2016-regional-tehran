#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    while(1)
    {
        int n; cin>>n;
        if(n==0) break;
        int a[1000];
        double d[1000];
        int k=0;
        for(int i=0;i<n;i++)
        {
            cin >> d[i] >> a[i];
            k+=a[i];
        }
        double m[2001]={0};
        m[0]=1;
        double tmp[2001];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<2001;j++)
                tmp[j] = m[j] * (1 - d[i]);
            for(int j=0;j<2001-a[i];j++)
                tmp[j + a[i]] += (d[i] * m[j]);
            for(int j=0;j<2001;j++)
                m[j] = tmp[j];
        }
        double x=0;
        for(int i=k/2+1;i<=k;i++)
            x+=m[i];
        printf("%.4lf\n", x);
    }
    return 0;
}