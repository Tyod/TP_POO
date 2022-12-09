#include "Eventos.h"

using namespace std;


class alicancaDiplomatica : public evento
{

public:
	alicancaDiplomatica();

	bool efeitoEvento(int ano, imperio  &i1);
};
