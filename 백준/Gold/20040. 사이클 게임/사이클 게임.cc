// 2022-09-14
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

vi uni(500001);

int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        uni[a] = b;
        return true;
    }
    return false;
}


int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    for(int i{0}; i < n; ++i) uni[i] = i;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        if(!Union(a, b)){
            cout << i + 1;
            return 0;
        }
    }
    cout << 0;
}
	

