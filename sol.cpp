#include <iostream>
#include <cstring>
#define LGMAX 204
using namespace std;
//variabile globale
char e[LGMAX], p[LGMAX];
int i, lg, lgp;
//functii ajutatoare
void TransformExpresie();
void TransformFactor();
void TransformTermen();
//functia principala
int main()
{
	cout << "Introduceti expresia: ";
	cin.getline(e, LGMAX);
	lg = strlen(e);
	TransformExpresie();
	cout << "Expresia in forma poloneza: " << p << '\n';
	return 0;
}
void TransformFactor()
{
	if (e[i] == '(') // factorul e o expresie intre paranteze
	{
		i++; // trec peste (
		TransformExpresie(); // transform expresia din paranteze
		i++; // trec peste )
	}
	else
	{
		// factorul este o litera sau o cifra
		p[lgp++] = e[i++];
	}
}
void TransformTermen()
{
	TransformFactor(); // transform primul factor al termenului
	while (i < lg && e[i] == '*') // mai urmeaza factori
	{
		i++; // trec peste *
		TransformFactor();
		p[lgp++] = '*';
	}
}
void TransformExpresie()
{
	TransformTermen(); // transform primul termen din expresie
	while (i < lg && e[i] == '+') // mai urmeaza termeni
	{
		i++; // trec peste +
		TransformTermen();
		p[lgp++] = '+';
	}
}
// solutia oficiala
