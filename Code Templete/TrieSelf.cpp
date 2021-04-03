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
#define mk                      make_pair


//***********************************************************************//
//                      SHAHED AHMED, CSE'15, IUT                        //
//***********************************************************************//


struct node{

        int cnt;
        node* nxt[26];
        node()
        {
                cnt = 0;
                for(int i=0;i<26;i++) nxt[i] = NULL;
        }

} *root;


void insrt(string &s)
{
        node *curr = root;

        for(int i=0;i<s.size();i++)
        {
                if(curr->nxt[s[i]-'a']==NULL) curr->nxt[s[i]-'a'] = new node();
                curr =curr->nxt[s[i]-'a'];
        }
        curr ->cnt++;
}


int finds(string &s)
{
        node *curr = root;
        for(int i=0;i<s.size();i++)
        {
                if(curr->nxt[s[i]-'a']==NULL) return 0;
                curr =curr->nxt[s[i]-'a'];
        }
        return curr->cnt;
}

void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->nxt[i])
            del(cur->nxt[i]);
    delete (cur);
}



int main()
{
        root = new node();

        int n;
        cin>>n;
        string s;
        for(int i=0;i<n;i++)
        {
                cin>>s;
                insrt(s);
        }
        cin>>n;


        for(int i=0;i<n;i++)
        {
                cin>>s;
                cout<<finds(s)<<"\n";
        }
        cout<<"the answer is 1"<<"\n";


}
