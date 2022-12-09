#include "RecursoAbandonado.h"

recursoAbandonado::recursoAbandonado() :evento("Recurso Abandonado")
{

}


bool recursoAbandonado::efeitoEvento(int ano, imperio &i1)
{
	if (ano == 1)
	{
		i1.atualizaArmazem(1);
		return true;
	}
		
	if (ano == 2)
	{
		i1.atualizaCofre(1);
		return true;
	}

	return false;
}

