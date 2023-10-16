#include <fstream>
#define CMAX_ASCII 256
using namespace std;
ifstream fin("prim.txt");
ofstream fout("doi.txt");
typedef int multime[CMAX_ASCII];
void initializeazaMultimea(multime);
void citesteMultimea(multime);
bool incluziune(multime, multime);
int main()
{
	multime A, B;
	initializeazaMultimea(A);
	initializeazaMultimea(B);
	citesteMultimea(A);
	citesteMultimea(B);
	fin.close();
	if (incluziune(A, B))
	{
		fout << "DA";
	}
	else
	{
		fout << "NU";
	}
	fout.close();
	return 0;
}
void initializeazaMultimea(multime M)
{
	for (int i = 0; i < CMAX_ASCII; i++)
	{
		M[i] = 0;
	}
}
void citesteMultimea(multime M)
{
	char c;
	do
	{
		fin.get(c);
		if (c != '\n' && c != EOF)
		{
			M[c] = 1;
		}
	} while (c != '\n' && c != EOF);
}
// verifica daca multimea A este inclusa in multimea B
bool incluziune(multime A, multime B)
{
	for (int i = 0; i < CMAX_ASCII; i++)
	{
		if (A[i] > B[i])
		{
			return 0;
		}
	}
	return 1;
}
