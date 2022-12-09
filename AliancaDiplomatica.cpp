#include "AliancaDiplomatica.h"

alicancaDiplomatica::alicancaDiplomatica():evento("Alianca Diplomatica")
{

}


bool alicancaDiplomatica::efeitoEvento(int ano, imperio &i1)
{
	i1.atualizaForcaMilitar(1);
	return true;
}
