#ifndef  DUNA_H
#define DUNA_H

#include "Territorios.h"

using namespace std;


class duna : public territorio
{
	static int indice;

public:

	duna();


	void setCriacaoDeOuro(int turno, int ano);
	void setCriacaoDeProdutos(int turno, int ano);

};

#endif // ! DUNA_H



