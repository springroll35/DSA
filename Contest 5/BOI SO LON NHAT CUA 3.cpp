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

void process() {
    priority_queue<int, std::vector<int>, greater<int> > q1, q2;
    priority_queue<int> q;
    int n;
    int sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        if(x % 3 == 1) {
            q1.push(x);
        }
        else if(x % 3 == 2) {
            q2.push(x);
        }
        else {
            q.push(x);
        }
    }
    if(sum == 0) {
        cout << 0 << endl;
        return;
    }
    if(sum % 3 == 1) {
        if(q1.empty()) {
            if(q2.empty()) {
                cout << -1 << endl;
                return;
            }
            else {
                q2.pop();
            }
            if(q2.empty()) {
                cout << -1 << endl;
                return;
            }
            else {
                q2.pop();
            }
        }
        else q1.pop();
    }
    else if(sum % 3 == 2) {
        if(q2.empty()) {
            if(q1.empty()) {
                cout << -1 << endl;
                return;
            }
            else {
                q1.pop();
            }
            if(q1.empty()) {
                cout << -1 << endl;
                return;
            }
            else {
                q1.pop();
            }
        }
        else {
            q2.pop();
        }
    }
    while(q1.size()) q.push(q1.top()), q1.pop();
    while(q2.size()) q.push(q2.top()), q2.pop();
    if(q.empty()) {
        cout << -1;
    }
    while(q.size()) cout << q.top(), q.pop();
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