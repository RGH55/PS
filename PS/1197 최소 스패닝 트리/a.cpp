#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int V, E, ans;
vector<pair<int, int> > vt[10005];
priority_queue<pair<int, int> > pq;
bool visited[10005];

int main()
{
    scanf("%d %d", &V, &E);
    for(int i=0; i<E; i++){
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        vt[s].push_back({e, w});
        vt[e].push_back({s, w});
    }
    visited[1] = true;
    for(vector<pair<int, int> >::iterator it = vt[1].begin(); it != vt[1].end(); ++it){
        pq.push({-it->second, it->first});
    }
    while(!pq.empty()){
        int w = -pq.top().first;
        int n = pq.top().second;
        pq.pop();
        if(visited[n]) continue;
        visited[n] = true;
        ans += w;
        for(vector<pair<int, int> >::iterator it = vt[n].begin(); it != vt[n].end(); ++it){
            pq.push({-it->second, it->first});
        }
    }
    printf("%d\n", ans);
    return 0;
}
