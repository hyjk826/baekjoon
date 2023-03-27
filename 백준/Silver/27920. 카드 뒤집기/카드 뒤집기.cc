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
    int n;
    cin >> n;
    vi vec;
    for(int i{n - (n % 2 == 0)}; i >= 1; i -= 2){
        vec.push_back(i);
    }
    for(int i{2}; i <= n; i += 2){
        vec.push_back(i);
    }
    vp A;
    for(int i{0}; i < n; ++i){
        A.push_back({vec[i], i});
    }
    sort(A.begin(), A.end());
    cout << "YES\n";
    for(auto& i : vec) cout << i << " ";
    cout << "\n";
    for(auto& i : A) cout << i.second + 1 << " ";
}
