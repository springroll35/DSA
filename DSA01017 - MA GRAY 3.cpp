#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define sc second
#define pb push_back
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int n;

char cxor(char x, char y) {
    return (x == y ? '0' : '1'); 
}

char cnot(char x) {
    return (x == '0' ? '1' : '0');
}

void process() {
    // chuyen nhi phan sang ma gray
    string binary;
    cin >> binary;
    string gray;
    // bit dau tien bang nhau
    gray += binary[0];
    for(int i = 1; i < binary.size(); i++) {
        // bit gray = xor cua bit nhi phan voi bit nhi phan lien ke truoc no
        gray += cxor(binary[i-1], binary[i]);
    }
    cout << gray << endl;
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