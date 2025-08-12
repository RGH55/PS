#include <cstdio>
#include <algorithm>
#include <utility>
#define MOD 1000000007

using namespace std;
using ll = long long;

ll N;

pair<ll, ll> f(ll n)
{
    if(n == 0) return {0, 1};
    if(n == 1) return {1, 1};
    pair<ll, ll> p = f((n-1)/2);
    ll x = p.first, y = p.second;
    if(n%2 == 0) return {(2*x*y + y*y)%MOD, (2*y*y + 2*x*y + x*x)%MOD};
    return {(x*x + y*y)%MOD, (2*x*y + y*y)%MOD};
}

int main()
{
    scanf("%lld", &N);
    printf("%lld ", f(N).first);
    return 0;
}
