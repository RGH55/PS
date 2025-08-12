#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, K;
long long ans;
vector<pair<int, int> > vt;
int c[300005];
priority_queue<int> pq;

int main()
{
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
        int m, v;
        scanf("%d %d", &m, &v);
        vt.push_back({m, v});
    }
    for(int i=0; i<K; i++) scanf("%d", &c[i]);
    sort(vt.begin(), vt.end());
    sort(c, c+K);
    vector<pair<int, int> >::iterator it = vt.begin();
    for(int i=0; i<K; i++){
        while(it != vt.end() && it->first <= c[i]){
            pq.push(it->second);
            ++it;
        }
        if(pq.empty()) continue;
        ans += pq.top();
        pq.pop();
    }
    printf("%lld\n", ans);
    return 0;
}
