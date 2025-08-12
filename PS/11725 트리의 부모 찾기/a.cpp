#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> vt[100005];
queue<int> q;
int ans[100005];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N-1; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        vt[s].push_back(e);
        vt[e].push_back(s);
    }
    q.push(1);
    ans[1] = 1;
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        for(vector<int>::iterator it = vt[n].begin(); it != vt[n].end(); ++it){
            if(ans[*it] != 0) continue;
            ans[*it] = n;
            q.push(*it);
        }
    }
    for(int i=2; i<=N; i++) printf("%d\n", ans[i]);
    return 0;
}
