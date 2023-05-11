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
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
	fastio;
    bool ex = false;
	for(int i{1};;++i){
        int a, b;
        vector<vi> g(20);
        vi degree(20);
        vi ch(20);
        int cnt{0};
        while(cin >> a >> b){
            if(a == -1 && b == -1){
                ex = true; break;
            }
            if(a == 0 && b == 0) break;
            g[a].push_back(b);
            ch[a] = ch[b] = 1;
            degree[b]++;
            cnt++;
        }
        if(ex) break;
        bool ok = true;
        vi A;
        for(int i{0}; i < 20; ++i){
            if(ch[i] == 0) continue;
            if(degree[i] == 0) A.push_back(i);
            else ok &= (degree[i] == 1);
        }
        if(A.size() != 1) ok = false;
        if(cnt == 0 || ok) cout << "Case " << i << " is a tree.\n";
        else cout << "Case " << i << " is not a tree.\n";
    }
}
