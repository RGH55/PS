#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int N;
ll D;
ll a[100005][2];
vector<pair<ll, int>> vt;
int cnt, ans;

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%lld %lld", &a[i][0], &a[i][1]);
    scanf("%lld", &D);
    for(int i=0; i<N; i++){
        if(abs(a[i][0] - a[i][1]) <= D){
            vt.push_back({min(a[i][0], a[i][1]), 1});
            vt.push_back({max(a[i][0], a[i][1]) - D, 0});
        }
    }
    sort(vt.begin(), vt.end());
    for(vector<pair<ll, int>>::iterator it = vt.begin(); it != vt.end(); ++it){
        if(it->second == 0) cnt++;
        else cnt--;
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}
