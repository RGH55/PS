#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int> > vt;
int dp[100005];

int main()
{
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
        int w, v;
        scanf("%d %d", &w, &v);
        vt.push_back({w, v});
    }
    //sort(vt.begin(), vt.end()); 필요없음;;;
    for(vector<pair<int, int> >::iterator it = vt.begin(); it != vt.end(); ++it){
        int w = it->first, v = it->second;
        for(int i=K-w; i>=0; i--){
            dp[i+w] = max(dp[i+w], dp[i] + v);
        }
    }
    printf("%d\n", dp[K]);
    return 0;
}
