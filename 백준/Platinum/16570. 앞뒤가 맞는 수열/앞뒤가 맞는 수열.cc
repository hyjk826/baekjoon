#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<vecing>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vi Z_algorithm(vi& vec){
    int l{0}, r{0};
    vi z((int)vec.size());
    for(int i{1}; i < (int)vec.size(); ++i){
        if(i > r){
            l = r = i;
            while(r < (int)vec.size() && vec[r - l] == vec[r]) r++;
            z[i] = r - l; r--;
        }
        else{
            int k = i - l;
            if(z[k] < r - i + 1) z[i] = z[k];
            else{
                l = i;
                while(r < (int)vec.size() && vec[r - l] == vec[r]) r++;
                z[i] = r - l; r--;
            }
        }
    }
    return z;
}

int main(){
	fastio;
	int n;
    cin >> n;
    vi vec(n);
    for(int i{n - 1}; i >= 0; --i){
        cin >> vec[i];
    }
    auto Z = Z_algorithm(vec);
    int mx = *max_element(Z.begin(), Z.end());
    if(mx == 0) cout << -1;
    else{
        cout << mx << " " << count(Z.begin(), Z.end(), mx);
    }
}
