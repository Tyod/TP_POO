#ifndef CASTELO_H
#define CASTELO_H

#include "Territorios.h"

using namespace std;


class castelo : public territorio 
{
	static int indice;

public:
	
	castelo();

	void setCriacaoDeOuro(int turno, int ano);
	void setCriacaoDeProdutos(int turno, int ano);

};

#endif // !CASTELO_H



