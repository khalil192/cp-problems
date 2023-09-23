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
lli mod = 1e9 + 7;

lli gcd(lli a, lli b){
      if (b == 0)
        return a;
      return gcd(b, a % b);
}


bool isPow2(lli x){
     if(x <= 1){
          return true;
     }

     while(x%2 == 0){
          x /= 2;
     }
     return x == 1;
}

lli getSplit(lli x){
     lli p = 1;

     while(p < 1e11){
          if(isPow2(p+x)){
               return p;
          }
          p *= 2;
     }

     return -1;
}

void solve(){
     lli n;
     cin>>n;

     vi a(n);
     lli sum =0;

     fo(i,n){
          cin>>a[i];
          sum += a[i];
     }

     if(sum %n != 0){
          cout<<"No\n"; return;
     }

     lli avg = sum/n;

     vi ex, ne;
     fo(i,n){
          if(a[i] == avg){
               continue;
          }
          if(a[i] > avg){
               // cout<<"at here\n";
               
               lli x = a[i] - avg;
               lli s = getSplit(x);
               if(s == -1){cout<<"No\n"; return;}

               // we have s, s + x
               //  remove s+x, add x
               ex.push_back(s+x);
               ne.push_back(s);
               // cout<<"ex = "<<s+x<<" "<<s<<"\n";
          }
          else{
               // cout<<"here "<<a[i]<<"\n";
               lli x = avg - a[i];
               lli s = getSplit(x);
               if(s == -1){cout<<"No\n"; return;}

               //  add s+x, remove s 
               ex.push_back(s);
               ne.push_back(s+x);
               // cout<<"ne = "<<s+x<<" "<<s<<"\n";

          }
     
     
     }

     sort(ex.begin(),ex.end());
     sort(ne.begin(),ne.end());

     if(ex != ne){
          cout<<"No\n"; return;
     }

     cout<<"Yes\n";

}  

int main(){

     ULTRA_INSTINCT;
     lli t = 1;
     cin >> t;
     fo(i, t){
          //   cout<<"Case #"<<i+1<<": ";
          solve();
     }
     return 0;
}