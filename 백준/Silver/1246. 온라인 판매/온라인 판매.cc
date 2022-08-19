// 2022-08-19
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

int main(){
    fastio;
	int n, m;
    cin >> n >> m;
    vi vec(m);
    for(int i{0}; i < m; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int mx{0};
    int a;
    for(int i{0}; i < m; ++i){
        if(mx < min(n, (m - i)) * vec[i]){
            mx = min(n, (m - i)) * vec[i];
            a = vec[i];
        }
    }
    cout << a << " " << mx;
}