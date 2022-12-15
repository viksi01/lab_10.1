#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void CreateTXT(char* fname)
{
	ofstream fout(fname); 
	char ch;
	string s;
	do
	{
		cin.get(); 
		cin.sync(); 
		cout << "enter line: "; getline(cin, s); 
		fout << s << endl;
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
void PrintTXT(char* fname)
{
	ifstream fin(fname); 
	string s; 
	while (getline(fin, s)) 
	{
		cout << s << endl;
	}
	cout << endl;
}
int ProcessTXT(char* fname)
{
	ifstream fin(fname);
	string s;
	int k = 0;
	while (getline(fin, s)) 
	{ 
		for (unsigned i = 0; i < s.length(); i++)
			if ((s[i] == 'a' || s[i] == 'b' || s[i] == 'c') && (s[i + 1] == 'a' || s[i + 1] == 'b' || s[i + 1] == 'c')
				&& (s[i + 2] == 'a' || s[i + 2] == 'b' || s[i + 2] == 'c'))
				k++;
	}
	return k;
}

int main()
{

	char fname[100] = "t.txt"; 
	CreateTXT(fname); 
	PrintTXT(fname); 
	cout << "k( 'a', 'b', 'c') = " << ProcessTXT(fname) << endl;
	return 0;
}
