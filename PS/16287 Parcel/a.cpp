#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, W;
int a[5005];
bool visited[800005];

int main()
{
    scanf("%d %d", &W, &N);
    for(int i=0; i<N; i++) scanf("%d", &a[i]);
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            int sum = a[i] + a[j];
            if(sum < W && visited[W - sum]){
                printf("YES\n");
                return 0;
            }
        }
        for(int j=0; j<i; j++) if(a[i] + a[j] < W) visited[a[i] + a[j]] = true;
    }
    printf("NO\n");
    return 0;
}
