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

bool isOperator(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        return true;
    }
    return false;
}

void process() {
    string s;
    cin >> s;
    int n = s.length();
    stack<string> st;
    for(int i = 0; i < n; i++) {
        if(isOperator(s[i])) {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            st.push(s[i] + s2 + s1);
        }
        else {
            st.push(string(1, s[i]));
        }
    }
    cout << st.top() << endl;

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