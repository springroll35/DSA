#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 35;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int n, k, s;
int x[maxn];
ll ans;

void print() {
    int sum = 0;
    for(int i = 1; i <= k; i++) {
        sum += x[i];
    }
    if(sum == s)
        ans++;
}

void Try(int i) {
    // x[i-1]+1 <= x[i] <= n-k+i+1 (i =  0 ... k-1)
    for(int j = x[i-1]+1; j <= n-k+i; j++) {
        x[i] = j;
        if (i == k) print();
        else Try(i+1);
    }
}

void process() {
    while(1) {
        cin >> n >> k >> s;
        ans = 0;
        if (n == 0 && k == 0 && s == 0) break;
        Try(1);
        cout << ans << endl;
    }
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