#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N;
int a[1000005], dp[1000005];
vector<int> ans;
stack<int> st;

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &a[i]);
    ans.push_back(a[0]);
    for(int i=1; i<N; i++){
        if(ans.back() < a[i]){
            ans.push_back(a[i]);
            dp[i] = ans.size() - 1;
        }
        else{
            dp[i] = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[dp[i]] = a[i];
        }
    }
    printf("%d\n", ans.size());
    int n = ans.size() - 1, i = N - 1;
    while(n >= 0){
        while(dp[i] != n) i--;
        st.push(a[i]);
        n--;
    }
    while(!st.empty()){
        printf("%d ", st.top());
        st.pop();
    }
    printf("\n");
    return 0;
}
