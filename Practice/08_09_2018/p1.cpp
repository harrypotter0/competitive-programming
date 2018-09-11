int remAnagram(){
 int a[26]={0},b[26]={0};
 for (int i =0;i<str1.size();i++{
     a[str1[i]-97]+=1;
 }
 for(int i =0;i<str2.size();i++){
     a[str2[i]-97]+=1;
 }
 int n =0;
 for(int i =0;i<26;i++){
     n+=abs(a[i]-b[i]);
 }
 return n;
}