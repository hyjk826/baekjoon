// 2022-06-26
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int k;
    cin >> k;
    int n;
    cin >> n;
    int sum{0};
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        sum += a * b;
    }
    if(sum == k) cout << "Yes";
    else cout << "No";
}
