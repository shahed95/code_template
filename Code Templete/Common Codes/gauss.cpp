#include<bits/stdc++.h>

using namespace std;

double g[5][5];

void gauss(int n)   // input: N * (N + 1) Matrix
{
    for (int i = 1; i <= n; ++i)
    {
        double temp = 0;
        int pos = -1;
        for (int j = i; j <= n; ++j)
        {
            if (fabs(g[j][i]) > temp) temp = fabs(g[j][i]), pos = j;
        }
        if (pos == -1) continue;
        for (int k = 1; k <= n + 1; ++k) swap(g[pos][k], g[i][k]);
        temp = g[i][i];
        for (int k = 1; k <= n + 1; ++k) g[i][k] /= temp;
        for (int j = i + 1; j <= n; ++j)
        {
            temp = g[j][i];
            for (int k = 1; k <= n + 1; ++k) g[j][k] -= temp * g[i][k];
        }
    }
    for (int i = n; i >= 1; --i)
    {
        for (int j = 1; j < i; ++j)
        {
            g[j][n + 1] -= g[i][n + 1] * g[j][i];
            g[j][i] = 0;
        }
    }


}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n+1; j++)
        {
            cin>>g[i][j];
        }
    }
    gauss(n);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n+1; j++)
        {
            cout<<g[i][j]<<" ";
        }
    }
}
