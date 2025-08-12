#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

char s[105];
stack<char> st;
vector<char> ans;

int main()
{
    scanf("%s", s);
    for(int i=0; s[i]!='\0'; i++){
        if(s[i] == '('){
            st.push('(');
        }
        else if(s[i] == ')'){
            while(st.top() != '('){
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else if(s[i] == '*' || s[i] == '/'){
            while(!st.empty() && (st.top() == '*' || st.top() == '/')){
                ans.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
        else if(s[i] == '+' || s[i] == '-'){
            while(!st.empty() && st.top() != '('){
                ans.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
        else ans.push_back(s[i]);
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    for(int i=0; i<ans.size(); i++) printf("%c", ans[i]);
    printf("\n");
    return 0;
}
