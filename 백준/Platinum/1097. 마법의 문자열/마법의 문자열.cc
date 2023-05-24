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

vi Z_algorithm(string str){
    int l{0}, r{0};
    vi z((int)str.size());
    for(int i{1}; i < (int)str.size(); ++i){
        if(i > r){
            l = r = i;
            while(r < (int)str.size() && str[r - l] == str[r]) r++;
            z[i] = r - l; r--;
        }
        else{
            int k = i - l;
            if(z[k] < r - i + 1) z[i] = z[k];
            else{
                l = i;
                while(r < (int)str.size() && str[r - l] == str[r]) r++;
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
    vs vec(n);
    int a = 0;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        a += (int)vec[i].size();
    }
    sort(vec.begin(), vec.end());
    int ans{0};
    int k;
    cin >> k;
    int cnt{0};
    vi A(n);
    iota(A.begin(), A.end(), 0);
    do{
        string tmp;
        for(auto& i : A) tmp += vec[i];
        auto Z = Z_algorithm(tmp);
        int mn{1};
        for(int i{0}; i < (int)Z.size(); ++i){
            if(Z[i] + i == a){
                if(a % i == 0){
                    mn = a / i; 
                }
                break;
            }
        }
        if(mn == k) ans++;
    }while(next_permutation(A.begin(), A.end()));
    cout << ans;
}
