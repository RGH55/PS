#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
char a[1005][1005];
bool visited[1005][1005][2];
queue<pair<pair<int, int>, pair<int, int> > > q;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) scanf("%s", a[i]);
    q.push({{0, 0}, {1, 0}});
    int ans = -1;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second.first;
        int f = q.front().second.second;
        q.pop();
        if(x < 0 || x >= N || y < 0 || y >= M) continue;
        if(visited[x][y][f]) continue;
        if(a[x][y] == '1') f++;
        if(f > 1) continue;
        visited[x][y][f] = true;
        if(x == N-1 && y == M-1){
            ans = t;
            break;
        }
        for(int i=0; i<4; i++) q.push({{x + dx[i], y + dy[i]}, {t + 1, f}});
    }
    printf("%d\n", ans);
    return 0;
}
