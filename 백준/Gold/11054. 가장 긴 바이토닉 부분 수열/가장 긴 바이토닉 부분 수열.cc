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

int main(){
    fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi A(n), B(n);
    vi v;
    v.push_back(-MAX);
    for(int i{0}; i < n; ++i){
        if(v.back() < vec[i]){
            v.push_back(vec[i]);
            A[i] = v.size() - 1;
        }
        else{
            int index = lower_bound(v.begin(), v.end(), vec[i]) - v.begin();
            v[index] = vec[i];
            A[i] = index;
        }
    }
    v.clear();
    reverse(vec.begin(), vec.end());
    v.push_back(-MAX);
    for(int i{0}; i < n; ++i){
        if(v.back() < vec[i]){
            v.push_back(vec[i]);
            B[i] = v.size() - 1;
        }
        else{
            int index = lower_bound(v.begin(), v.end(), vec[i]) - v.begin();
            v[index] = vec[i];
            B[i] = index;
        }
    }
    reverse(B.begin(), B.end());
    int ans{0};
    for(int i{0}; i < n; ++i){
        ans = max(ans, A[i] + B[i] - 1);
    }
    cout << ans;
}