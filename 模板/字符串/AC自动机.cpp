//created by missever

#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;

const int csize = 4;
const int maxn = 1e5 + 5;
int f[maxn][csize + 1];//csize为当前结点fail指针
int m;
int val[maxn];
char ss[maxn];

void insert(char *s)
{
    int l = strlen(s);
    int i,c,t = 1;
    for(i = 0; i < l; i++)
    {
        c = s[i] - 'a';
        if(!f[t][c])
        {
            memset(f[m],0,sizeof(f[m]));
            f[t][c] = m++;
        }
        t = f[t][c];
    }
    val[t] = 1;
}

queue<int>q;
void build()
{
    int u,v,i;
    q.push(1);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
		//val[u] |= val[f[u][csize]]; 不合法字符标记的转移
        for(i = 0; i < csize; i++)
        {
            if(f[u][i])
            {
                v = f[u][csize];
                while(v && !f[v][i]) v = f[v][csize];
                f[f[u][i]][csize] = v ? f[v][i] : 1 ;
                q.push(f[u][i]);
            }
            else f[u][i] = (u != 1) ? f[f[u][csize]][i] : 1 ;
        }
    }
}

int main()
{

    return 0;
}
