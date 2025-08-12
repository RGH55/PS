#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 1000000000

using namespace std;

int T, N, M, W;
vector<pair<pair<int, int>, int> > vt;
int dist[505];

int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &N, &M, &W);
        vt.clear();
        for(int i=0; i<M; i++){
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);
            vt.push_back({{s, e}, t});
            vt.push_back({{e, s}, t});
        }
        for(int i=0; i<W; i++){
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);
            vt.push_back({{s, e}, -t});
        }
        for(int i=0; i<=N; i++) dist[i] = INF;

        for(int i=0; i<N-1; i++){
            for(vector<pair<pair<int, int>, int> >::iterator it = vt.begin(); it != vt.end(); ++it){
                int s = it->first.first;
                int e = it->first.second;
                int t = it->second;
                if(dist[e] > dist[s] + t) dist[e] = dist[s] + t;
            }
        }
        bool flag = false;
        for(vector<pair<pair<int, int>, int> >::iterator it = vt.begin(); it != vt.end(); ++it){
            int s = it->first.first;
            int e = it->first.second;
            int t = it->second;
            if(dist[e] > dist[s] + t) flag = true;
            if(flag) break;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
