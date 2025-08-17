#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> vt[1000005];
int cnt[1000005], ans;
bool visited[1000005];
queue<int> leaf, q;

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N-1; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        vt[x].push_back(y);
        vt[y].push_back(x);
        cnt[x]++; cnt[y]++;
    }
    for(int i=1; i<=N; i++) if(cnt[i] == 1) leaf.push(i);
    while(!leaf.empty()){
        int l = leaf.front();
        leaf.pop();
        if(visited[l]) continue;
        ans++;
        for(vector<int>::iterator it = vt[l].begin(); it != vt[l].end(); ++it) q.push(*it);
        while(!q.empty()){
            int n = q.front();
            q.pop();
            if(visited[n]) continue;
            visited[n] = true;
            for(vector<int>::iterator it = vt[n].begin(); it != vt[n].end(); ++it){
                cnt[*it]--;
                if(cnt[*it] == 0) q.push(*it);
                else if(cnt[*it] == 1) leaf.push(*it);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
