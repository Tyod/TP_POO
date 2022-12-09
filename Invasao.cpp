#include "Invasao.h"

invasao::invasao() :evento("Invasao")
{

}

bool invasao::efeitoEvento(int ano, imperio &i1)
{ 
	int forcaDeInvasao = 0;

	if (ano == 1)
	{
		forcaDeInvasao = 2 + rand() % 6 + 1;
		cout << "\n Forca da invasao: " << forcaDeInvasao;
	}
		
	if (ano == 2)
	{
		forcaDeInvasao = 3 + rand() % 6 + 1;
		cout << "\n Forca da invasao: " << forcaDeInvasao;
	}
		

	if (i1.procura_tech("Defesas territoriais") == true)
	{
		i1.devolve_UltimaTerra()->setResistencia(i1.devolve_UltimaTerra()->getResistencia() + 1);
		if (forcaDeInvasao >= i1.devolve_UltimaTerra()->getResistencia())
		{
			cout << "\n Resistencia do territorio: " << i1.devolve_UltimaTerra()->getResistencia();
			cout << "\n A invasao foi bem sucedida!" << endl;
			return true;
		}
		else
		{
			cout << "\n Resistencia do territorio: " << i1.devolve_UltimaTerra()->getResistencia();
			cout << "\n A invasao nao foi sucedida!" << endl;
			return false;
		}
	}
	else
	{
		if (forcaDeInvasao >= i1.devolve_UltimaTerra()->getResistencia())
		{
			cout << "\n Resistencia do territorio: " << i1.devolve_UltimaTerra()->getResistencia();
			cout << "\n A invasao foi bem sucedida!" << endl;
			return true;
		}
		else
		{
			cout << "\n Resistencia do territorio: " << i1.devolve_UltimaTerra()->getResistencia();
			cout << "\n A invasao nao foi sucedida!" << endl;
			return false;
		}
	}
    
}