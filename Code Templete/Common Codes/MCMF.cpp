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
// Min-cost max-flow (uses Dijkstra's algorithm)
//
// Given a directed weighted graph, source, and sink, computes the minimum cost
// of the maximum flow from source to sink.
// This version uses Dijkstra's algorithm and gives good performance on all
// kinds of graphs.
//
// To use, call init(n), then add edges using edge(x, y, c, w), and finally
// call run(src, sink).
//
// Functions:
// - init(n) initializes the algorithm with the given number of nodes
// - edge(x, y, c, w) adds an edge x->y with capacity c and weight w
// - run(src, sink) runs the algorithm and returns {total_cost, total_flow}
//
// Time complexity: O(V * E^2 log E)
//
// Constants to configure:
// - MAXV is the maximum number of vertices
// - MAXE is the maximum number of edges (i.e. twice the calls to function edge)
// - oo is the "infinity" value


const int MAXV = 1000100;
const int MAXE = 1000100;
const LL oo = 1e18;

int V, E;
int last[MAXV], how[MAXV];
LL dist[MAXV], pi[MAXV];
int nxt[MAXE], from[MAXE], adj[MAXE];
LL cap[MAXE], cost[MAXE];

struct cmpf
{
    bool operator () (int a, int b)
    {
        if (dist[a] != dist[b]) return dist[a] < dist[b];
        return a < b;
    }
};
set<int, cmpf> S;

void init(int n)
{
    V = n;
    E = 0;
    REP(i, V) last[i] = -1;
}

void edge(int x, int y, LL c, LL w)
{
    from[E] = x;
    adj[E] = y;
    cap[E] = c;
    cost[E] = +w;
    nxt[E] = last[x];
    last[x] = E++;
    from[E] = y;
    adj[E] = x;
    cap[E] = 0;
    cost[E] = -w;
    nxt[E] = last[y];
    last[y] = E++;
}

pair<LL, LL> run(int src, int sink)
{
    LL total = 0;
    LL flow = 0;

    REP(i, V) pi[i] = oo;
    pi[src] = 0;

    for (;;)
    {
        bool done = true;
        REP(x, V) for (int e = last[x]; e != -1; e = nxt[e])
            if (cap[e] && pi[adj[e]] > pi[x] + cost[e])
                pi[adj[e]] = pi[x] + cost[e], done = false;
        if (done) break;
    }

    for (;;)
    {
        REP(i, V) dist[i] = oo;
        S.clear();

        dist[src] = 0;
        S.insert(src);

        while (!S.empty())
        {
            int x = *S.begin();
            S.erase(S.begin());
            if (x == sink) break;

            for (int e = last[x]; e != -1; e = nxt[e])
            {
                if (cap[e] == 0) continue;

                int y = adj[e];
                LL val = dist[x] + pi[x] + cost[e] - pi[y];

                if (val < dist[y])
                {
                    S.erase(y);
                    dist[y] = val;
                    how[y] = e;
                    S.insert(y);
                }
            }
        }
        if (dist[sink] >= oo / 2) break;

        LL aug = cap[how[sink]];
        for (int i = sink; i != src; i = from[how[i]])
            aug = min(aug, cap[how[i]]);

        for (int i = sink; i != src; i = from[how[i]])
        {
            cap[how[i]] -= aug;
            cap[how[i]^1] += aug;
            total += cost[how[i]] * aug;
        }
        flow += aug;

        REP(i, V) pi[i] = min(pi[i] + dist[i], oo);
    }

    return {total, flow};
}


vector<int>nodes[300];
int dd[300];
int main()
{

        int T;
        //cin>>T;
        while(T--)
        {

        int n,d;

        scanf("%d %d",&n,&d);

        vector<pair<char,int> > v;

        char x;
        int y;
        int nd=2;

        for(int i=0;i<n;i++)
        {
                scanf(" %c-%d",&x,&y);
                //cout<<x<<"-"<<y<<"\n";
                dd[i]=y;

                if(x=='B')
                {
                        nodes[i].pb(nd++);
                }

                else
                {
                        nodes[i].pb(nd++);
                        nodes[i].pb(nd++);
                        edge(nd-2,nd-1,1,0);
                }

        }

        for(int i=0;i<n;i++)
        {
                cout<<nodes[i][0]<<", "<<dd[i]<<"\n";
        }

        }


}

