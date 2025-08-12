#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 100000000

using namespace std;

int N, M, X;
int dist[2][1005];
vector<pair<int, int> > vt[2][1005];
priority_queue<pair<int, int> > pq;

int main()
{
    scanf("%d %d %d", &N, &M, &X);
    for(int i=0; i<M; i++){
        int s, e, t;
        scanf("%d %d %d", &s, &e, &t);
        vt[0][s].push_back({e, t});
        vt[1][e].push_back({s, t});
    }
    for(int i=1; i<=N; i++) dist[0][i] = dist[1][i] = INF;
    dist[0][X] = dist[1][X] = 0;
    for(int i=0; i<2; i++){
        pq.push({0, X});
        while(!pq.empty()){
            int d = -pq.top().first;
            int n = pq.top().second;
            pq.pop();
            if(dist[i][n] < d) continue;
            for(vector<pair<int, int> >::iterator it = vt[i][n].begin(); it != vt[i][n].end(); ++it){
                    if(d + it->second < dist[i][it->first]){
                        dist[i][it->first] = d + it->second;
                        pq.push({-dist[i][it->first], it->first});
                    }
            }
        }
    }
    for(int i=1; i<=N; i++) dist[0][i] += dist[1][i];
    printf("%d\n", *max_element(dist[0]+1, dist[0]+N+1));
    return 0;
}
