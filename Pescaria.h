#ifndef PESCARIA_H
#define PESCARIA_H

#include "Territorios.h"

using namespace std;


class pescaria : public territorio
{
	static int indice;

public:

	pescaria();


	void setCriacaoDeOuro(int turno, int ano);
	void setCriacaoDeProdutos(int turno, int ano);

};

#endif // PESCARIA_H
