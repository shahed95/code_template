#include<bits/stdc++.h>



using namespace std;
#define vi vector<int>
#define sz(a) (a).size()
#define rep(i,a,b)        for(int i=a;i<=b;i++)

vi pi(const string& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

vi match(const string& s, const string& pat) {
	vi p = pi(pat + '\0' + s), res;
	rep(i,sz(p)-sz(s),sz(p))
		if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
	return res;
}


int main()
{
        string a,b;
        cin>>a;

        vector<>
        /*
        cin>>a>>b;

        vector<int> ans = match(a,b);


        for(int i=0;i<ans.size();i++)
        {
                cout<<ans[i]<<"\n";
        }
        */




}
