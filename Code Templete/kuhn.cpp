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
#define REP(x,r)               for (int x = 0; x <r; ++x)
#define NN                      cout<<"\n";
#define NNN                     cout<<"\n------------------------------\n";

//***********************************************************************//
//                      SHAHED AHMED, CSE'15, IUT                        //
//***********************************************************************//

// kuhn

const int maxn = 100010;

vector<int> ad[maxn];
int mt[maxn];
bool used[maxn];

bool kuhn (int v) {
    if (used[v]) return 0;
    used[v] = 1;
    for (int u : ad[v]) {
        if (mt[u] == -1 || kuhn(mt[u])) {
            mt[u] = v;
            return 1;
        }
    }
    return 1;
}

int main()
{
        int n;
        int cnt=0;
        cin>>n;



        int x,y;
        for(int i=1;i<n;i++)
        {
                cin>>x>>y;
                ad[x].pb(y);
        }
        memset(mt, -1, sizeof(mt));

        for (int i = 1; i <=n; i++) {
            memset(used, 0, sizeof(mt));
            if (kuhn(i)) cnt++;
        }

        cout<<cnt;

}
