#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define pb              push_back
#define PI              acos(-1.0)
#define pii             pair<int,int>
#define pll             pair<LL,LL>
#define all(a)          a.begin(),a.end()
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))


#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);
const LL MOD = 1e9 + 7;
template <typename T> inline T BigMod(T A,T B,T M = MOD){T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}

vector<int> v;

int sz;

LL dp[32][32][2][2];

void getdig(LL a)
{
    v.clear();
    while(a>0)
    {
        v.pb(a%10);
        a/=10;
    }
    reverse(all(v));

    sz=v.size();
}

// start==1 means starting position, so no zero , zero nile next ta re starting position chinta kore call dei
// flag==1 means upper limit v[index] porjonto
LL digitdp(int pos, int cnt,int start,int flag)
{
    if(pos==sz) return cnt;

    if(dp[pos][cnt][start][flag]!=0&& flag!=1) return dp[pos][cnt][start][flag];

    int k;
    LL ret=0;
    if(flag) k=v[pos];
    else k=9;

    if(start)
    {
        for(int i=1;i<=k;i++)
        {
            ret+= digitdp(pos+1,cnt+(i==0?1:0) ,0, (i==v[pos]?flag:0) );
        }
        ret+= digitdp(pos+1,0,1,0);
    }
    else
    {
        for(int i=0;i<=k;i++)
        {
            ret+= digitdp(pos+1,cnt+(i==0?1:0),0,(i==v[pos]?flag:0));
        }
    }

    if(!flag) dp[pos][cnt][start][flag]=ret;
    return ret;

}


int main()
{
//    FastRead
    int T;
    int C=1;
    cin>>T;
    while(T--)
    {
        LL a,b;
        cin>>a>>b;

        memset(dp,0,sizeof dp);
        getdig(a-1);
        LL x = digitdp(0,0,1,1);

        memset(dp,0,sizeof dp);
        getdig(b);
        LL y = digitdp(0,0,1,1);
        cout<<"Case "<<C++<<": "<<y-x+(a==0?1:0)<<"\n";

    }


}
