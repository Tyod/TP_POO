#include "Montanha.h"

using namespace std;

int montanha::turno = 0;
int montanha::indice = 0;
int montanha::primeiravez = 1;

montanha::montanha():territorio("Montanha" + to_string(++indice), "Continente", 6, 0, 0, 1)
{

}


void montanha::setCriacaoDeOuro(int turno, int ano)
{
	this->criacaoDeOuro = 0;
}


void montanha::setCriacaoDeProdutos(int turno, int ano)
{
	if (montanha::primeiravez == 1)
	{
		montanha::turno = turno;
		montanha::primeiravez = montanha::primeiravez + 1;
	}

	if (montanha::turno + 2 <= turno)
		this->criacaoDeProdutos = 1;
	else
		this->criacaoDeProdutos = 0;
}


