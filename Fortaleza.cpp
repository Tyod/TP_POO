#include "Fortaleza.h"

int fortaleza::indice = 0;

fortaleza::fortaleza() :territorio("Fortaleza" + to_string(++indice), "Continente", 8, 0, 0, 1)
{
}



void fortaleza::setCriacaoDeOuro(int turno, int ano)
{
	this->criacaoDeOuro = 0;
}

void fortaleza::setCriacaoDeProdutos(int turno, int ano)
{
	this->criacaoDeProdutos = 0;
}


