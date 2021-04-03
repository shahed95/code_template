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



vector<int> compress (vector<int> a) {
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for (int i=0;i<a.size();i++)
    {
            a[i] = int(lower_bound(b.begin(), b.end(), a[i]) - b.begin());
    }

    return a;
}

struct node
{
    int sum;
} segTree[4*100010];

int md =1000000007;

void update_tree (int updateIndex, int newValue, int rangeLeft, int rangeRight, int index)
{
    if (rangeLeft <= updateIndex && updateIndex <= rangeRight) {
        if (rangeLeft == rangeRight)
        {
            segTree[index].sum += newValue;
            segTree[index].sum%=md;
            return;
        }
        int mid = (rangeLeft + rangeRight) / 2;

        update_tree(updateIndex, newValue, rangeLeft, mid, 2*index);
        update_tree(updateIndex, newValue, mid+1, rangeRight, 2*index+1);

        segTree[index].sum = segTree[2*index].sum + segTree[2*index+1].sum;
        segTree[index].sum%=md;

    }
}

int get_sum(int queryLeft, int queryRight, int rangeLeft, int rangeRight, int index)
{
    if (queryRight < rangeLeft || rangeRight < queryLeft || queryRight < queryLeft)
        return 0;
    if (queryLeft <= rangeLeft && rangeRight <= queryRight)
        return segTree[index].sum;
    int mid = (rangeLeft + rangeRight) / 2;
    return (get_sum(queryLeft, queryRight, rangeLeft, mid, 2*index) + get_sum(queryLeft, queryRight, mid+1, rangeRight, 2*index+1))%md;
}


int main()
{
        FastRead
        int T,C=1;
        cin>>T;
        while(T--)
        {
                int n;
                cin>>n;
                vector<int> v1,v2;
                int x;
                for(int i=0;i<n;i++)
                {
                        cin>>x;
                        v1.pb(x);
                }

                v2 = compress(v1);

                int N= n+3;
                int ans=0;
                for(int i=0;i<n;i++)
                {
                        v2[i]+=2;

                        LL baamechoto = get_sum(1,v2[i]-1,1,N,1);
                        ans += baamechoto+1;
                        ans%=md;
                        //cout<<baamechoto+1<<" ,";
                        update_tree(v2[i],baamechoto+1,1,N,1);
                }

                tcase cout<<ans<<"\n";

                memset(segTree, 0, sizeof segTree);



        }

}
