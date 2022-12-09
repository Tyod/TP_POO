#include "Eventos.h"

using namespace std;


class recursoAbandonado : public evento
{

public:
	recursoAbandonado();

	bool efeitoEvento(int ano, imperio &i1);
};
