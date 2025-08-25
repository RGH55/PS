#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int T, N;
vector<ll> vt;

int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            ll inp;
            scanf("%lld", &inp);
            vt.push_back(inp);
        }
        sort(vt.begin(), vt.end());
        long long ans = 0;
        for(int i=vt.size() - 1; i>=0; i-=2){
            ans += vt[i];
        }
        printf("%lld\n", ans);
        vt.clear();
    }
    return 0;
}
