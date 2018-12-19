// Reverse Nim : The player that cannot make a move for the first time wins.
#include<bits/stdc++.h>
using namespace std;

int tc;
int n;
string s;

string stak[55];

int bn[2];

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   cin >> tc;
   while(tc--){
      memset(bn,0,sizeof(bn));
      cin >> n >> s;
      for(int i=1;i<=n;i++){
         cin >> stak[i];
         bn[stak[i][0]-'0']++;
         for(int j=1;j<stak[i].size();j++){
            if(stak[i][j] != stak[i][j-1]) bn[stak[i][j] - '0']++; // compress similar consecutive values
         }
      }
      //dee 0, dum 1
      int tmp = 0;
      if(s == "Dum") tmp = 1; 
      if(bn[0] > bn[1]) printf("Dum\n"); // If number of moves of Dee (0) is more than Dum(1) is winner
      else if(bn[1] > bn[0]) printf("Dee\n"); // else opposite 
      else if(tmp == 1) printf("Dum\n"); // First Player is the winner here Dum  
      else printf("Dee\n");
   }
 	return 0;
}
