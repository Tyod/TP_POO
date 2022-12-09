#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>

using namespace std;

#include "Jogo.h"


class interface
{
	string nomeInterface;
	jogo j1;

public:

	//Construtor e Destrutor
	interface(string nomeInterface = "Interface");
	~interface();

	

	//Funções Responsaveis pela interação com o utilizador em cada uma das fases
	void Fase_incial();
	void Primeira_Fase();
	void Segunda_Fase();
	void Terceira_Fase();
	void Quarta_Fase();

	//Função finalizadora do jogo
	void Finaliza_jogo();

	//Função que gere todo o ciclo de fases do jogo
	void executa();
};
#endif // !INTERFACE_H

