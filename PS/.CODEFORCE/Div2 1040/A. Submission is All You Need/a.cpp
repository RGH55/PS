#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;

int main()
{
    scanf("%d", &T);
    while(T--){
        int ans = 0;
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            int inp;
            scanf("%d", &inp);
            if(inp == 0) ans += 1;
            else ans += inp;
        }
        printf("%d\n", ans);
    }
    return 0;
}
