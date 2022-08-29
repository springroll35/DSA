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

int ans;

struct Node
{
    Node* pLeft;
    Node* pRight;
    int data;
    Node(int x) {
        this->data = x;
        pLeft = pRight = NULL;
    }
};

typedef Node* tree;

void add(tree& T, int u, int v, char c) {
    if(!T) {
        T = new Node(u);
        tree p = new Node(v);
        if(c == 'L') T->pLeft = p;
        else T->pRight = p;
    }
    else {
        if(T->data == u) {
            tree p = new Node(v);
            if(c == 'L') T->pLeft = p;
            else T->pRight = p;
        }
        else {
            if(T->pLeft) add(T->pLeft, u, v, c);
            if(T->pRight) add(T->pRight, u, v, c);
        }
    }
}

int query(tree T) {
    if(!T) return 0;
    if(!T->pLeft && !T->pRight) return T->data;
    int sumLeft = query(T->pLeft);
    int sumRight = query(T->pRight);
    if(!T->pLeft) return sumRight + T->data;
    if(!T->pRight) return sumLeft + T->data;
    if(T->pLeft && T->pRight) {
        ans = max(ans, sumLeft + sumRight + T->data);
        return max(sumLeft, sumRight) + T->data;
    }
}

void process() {
    int n;
    cin >> n;
    tree t = NULL;
    while(n--) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        add(t, u, v, c);
    }
    ans = -1e9;
    query(t);
    cout << ans << endl;
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