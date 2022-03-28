#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int n, k;

void process() {
    cin >> n >> k;
    std::vector<int> a(n);
    for(int i = 1; i <= k; i++) cin >> a[i];
    int pos = k-1;
    while(pos && a[pos] + 1 == a[pos+1]) pos--;
    if(pos == 0) {
        for(int i = 1; i <= k; i++) cout << n-k+i << ' ';
        cout << endl;
        return;
    }
    a[++pos]--;
    for(int i = k; i > pos; i--) {
        a[i] = n-k+i;
    }
    for(int i = 1; i <= k; i++) cout << a[i] << ' ';
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