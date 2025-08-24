#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

ll N, ans;
vector<ll> p;

void f(int n, int cnt, ll m)
{
    if(n == p.size()){
        if(cnt > 0) ans += N/m * (cnt%2 ? -1 : 1);
        return;
    }
    f(n + 1, cnt + 1, m * p[n]);
    f(n + 1, cnt, m);
}

int main()
{
    scanf("%lld", &N);
    ll n = N;
    for(ll i=2; i*i <= N; i++){
        if(n % i == 0){
            p.push_back(i);
            vector<ll> tmp = {i};
            while(n % tmp.back() == 0) tmp.push_back(tmp.back() * tmp.back());
            for(vector<ll>::reverse_iterator it = tmp.rbegin(); it != tmp.rend(); ++it){
                if(n % *it == 0) n /= *it;
            }
        }
    }
    if(n != 1) p.push_back(n);
    ans = N;
    f(0, 0, 1);
    printf("%lld\n", ans);
    return 0;
}
