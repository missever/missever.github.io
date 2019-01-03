#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include <iostream>
using namespace std;

#define INF 1e5
#define maxn 20
int Graph[maxn][maxn];
int dp[1<<maxn], n, m;
bool no_edge_inside(int s)
{
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        if(s & (1<<i))
            v.push_back(i);
    }
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = i+1; j < v.size(); j++)
            if(Graph[v[i]][v[j]])
            return false;
    }
    return true;
}
int main()
{
  //  freopen("in.txt", "r", stdin);
    cin >> n >> m;
    memset(Graph, 0, sizeof(Graph));
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Graph[a][b] = Graph[b][a] = 1;
    }
    dp[0] = 0;
    for(int s = 1; s < (1<<n); s++)
    {
        dp[s] = INF;
        for(int j = s; j; j = (j-1)&s)
        {

            if(no_edge_inside(j))
                dp[s] = min(dp[s], dp[s-j] + 1);
        }
    }
    cout << dp[(1<<n)-1] << endl;
}
