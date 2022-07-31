// 2022-07-30
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int n;
vi graph[10001];
vi lv[10001];
int cnt{1};

void inorder(int v, int L){
    if(v == -1 || graph[v].size() == 0) return;
    inorder(graph[v][0], L + 1);
    lv[L].push_back(cnt++);
    inorder(graph[v][1], L + 1);
}

int main() {
	fastio;
	cin >> n;
    vi ch(n + 1);
    for(int i{0}; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        if(b != -1) ch[b]++;
        if(c != -1) ch[c]++;
        graph[a].push_back(b);
        graph[a].push_back(c);
    }
    int root{-1};
    for(int i{1}; i <= n; ++i){
        if(ch[i] == 0) {
            root = i;
            break;
        }
    }
    inorder(root, 1);
    int ansL{-1};
    int mx{0};
    for(int i{1}; i <= 10000; ++i){
        if(lv[i].size() == 0) continue;
        sort(lv[i].begin(), lv[i].end());
        int k = lv[i].back() - lv[i].front() + 1;
        if(k > mx){
            ansL = i;
            mx = k;
        }
    }
    cout << ansL << " " << mx;
}

