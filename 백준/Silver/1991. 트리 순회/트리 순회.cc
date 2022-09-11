// 2022-09-11
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int n;
vector<vi> g(26);

void preorder(int k){
    if(k == '.' - 'A') return;
    cout << char('A' + k);
    for(auto& i : g[k]){
        preorder(i);
    }
}

void inorder(int k){
    if(k == '.' - 'A') return;
    inorder(g[k][0]);
    cout << char('A' + k);
    inorder(g[k][1]);
}

void postorder(int k){
    if(k == '.' - 'A') return;
    postorder(g[k][0]);
    postorder(g[k][1]);
    cout << char('A' + k);
} 

int main(){
    fastio;
    cin >> n;
    for(int i{0}; i < n; ++i){
        char a, b, c;
        cin >> a >> b >> c;
        g[a - 'A'].push_back(b - 'A');
        g[a - 'A'].push_back(c - 'A');
    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
}