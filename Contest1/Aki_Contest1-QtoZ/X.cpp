/**
  Template by Akikaze (秋風) - formerly proptit_4t41.
  Code written by a random fan of momocashew and Chiho.
  
  H△G x Mili - November 27th, 2013
  Mag Mell (Mili) - Sep 17th, 2014
  H△G x Mili Vol.2 - May 9th, 2015
  Miracle Milk (Mili) - Oct 12th, 2016
  青色フィルム (H△G) - February 14th, 2018
  Millennium Mother (Mili) - April 25th, 2018
**/

/** -----PRAGMA----- **/
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define ld long double
#define pub push_back
#define mp make_pair
#define fi first
#define se second
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/


/** -----GLOBAL VARIABLES----- **/
string s1, s2; i64 n1, n2;
vector<vi> dp(1004, vi(1004, -1));

/** -----EXTENSIVE FUNCTIONS----- **/
i64 LCS(i64 x, i64 y) {
  if (x < 0 || y < 0) return 0;
  if (dp[x][y] != -1) return dp[x][y];
  if (s1[x] == s2[y]) {
    dp[x][y] = (LCS(x-1, y-1) + 1);
    return dp[x][y];
  }
  dp[x][y] = max(LCS(x, y-1), LCS(x-1, y));
  return dp[x][y];
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  cin >> s1 >> s2; n1 = s1.size(); n2 = s2.size();
}

void ProSolve() {
  cout << LCS(n1-1, n2-1);
}

/** -----MAIN FUNCTION----- **/
int main() {
      #ifdef Akikaze
      //freopen("FILE.INP", "r", stdin);
      //freopen("FILE.OUT", "w", stdout);
      #endif
  VarInput();
      #ifdef Akikaze
      auto TIME1 = chrono::steady_clock::now();
      #endif
  ProSolve();
      #ifdef Akikaze
      auto TIME2 = chrono::steady_clock::now();
      auto DIFF = TIME2 - TIME1;
      cout << "\n\nTime elapsed: " << fixed << setprecision(18) << chrono::duration<double>(DIFF).count() << " seconds.";
      #endif
  return 0;
}