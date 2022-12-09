#ifndef  IMPERIO_H
#define  IMPERIO_H

#include <iostream>
#include <vector>

#include "Territorios.h"
#include "TerritorioInicial.h"
#include "Tecnologias.h"



using namespace std;


class imperio
{
	string nomeImperio;
	int cofre;
	int armazem;
	int forcaMilitar;
	int pontuacao;

	int maxForca = 3;
	int maxCofre =  3;
	int maxArmazem = 3;

	vector<territorio*> terras;
	vector<tecnologia*> tecnologias;

public:

	//Construtor  e destrutor
	imperio(string nomeImperio = "BROAS", int cofre = 0, int armazem = 0, int forcaMilitar = 0, int pontuacao = 0);
	~imperio();


	//Fun��es de gestao de recursos e for�a militar
	int getCofre();
	int getArmazem();
	int getForca();
	int getMaxCofre();
	int getMaxArmazem();
	int getMaxForcaMilitar();

	void atualizaCofre(int quantidade);
	void atualizaArmazem(int quantidade);
	void atualizaForcaMilitar(int quantidade);

	void setMaxCofre(int novoMAX);
	void setMaxArmazem(int novoMAX);
	void setMaxForcaMilitar(int novoMAX);

	
	//Fun��es de gestao de territorios
	bool addTerra(territorio* a);
    bool removeTerra(string nome);
	territorio* procuraTerra(string nome);
	territorio* devolve_UltimaTerra();
	void geraRecursosImp(int ano, int turno);
	int conta_Terras();
	

	//Fun��es de gestao de tecnologias
	bool addTecnologia(tecnologia*);
	bool procura_tech(string nome);
	void adicionaEfeitosTech(string nome);
	int conta_Tech();

	//Fun��o responsav�l por calcular a pontuacao total resultante da soma dos territorios
	int totalPontos();

	//Fun��o responsav�l por conquistar averiguar se conquista
	bool conquista(string nome, string categoria, int resistencia);

	//Fun��o resposavel por mostrar o estado atual do imperio
	string getAsString();

};


#endif // IMPERIO_H
