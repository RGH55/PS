#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
bool visited[105];
vector<int> vt;

void f(int n)
{
    if(n == M){
        for(vector<int>::iterator it = vt.begin() + 1; it != vt.end(); ++it){
            printf("%d ", *it);
        }
        printf("\n");
        return;
    }
    for(int i=vt.back()+1; i<=N; i++){
        if(visited[i]) continue;
        vt.push_back(i);
        visited[i] = true;
        f(n+1);
        vt.pop_back();
        visited[i] = false;
    }
    return;
}


int main()
{
    scanf("%d %d", &N, &M);
    vt.push_back(0);
    f(0);
    return 0;
}
