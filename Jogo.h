#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include <time.h>

#include "Mundo.h"

using namespace std;

class jogo
{
	int turno;
	int ano;
	mundo m1;

public:

	//Construtor e Destrutor
	jogo(int turno = 1, int ano = 1);
	~jogo();

	//Fun��es get da class jogo
	int getTurno();
	int getAno();

	//Fun��es de averigua��o da continuidade do programa
	void GereTempo();
	bool termina_Tempo();
	bool TerraNatalConquistada();
	

	//Fun��es inicializadoras dos vetores de tecnologias e eventos presentes no mundo bem como do fator aleat�rio
	void init_tech();
	void init_eventos();
	void init_rand();

	//Fun��es de utilidade relativa a gera��o de recursos, conquista de territorios e efeitos de eventos 
	void geraRecursos();
	void adcionaEfeitoEventoJog(string nome);
	void conquistaJog(string nome);

	//Fun��es de leitura de comandos
	void leitura_FaseInicial(string comando);
	void leitura_PrimeiraFase(string comando);
	void leitura_SegundaFase(string comando);
	void leitura_TerceiraFase(string comando);
	void leitura_QuartaFase(string comando);

	//Fun��o encarregada de preparar para a finaliza��o do jogo
	int Finalizacao_de_jogo();

	void debug();
};


#endif // !JOGO_H
