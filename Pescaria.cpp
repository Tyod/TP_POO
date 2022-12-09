#include "Pescaria.h"

using namespace std;

int pescaria::indice = 0;

pescaria::pescaria() :territorio("Pescaria" + to_string(++indice), "Ilha", 9, 0, 0, 2)
{

}




void pescaria::setCriacaoDeOuro(int turno, int ano)
{
	this->criacaoDeOuro = 1;
}

void pescaria::setCriacaoDeProdutos(int turno, int ano)
{
	if (ano == 1)
		this->criacaoDeProdutos = 2;
	if (ano == 2)
		this->criacaoDeProdutos = 4;
}


