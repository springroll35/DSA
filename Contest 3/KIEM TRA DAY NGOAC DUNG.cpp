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
    stack<char> st;
    bool ok = true;
    for(int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] =='{') {
            st.push(s[i]);
        }
        else if(s[i] == ')') {
            if(st.size() && st.top() == '(') st.pop();
            else {
                ok = false;
                break;
            }
        }
        else if(s[i] == ']') {
            if(st.size() && st.top() == '[') st.pop();
            else {
                ok = false;
                break;
            }
        }
        else if(s[i] == '}') {
            if(st.size() && st.top() == '{') st.pop();
            else {
                ok = false;
                break;
            }
        }
    }
    if(st.size()) {
        ok = false;
    }
    cout << (ok ? "YES" : "NO") << endl;

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