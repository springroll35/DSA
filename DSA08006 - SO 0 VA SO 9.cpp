#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 105;
const ll mod = 1e9+7;
const int row[4] = {-1, 0, 1, 0};
const int col[4] = {0, -1, 0, 1};
typedef pair<int,int> ii;

void process() {
    int n;
    cin >> n;
    queue<ll> q;
    q.push(9);
    while(q.size()) {
        ll x = q.front();
        q.pop();
        if(x % n == 0) {
            cout << x << endl;
            break;
        }
        q.push(x * 10);
        q.push(x * 10 + 9);
    }
    
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