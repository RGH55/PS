#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX 150000

using namespace std;

int N, K;
queue<pair<int, int> > q;
bool visited[MAX];

int main()
{
    scanf("%d %d", &N, &K);
    q.push({N, 0});
    while(!q.empty()){
        int n = q.front().first;
        int t = q.front().second;
        q.pop();
        if(n < 0 || n >= MAX) continue;
        if(visited[n]) continue;
        do{
            visited[n] = true;
            if(n == K){
                printf("%d\n", t);
                return 0;
            }
            q.push({n-1, t+1});
            q.push({n+1, t+1});
            n *= 2;
        }while(n < MAX && n != 0);
    }
    printf("-1\n");
    return 0;
}
