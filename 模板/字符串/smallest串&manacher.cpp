//created by missever

#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;

const int N=200005<<1;

char T[N];   //原字符串
char S[N];   //转换后的字符串
int  R[N];   //回文半径

void Init(char *T)
{
    S[0]='$';
    int len=strlen(T);
    for(int i=0; i<=len; i++)
    {
        S[2*i+1]='#';
        S[2*i+2]=T[i];
    }
}

int Manacher(char *S)
{
    int k=0,mx=0;
    int len=strlen(S);
    for(int i=0; i<len; i++)
    {
        if(mx>i)
            R[i]=R[2*k-i]<mx-i? R[2*k-i] : mx-i;
        else
            R[i]=1;
        while(S[i+R[i]]==S[i-R[i]])
            R[i]++;
        if(R[i]+i>mx)
        {
            mx=R[i]+i;
            k=i;
        }
    }
    int ans=1;
    for(int i=0; i<len; i++)
        ans=R[i]>ans? R[i] : ans;
    return ans - 1;
}

string smallest(string s)
{
    int i,j,k,l;
    int n = s.size() / 2;
    for(i = 0,j = 1;j < n; )
    {
        for(k = 0;k < n && s[i + k] == s[j + k]; k++);
        if(k >= n) break;
        if(s[i + k] < s[j + k]) j += k + 1;
        else
        {
            l = i + k;
            i = j;
            j = max(l,j) + 1;
        }
    }
    printf("%d",i + 1);
    return s.substr(i,n);
}

int main()
{

    return 0;
}
