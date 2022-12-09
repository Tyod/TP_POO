#ifndef MINA_H
#define MINA_H

#include "Territorios.h"

using namespace std;


class mina : public territorio
{
	static int indice;

public:

	mina();


	void setCriacaoDeOuro(int turno, int ano);
	void setCriacaoDeProdutos(int turno, int ano);

};

#endif // MINA_H
