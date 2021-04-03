#include<bits/stdc++.h>

using namespace std;

#define LCM(a,b)                (a / __gcd(a,b) ) *b
#define GCD(a,b)                __gcd(a,b)
#define dist(x1,y1,x2,y2)       sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define distl(x1,y1,x2,y2)      sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define fRead(x)                freopen(x,"r",stdin)
#define fWrite(x)               freopen (x,"w",stdout)
#define LL                      long long
#define ULL                     unsigned long long
#define pb                      push_back
#define tcase                   cout<<"Case "<<C++<<": ";
#define all(a)                  a.begin(),a.end()
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end
#define ABS(x)                  ((x)<0?-(x):(x))
#define min3(a,b,c)             min(a,min(b,c))
#define min4(a,b,c,d)           min(a,min(b,min(c,d)))
#define max3(a,b,c)             max(a,max(b,c))
#define max4(a,b,c,d)           max(a,max(b,max(c,d)))
#define PI                      acos(-1.0)
#define ff                      first
#define ss                      second
#define SP(x,y)                 fixed<<setprecision((y))<<(x)
#define FastRead                ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(x, l, r)            for (int x = l; x<=r; ++x)
#define REP(x,r)                for (int x = 0; x <r; ++x)
#define NN                      cout<<"\n";
#define NNN                     cout<<"\n------------------------------\n";

//***********************************************************************//
//                      SHAHED AHMED, CSE'15, IUT                        //
//***********************************************************************//

int T[19][100010];
int L[100010];
struct RMQ
{
    RMQ(vector<int>&a)
    {
        int N = a.size();
        L[1]=0; for(int i=2;i<= N;i++)L[i]=L[i/2]+1;

        for (int i=0;i<=L[N];i++)
        {
            int curlen = 1<<i;
            for (int j=1; j<=N;j++)
            {
                if (i==0)
                {
                    T[i][j]=a[j-1]; // O index
                    continue;
                }
                T[i][j] = min(T[i-1][j],T[i-1][j+curlen/2]);
            }
        }
    }

    int getMin(int l, int r)
    {
        l++;r++;    // O index
        int curlog = L[r - l + 1];
        return min(T[curlog][l], T[curlog][r - (1 << curlog) + 1]);
    }
};


int main()
{
    cout<<log2(1000000)*1000000;
    FastRead
    vector<int> v;

    int n;
    cin>>n;
    int x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.pb(x);
    }

    RMQ R(v);
    int q;
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        cout<<R.getMin(x,y)<<"\n";
    }

}
//DSAWWDAW
