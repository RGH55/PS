#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

int N;
int a[100005], sum[100005];
stack<int> st;

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) sum[i] = 0;
    for(int i=0; i<N; i++) scanf("%d", &a[i]);
    for(int i=0; i<N; i++){
        while(!st.empty() && a[st.top()] > a[i]){
            sum[st.top()] += i - st.top() - 1;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        sum[st.top()] += N - st.top() - 1;
        st.pop();
    }
    for(int i=N-1; i>=0; i--){
        while(!st.empty() && a[st.top()] > a[i]){
            sum[st.top()] += st.top() - i - 1;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        sum[st.top()] += st.top();
        st.pop();
    }
    int ans = 0;
    for(int i=0; i<N; i++) ans = max(ans, a[i] * (sum[i] + 1));
    printf("%d\n", ans);
    return 0;
}
