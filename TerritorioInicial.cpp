#include "TerritorioInicial.h"

using namespace std;



territorioInicial::territorioInicial() :territorio("Territorio Inicial", "Continente", 9, 1, 1, 1)
{

}




void territorioInicial::setCriacaoDeOuro(int turno, int ano)
{
	criacaoDeOuro = 1;
}

void territorioInicial::setCriacaoDeProdutos(int turno, int ano)
{
	criacaoDeProdutos = 1;
}
