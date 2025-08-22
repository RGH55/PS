#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int V, E;
vector<int> vt[10005];
vector<vector<int>> ans;
int id, parent[10005];
bool visited[10005], popped[10005];
stack<int> st;

bool cmp(const vector<int>& a, const vector<int>& b)
{
    return a.front() < b.front();
}

bool dfs(int n)
{
    if(popped[n]) return false;
    if(visited[n]) return true;
    int lowset = parent[n] = ++id;
    visited[n] = true;
    st.push(n);
    for(vector<int>::iterator it = vt[n].begin(); it != vt[n].end(); ++it){
        if(dfs(*it)) parent[n] = min(parent[n], parent[*it]);
    }
    if(parent[n] == lowset){
        vector<int> tmp;
        while(st.top() != n){
            tmp.push_back(st.top());
            popped[st.top()] = true;
            st.pop();
        }
        tmp.push_back(st.top());
        popped[st.top()] = true;
        st.pop();
        ans.push_back(tmp);
        return false;
    }
    return true;
}

int main()
{
    scanf("%d %d", &V, &E);
    for(int i=0; i<E; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        vt[x].push_back(y);
    }
    for(int i=1; i<=V; i++) dfs(i);
    for(vector<vector<int>>::iterator it = ans.begin(); it != ans.end(); ++it) sort(it->begin(), it->end());
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    for(vector<vector<int>>::iterator it = ans.begin(); it != ans.end(); ++it){
        for(vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2) printf("%d ", *it2);
        printf("-1\n");
    }
    return 0;
}
