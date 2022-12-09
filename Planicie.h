#ifndef PLANICIE_H
#define PLANICIE_H

#include "Territorios.h"

using namespace std;


class planicie : public territorio
{
	static int indice;

public:

	planicie();


	void setCriacaoDeOuro(int turno, int ano);
	void setCriacaoDeProdutos(int turno, int ano);

};

#endif // PLANICIE_H
