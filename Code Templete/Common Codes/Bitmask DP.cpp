#include<bits/stdc++.h>

using namespace std;

#define LL              long long


int Set(int N,int pos) return N=N | (1<<pos);
bool check(int N,int pos) return (bool)(N & (1<<pos));


LL n;

LL gc[22][22];

LL dp[11][(1<<20)+2];

LL call(int pos, int mask)
{
        if(pos==n) return 0;

        if(dp[pos][mask]!=-1) return dp[pos][mask];

        LL ans=0;

        for(int i=0; i<n; i++)
        {
                if(check(mask,i)!=0) continue;

                for(int j=i+1;j<n;j++)
                {
                        if(check(mask,j)!=0) continue;
                        ans = max(ans,call(pos+1,Set(mask,i)|Set(mask,j))+gc[i][j]*(pos+1));

                }
        }

        return dp[pos][mask]=ans;

}

LL a[22];

int main()
{
        memset(dp,-1,sizeof dp);

        cin>>n;
        n=2*n;

        for(int i=0;i<n;i++)
        {
                cin>>a[i];
        }

        for(int i=0;i<n;i++)
        {
                for(int j=i+1;j<n;j++)
                {
                        gc[i][j] = __gcd(a[i],a[j]);
                }
        }

        cout<<call(0,0);
}
