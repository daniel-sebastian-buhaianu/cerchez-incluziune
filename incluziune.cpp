#include <fstream>
#define LGMAX 1000
using namespace std;
ifstream fin("prim.txt");
ofstream fout("doi.txt");
int faz[26], fAZ[26], f09[10];
int main()
{
	char c, inc;
	int lg, nr;
	lg = 0;
	do
	{
		fin.get(c);
		if (c != '\n')
		{
			if (c >= 'a' && c <= 'z')
			{
				lg++;
				faz[c-'a']++;
			}
			else if (c >= 'A' && c <= 'Z')
			{
				lg++;
				fAZ[c-'A']++;
			}
			else if (c >= '0' && c <= '9')
			{
				lg++;
				f09[c-'0']++;
			}
		}
	} while (c != '\n');
	nr = 0;
	do
	{
		fin.get(c);
		if (c != '\n' && c != EOF)
		{
			if (c >= 'a' && c <= 'z' && faz[c-'a'])
			{
				nr++;
			}
			else if (c >= 'A' && c <= 'Z' && fAZ[c-'A'])
			{
				nr++;
			}
			else if (c >= '0' && c <= '9' && f09[c-'0'])
			{
				nr++;
			}
		}
	} while (c != '\n' && c != EOF);
	if (nr == lg)
	{
		fout << "DA";
	}
	else
	{
		fout << "NU";
	}
	return 0;
}
