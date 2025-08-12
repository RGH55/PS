#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> vt, a;
int cnt[10005];

void f(int n)
{
    if(n == M){
        for(vector<int>::iterator it = vt.begin(); it != vt.end(); ++it){
            printf("%d ", *it);
        }
        printf("\n");
        return;
    }
    for(int i=0; i<a.size(); i++){
        if(cnt[a[i]] == 0) continue;
        vt.push_back(a[i]);
        cnt[a[i]]--;
        f(n+1);
        vt.pop_back();
        cnt[a[i]]++;
    }
    return;
}


int main()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        int inp;
        scanf("%d", &inp);
        if(cnt[inp] == 0) a.push_back(inp);
        cnt[inp]++;
    }
    sort(a.begin(), a.end());
    f(0);
    return 0;
}
