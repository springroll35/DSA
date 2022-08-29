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
const ll mod = 1e15+7;
typedef pair<int,int> ii;

void process() {
    int n, m;
    cin >> n >> m;
    int a[m], b[m], l[m], r[m];
    for(int &x : a) cin >> x;
    for(int i = 0; i < m; i++) b[i] = n - a[i];
    stack<int> st1, st2, st3, st4;
    st1.push(m - 1);
    for(int i = m - 1; i >= 0; i--) {
        while(st1.size() && a[i] <= a[st1.top()]) st1.pop();
        if(st1.size()) r[i] = st1.top() - 1;
        else r[i] = m - 1;
        st1.push(i);
    }
    for(int i = 0; i < m; i++) {
        while(st2.size() && a[i] <= a[st2.top()]) st2.pop();
        if(st2.size()) l[i] = st2.top() + 1;
        else l[i] = 0;
        st2.push(i);
    }
    ll ans1 = 0, ans2 = 0;
    for(int i = 0; i < m; i++) ans1 = max(ans1, 1ll * a[i] * (r[i] - l[i] + 1));
    st3.push(m - 1);
    for(int i = m - 1; i >= 0; i--) {
        while(st3.size() && b[i] <= b[st3.top()]) st3.pop();
        if(st3.size()) r[i] = st3.top() - 1;
        else r[i] = m - 1;
        st3.push(i);
    }
    for(int i = 0; i < m; i++) {
        while(st4.size() && b[i] <= b[st4.top()]) st4.pop();
        if(st4.size()) l[i] = st4.top() + 1;
        else l[i] = 0;
        st4.push(i);
    }
    for(int i = 0; i < m; i++) ans2 = max(ans2, 1ll * b[i] * (r[i] - l[i] + 1));
    cout << max(ans1, ans2);
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    //cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}