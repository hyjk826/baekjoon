// 2022-08-14
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

struct st{
    int m, s, d;
};

int main() {
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    map<pi, vector<st>> mp; 
    int xx[]{-1,-1,0,1,1,1,0,-1};
    int yy[]{0,1,1,1,0,-1,-1,-1};
    for(int i{0}; i < m; ++i){
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        r--;
        c--;
        mp[{r, c}].push_back({m, s, d});
    }
    for(int i{0}; i < k; ++i){
        map<pi, vector<st> > temp;
        for(auto& j : mp){
            for(auto& k : j.second){
                int nx = (j.first.first + xx[k.d] * k.s + n * 1000) % n;
                int ny = (j.first.second + yy[k.d] * k.s + n * 1000) % n;
                temp[{nx, ny}].push_back({k.m, k.s, k.d});
            }
        }
        map<pi, vector<st> > temp2;
        for(auto& j : temp){
            if(j.second.size() == 1){
                 temp2[{j.first.first, j.first.second}].push_back({j.second.front().m, j.second.front().s, j.second.front().d});
                 continue;
            }
            int sumM{0}, sumS{0};
            vi d;
            for(auto& k : j.second){
                sumM += k.m;
                sumS += k.s;
                d.push_back(k.d);
            }
            bool flag = true;
            for(int k{0}; k < (int)d.size(); ++k){
                if(d[k] % 2 != d[0] % 2) flag = false;
            }
            int mm = sumM / 5;
            int ss = sumS / (int)j.second.size();
            if(mm == 0) continue;
            int dd = 0;
            if(!flag) dd = 1; 
            for(int k{dd}; k < 8; k += 2){
                temp2[{j.first.first, j.first.second}].push_back({mm, ss, k});
            }
        }
        mp = temp2;
    }
    int ans{0};
    for(auto& i : mp){
        for(auto& j : i.second){
            ans += j.m;
        }
    }
    cout << ans;
}

