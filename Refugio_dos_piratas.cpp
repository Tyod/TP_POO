#include "Refugio_dos_piratas.h"

using namespace std;

int refugioPirata::indice = 0;

refugioPirata::refugioPirata() :territorio("Refugio dos Piratas" + to_string(++indice), "Ilha", 9, 1, 0, 2)
{

}


void refugioPirata::setCriacaoDeOuro(int turno, int ano)
{
	this->criacaoDeOuro = 1;
}

void refugioPirata::setCriacaoDeProdutos(int turno, int ano)
{
	this->criacaoDeProdutos = 0;
}
