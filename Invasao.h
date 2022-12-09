#include "Eventos.h"

using namespace std;


class invasao : public evento
{

public: 

	invasao();

	bool efeitoEvento(int ano, imperio& i1);
	
};
