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
const int row[6] = {-1, 0, 0, 1, 0, 0};
const int col[6] = {0, -1, 1, 0, 0, 0};
const int height[6] = {0, 0, 0, 0, -1, 1};
typedef pair<int,int> ii;

void process() {
    int n;
    cin >> n;
    std::vector<int> a(n), d(1e6+1, 0), ans(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        d[a[i]]++;
    }
    stack<int> st;
    st.push(a[n-1]);
    ans[n-1] = -1;
    for(int i = n-2; i >= 0; i--) {
        while(st.size() && d[st.top()] <= d[a[i]]) st.pop();
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(a[i]);
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