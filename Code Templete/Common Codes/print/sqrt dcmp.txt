//....   ^^||(2h    uI|2({]h   ....//

#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)
#define LL              long long
#define ULL             unsigned long long
#define pb              push_back
#define PI              acos(-1.0)
#define all(a)          a.begin(),a.end()
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define tcase           cout<<"Case "<<C++<<": ";
#define cout3(x,y,z)      cout<<(x)<<" "<<(y)<<" "<<(z)<<" ";
#define cout4(x,y,z,l)      cout<<(x)<<" "<<(y)<<" "<<(z)<<" "<<(l)<<" ";
#define cout5(x,y,z,l,m)      cout<<(x)<<" "<<(y)<<" "<<(z)<<" "<<(l)<<" "<<(m)<<" ";
#define Ln cout<<"\n";
#define SP(x,y)          fixed<<setprecision((y))<<(x)
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(NULL);


int xorcnt[301][1048576];

int extraxor[320];
int blocksize;
int a[100010];
int xorval[100010];
int blockpos[100010];
int blockstart[320];
int blockend[320];
int bp;
int n,m;
void updateblock(int pos,int newval)
{
    int currblock = blockpos[pos];
    int change = newval^a[pos];
    a[pos]= newval;

    for(int i=pos;i<=blockend[currblock];i++)
    {
        xorcnt[currblock] [xorval[i]]--;
        xorval[i] = xorval[i]^change;
        xorcnt[currblock] [xorval[i]]++;
    }
    currblock++;
    while(currblock<=bp)
    {
        extraxor[currblock]= extraxor[currblock]^change;

        currblock++;
    }
}

int query(int pos,int val)
{
    int currblock = blockpos[pos];
    int ret=0;
    for(int i=blockstart[currblock];i<=pos;i++)
    {
//        cout<<"pos ="<<i<<", currblock ="<<currblock<<",extra xor "<<extraxor[currblock]<<", finding ="<<(val^extraxor[currblock])<<"\n";
        if(xorval[i]==(val^extraxor[currblock])) ret++;
  //      cout<<"ret = "<<ret<<"\n";
    }
    currblock--;
    while(currblock>=0)
    {
        ret+= xorcnt[currblock][val^extraxor[currblock]];
        //cout<<"currblock ="<<currblock<<",extra xor "<<extraxor[currblock]<<", finding ="<<(val^extraxor[currblock])<<"\n";
      //  cout<<"ret = "<<ret<<"\n";
        currblock--;
    }

    return ret;
}

int main()
{
    FastRead
    cin>>n>>m;
    blocksize= min(300,(int)sqrt(n)+1);

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        xorval[i]= xorval[i-1]^a[i];
    }

    bp=-1;
    for(int i=1;i<=n;i++)
    {
        if(i%blocksize==1) blockstart[++bp]=i;
        blockend[bp]=i;
        blockpos[i]=bp;
        xorcnt[bp][xorval[i]]++;
    }


    int x,y,z;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        if(x==1) updateblock(y,z);
        else cout<<query(y,z)<<"\n";

    }





}
