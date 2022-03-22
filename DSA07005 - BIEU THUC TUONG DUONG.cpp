#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 1e3+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

void process() {
    string s;
    cin >> s;
    int n = s.length();
    stack<int> st;
    st.push(0);
    char* ans = new char(n);
    int i = 0, sz = 0;
    while(i < n) {
        if (s[i] == '(' && i == 0) {
            i++;
            continue;
        }
        
        if (s[i] == '+') {
            if(st.top() == 1) {
                ans[sz++] = '-';
            }
            if(st.top() == 0) {
                ans[sz++] = '+';
            }
        }
        
        else if(s[i] == '-') {
            if(st.top() == 1) {
                if(ans[sz-1] == '+' || ans[sz-1] == '-') {
                    ans[sz-1] = '+';
                }
                else {
                    ans[sz++] = '+';
                }
            }
            else if (st.top() == 0) {
                if(ans[sz-1] == '+' || ans[sz-1] == '-') {
                    ans[sz-1] = '-';
                }
                else {
                    ans[sz++] = '-';
                }
            }
        }
        
        else if(s[i] == '(' && i > 0) {
            if(s[i-1] == '-') {
                int x = (st.top() == 1) ? 0 : 1;
                st.push(x);
            }
            else if(s[i-1] == '+') {
                st.push(st.top());
            }
        }
        
        else if(s[i] == ')') {
            st.pop();
        }
        
        else {
            ans[sz++] = s[i];
        }
        
        
        i++;
    }
    for(int j = 0; j < sz; j++) cout << ans[j];
    cout << endl;
    //cout << ans.size();
    
    //cout << ans[1];
    //cout << '+';
    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test;
    cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}