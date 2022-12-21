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

int LIS(vi &A)
{
    vi v;
    for (int i{0}; i < (int)A.size(); ++i)
    {
        if (v.empty() || v.back() <= A[i])
            v.push_back(A[i]);
        else
        {
            int idx = upper_bound(v.begin(), v.end(), A[i]) - v.begin();
            v[idx] = A[i];
        }
    }
    return v.size();
}

int main(){
	fastio;
	int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vp vec;
    for(int i{0}; i < k; ++i){
        int a, b;
        cin >> a >> b;
        if(a > n || b > m) continue;
        vec.push_back({a, b});
    }
    sort(vec.begin(), vec.end());
    vi A;
    for(auto& i : vec) A.push_back(i.second);
    cout << LIS(A);
}
	
