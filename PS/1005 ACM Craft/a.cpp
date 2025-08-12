#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T, N, K, W;
int a[1005], cnt[1005];
vector<int> vt[1005];
priority_queue<pair<int, int> > pq;

int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &K);
        for(int i=1; i<=N; i++) scanf("%d", &a[i]);
        for(int i=0; i<K; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            vt[x].push_back(y);
            cnt[y]++;
        }
        scanf("%d", &W);
        for(int i=1; i<=N; i++){
            if(cnt[i] == 0) pq.push({-a[i], i});
        }
        while(!pq.empty()){
            int t = -pq.top().first;
            int n = pq.top().second;
            pq.pop();
            if(n == W){
                printf("%d\n", t);
                break;
            }
            for(vector<int>::iterator it = vt[n].begin(); it != vt[n].end(); ++it){
                if(--cnt[*it] == 0) pq.push({-(t + a[*it]), *it});
            }
        }
        while(!pq.empty()) pq.pop();
        for(int i=1; i<=N; i++){
            vt[i].clear();
            cnt[i] = 0;
        }
    }
    return 0;
}
