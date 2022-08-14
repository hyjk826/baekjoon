// 2022-08-14
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

vi cnt(1000001);

int main() {
	fastio;
    int n;
    cin >> n;
    vi vec(n);    
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        cnt[vec[i]]++;
    }
    reverse(vec.begin(), vec.end());
    vi A;
    vi ans;
    for(int i{0}; i < n; ++i){
        while(!A.empty() && cnt[A.back()] <= cnt[vec[i]]) A.pop_back();
        if(A.empty()) ans.push_back(-1);
        else ans.push_back(A.back());
        A.push_back(vec[i]);
    }
    reverse(ans.begin(), ans.end());
    for(auto& i : ans){
        cout << i << " ";
    }
}

