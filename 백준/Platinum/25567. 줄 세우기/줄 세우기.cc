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

vi front((int)2e5 + 1);
vi back((int)2e5 + 1);
vi p1((int)2e5 + 1);
vi p2((int)2e5 + 1);


int front_find(int a){
    if(a == p1[a]) return a;
    return p1[a] = front_find(p1[a]);
}

int back_find(int a){
    if(a == p2[a]) return a;
    return p2[a] = back_find(p2[a]);
}

bool merge(int a, int b){
    a = back_find(a);
    int fb = back_find(b);
    if(a == fb) return false;
    b = front_find(b);
    back[a] = b;
    p2[a] = b;
    front[b] = a;
    p1[b] = a;
    return true;
}

int main(){
	fastio;
    int n;
    cin >> n;
    int mx{0};
    for(int i{0}; i < n; ++i){
        int m;
        cin >> m;
        vi A(m);
        for(int j{0}; j < m; ++j){
            cin >> A[j];
            mx = max(mx, A[j]);
        }
        front[A[0]] = A[0];
        p1[A[0]] = A[0];
        back[A[m - 1]] = A[m - 1];
        p2[A[m - 1]] = A[m - 1];
        for(int i{0}; i < m - 1; ++i){
            back[A[i]] = A[i + 1];
            p2[A[i]] = A[i + 1];
        }
        for(int i{1}; i < m; ++i){
            front[A[i]] = A[i - 1];
            p1[A[i]] = A[i - 1];
        }
    }
    int q;
    cin >> q;
    vl query(q);
    struct st{
        int a, b, idx;
    };
    vector<st> A;
    for(int i{0}; i < q; ++i){
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 1){
            if(merge(a, b)){
                query[i] = -1;
            }
            else query[i] = -2;
        }
        else{            
            int fa = front_find(a);
            int fb = front_find(b);
            if(fa != fb){
                query[i] = -3;
            }
            else A.push_back({a, b, i});
        }
    }
    vl B(mx + 1);
    for(int i{1}; i <= mx; ++i){
        if(B[i]) continue;
        int f = front_find(i);
        ll sum{0};
        while(1){
            sum += f;
            B[f] = sum;
            if(back[f] == f) break;
            f = back[f]; 
        }
    }
    for(auto& i : A){
        int a = i.a;
        int b = i.b;
        if(a == b) query[i.idx] = a;
        else{
            if(B[a] < B[b]){
                if(front[a] == a) query[i.idx] = B[b];
                else query[i.idx] = B[b] - B[front[a]];
            }
            else{
                if(front[b] == b) query[i.idx] = B[a];
                else query[i.idx] = B[a] - B[front[b]];
            }
        }
    }
    for(int i{0}; i < q; ++i){
        if(query[i] == -1) cout << "YES\n";
        else if(query[i] == -2) cout << "NO\n";
        else if(query[i] == -3) cout << -1 << "\n";
        else cout << query[i] << "\n";
    }
}
