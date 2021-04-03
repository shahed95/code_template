#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
template <typename T> inline T BigMod(T A,T B,T M = MOD){T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}

const long long  N = 200000; // Max value

long long fact[N+5];     //  n!
long long invfact[N+5];  // 1/n!

void func()
{
    fact[0]=1;
    invfact[0] = BigMod(fact[0],MOD-2LL,MOD);

    for(int i =1;i<=N;i++)
    {
        fact[i] = (fact[i-1] * i)%MOD;
        invfact[i] = BigMod(fact[i],MOD-2LL,MOD); // this line takes O(logM)time (M= MOD), don't pre-calculate it if N is large (N>1000000)
    }
}


long long ncr(long long n, long long r)
{
    long long lob = fact[n];
    long long hor = (invfact[n-r]*invfact[r])%MOD; // calculate invfact here if N is large
    long long ans = (lob*hor)%MOD;
    return ans;
}


int main()
{
    func();
    long long n,r;
    cin>>n>>r;
    cout<<ncr(n,r);
}

