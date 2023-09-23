#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#define lli long long int
#define mp make_pair
#define ULTRA_INSTINCT                 \
     ios_base::sync_with_stdio(false); \
     cin.tie(0)
#define fo(i, n) for (lli i = 0; i < (n); i++)
#define FO(i, x, n) for (lli i = (x); i < (n); i++)
#define pb push_back
#define vi vector<lli>
#define pi pair<lli, lli>
#define vii vector<pi>
#define Endl "\n"
using namespace std;
const lli mod = 1e9 + 7;

lli gcd(lli a, lli b){
      if (b == 0)
        return a;
      return gcd(b, a % b);
}


//problem : https://cses.fi/problemset/task/1634

void solve(){

     lli n,k;
     cin>>n>>k;

     vi a(n);

     fo(i,n){
          cin>>a[i];
     }

     vi dp(k+1, 1e8);

     dp[0] = 0;
     FO(i,1,k+1){
          fo(j,n){
               if(a[j] <= i){
                    dp[i] = min(dp[i], dp[i - a[j]] +1);
               }
          }
     }

     if(dp[k] == 1e8){
          dp[k] = -1;
     }

     cout<<dp[k]<<"\n";

     


}

int main(){

     ULTRA_INSTINCT;
     lli t = 1;
     // cin >> t;
     fo(i, t){
          //   cout<<"Case #"<<i+1<<": ";
          solve();
     }
     return 0;
}