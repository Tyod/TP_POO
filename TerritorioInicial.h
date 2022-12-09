#ifndef TERRITORIOINICIAL_H
#define TERRITORIOINICIAL_H

#include "Territorios.h"

using namespace std;


class territorioInicial : public territorio
{

public:

	territorioInicial();

	void setCriacaoDeOuro(int turno, int ano);
	void setCriacaoDeProdutos(int turno, int ano);

};

#endif // TERRITORIOINICIAL_H

