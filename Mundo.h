#ifndef  MUNDO_H
#define MUNDO_H

#include <iostream>
#include <vector>
#include <fstream>


#include "Imperio.h"


#include "Castelo.h"
#include "Duna.h"
#include "Fortaleza.h"
#include "Mina.h"
#include "Montanha.h"
#include "Pescaria.h"
#include "Planicie.h"
#include "Refugio_dos_piratas.h"


#include "AliancaDiplomatica.h"
#include "Invasao.h"
#include "RecursoAbandonado.h"

using namespace std;

class mundo
{
	string nome;
	imperio i1;
	vector<territorio*> terras_nConq;
	vector<tecnologia*> tecnologias_nConq;
	vector<evento*> eventos;

public:

	//FUNÇÕES MUNDO
	//Construtor e destrutor
	mundo(string nome = "Middle Earth");
	~mundo();

	//Funções de inicialização da classe
	void carregaTerras_nConq();
	void carrega_tech();
	void carrega_eventos();
	void cria_terras_nConq(string nom, int quantidade);


	//Funções de gestão de territorios
	bool addTerra_nConqMund(string nome);
	bool removeTerra_nConqMundo(string nome);

	int conta_terrasnConq();

	territorio* procura_territorio_nConq(string nome);

	bool terraExiste(string nomeTerrConq);
	bool terraConquistada(string nomeTerrConq);

	void geraRecursosMund(int ano, int turno);


	//Funções de gestão de tecnologias
	bool addTecnologia_nConqMund(string nome, int custo);
	bool removeTecnologia_nConqMund(string nome);

	bool adquiriu_tech(string nome);

	int procura_Custo_Tecnologia(string nome);
	bool existe_tech(string nome);


	//Funções de gestão de eventos
	bool addEvento(string nome);
	void adicionaEfeitosEventos(string nome, int ano);



	//Função resposavel por mostrar o estado atual do mundo
	string getAsString();
	






	//FUNÇÕES IMPÉRIO
	//Funções de gestao de recursos e força militar
	int getCofreIMP();
	int getArmazemIMP();
	int getForcaIMP();
	int getMaxCofreIMP();
	int getMaxArmazemIMP();
	int getMaxForcaIMP();

	void atualizaCofreIMP(int quantidade);
	void atualizaArmazemIMP(int quantidade);
	void atualizaForcaMilitarIMP(int quantidade);

	void setMaxCofreIMP(int novoMAX);
	void setMaxArmazemIMP(int novoMAX);
	void setMaxForcaMilitarIMP(int novoMAX);

	void adicionaEfeitosTechIMP(string nome);

	int contaTerrasIMP();
	int contaTechIMP();

	int totalPontosIMP();

	void ConquistaIMP(string nome);

	

	//Função resposavel por mostrar o estado atual do imperio
	string getAsStringIMP();
};


#endif //  MUNDO_H

