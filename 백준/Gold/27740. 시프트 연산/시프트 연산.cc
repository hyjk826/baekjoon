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
    vi A;
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        if(a == 1) A.push_back(i);
    }
    int ans = A.back();
    string str = string(A.back(), 'L');
    if(n + 1 - A[0] < ans){
        ans = n + 1 - A[0];
        str = string(n + 1 - A[0], 'R');
    }
    for(int i{0}; i < (int)A.size() - 1; ++i){
        int sum = A[i] + A[i] + (n + 1 - A[i + 1]);
        if(sum < ans){
            ans = sum;
            str.clear();
            str = string(A[i], 'L');
            str += string(A[i] + (n + 1 - A[i + 1]), 'R');
        }
    }
    for(int i{(int)A.size() - 1}; i >= 1; --i){
        int k = n + 1 - A[i];
        int sum = k + k + A[i - 1];
        if(sum < ans){
            ans = sum;
            str.clear();
            str = string(k, 'R');
            str += string(k + A[i - 1], 'L');
        }
    }
    cout << ans << "\n" << str;
}
