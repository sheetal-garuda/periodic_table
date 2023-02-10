#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "grep.h"
int isSubstring(char* source,char* pattern) /*This function
 is used to
 find if a line
 contains the
pattern */
{
 int count1= strlen(source);
 int count2=strlen(pattern);
 int flag;
 for (int i = 0; i <= count1 - count2; i++)
 {
 for (int j = i; j < i + count2; j++)
 {
 flag = 1;
 if (source[j] != pattern[j - i])
 {
 flag = 0; /* not a
 substring */
 break;
 }
 }
 if (flag == 1) //substring
 break;
 }
 return flag;
}
void findPatternIgnoreCase(FILE *f, char* pattern, char* result) /*Upper
 case */

{
 char temp[10000];
 /* To store the
 Original line
 */
 char pattern1[10000];
 /* To convert
 The case to
 Upper */
 strcpy(pattern1,pattern);
 for(int i=0; pattern1[i] != '\0'; i++)
 pattern1[i]=toupper(pattern1[i]); /* converting
 each letter
 to upper */
 while( fgets ( temp, 10000, f ) != NULL ) /* stores each 
 line */
 {
 char *str = (char *)calloc(10000,sizeof(char));
 strcpy(str,temp); /*Storing each
 line from file
*/
 for(int i=0; temp[i] != '\0'; i++) /*Converting
 each line to
 upper case
 */
 str[i]=toupper(str[i]);
 if(isSubstring(str,pattern1))
 strcat(result,temp);
 free(str);
 }
}
void findPattern(FILE *f, char* pattern, char* result) /* This function
 is for grep
command
 without any
 options */
{
 char temp[10000];
 while( fgets ( temp, 10000, f ) != NULL )
 {
 if(isSubstring(temp,pattern))
 strcat(result,temp);
 }
}
