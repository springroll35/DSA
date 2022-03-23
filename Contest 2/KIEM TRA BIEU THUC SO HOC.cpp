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

bool check(string s) {
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        bool ok = false;
        st.push(s[i]);
        if (st.top() == ')') {
            while(st.top() != '(') {
                st.pop();
                if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
                    ok = true;
                }
            }
            st.pop();
            if (ok == false) return true;
        }
    }
    return false;
}

void process() {
    string s;
    getline(cin, s);
    cout << (check(s) ? "Yes" : "No") << endl;
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
    cin.ignore();
    while(test--) {
        process();
    }
    

    return 0;
}