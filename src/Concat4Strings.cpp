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
int min(int a, int b)
{
	return (a < b) ? a : b;
}

int Pair(string str1, string str2, string &str)
{
	int max = INT_MIN;
	int len1 = str1.length();
	int len2 = str2.length();

	for (int i = 1; i <= min(len1, len2); i++)
	{
		if (str1.compare(len1 - i, i, str2, 0, i) == 0)
		{
			if (max < i)
			{
				max = i;
				str = str1 + str2.substr(i);
			}
		}
	}

	for (int i = 1; i <= min(len1, len2); i++)
	{
		if (str1.compare(0, i, str2, len2 - i, i) == 0)
		{
			if (max < i)
			{
				max = i;
				str = str2 + str1.substr(i);
			}
		}
	}

	return max;
}

char * concat_4strings(char *s1, char *s2, char *s3, char *s4){
	int res = Pair(s1,s2, str);
	int res1 = Pair(s1, s3, str);
	int res = Pair(s1, s4, str);
	int res = Pair(s2, s3, str);
	int res = Pair(s2, s4, str);
}