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

struct st{
    int x, y, z;
};

int main(){
	fastio;
    while(1){
        int n, a, b;
        cin >> n >> a >> b;
        if(n + a + b == 0) break;
        vector<st> vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i].x >> vec[i].y >> vec[i].z;
        }      
        int ans{0};
        int x{0}, y{0};
        vector<st> A, B;
        for(int i{0}; i < n; ++i){
            if(vec[i].y <= vec[i].z) {
                x += vec[i].x;
                ans += vec[i].y * vec[i].x;
                A.push_back(vec[i]);
            }
            else{
                y += vec[i].x;
                ans += vec[i].z * vec[i].x;
                B.push_back(vec[i]);
            }
        }
        if(x <= a && y <= b) cout << ans << "\n";
        else if(x > a){
            sort(A.begin(), A.end(), [&](st& q, st& w){
                return q.z - q.y < w.z - w.y;
            });
            int need = x - a;
            for(auto& i : A){
                int mn = min(need, i.x);
                ans += mn * (i.z - i.y);
                need -= mn;
            }
            cout << ans << "\n";
        }
        else if(y > b){
            sort(B.begin(), B.end(), [&](st& q, st& w){
                return q.y - q.z < w.y - w.z;
            });
            int need = y - b;
            for(auto& i : B){
                int mn = min(need, i.x);
                ans += mn * (i.y - i.z);
                need -= mn;
            }
            cout << ans << "\n";
        }
    }
}
