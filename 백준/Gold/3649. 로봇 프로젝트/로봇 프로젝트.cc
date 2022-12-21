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
	int x;
    while(cin >> x){
        x *= (int)1e7;
        int n;
        cin >> n;
        vi vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        int j = n - 1;
        bool ok = false;
        for(int i{0}; i < n; ++i){
            while(i < j && vec[i] + vec[j] > x){
                j--;
            }
            if(i >= j) break;
            if(vec[i] + vec[j] == x){
                cout << "yes " << vec[i] << " " << vec[j] << "\n";
                ok = true;
                break;
            }
        }
        if(ok) continue;
        cout << "danger\n";
    }
}
	
