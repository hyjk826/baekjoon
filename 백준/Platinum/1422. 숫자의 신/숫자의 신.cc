// 2022-12-21
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
	int K, N;
    cin >> K >> N;
    vi vec(K);
    vs A;
    for(int i{0}; i < K; ++i){
        cin >> vec[i];
        A.push_back(to_string(vec[i]));
    }
    N -= K;
    sort(vec.rbegin(), vec.rend());
    string mx = A.front();
    for(int i{0}; i < N; ++i){
        A.push_back(to_string(vec.front()));
    }
    sort(A.begin(), A.end(), [&](string a, string b){
        string s = a;
        string t = b;
        s += b;
        t += a;
        return s > t;
    });
    string ans;
    for(auto& i : A){
        ans += i;
    }
    cout << ans;
}
	
