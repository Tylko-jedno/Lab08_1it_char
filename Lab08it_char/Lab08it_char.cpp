#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Count(char* str)
{
	int k = 0;
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == '+' || str[i] == '-' || str[i] == '=')
			k++;
	return k;
}
char* Change(const char* str) {
    int newLength = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '=') {
            newLength += 2;
        }
        else {
            newLength += 1;
        }
    }

    char* newStr = new char[newLength + 1];
    int j = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '=') {
            newStr[j++] = '*';
            newStr[j++] = '*';
        }
        else {
            newStr[j++] = str[i];
        }
    }

    newStr[j] = '\0'; 
    return newStr;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str) << "symbols: " << "+ = -'" << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (result): " << dest << endl;
	return 0;
}