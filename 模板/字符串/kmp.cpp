//created by missever

#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;

int f[100000];//next
// 范围 1~n
// 特征匹配(满足相同大小关系)下的kmp  p[j] = p[i]变为大于该值的数的个数和等于该值的数的个数分别相等
int kmp(string p,string s)
{
    int n = p.size();
    int m = s.size();
    int i,j;
    int ans = 0;
    memset(f,0,sizeof(f));
    for(i = 1;i < n; i++)
    {
        j = i;
        while(j > 0)
        {
            j = f[j];
            if(p[j] == p[i])
            {
                f[i+1] = j + 1;
                break;
            }
        }
    }
    for(i = 0,j = 0;i < m; i++)
    {
        if(j < n && s[i] == p[j]) j++;
        else
        {
            while(j > 0)
            {
                j = f[j];
                if(s[i] == p[j])
                {
                    j++;
                    break;
                }
            }
        }
        //if(j == n) return i;
        if(j == n) ans++;
    }
    return ans;
}

int main(){

    return 0;
}
