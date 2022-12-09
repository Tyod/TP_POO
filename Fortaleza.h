#ifndef FORTALEZA_H
#define FORTALEZA_H

#include "Territorios.h"

using namespace std;


class fortaleza : public territorio
{
	static int indice;

public:

	fortaleza();


	void setCriacaoDeOuro(int turno, int ano);
	void setCriacaoDeProdutos(int turno, int ano);

};

#endif // FORTALEZA_H

