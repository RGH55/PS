#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int T, N;
vector<int> vt[505];
vector<int> ans;

int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i=0; i<=N; i++) vt[i].clear();
        ans.clear();
        int top = 0;
        for(int i=1; i<=N; i++){
            printf("? %d %d ", i, N);
            for(int j=1; j<=N; j++) printf("%d ", j);
            printf("\n\n");
            fflush(stdout);
            int len;
            scanf("%d", &len);
            vt[len].push_back(i);
            top = max(top, len);
        }
        int n = vt[top].front();
        ans.push_back(n);
        for(int i=top - 1; i>0; i--){
            for(vector<int>::iterator it = vt[i].begin(); it != vt[i].end(); ++it){
                printf("? %d %d %d %d\n\n", n, 2, n, *it);
                fflush(stdout);
                int len;
                scanf("%d", &len);
                if(len == 2){
                    n = *it;
                    ans.push_back(n);
                    break;
                }
            }
        }
        printf("! %d ", top);
        for(vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) printf("%d ", *it);
        printf("\n\n");
        fflush(stdout);
    }
    return 0;
}
