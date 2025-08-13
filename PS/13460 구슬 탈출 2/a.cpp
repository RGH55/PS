#include <cstdio>
#include <algorithm>
#include <queue>
#define X first
#define Y second
#define MAX 1e9

using namespace std;
using pii = pair<int, int>;

int N, M;
char a[15][15];
bool visited[15][15][15][15];
pii O, R, B;
queue<pair<pair<pii, pii>, int> > q;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) scanf("%s", a[i]);
    for(int i=0; i<N; i++) for(int j=0; j<M; j++){
        if(a[i][j] == 'O') O = {i, j};
        else if(a[i][j] == 'R') R = {i, j};
        else if(a[i][j] == 'B') B = {i, j};
    }
    q.push({{R, B}, 0});
    while(!q.empty()){
        int t = q.front().second;
        pii r = q.front().first.first, b = q.front().first.second;
        q.pop();
        if(t >= 10) continue;
        if(visited[r.X][r.Y][b.X][b.Y]) continue;
        visited[r.X][r.Y][b.X][b.Y] = true;
        for(int i=0; i<4; i++){
            pii nr = r, nb = b;
            bool flagR = false, flagB = false;
            for(int j=0; j<2; j++){
                while(!flagR && a[nr.X][nr.Y] != '#' && make_pair(nr.X, nr.Y) != nb){
                    if(a[nr.X][nr.Y] == 'O'){
                        flagR = true;
                        nr = {0, 0};
                    }
                    nr.X += dx[i]; nr.Y += dy[i];
                }
                nr.X -= dx[i]; nr.Y -= dy[i];
                while(!flagB && a[nb.X][nb.Y] != '#' && make_pair(nb.X, nb.Y) != nr){
                    if(a[nb.X][nb.Y] == 'O'){
                        flagB = true;
                        nb = {0, 0};
                    }
                    nb.X += dx[i]; nb.Y += dy[i];
                }
                nb.X -= dx[i]; nb.Y -= dy[i];
            }
            if(flagB) continue;
            if(flagR){
                printf("%d\n", t + 1);
                return 0;
            }
            q.push({{nr, nb}, t + 1});
        }
    }
    printf("-1\n");
    return 0;
}
