
#include <stdio.h>
# include <string.h>
# define MAXLINE 80
void encrypt ( char *s);
int main (void)
{
   char line [MAXLINE];

   gets(line);
   encrypt (line);
   printf ("%s\n", line);
     return 0;
}


/* 请在这里填写答案 */
void encrypt ( char *s)
{
    for (int i = 0; i < 80;i++)
    {
        if(s[i]==0)
        {
            break;
        }
        if(s[i]=='z')
        {
            s[i] = 'a';
        }
        else
            s[i] += 1;
    }
}