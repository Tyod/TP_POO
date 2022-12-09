#include "Castelo.h"

using namespace std;

int castelo::indice = 0;

castelo::castelo():territorio("Castelo" + to_string(++indice), "Continente",7,0,0,1)
{

}




void castelo::setCriacaoDeOuro(int turno, int ano)
{
	criacaoDeOuro = 1;
}

void castelo::setCriacaoDeProdutos(int turno, int ano)
{
	if (turno <= 2)
		criacaoDeProdutos = 3;
	else
		criacaoDeProdutos = 0;
}




