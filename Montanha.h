#ifndef MONTANHA_H
#define MONTANHA_H

#include "Territorios.h"

using namespace std;


class montanha : public territorio
{
	static int indice;
	static int turno;
	static int primeiravez;

public:

	montanha();

	void setCriacaoDeOuro(int turno, int ano);
	void setCriacaoDeProdutos(int turno, int ano);

};

#endif // MONTANHA_H
