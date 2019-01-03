//created by missever

#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;

double A,B;
const double PI = acos(-1);

double f(double x)
{
    return PI * pow(A * exp(-x * x) + B * sqrt(x),2); // 带积分函数
}

double simpson(double a,double b)
{
    double c=(a + b) / 2.0;
    return (f(a)+4.0*f(c)+f(b))*(b-a)/6.0;
}

double asr(double a,double b,double EPS,double A)
{
    double c=(a + b) / 2.0;
    double L=simpson(a,c),R=simpson(c,b);
    if(fabs(L+R-A)<=15.0*EPS) return L+R+(L+R-A)/15.0;
    return asr(a,c,EPS/2.0,L)+asr(c,b,EPS/2.0,R);
}

double asr_main(double a,double b,double EPS) // 积分区间(a,b),精度eps
{
    return asr(a,b,EPS,simpson(a,b));
}

int main()
{
    double h,pp,ans,ff;
    int n,e;
    ans = 1e9;
    cin>>pp>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>A>>B>>h;
        ff = asr_main(0,h,1e-12);
        if(fabs(ff - pp) < ans)
        {
            ans = fabs(ff - pp);
            e = i;
        }
    }
    cout<<e<<endl;
    return 0;
}
