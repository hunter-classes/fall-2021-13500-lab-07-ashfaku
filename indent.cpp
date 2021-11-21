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
	std::ifstream file("bad-code.cpp");
    if (file.fail())
    {
        std::cerr<<"Can't be read!\n";
        exit(1);
    }
	while (getline(file, s))
	{
		string r = removeLeadingSpaces(s);
		int open = countChar(s, '{'), close = countChar(s, '}');
		for (int i = 0; i < (r[0] != '}' ? tab : (countChar(s, ':') == 0 ? tab - 1 : tab)); i++)
			line += "\t";
		line += r;
		tab += open - close;
		line += "\n";
	}
	cout << line << endl;
	std::ofstream file1;
	file1.open("fixed.cpp");
	file1 << line;
	file.close();
	file1.close();
	return 0;
}


