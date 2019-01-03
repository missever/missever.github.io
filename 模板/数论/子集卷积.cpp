//created by missever

#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
typedef long long LL;

const int maxn = 17,maxm = 1 << 17;
int n;
int bitcnt[maxm];
int a[maxm],b[maxm],c[maxm];
int fa[maxn + 1][maxm],fb[maxn + 1][maxm],fc[maxn + 1][maxm];

void init()
{
    for(int i = 1;i < maxm; i++) bitcnt[i] = bitcnt[i >> 1] + (i & 1);
}

void conv()
{
    int i,j,k;
    for(i = 0;i <= maxn; i++)
    {
        for(j = 0;j < maxm; j++)
        {
            if(i == bitcnt[j])
            {
                fa[i][j] = a[j];
                fb[i][j] = b[j];
            }
            else fa[i][j] = fb[i][j] = 0;
        }

    for(i = 0;i < maxn; i++)
    {
        for(j = 1;j < maxm; j++)
        {
            if((j >> i) & 1)
            {
                for(k = 0;k < bitcnt[j]; k++)
                {
                    fa[k][j] = (fa[k][j] + fa[k][j ^ (1<<i)]) % MAX;
                    fb[k][j] = (fb[k][j] + fb[k][j ^ (1<<i)]) % MAX;
                }
            }
        }
    }
    for(i = 0;i <= maxn; i++)
    {
        for(j = 0;j < maxm; j++)
        {
            fc[i][j] = 0;
            for(k = 0;k <= i; k++) fc[i][j] = (fc[i][j] + 1LL * fa[k][j] * fb[i - k][j] % MAX) % MAX;
        }
    }
    for(i = 0;i < maxn; i++)
    {
        for(j = 1;j < maxm; j++)
        {
            if((j >> i) & 1)
            {
                for(k = 0;k <= maxn; k++) fc[k][j] = (fc[k][j] + fc[k][j ^ (1<<i)]) % MAX;
            }
        }
    }
    for(j = 0;j < maxm; j++) c[j] = fc[bitcnt[j]][j];
}

int main(){

    return 0;
}
