#include "Planicie.h"

using namespace std;

int planicie::indice = 0;

planicie::planicie():territorio("Planicie" + to_string(++indice), "Continente", 5, 0, 0, 1)
{

}



void planicie::setCriacaoDeOuro(int turno, int ano)
{
		this->criacaoDeOuro = 1;
}

void planicie::setCriacaoDeProdutos(int turno, int ano)
{
	if (ano == 1)
		this->criacaoDeProdutos = 1;
	if (ano == 2)
		this->criacaoDeProdutos = 2;
}


