/*
Given 4 strings, write a fucntion to get smallest string that consists all four strings. 
In Case of Multiple strings with smallest length,
Return the string which occurs alphabetically first .

Ex : (acat, tiger, silica, licaria) O/P: "silicariacatiger"
Ex : (def,abc,ghi,jkl)   O/P : “abcdefghijkl” (Alphabetically first )
Ex : (apple,pp,pineapple,nea) O/P: "pineapple";
Ex : (zzzabc,abcdef,yyyzzz,cabyyy) O/P: "cabyyyzzzabcdef" (Order Swapped )

Note : Each string given as input ,should be in the same format in the output string. 
Ie if input string is abcd ,it cannot be modified as bdca in the final string .

The Order of Strings in the Final string ,maynot be in the same order 
given in which they are given
Function Signatue : char * smallestword(char *s1,char *s2,char *s3,char *s4);

Note : You can use String.h functions .

Constraints : 
Length of each String will be less than 100 .

Difficulty : Hard
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char * concat_4strings(char *s1, char *s2, char *s3, char *s4){
	//Return the new string created.
	int *a1, *a2, *a3, *a4,i;
	a1 = (int *)malloc(sizeof(int)* 26);
	a2 = (int *)malloc(sizeof(int)* 26);
	a3 = (int *)malloc(sizeof(int)* 26);
	a4 = (int *)malloc(sizeof(int)* 26);
	if (s1&&s2&&s3&&s4)
	{
		for (i = 0; s1[i] != NULL; i++)
		{
			a1[s1[i] - '0']++;
		}
		for (i = 0; s2[i] != NULL; i++)
		{
			a2[s2[i] - '0']++;
		}
		for (i = 0; s3[i] != NULL; i++)
		{
			a3[s3[i] - '0']++;
		}
		for (i = 0; s4[i] != NULL; i++)
		{
			a4[s4[i] - '0']++;
		}
		
	}
	else
	{
		return NULL;
	}
}