#include <iostream>
#include <fstream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int countChar(string l, char s)
{
	int c = 0, index = -1;
	while (l[++index])
		c += (l[index] == s ? 1 : 0);
	return c;
}
string removeLeadingSpaces(string s)
{
	string r = "";
	int i = -1;
	while (isspace(s[++i]));
	for (; i < s.length(); i++)
		r += s[i];
	return r;
}
int main()
{
	string s;
	int tab = 0;
	string line = "", original = "";
	while (getline(cin, s))
	{
		original += s + "\n";
		int open = countChar(s, '{'), close = countChar(s, '}');
		for (int i = 0; i < (close == 0 ? tab : tab - 1); i++)
			line += "\t";
		line += removeLeadingSpaces(s);
		tab += open;
		tab -= close;
		line += "\n";
	}
	cout << original << endl << "------------------------------------------------------" << endl;
	cout << line << endl;
	std::ofstream file;
	file.open("fixed.cpp");
	file << line;
	file.close();
	return 0;
}
