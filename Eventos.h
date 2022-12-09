#ifndef EVENTOS_H
#define EVENTOS_H

#include <iostream>

#include "Imperio.h"

using namespace std;

class evento
{
protected:
	string nome;

public:

	evento(string nome);
	~evento();

	virtual bool efeitoEvento(int ano, imperio &i1)=0;
};
#endif // !EVENTOS_H

