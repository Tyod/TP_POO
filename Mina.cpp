#include "Mina.h"


using namespace std;

int mina::indice = 0;

mina::mina():territorio("Mina" + to_string(++indice), "Continente", 5, 0, 0, 1)
{

}



void mina::setCriacaoDeOuro(int turno, int ano)
{
	if (turno <= 3)
		this->criacaoDeOuro = 1;
	if (turno > 3)
		this->criacaoDeOuro = 2;
}

void mina::setCriacaoDeProdutos(int turno, int ano)
{
	this->criacaoDeProdutos = 0;
}

