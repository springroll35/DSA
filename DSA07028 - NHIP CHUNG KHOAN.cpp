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
    int n;
    cin >> n;
    std::vector<int> a(n), ans(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(st.size() && a[st.top()] <= a[i]) st.pop();
        if(st.empty()) {
            ans[i] = i+1;
        }
        else {
            ans[i] = i-st.top();
        }
        st.push(i);
    }
    for(auto x : ans) cout << x << ' ';
    cout << endl;
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