#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(k) k.begin(), k.end()
#define fi first
#define sc second
#define pb push_back
#define endl "\n"

const int maxn = 1e4+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

struct Node {
    int a[6];
};

bool check(Node x, Node y) {
    for(int i = 0; i < 6; i++) {
        if(x.a[i] != y.a[i]) return false;
    }
    return true;
}

void process() {
    Node s, t;
    for(int i = 0; i < 6; i++) cin >> s.a[i];
    for(int i = 0; i < 6; i++) cin >> t.a[i];
    if(check(s, t)) {
        cout << 0 << endl;
        return;
    }
    queue<pair<Node, int>> q;
    q.push({s, 0});
    while(q.size()) {
        Node u = q.front().fi;
        int d = q.front().sc;
        q.pop();
        if(check(u, t)) {
            cout << d << endl;
            return;
        }
        Node k;
        k.a[0] = u.a[3]; k.a[1] = u.a[0];
        k.a[2] = u.a[2]; k.a[3] = u.a[4]; 
        k.a[4] = u.a[1]; k.a[5] = u.a[5];
        if(check(k, t)) {
            cout << d + 1 << endl;
            return;
        }
        q.push({k, d + 1});

        k.a[0] = u.a[0]; k.a[1] = u.a[4]; 
        k.a[2] = u.a[1]; k.a[3] = u.a[3];
        k.a[4] = u.a[5]; k.a[5] = u.a[2];
        if(check(k, t)) {
            cout << d + 1 << endl;
            return;
        }
        q.push({k, d + 1});

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