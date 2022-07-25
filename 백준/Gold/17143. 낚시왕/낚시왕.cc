// 2022-07-25
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
    int x, y, v, d, s;
    bool operator< (st a){
        if(x == a.x){
            if(y == a.y){
                return s < a.s;
            }
            else return y < a.y;
        }
        else return x < a.x;
    }
};

int main() {
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vector<st> vec(k);
    int ans{0};
    int mn{-1};
    for(int i{0}; i < k; ++i){
        cin >> vec[i].x >> vec[i].y >> vec[i].v >> vec[i].d >> vec[i].s;
        vec[i].x--;
        vec[i].y--;
        if(vec[i].y == 0){
            if(mn == -1){
                mn = i;
                continue;
            }
            if(vec[i].x < vec[mn].x){
                mn = i;
            }
        }
    };
    if(mn != -1){
        ans += vec[mn].s;
        vec.erase(vec.begin() + mn);
    }
    for(int i{1}; i < m; ++i){
        vector<st> temp;
        vector<st> temp2;
        mn = -1;
        for(auto& j : vec){
            int x = j.x;
            int y = j.y;
            int v = j.v;
            if(j.d == 1){ // 위 아래 오른쪽 왼쪽
                v %= (n - 1) * 2;
                if(v <= x){
                    x -= v;
                } 
                else{
                    v -= x;
                    if(v <= n - 1) {
                        x = v;
                        j.d = 2;
                    }
                    else{
                        v -= n - 1;
                        x = n - 1 - v;
                    }
                }
            } 
            else if(j.d == 2){
                v %= (n - 1) * 2;
                if(v <= n - 1 - x){
                    x += v;
                }
                else{
                    v -= n - 1 - x;
                    if(v <= n - 1){
                        x = n - 1 - v;
                        j.d = 1;
                    }
                    else{
                        v -= n - 1;
                        x = v;
                    }
                }
            }
            else if(j.d == 3){
                v %= (m - 1) * 2;
                if(v <= m - 1 - y){
                    y += v;
                }
                else{
                    v -= m - 1 - y;
                    if(v <= m - 1){ 
                        y = m - 1 - v;
                        j.d = 4;
                    }
                    else{
                        v -= m - 1;
                        y = v;
                    }
                }
            }
            else{
                v %= (m - 1) * 2;
                if(v <= y){
                    y -= v;
                }
                else{
                    v -= y;
                    if(v <= m - 1){ 
                        y = v;
                        j.d = 3;
                    }
                    else{
                        v -= m - 1;
                        y = m - 1 - v;
                    }
                }
            }
            temp.push_back({x, y, j.v, j.d, j.s});
        }
        sort(temp.begin(), temp.end());
        vi v;    
        for(int j{0}; j < (int)temp.size(); ++j){
            if(j < (int)temp.size() - 1){
                if(temp[j].x == temp[j + 1].x && temp[j].y == temp[j + 1].y) continue;
                temp2.push_back(temp[j]);
                if(temp[j].y == i){
                    if(mn == -1) mn = j;
                    else{
                        if(temp[j].x < temp[mn].x) mn = j;
                    }
                }
            }
            else{
                if(temp[j].y == i){
                    if(mn == -1) mn = j;
                    else{
                        if(temp[j].x < temp[mn].x) mn = j;
                    }
                }
                temp2.push_back(temp[j]);
            }
        }
        if(mn != -1){
            for(int j{0}; j < (int)temp2.size(); ++j){
                if(temp2[j].y == i && temp2[j].s == temp[mn].s){
                    ans += temp2[j].s;
                    temp2.erase(temp2.begin() + j);
                    break;
                }
            }
        }
        vec = temp2;
    }
    cout << ans;
}

