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
    // chuyen ma gray sang nhi phan
    string gray;
    cin >> gray;
    string binary;
    // bit dau tien bang nhau
    binary += gray[0];
    for(int i = 1; i < gray.size(); i++) {
        // bit gray = 0 thi sao chep bit nhi phan truoc
        if (gray[i] == '0') binary += binary[i-1];
        // neu khong thi lay bit dao cua bit nhi phan truoc
        else binary += cnot(binary[i-1]);
    }
    cout << binary << endl;
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