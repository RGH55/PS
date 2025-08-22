#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, S, D;
int dist[505];
vector<pair<int, int>> vt[505];
vector<int> from[505];
bool visited[505], banned[505][505];
priority_queue<pair<int, pair<int, int>>> pq;

void init(int n)
{
    for(int i=0; i<n; i++){
        vt[i].clear();
        from[i].clear();
        visited[i] = false;
        for(int j=0; j<n; j++) banned[i][j] = false;
    }
}

void traceback(int n)
{
    if(n == S) return;
    for(vector<int>::iterator it = from[n].begin(); it != from[n].end(); ++it){
        if(banned[*it][n]) continue;
        banned[*it][n] = true;
        traceback(*it);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    while(N){
        init(N);
        scanf("%d %d", &S, &D);
        for(int i=0; i<M; i++){
            int x, y, d;
            scanf("%d %d %d", &x, &y, &d);
            vt[x].push_back({y, d});
        }
        pq.push({0, {S, -1}});
        while(!pq.empty()){
            int n = pq.top().second.first;
            int d = -pq.top().first;
            int p = pq.top().second.second;
            pq.pop();
            if(visited[n] && d == dist[n]) from[n].push_back(p);
            if(visited[n]) continue;
            visited[n] = true;
            dist[n] = d;
            from[n].push_back(p);
            for(vector<pair<int, int>>::iterator it = vt[n].begin(); it != vt[n].end(); ++it){
                pq.push({-(d + it->second), {it->first, n}});
            }
        }
        traceback(D);
        for(int i=0; i<N; i++) visited[i] = false;
        dist[D] = -1;
        pq.push({0, {S, -1}});
        while(!pq.empty()){
            int n = pq.top().second.first;
            int d = -pq.top().first;
            int p = pq.top().second.second;
            pq.pop();
            if(visited[n]) continue;
            visited[n] = true;
            dist[n] = d;
            for(vector<pair<int, int>>::iterator it = vt[n].begin(); it != vt[n].end(); ++it){
                if(banned[n][it->first]) continue;
                pq.push({-(d + it->second), {it->first, n}});
            }
        }
        printf("%d\n", dist[D]);
        scanf("%d %d", &N, &M);
    }
    return 0;
}
