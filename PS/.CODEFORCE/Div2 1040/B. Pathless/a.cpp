#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, S;

int main()
{
    scanf("%d", &T);
    while(T--){
        int sum = 0, cnt[3] = {0,};
        scanf("%d %d", &N, &S);
        for(int i=0; i<N; i++){
            int inp;
            scanf("%d", &inp);
            sum += inp;
            cnt[inp]++;
        }
        if(S == sum + 1 || S < sum){
            for(int i=0; i<cnt[1]; i++) printf("1 ");
            for(int i=0; i<cnt[2]; i++) printf("2 ");
            for(int i=0; i<cnt[0]; i++) printf("0 ");
            printf("\n");
        }
        else printf("-1\n");
    }
    return 0;
}
