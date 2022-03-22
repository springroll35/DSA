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
    stack<char> st;
    int cnt = 0;
    for(char c : s) {
        if (c == ')') cnt++;
    }
    if (cnt == s.length()) {
        cout << s.length() / 2 << endl;
        return;
    }
    for(char c : s) {
        if (st.size() && c == ')') {
            if (st.top() == '(') {
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        else st.push(c);
    }
    int sz = st.size();
    int n = 0;
    while(st.size() && st.top() == '(') {
        st.pop();
        n++;
    }
    cout << sz / 2 + n % 2 << endl;

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