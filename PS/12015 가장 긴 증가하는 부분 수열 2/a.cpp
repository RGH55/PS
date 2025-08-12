#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int a[1000005];
vector<int> ans;

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &a[i]);
    ans.push_back(a[0]);
    for(int i=1; i<N; i++){
        if(ans.back() < a[i]) ans.push_back(a[i]);
        else *lower_bound(ans.begin(), ans.end(), a[i]) = a[i];
    }
    printf("%d\n", ans.size());
    return 0;
}
