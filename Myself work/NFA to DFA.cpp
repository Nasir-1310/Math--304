#include<bits/stdc++.h>
using namespace std;

#define a 1
#define ab 2
#define abc 3
#define abcd 4
#define ad 5
#define abd 6
#define max 100

int main()
{
 char s[max];
 string path[max];
 int f = a;
 int head = -1;

 printf("Enter your string : ");
 scanf("%s",s);

 for(int i = 0 ; s[i] != '\0' ; i++)
 {
  switch(f)
  {
  case a : if(s[i] == '0')
   {
    f = a;
    head++;
    path[head] = "a";
   }
   else if(s[i] == '1')
   {
    f = ab;
    head++;
    path[head] = "ab";
   }
  break;
     case ab : if(s[i] == '0')
      {
       f = a;
       head++;
       path[head] = "a";
      }
      else if(s[i] == '1')
      {
       f = abc;
       head++;
       path[head] = "abc";
      }
     break;
     case abc : if(s[i] == '0')
      {
       f = a;
       head++;
       path[head] = "a";
      }
      else if(s[i] == '1')
      {
       f = abcd;
       head++;
       path[head] = "abcd";
      }
     break;
     case abcd : if(s[i] == '0')
      {
       f = ad;
       head++;
       path[head] = "ad";
      }
      else if(s[i] == '1')
      {
       f = abcd;
       head++;
       path[head] = "abcd";
      }
     break;
        case ad : if(s[i] == '0')
      {
       f = ad;
       head++;
       path[head] = "ad";
      }
      else if(s[i] == '1')
      {
       f = abd;
       head++;
       path[head] = "abd";
      }
     break;
        case abd : if(s[i] == '0')
      {
       f = ad;
       head++;
       path[head] = "ad";
      }
      else if(s[i] == '1')
      {
       f = abcd;
       head++;
       path[head] = "abcd";
      }
     break;

  }
 }

 if(f == abcd||  f == abd || f == ad)
 {
  printf("Your string is accepted!\n");
  printf("path : ");
  for(int j = 0 ; j <=head ; j++) cout << path[j] << " ";
   printf("\n");
 }
 else printf("Your String is not accepted!\n");

 return 0;
}
