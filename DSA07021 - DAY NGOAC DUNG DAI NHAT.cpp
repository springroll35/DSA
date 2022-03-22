#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

void process() {
    string s;
    cin >> s;
    stack<int> st;
    st.push(-1);
    int ans = 0;
    for(int i = 0; i < s.length(); i++) {
        if (s[i] == ')') {
            if (st.size()) {
                st.pop();
            }
            if (st.empty()){
                st.push(i);
            }
            else {
                ans = max(ans, i - st.top());
            }
        }
        else st.push(i);
    }
    cout << ans << endl;
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