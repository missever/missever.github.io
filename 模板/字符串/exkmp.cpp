//created by missever

#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;

const int nn = 100005;
int pa[nn],pb[nn];//a,bµÄÆ¥Åä½á¹û
char a[nn],b[nn];

void exkmp()
{
    int i,j,k,m,n;
    int len,l;
    m = n = strlen(b);
    for(j = 0;j + 1 < m && a[j] == a[1 + j]; j++);
    pa[1] = j;
    for(i = 2,k = 1;i < m; i++)
    {
        len = k + pa[k];
        l = pa[i - k];
        if(l + i < len) pa[i] = l;
        else
        {
            for(j = max(0,len - i);i + j < m && a[j] == a[i + j]; j++);
            pa[i] = j;
            k = i;
        }
    }
    for(j = 0;j < n && j < m && a[j] == b[j]; j++);
    pb[0] = j;
    for(i = 1,k = 0;i < n; i++)
    {
        len = k + pb[k];
        l = pa[i - k];
        if(l + i < len) pb[i] = l;
        else
        {
            for(j = max(0,len - i);i + j < n && j < m && a[j] == b[i + j]; j++);
            pb[i] = j;
            k = i;
        }
    }
}

int main(){

    return 0;
}
