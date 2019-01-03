//created by missever

#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
//N应该为2倍以上向量长度，后一半为0，不然可能会算错
const int N = 1 << 18;
const double pi = acos(-1.0);

struct Complex {
    double r, i;
    Complex(double _r = 0.0, double _i = 0.0) {
        r = _r, i = _i;
    }
    Complex operator + (const Complex &b) const {
        return Complex(r + b.r, i + b.i);
    }
    Complex operator - (const Complex &b) const {
        return Complex(r - b.r, i - b.i);
    }
    Complex operator * (const Complex &b) const {
        return Complex(r * b.r - i * b.i, r * b.i + i * b.r);
    }
} va[N],vb[N];

void FFT(Complex p[], int N, int op) {
    for (int i = 0, j = 0; i < N; i++) {
        if (i > j) swap(p[i], p[j]);
        for (int l = N >> 1; (j ^= l) < l; l >>= 1);
    }
    double p0 = pi * op;
    for (int h = 2; h <= N; h <<= 1, p0 *= 0.5) {
        int hf = h >> 1;
        Complex unit(cos(p0), sin(p0));
        for (int i = 0; i < N; i += h) {
            Complex w(1.0, 0.0);
            for (int j = i; j < i + hf; j++) {
                Complex u = p[j], t = w * p[j + hf];
                p[j] = u + t;
                p[j + hf] = u - t;
                w = w * unit;
            }
        }
    }
    if (op == 1) return ;
    for (int i = 0; i < N; ++i) p[i].r /= N;
}

void Conv(Complex a[],Complex b[],int len)
{
    FFT(a,len,1);
    FFT(b,len,1);
    for(int i=0;i<len;++i) a[i] = a[i]*b[i];
    FFT(a,len,-1);
}

/*
//二维FFT
可以转化为一维 (i,j)转化为i*m+j 
*/