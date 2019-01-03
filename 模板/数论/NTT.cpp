#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
//记得添加预处理函数
typedef long long LL;
const int N = (1 << 18) + 5; // N应该为2倍以上向量长度，后一半为0，不然可能会算错
const int mod = 998244353; //985661441 原根3   1004535809 原根3
const int G = 3;
const int NUM = 20;

int wn[NUM];
int a[N], b[N];

int mul(int x, int y) {
    LL z = 1LL * x * y;
    return z - z / mod * mod;
}

int add(int x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}

int powt(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = mul(ans, a);
        b >>= 1;
        a = mul(a, a);
    }
    return ans;
}

void GetWn() {
    for(int i = 0; i < NUM; i++) {
        int t = 1 << i;
        wn[i] = powt(G, (mod - 1) / t);
    }
}

void NTT(int a[], int len, int t) {
    for (int i = 0, j = 0; i < len; i++) {
        if (i > j) swap(a[i], a[j]);
        for (int l = len >> 1; (j ^= l) < l; l >>= 1);
    }
    int id = 0;
    for(int h = 2; h <= len; h <<= 1) {
        id++;
        for(int j = 0; j < len; j += h) {
            int w = 1;
            for(int k = j; k < j + h / 2; ++k) {
                int u = a[k];
                int t = mul(w, a[k + h / 2]);
                a[k] = add(u, t);
                a[k + h / 2] = add(u, mod - t);
                w = mul(w, wn[id]);
            }
        }
    }
    if(t == -1) {
        for(int i = 1; i < len / 2; i++) swap(a[i], a[len - i]);
        LL inv = powt(len, mod - 2);
        for(int i = 0; i < len; i++)  a[i] = mul(a[i], inv);
    }
}

void Conv(int len) {
    NTT(a,len,1);
    NTT(b,len,1);
    for(int i = 0; i < len; ++i) a[i] = mul(a[i],b[i]);
    NTT(a,len,-1);
}

//输入向量a,b 输出向量a
void work(int n1,int n2)
{
	GetWn();
    int i,len = 1;
    while(len < 2 * n1 || len < 2 * n2) len <<= 1;
    for(i = 0;i < len; i++)
    {
        if(i >= n1) a[i] = 0;
        if(i >= n2) b[i] = 0;
    }
    Conv(len);
}

void NTT_2D(int a[][N],int len,int op)
{
    for(int i = 0;i < len; i++) NTT(a[i],len,op);
	for(int i = 0;i < len; i++)
	{
		for(int j = i + 1;j < len; j++) swap(a[i][j],a[j][i]);
	}
	for(int i = 0;i < len; i++) NTT(a[i],len,op);
	for(int i = 0;i < len; i++)
	{
		for(int j = i + 1;j < len; j++) swap(a[i][j],a[j][i]);
	}
}

void Conv_2D(int a[][N],int b[][N],int len)
{
    NTT_2D(a,len,1);
    NTT_2D(b,len,1);
    for(int i = 0;i < len; ++i)
    {
        for(int j = 0;j < len; j++) a[i][j] = mul(a[i][j],b[i][j]);
    }
    NTT_2D(a,len,-1);
}


int main()
{
    return 0;
}
