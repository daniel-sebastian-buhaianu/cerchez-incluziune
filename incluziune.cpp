#include <fstream>
using namespace std;
ifstream fin("prim.txt");
ofstream fout("doi.txt");
struct multime
{
	int faz[26], fAZ[26], f09[10], nr;
};
void initializeazaMultimea(multime &);
void citesteMultimea(multime &);
bool incluziune(multime, multime);
int main()
{
	multime A, B;
	initializeazaMultimea(A);
	initializeazaMultimea(B);
	citesteMultimea(A);
	citesteMultimea(B);
	if (incluziune(A, B))
	{
		fout << "DA";
	}
	else
	{
		fout << "NU";
	}
	return 0;
}
void initializeazaMultimea(multime & M)
{
	for (int i = 0; i < 26; i++)
	{
		M.faz[i] = M.fAZ[i] = 0;
		if (i < 10)
		{
			M.f09[i] = 0;
		}
	}
	M.nr = 0;
}
void citesteMultimea(multime & M)
{
	char c;
	do
	{
		fin.get(c);
		if (c != '\n' && c != EOF)
		{
			if (c >= 'a' && c <= 'z')
			{
				M.nr++;
				M.faz[c-'a']++;
			}
			else if (c >= 'A' && c <= 'Z')
			{
				M.nr++;
				M.fAZ[c-'A']++;
			}
			else if (c >= '0' && c <= '9')
			{
				M.nr++;
				M.f09[c-'0']++;
			}
		}
	} while (c != '\n' && c != EOF);
}
// verifica daca multimea A este inclusa in multimea B
bool incluziune(multime A, multime B)
{
	int i, nr;
	for (nr = i = 0; i < 26; i++)
	{
		if (i < 10 && B.f09[i] && A.f09[i])
		{
			nr++;
		}
		if (B.faz[i] && A.faz[i])
		{
			nr++;
		}
		if (B.fAZ[i] && A.fAZ[i])
		{
			nr++;
		}
	}
	if (nr == A.nr)
	{
		return 1;
	}
	return 0;
}
