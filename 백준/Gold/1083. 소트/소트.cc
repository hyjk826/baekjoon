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
	int n, k;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    cin >> k;
    int index{0};
    while(k && index < n){
        int mx{index};
        for(int i{index}; i <= min(n - 1, index + k); ++i){
            if(vec[mx] < vec[i]){
                mx = i;
            }
        }
        for(int i{mx}; i > index; --i){
            swap(vec[i], vec[i - 1]);
        }
        k -= mx - index;
        index++;
    }
    for(auto& i : vec){
        cout << i << " ";
    }
}