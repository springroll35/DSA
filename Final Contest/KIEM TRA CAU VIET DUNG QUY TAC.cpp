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

string check(string s) {
    stack<char> st;
    for(char i : s) {
        if(i == '(' || i == '[') st.push(i);
        if(i == ')') {
            if(st.size() && st.top() == '(') st.pop();
            else return "NO";
        }
        else if(i == ']') {
            if(st.size() && st.top() == '[') st.pop();
            else return "NO";
        }
    }
    if(st.empty()) return "YES";
    return "NO";
}

void process() {
    string s;
    getline(cin, s);
    cout << check(s) << endl;
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
    cin.ignore();
    while(test--) {
        process();
    }
    

    return 0;
}