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
const int lu[10] = {3, 0, 2, 7, 4, 1, 6, 8, 5, 9};
const int ru[10] = {0, 4, 1, 3, 8, 5, 2, 7, 9, 6};
const int ld[10] = {1, 5, 2, 0, 4, 8, 6, 3, 7, 9};
const int rd[10] = {0, 2, 6, 3, 1, 5, 9, 7, 4, 8};
typedef pair<int,int> ii;
typedef pair<string,int> si;

string s, t = "1238004765", l = "0012345678", r = "0012345678";
map<string, int> up, down;
bool check;

void init() {
    check = 0;
    s = "";
    up.clear();
    down.clear();
}

void turnUp(string s) {
    for (int i = 0; i < 10; i++) {
        l[i] = s[lu[i]];
        r[i] = s[ru[i]];
    }
}

void turnDown(string s) {
    for (int i = 0; i < 10; i++) {
        l[i] = s[ld[i]];
        r[i] = s[rd[i]];
    }
}

void BFS1() {
    queue<si> q;
    q.push({s, 0});
    up[s] = 0;

    while (q.size()) {
        si x = q.front(); 
        q.pop();
        if (x.fi == t) {
            check = 1;
            cout << x.sc << endl;
            return;
        }
        if (x.sc > 14) return;
        turnUp(x.fi);
        if (up.find(l) == up.end()) {
            q.push({l, x.sc + 1});
            up[l] = x.sc + 1;
        }
        if (up.find(r) == up.end()) {
            q.push({r, x.sc + 1});
            up[r] = x.sc + 1;
        }
    }
}

void BFS2() {
    queue<si> q;
    q.push({t, 0});
    down[t] = 0;

    while (q.size()) {
        si x = q.front(); 
        q.pop();
        if (up.find(x.fi) != up.end()) {
            cout << x.sc + up[x.fi] << endl;
            return;
        }
        turnDown(x.fi);
        if (down.find(l) == down.end()) {
            q.push({l, x.sc + 1});
            down[l] = x.sc + 1;
        }
        if (down.find(r) == down.end()) {
            q.push({r, x.sc + 1});
            down[r] = x.sc + 1;
        }
    }
}



void process() {
    init();
    for (int i = 1; i <= 10; ++i) {
        int x; 
        cin >> x;
        s += char(x + '0');
    }
    BFS1();
    if (!check) BFS2();
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