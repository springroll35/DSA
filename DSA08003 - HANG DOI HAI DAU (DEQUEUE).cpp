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
    int t;
    cin >> t;
    deque<int> q;
    while(t--) {
        string s;
        cin >> s;
        if(s == "PUSHFRONT" || s == "PUSHBACK") {
            int x;
            cin >> x;
            if (s == "PUSHFRONT") q.push_front(x);
            else q.push_back(x);
        }
        if(s == "PRINTFRONT") {
            if (q.size()) cout << q.front() << endl;
            else cout << "NONE" << endl;
        }
        if(s == "PRINTBACK") {
            if (q.size()) cout << q.back() << endl;
            else cout << "NONE" << endl;
        }
        if(q.size() && s == "POPFRONT") {
            q.pop_front();
        }
        if(q.size() && s == "POPBACK") {
            q.pop_back();
        }
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