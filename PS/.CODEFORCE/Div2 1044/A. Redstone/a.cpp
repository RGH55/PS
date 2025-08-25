#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;
int a[105];

int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i=0; i<N; i++) scanf("%d", &a[i]);
        bool visited[105] = {0,}, ans = false;
        for(int i=0; i<N; i++){
            if(visited[a[i]]) ans = true;
            visited[a[i]] = true;
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
