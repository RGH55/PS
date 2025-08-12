#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int cnt[1005];
vector<int> vt[1005], ans;
queue<int> q;

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        int t;
        scanf("%d", &t);
        int x, y;
        scanf("%d", &x);
        while(--t){
            scanf("%d", &y);
            vt[x].push_back(y);
            cnt[y]++;
            x = y;
        }
    }
    for(int i=1; i<=N; i++) if(cnt[i] == 0) q.push(i);
    while(!q.empty()){
        int n = q.front();
        q.pop();
        ans.push_back(n);
        for(vector<int>::iterator it = vt[n].begin(); it != vt[n].end(); ++it){
            if(--cnt[*it] == 0) q.push(*it);
        }
    }
    if(ans.size() != N) printf("0\n");
    else{
        for(vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) printf("%d\n", *it);
    }
    return 0;
}
