#include "Duna.h"

using namespace std;

int duna::indice = 0;

duna::duna() :territorio("Duna" + to_string(++indice), "Continente", 4, 0, 1, 1)
{

}




void duna::setCriacaoDeOuro(int turno, int ano)
{
	this->criacaoDeOuro = 0;
}

void duna::setCriacaoDeProdutos(int turno, int ano)
{
	this->criacaoDeProdutos = 1;
}


