#include <iostream>
#include <malloc.h>
#include <conio.h>
using namespace std;

struct phanso
{
	int ts, ms;
};
typedef phanso PHANSO;

ostream &operator<<(ostream &outDev, const PHANSO &ps)
{
	if ((ps.ms == 1) || (ps.ts == 0)) outDev << ps.ts;
	else outDev << ps.ts << "/" << ps.ms;
	return outDev;
}

istream &operator>>(istream &inDev, PHANSO &ps)
{
	inDev >> ps.ts >> ps.ms;
	return inDev;
}

void Chenphantu(PHANSO *&ps, int &n, PHANSO x)
{
	int m = n + 1;
	PHANSO *psnew = (PHANSO*)realloc(ps, m*sizeof(PHANSO));
	if (psnew != NULL)
	{
		psnew[n] = x;
		n++;
		ps = psnew;
	}
}

void Nhapmangphanso(PHANSO *&ps, int &n)
{
	PHANSO x;
	ps = NULL; n = 0;
	while (cin >> x)
	{
		Chenphantu(ps, n, x);
	}
}

void Xuatmangphanso(PHANSO *ps, int n)
{
	for (int i = 0; i < n; i++)
		cout << ps[i] << " ";
}

void Chenphantuphanso(PHANSO *&ps, int &n, PHANSO *a)
{
	PHANSO x = *a;
	Chenphantu(ps, n, x);
}

void Xoaphantu(PHANSO *&ps, int &n)
{
	int m = n - 1;
	PHANSO *psnew = (PHANSO*)realloc(ps, m*sizeof(PHANSO));
	n--;
	ps = psnew;
}

void main()
{
	PHANSO *ps;
	int n;
	Nhapmangphanso(ps, n);
	cout << "Mang phan so sau khi nhap: " << endl;
	Xuatmangphanso(ps, n);
	cout << endl;
	PHANSO *a = new PHANSO{ 2, 3 };
	Chenphantuphanso(ps, n, a);
	cout << "Mang sau khi chen (2/3)" << endl;
	Xuatmangphanso(ps, n);
	cout << endl;
	Xoaphantu(ps, n);
	cout << "Mang sau khi xoa (2/3)" << endl;
	Xuatmangphanso(ps, n);
	if (ps != NULL) delete[] ps;
	delete a;
	//_getch();
}