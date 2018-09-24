#include <iostream>
using namespace std;
void findLongestPalindromicString(string text)
{
    int N =text.size();
    if(N == 0)return;
    N = 2*N + 1;
    int L[N]; L[0] = 0;L[1] = 1;
    int C = 1,R = 2,i = 0,iMirror,maxLPSLength=0;
    int maxLPSCenterPosition=0,start=-1,end=-1;
    int diff = -1;
    for (i = 1; i < N; i++) 
    {
        iMirror  = 2*C-i;
        L[i] = 0; diff = R - i;
        if(diff > 0) L[i] = min(L[iMirror], diff);
        while ( ((i + L[i]) < N && (i - L[i]) > 0) && 
            ( ((i + L[i] + 1) % 2 == 0) || 
        (text[(i + L[i] + 1)/2] == text[(i - L[i] - 1)/2] )))
        {
            L[i]++;
        }
        if(L[i] > maxLPSLength)
        {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }
        if (i + L[i] > R) 
        {
            C = i;
            R = i + L[i];
        }
    }
    start = (maxLPSCenterPosition - maxLPSLength)/2;
    end = start + maxLPSLength - 1;
    for(i=start; i<=end; i++)
        cout<<text[i];
    cout<<"\n";
}
int main() {
int t;cin>>t;
while(t--){
    string str;cin>>str;
    findLongestPalindromicString(str);
}
	return 0;
}