#include<bits/stdc++.h>

using namespace std;

const int N=85;
int n,a[N],dp[N][N][N*N],f[N*N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<int>pos;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]) pos.push_back(i);
    }
    int num=pos.size();
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=num;j++)
        {
            for(int k=0;k<=n*(n-1)/2;k++) dp[i][j][k]=-1e9;
        }
    }
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=min(i,num);j++)
        {
            for(int k=0;k<=n*(n-1)/2;k++)
            {
                for(int ni=0;ni<i;ni++)
                {
                    if(k>=abs(pos[j-1]-i)) dp[i][j][k]=max(dp[i][j][k],dp[ni][j-1][k-abs(pos[j-1]-i)]+(i-ni-1)*(n-i-(num-j)));
                }
                if(j==num) f[k]=max(f[k],dp[i][j][k]);
            }
        }
    }
    for(int i=0;i<=n*(n-1)/2;i++)
    {
        if(i) f[i]=max(f[i-1],f[i]);
        cout<<f[i]<<' ';
    }
}
