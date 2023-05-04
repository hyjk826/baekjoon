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
    int t;
    cin >> t;
    while(t--){
        string a, b, c;
        cin >> a >> b >> c;
        vp A((int)c.size() + 1);
        vp B((int)c.size() + 1);
        A[0] = {-1,-1};
        B[0] = {-1,-1};
        int idx{0};
        for(int i{0}; i < (int)a.size(); ++i){
            if(idx < (int)c.size() && c[idx] == a[i]) {
                A[idx + 1].first = i;
                idx++;
            }
        }
        idx = 0;
        for(int i{0}; i < (int)b.size(); ++i){
            if(idx < (int)c.size() && c[idx] == b[i]) {
                B[idx + 1].first = i;
                idx++;
            }
        }
        idx = (int)c.size() - 1;
        for(int i{(int)a.size() - 1}; i >= 0; --i){
            if(idx >= 0 && c[idx] == a[i]){
                A[idx + 1].second = i;
                idx--;
            }
        }
        idx = (int)c.size() - 1;
        for(int i{(int)b.size() - 1}; i >= 0; --i){
            if(idx >= 0 && c[idx] == b[i]){
                B[idx + 1].second = i;
                idx--;
            }
        }
        A.push_back({a.size(), a.size()});
        B.push_back({b.size(), b.size()});
        vector<vi> g1(26), g2(26);
        for(int i{0}; i < (int)a.size(); ++i){
            g1[a[i] - 'a'].push_back(i);
        }
        for(int i{0}; i < (int)b.size(); ++i){
            g2[b[i] - 'a'].push_back(i);
        }
        bool ok = false;
        for(int i{0}; i < (int)A.size() - 1; ++i){
            int l1 = A[i].first + 1 ; int r1 = A[i + 1].second - 1;
            int l2 = B[i].first + 1; int r2 = B[i + 1].second - 1;
            if(l1 > r1) continue;
            if(l2 > r2) continue;
            for(int j{0}; j < 26; ++j){
                int x = upper_bound(g1[j].begin(), g1[j].end(), r1) - lower_bound(g1[j].begin(), g1[j].end(), l1);
                int y = upper_bound(g2[j].begin(), g2[j].end(), r2) - lower_bound(g2[j].begin(), g2[j].end(), l2);
                if(x > 0 && y > 0){
                    ok = true; break;
                }
            }
            if(ok) break;
        }
        if(ok) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
	
}
