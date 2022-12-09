#include "Mundo.h"

//Construtor e Destrutor
mundo::mundo(string nome)
{
	this->nome = nome;
}

mundo::~mundo()
{
	for (unsigned int i = 0; i < terras_nConq.size(); i++)
	{
		delete terras_nConq[i];
	}

	for (unsigned int i = 0; i < tecnologias_nConq.size(); i++)
	{
		delete tecnologias_nConq[i];
	}

	for (unsigned int i = 0; i < eventos.size(); i++)
	{
		delete eventos[i];
	}
}

void mundo::carregaTerras_nConq()
{
	string leitura;
	string nome_leitura;
	int quantidade_leitura;

	ifstream ifs("TerrasInit.txt");
	if (!ifs)
	{
		cout << "[ERROR] Nao foi possivel abrir o ficheiro!" << endl;
		exit(0);
	}

	while (!ifs.eof())
	{
		getline(ifs, leitura);
		quantidade_leitura = stoi(leitura.substr(leitura.length() - 1, leitura.length()));
		nome_leitura = leitura.substr(0, leitura.length()-2);

		cria_terras_nConq(nome_leitura, quantidade_leitura);
	}

	ifs.close();
}

void mundo::carrega_tech()
{
	string leitura;
	string nome_leitura;
	int custo_leitura;

	ifstream ifs("Tecnologias.txt");
	if (!ifs)
	{
		cout << "[ERROR] Nao foi possivel abrir o ficheiro das Tecnologias!" << endl;
		exit(0);
	}

	while (!ifs.eof())
	{
		getline(ifs, leitura);
		custo_leitura = stoi(leitura.substr(leitura.length() - 1, leitura.length()));
		nome_leitura = leitura.substr(0, leitura.length() - 2);

		addTecnologia_nConqMund(nome_leitura, custo_leitura);
	}

	ifs.close();
}

void mundo::carrega_eventos()
{
	string leitura;
	
	ifstream ifs("Eventos.txt");
	if (!ifs)
	{
		cout << "[ERROR] Nao foi possivel abrir o ficheiro dos Eventos!" << endl;
		exit(0);
	}

	while (!ifs.eof())
	{
		getline(ifs, leitura);
		addEvento(leitura);
	}

	ifs.close();
}

void mundo::cria_terras_nConq(string nome, int quantidade)
{ 

	for (int i = 0 ; i < quantidade; i++)
	{
		if (nome == "Planicie")
			terras_nConq.push_back(new planicie());

		if (nome == "Montanha")
			terras_nConq.push_back(new montanha());

		if (nome == "Fortaleza")
			terras_nConq.push_back(new fortaleza());

		if (nome == "Mina")
			terras_nConq.push_back(new mina());

		if (nome == "Duna")
			terras_nConq.push_back(new duna());

		if (nome == "Castelo")
			terras_nConq.push_back(new castelo());

		if (nome == "Refugio dos piratas")
			terras_nConq.push_back(new refugioPirata());

		if (nome == "Pescaria")
			terras_nConq.push_back(new pescaria());
	}

}






//Funções de gestão de territorios
bool mundo::addTerra_nConqMund(string nome)
{
	
	terras_nConq.push_back(i1.procuraTerra(nome));
	i1.removeTerra(nome);
	return true;
}

bool mundo::removeTerra_nConqMundo(string nome)
{
	for (unsigned int i = 0; i < terras_nConq.size(); i++)
	{
		if (terras_nConq[i]->getNome() == nome)
		{
			i1.addTerra(terras_nConq[i]);
			terras_nConq.erase(terras_nConq.begin() + i);
			return true;
		}	
	}

	return false;
}


int mundo::conta_terrasnConq()
{
	return terras_nConq.size();
}

territorio* mundo::procura_territorio_nConq(string nome)
{
	for (unsigned int i = 0; i < terras_nConq.size(); i++)
	{
		if (terras_nConq[i]->getNome() == nome)
			return terras_nConq[i];
	}

	return NULL;
}

bool mundo::terraExiste(string nomeTerra) {

	for (unsigned int i = 0; i < terras_nConq.size(); i++) {

		if (terras_nConq[i]->getNome() == nomeTerra)
			return true;

	}

	return false;
}

bool mundo::terraConquistada(string nomeTerra)
{
	for (unsigned int i = 0; i < terras_nConq.size(); i++)
	{
		if (terras_nConq[i]->getNome() == nomeTerra)
			return false;
	}

	return true;
}

void mundo::geraRecursosMund(int ano, int turno)
{
	i1.geraRecursosImp(ano, turno);
}


//Funções de gestão de tecnologias
bool mundo::addTecnologia_nConqMund(string nome, int custo)
{
	tecnologias_nConq.push_back(new tecnologia(nome, custo));
	return true;
}

bool mundo::removeTecnologia_nConqMund(string nome)
{
	for (unsigned int i = 0; i < tecnologias_nConq.size(); i++)
	{
		if (tecnologias_nConq[i]->getNome() == nome)
		{
			i1.addTecnologia(tecnologias_nConq[i]);
			tecnologias_nConq.erase(tecnologias_nConq.begin() + i);
			return true;
		}
	}
	 
	return false;
}


bool mundo::adquiriu_tech(string nome)
{
	for (unsigned int i = 0; i < tecnologias_nConq.size(); i++)
	{
		if (tecnologias_nConq[i]->getNome() == nome)
			return false;
	}

	return true;
}



int mundo::procura_Custo_Tecnologia(string nome)
{
	for (unsigned int i = 0; i < tecnologias_nConq.size(); i++)
	{
		if (tecnologias_nConq[i]->getNome() == nome)
			return tecnologias_nConq[i]->getCusto();
	}
	return -1;
}

bool mundo::existe_tech(string nome)
{
	for (unsigned int i = 0; i < tecnologias_nConq.size(); i++)
	{
		if (tecnologias_nConq[i]->getNome() == nome)
			return true;
	}

	return false;

}


//Funções de gestão de eventos
bool mundo::addEvento(string nome)
{
	if (nome == "Alianca Diplomatica")
	{
		eventos.push_back(new alicancaDiplomatica());
		return true;
	}
		

	if (nome == "Invasao")
	{
		eventos.push_back(new invasao());
		return true;
	}
		

	if (nome == "Recurso Abandonado")
	{
		eventos.push_back(new recursoAbandonado());
		return true;
	}

	return false;
}

void mundo::adicionaEfeitosEventos(string nome, int ano)
{
	if (nome == "alianca")
		eventos[0]->efeitoEvento(ano, i1);
	if (nome == "invasao")
	{
		if (eventos[1]->efeitoEvento(ano, i1) == true)
		{
			addTerra_nConqMund(i1.devolve_UltimaTerra()->getNome());
		}
	}
	if (nome == "recurso")
		eventos[2]->efeitoEvento(ano, i1);
}





string mundo::getAsString()
{
	ostringstream oss;

	oss << "\n\n Middle Earth:" << endl;

	if (terras_nConq.empty())
	{
		oss << " \n Nao foram carregados quaisquer territorios!";
		return oss.str();
	}
	else
	{
		oss << "\n Lista de territorios por conquistar: " << endl;

		for (unsigned int i = 0; i < terras_nConq.size(); i++)
		{
			oss << terras_nConq[i]->getAsString() << endl;
		}

	}

	if (tecnologias_nConq.empty())
	{
		oss << " \n Nao foram carregados quaisquer territorios!" << endl;
		return oss.str();
	}
	else
	{
		oss << "\n Lista de tecnologias por adquirir: " << endl;

		for (unsigned int i = 0; i < tecnologias_nConq.size(); i++)
		{
			oss << tecnologias_nConq[i]->getAsString() << endl;
		}

		return oss.str();
	}
}













//FUNÇÕES IMPERIO
//Funções de gestao de recursos e força militar
int mundo::getCofreIMP()
{
	return i1.getCofre();
}

int mundo::getArmazemIMP()
{
	return i1.getArmazem();
}

int mundo::getForcaIMP()
{
	return i1.getForca();
}

int mundo::getMaxCofreIMP()
{
	return i1.getMaxCofre();
}

int mundo::getMaxArmazemIMP()
{
	return i1.getMaxArmazem();
}

int mundo::getMaxForcaIMP()
{
	return i1.getMaxForcaMilitar();
}

void mundo::atualizaCofreIMP(int quantidade)
{
	i1.atualizaCofre(quantidade);
}

void mundo::atualizaArmazemIMP(int quantidade)
{
	i1.atualizaArmazem(quantidade);
}

void mundo::atualizaForcaMilitarIMP(int quantidade)
{
	i1.atualizaForcaMilitar(quantidade);
}

void mundo::setMaxCofreIMP(int novoMAX)
{
	i1.setMaxCofre(novoMAX);
}

void mundo::setMaxArmazemIMP(int novoMAX)
{
	i1.setMaxArmazem(novoMAX);
}

void mundo::setMaxForcaMilitarIMP(int novoMAX)
{
	i1.setMaxForcaMilitar(novoMAX);
}

void mundo::adicionaEfeitosTechIMP(string nome)
{
	i1.adicionaEfeitosTech(nome);
}

int mundo::contaTerrasIMP()
{
	return i1.conta_Terras();
}

int mundo::contaTechIMP()
{
	return i1.conta_Tech();
}

int mundo::totalPontosIMP()
{
	return i1.totalPontos();
}

void mundo::ConquistaIMP(string nome)
{
	if (procura_territorio_nConq(nome)->getCategoria() == "Ilha")
	{
		if (i1.conquista(nome, "Ilha", procura_territorio_nConq(nome)->getResistencia()) == true)
		{
			removeTerra_nConqMundo(nome);
		}
		else
		{
			i1.atualizaForcaMilitar(-1);
		}
	}
	else
	{
		if (i1.conquista(nome, "Continente", procura_territorio_nConq(nome)->getResistencia()) == true)
		{
			removeTerra_nConqMundo(nome);
		}
		else
		{
			i1.atualizaForcaMilitar(-1);
		}
	}		
}






//Função resposavel por mostrar o estado atual do imperio
string mundo::getAsStringIMP()
{
	ostringstream oss;

	oss << i1.getAsString();

	return oss.str();
}