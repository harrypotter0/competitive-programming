// Normal Nim ==> First Player who is not able to make a move loses :)
#include <iostream>
#include <string>

using namespace std;

   int main() {
      int t; cin >> t;
      while (t--) {
         string s; cin >> s;
         int i = -1, A  = 0, B = 0, nim = 0;

         auto add = [&](auto j) { // lambda function for addition
            if (s[i] == 'A') A += j - i - 1;
            if (s[i] == 'B') B += j - i - 1;
         };

         for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '.') continue;
            if (i == -1) i = j;
            else {
               if (s[j] == s[i]) add(j);
               else if (j - i != 1) nim ^= (j - i - 1);  // XOR of A-B moves
               i = -1;
            }
         }
         if (i != -1) add(s.size());

         if (A == B) cout << (nim != 0 ? "A\n" : "B\n"); // If no of spaces b/w A and B becomes equal then go for nim game
         else        cout << (A > B    ? "A\n" : "B\n"); // Else whoever has greater no of moves left is the winner
      }
      return 0;
   }