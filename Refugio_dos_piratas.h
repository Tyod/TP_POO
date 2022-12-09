#ifndef REFUGIO_DOS_PIRATAS_H
#define REFUGIO_DOS_PIRATAS_H

#include "Territorios.h"

using namespace std;


class refugioPirata : public territorio
{
	static int indice;

public:

	refugioPirata();


	void setCriacaoDeOuro(int turno, int ano);
	void setCriacaoDeProdutos(int turno, int ano);

};

#endif // REFUGIO_DOS_PIRATAS

