// Given a list of items with their weights and values
// Find the maximum value one can obtain with a total weight limit
// Time complexity: O(nw)
// Problem link: https://cses.fi/problemset/task/1158

#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;


//recursive

int n,m,q,r;
int dp[1005][100009];
int weight[1005];
int val[1005];

int solution(int price,int ind)
{
    if(ind==n and price>=0)return 0;
    if(price<0)return INT_MIN;
    if(price==0)return 0;
    if(dp[ind][price]!=-1)return dp[ind][price];
    int temp=0;
    temp=max(temp,max(solution(price,ind+1),val[ind]+solution(price-weight[ind],ind+1)));
    return dp[ind][price]=temp;
}




void solve() {
    int n, w; cin >> n >> w;
    int weight[n], val[n];
    for (int i = 0; i < n; i++) cin >> weight[i];
    for (int i = 0; i < n; i++) cin >> val[i];

    int dp[w + 1] = {};
    for (int i = 0; i < n; i++)
        for (int j = w; j >= weight[i]; j--)
            dp[j] = max(dp[j], dp[j - weight[i]] + val[i]);
    cout << dp[w] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc; tc = 1;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}