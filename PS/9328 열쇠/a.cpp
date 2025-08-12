#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T, H, W;
char a[105][105];
queue<pair<int, int> > q;
vector<pair<int, int> > vt[30];
bool key[30], visited[105][105];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

bool isKey(int x, int y)
{
    if('a' <= a[x][y] && a[x][y] <= 'z') return true;
    return false;
}

bool isDoor(int x, int y)
{
    if('A' <= a[x][y] && a[x][y] <= 'Z') return true;
    return false;
}

int main()
{
    scanf("%d", &T);
    while(T--){
        for(int i=0; i<105; i++) for(int j=0; j<105; j++) visited[i][j] = false;
        for(int i=0; i<30; i++) vt[i].clear();
        for(int i=0; i<30; i++) key[i] = false;
        scanf("%d %d", &H, &W);
        for(int i=0; i<H; i++) scanf(" %s", a[i]);
        char k[30];
        scanf(" %s", k);
        for(int i=0; k[i] != '\0' && k[i] != '0'; i++) key[k[i] - 'a'] = true;
        for(int i=0; i<H; i++){
            q.push({i, 0});
            q.push({i, W-1});
        }
        for(int i=0; i<W; i++){
            q.push({0, i});
            q.push({H-1, i});
        }
        int ans = 0;
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            if(x < 0 || x >= H || y < 0 || y >= W) continue;
            if(a[x][y] == '*') continue;
            if(visited[x][y]) continue;
            if(isDoor(x, y) && !key[a[x][y] - 'A']){
                int k = a[x][y] - 'A';
                vt[k].push_back({x, y});
                continue;
            }
            visited[x][y] = true;
            if(isKey(x, y)){
                int k = a[x][y] - 'a';
                key[k] = true;
                for(vector<pair<int, int> >::iterator it = vt[k].begin(); it != vt[k].end(); ++it){
                    q.push(*it);
                }
            }
            if(a[x][y] == '$') ans++;
            for(int i=0; i<4; i++) q.push({x + dx[i], y + dy[i]});
        }
        printf("%d\n", ans);
    }
    return 0;
}
