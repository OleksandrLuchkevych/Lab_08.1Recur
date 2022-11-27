#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* str, int i, int k)
{
	if (strlen(str) < 3)
		return 0;
	if (str[i] != 0)
	{
		if (str[i] == '.')
		{
			k++;
			if (k == 3)
				return i;
			else
				return Count(str, i + 1, k);
		
		}
		else
			return 0;
			
	}
}
char* Change(char* dest, const char* str, char* t, int i)
{
	if (str[i] != 0)
	{
		if (i != 0 && i % 4 == 0)
		{
			strcat(t, ".");
			return Change(dest, str, t + 1, i + 1);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str, 0, 0)<< endl;
	char* dest1 = new char[151];
	dest1[0] = '\0';
	char* dest2;
	dest2 = Change(dest1, str, dest1, 0);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest2 << endl;
	return 0;
}