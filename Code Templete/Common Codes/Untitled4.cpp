#include <bits/stdc++.h>

#define LCM(a,b)                (a / __gcd(a,b) ) *b
#define GCD(a,b)                __gcd(a,b)
#define dist(x1,y1,x2,y2)       sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define distl(x1,y1,x2,y2)      sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define fRead(x)                freopen(x,"r",stdin)
#define fWrite(x)               freopen (x,"w",stdout)
#define LL                      long long
#define ULL                     unsigned long long
#define pb                      push_back
#define tcase                   cout<<"Case #"<<C++<<": ";
#define all(a)                  a.begin(),a.end()
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end
#define ABS(x)                  ((x)<0?-(x):(x))
#define min3(a,b,c)             min(a,min(b,c))
#define min4(a,b,c,d)           min(a,min(b,min(c,d)))
#define max3(a,b,c)             max(a,max(b,c))
#define max4(a,b,c,d)           max(a,max(b,max(c,d)))
#define ff                      first
#define ss                      second
#define SP(x,y)                 fixed<<setprecision((y))<<(x)
#define FastRead                ios_base::sync_with_stdio(0);cin.tie(NULL);
#define NN                      cout<<"\n";
#define NNN                     cout<<"\n------------------------------\n";


#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
using namespace std;


const int mod = 1e9+7;
const int MAXN = 12010;
int AN;
int A[3 * MAXN + 100];
int cnt[MAXN + 1];
int SA[MAXN + 1];
int LCP[MAXN + 1]={0};
struct SuffixArray {

    void radix_pass(int* A, int AN, int* R, int RN, int* D) {
        memset(cnt, 0, sizeof(int) * (AN + 1));
        int* C = cnt + 1;
        for (int i = 0; i < RN; i++) ++C[A[R[i]]];
        for (int i = -1, v = 0; i <= AN && v < RN; v += C[i++]) swap(v, C[i]);
        for (int i = 0; i < RN; i++) D[C[A[R[i]]]++] = R[i];
    }

    void suffix_array(int* A, int AN) {
        if (!AN)
            SA[0] = 0;
        else if (AN == 1) {
            SA[0] = 1;
            SA[1] = 0;
            return;
        }

        int RN = 0;
        int* SUBA = A + AN + 2;
        int* R = SUBA + AN + 2;
        for (int i = 1; i < AN; i += 3) SUBA[RN++] = i;
        for (int i = 2; i < AN; i += 3) SUBA[RN++] = i;
        A[AN + 1] = A[AN] = -1;
        radix_pass(A + 2, AN - 2, SUBA, RN, R);
        radix_pass(A + 1, AN - 1, R, RN, SUBA);
        radix_pass(A + 0, AN - 0, SUBA, RN, R);

        int resfix, resmul, v;
        if (AN % 3 == 1) {
            resfix = 1;
            resmul = RN >> 1;
        }
        else {
            resfix = 2;
            resmul = RN + 1 >> 1;
        }
        for (int i = v = 0; i < RN; i++) {
            v += i && (A[R[i - 1] + 0] != A[R[i] + 0] || A[R[i - 1] + 1] != A[R[i] + 1] || A[R[i - 1] + 2] != A[R[i] + 2]);
            SUBA[R[i] / 3 + (R[i] % 3 == resfix) * resmul] = v;
        }

        if (v + 1 != RN) {
            suffix_array(SUBA, RN);
            SA[0] = AN;
            for (int i = 1; i <= RN; i++)
                SA[i] = SA[i] < resmul ? 3 * SA[i] + (resfix==1?2:1) : 3 * (SA[i] - resmul) + resfix;
        }
        else {
            SA[0] = AN;
            memcpy(SA + 1, R, sizeof(int) * RN);
        }

        int NMN = RN;
        for (int i = RN = 0; i <= NMN; i++)
            if (SA[i] % 3 == 1)
                SUBA[RN++] = SA[i] - 1;

        radix_pass(A, AN, SUBA, RN, R);

        for (int i = 0; i <= NMN; i++)
            SUBA[SA[i]] = i;

        int ii = RN - 1;
        int jj = NMN;
        int pos;
        for (pos = AN; ii >= 0; pos--) {
            int i = R[ii];
            int j = SA[jj];
            int v = A[i] - A[j];
            if (!v)
                if (j % 3 == 1)
                    v = SUBA[i + 1] - SUBA[j + 1];
                else {
                    v = A[i + 1] - A[j + 1];
                    if (!v) v = SUBA[i + 2] - SUBA[j + 2];
                }
            SA[pos] = v < 0 ? SA[jj--] : R[ii--];
        }
    }

    void prep_string(string &s) {
        int v = 0;
        AN = s.size();
        memset(cnt, 0, 256 * sizeof(int));
        for (int i = 0; i < AN; i++) cnt[s[i]]++;
        for (int i = 0; i < 256; i++) cnt[i] = cnt[i] ? v++ : -1;
        for (int i = 0; i < AN; i++) A[i] = cnt[s[i]];
    }

    int REVSA[MAXN + 1];
    void compute_reverse_sa() {
        for (int i = 0; i <= AN; i++) REVSA[SA[i]] = i;
    }


    void compute_lcp() {
        int len = 0;
        for (int i = 0; i < AN; i++, len = max(0, len - 1)) {
            int s = REVSA[i];
            int j = SA[s - 1];
            for (; i + len < AN && j + len < AN && A[i + len] == A[j + len]; len++);
            LCP[s] = len;
        }
    }


    void Construct(string &s) {
        prep_string(s);
        suffix_array(A, AN);
        compute_reverse_sa();
        compute_lcp();
    }


};

int T[22][MAXN];
int L[MAXN];


struct RMQ
{
    RMQ(int x)
    {
        int N = AN;
        L[1]=0; for(int i=2;i<= N;i++)L[i]=L[i/2]+1;

        for (int i=0;i<=L[N];i++)
        {
            int curlen = 1<<i;
            for (int j=1; j<=N;j++)
            {
                if (i==0)
                {
                    T[i][j]=LCP[j-1]; // O index
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

int pos[MAXN];
string a,s="";

int main() {
    /*
    string a = "abcdabcd";
    SuffixArray sa(a, 256);
    PR0(sa.SA, sa.SA.size()); // 4 0 5 1 6 2 7 3
    PR0(sa.LCP, sa.LCP.size()); // 0 4 0 3 0 2 0 1
    */

    FastRead

    char jora = '#';
    int tots=0;
    int sz=0;
    int m;
    cin>>m;
    while(m--)
    {
        cin>>a;
        for(auto &u:a) {s+=u;pos[sz]=tots;sz++;}
        s+=jora;
        pos[sz]=tots;
        sz++;

        jora++;
        tots++;
    }
    cout<<s<<"\n";
    for(auto u:pos) cout<<u;

    SuffixArray sa;
    sa.Construct(s);
    RMQ rmq(5);
    int ans=0;

    vector<int> lastpos(tots,-1);

    set<pair<int,int> > st;

    for(int i=0;i<AN;i++)
    {
        //cout<<s.substr(SA[i])<<"\n";

        int sno= pos[SA[i]];

        if(lastpos[sno]==-1)
        {
            lastpos[sno]=i;
            st.insert({lastpos[sno],sno});
        }
        else
        {
            st.erase({lastpos[sno],sno});
            lastpos[sno]=i;
            st.insert({lastpos[sno],sno});
        }

        if(st.size()==tots)
        {

            int apos = st.begin()->ff;
            int bpos = st.rbegin()->ff;

            ans=max(ans,rmq.getMin(apos+1,bpos));
        }

        /*
        if(SA[i]<a.size()) apos=i;
        else bpos=i;

        //cout<<"apos ="<<apos<<" bpos="<<bpos<<"\n";
        if(apos!=-1&&bpos!=-1)
        {
            ans=max(ans,rmq.getMin(min(apos,bpos)+1,max(apos,bpos)));
        }
        */
    }
    cout<<ans;



}
