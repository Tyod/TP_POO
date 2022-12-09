#include "Imperio.h"


//Construtor  e destrutor
imperio::imperio(string nomeImperio, int cofre, int armazem, int forcaMilitar, int pontuacao)
{
	this->nomeImperio = nomeImperio;
	this->cofre = cofre;
	this->armazem = armazem; 
	this->forcaMilitar = forcaMilitar;
	this->pontuacao = pontuacao;

	terras.push_back(new territorioInicial());
}

imperio::~imperio()
{
	for (unsigned int i = 0; i < terras.size(); i++)
	{
		delete terras[i];
	}

	for (unsigned int i = 0; i < tecnologias.size(); i++)
	{
		delete tecnologias[i];
	}

}






//Funções de gestao de recursos e força militar
int imperio::getCofre()
{
	return cofre;
}

int imperio::getArmazem()
{
	return armazem;
}

int imperio::getForca()
{
	return forcaMilitar;
}

int imperio::getMaxCofre()
{
	return maxCofre;
}

int imperio::getMaxArmazem()
{
	return maxArmazem;
}

int imperio::getMaxForcaMilitar()
{
	return maxForca;
}




void imperio::atualizaCofre(int quantidade)
{
	this->cofre += quantidade;

	if (this->cofre < 0)
		this->cofre = 0;
	if (this->cofre > maxCofre)
		this->cofre = maxCofre;
}


void imperio::atualizaArmazem(int quantidade)
{
	this->armazem += quantidade;

	if (this->armazem < 0)
		this->armazem = 0;
	if (this->armazem > maxArmazem)
		this->armazem = maxArmazem;
}

void imperio::atualizaForcaMilitar(int quantidade)
{
	this->forcaMilitar += quantidade;

	if (this->forcaMilitar < 0)
		this->forcaMilitar = 0;
	if (this->forcaMilitar > maxForca)
		this->forcaMilitar = maxForca;
}






void imperio::setMaxCofre(int novoMAX)
{
	this->maxCofre = novoMAX;
}

void imperio::setMaxArmazem(int novoMAX)
{
	this->maxArmazem = novoMAX;
}

void imperio::setMaxForcaMilitar(int novoMAX)
{
	this->maxForca = novoMAX;
}







//Funções de gestao de territorios
bool imperio::addTerra(territorio* a)
{
	terras.push_back(a);
	return true;
}


bool imperio::removeTerra(string nome)
{
	for (unsigned int i = 0; i < terras.size(); i++)
	{
		if (terras[i]->getNome() == nome)
		{
			terras.erase(terras.begin() + i);
			return true;
		}
	}

	return false;
}

territorio* imperio::procuraTerra(string nome)
{
	for (unsigned i = 0; i < terras.size(); i++)
	{
		if (terras[i]->getNome() == nome)
			return terras[i];
	}
	return NULL;
}

territorio* imperio::devolve_UltimaTerra()
{
	return terras[conta_Terras() - 1];
}

void imperio::geraRecursosImp(int ano, int turno)
{
	for (unsigned int i = 0; i < terras.size(); i++)
	{
		terras[i]->setCriacaoDeOuro(ano, turno);
		terras[i]->setCriacaoDeOuro(ano, turno);
	}
	for (unsigned int i = 0; i < terras.size(); i++)
	{
		atualizaCofre(terras[i]->getCriacaoDeOuro());
		atualizaArmazem(terras[i]->getCriacaoDeProdutos());
	}
}

int imperio::conta_Terras()
{
	return terras.size();
}



//Funções de gestao de tecnologias
bool imperio::addTecnologia(tecnologia* a)
{
	tecnologias.push_back(a);

	return true;
}

bool imperio::procura_tech(string nome)
{
	for (unsigned int i = 0; i < terras.size(); i++)
	{
		if (terras[i]->getNome() == nome)
			return true;
	}

	return false;
}

void imperio::adicionaEfeitosTech(string nome)
{
	if (nome == "Drones militares")
	{
		atualizaCofre(-3);
		setMaxForcaMilitar(5);
	}
		
	if (nome == "Misseis teleguiados")
	{
		atualizaCofre(-4);
	}

	if (nome == "Defesas territoriais")
	{
		atualizaCofre(-4);
	}

	if (nome == "Bolsa de valores")
	{
		atualizaCofre(-2);
	}

	if (nome == "Banco Central")
	{
		atualizaCofre(-2);
		setMaxCofre(5);
		setMaxArmazem(5);
	}
}

int imperio::conta_Tech()
{
	return tecnologias.size();
}

//Função responsavél por calcular a pontuacao total resultante da soma dos territorios
int imperio::totalPontos()
{
	int total = 0;

	for (unsigned int i = 0; i < terras.size(); i++)
	{
		total += terras[i]->getPontosDeVitoria();
	}

	return total;
}


//Função responsavél por conquistar averiguar se conquista
bool imperio::conquista(string nome, string categoria, int resistencia)
{
	int poderDeAtaque = 0;

	if (categoria == "Ilha")
	{
		if (conta_Terras() >= 5)
		{
			if (procura_tech("Misseis teleguiados") == true)
			{
				poderDeAtaque = rand() % 6 + getForca();
				cout << "\n Forca de ataque: " << poderDeAtaque;
				if (poderDeAtaque >= resistencia)
				{
					cout << "\n Resistencia do territorio: " << resistencia;
					cout << "\n Ataque efectuado com sucesso!";
					return true;
				}
				else
				{
					cout << "\n Resistencia do territorio: " << resistencia;
					cout << "\n O imperio perdeu no ataque ao territorio!" << endl;
					return false;
				}
			}
			else
			{
				cout << "\n O imperio nao possui a tecnologia 'Misseis teleguiados'!" << endl;
				return false;
			}
		}
		else
		{
			cout << "\n O imperio nao possui territorios sufucientes para conquistar um territorio da categoria Ilha!" << endl;
			return false;
		}
	}
	else
	{
		poderDeAtaque = rand() % 6 + getForca();
		cout << "\n Forca de ataque: " << poderDeAtaque;
		if (poderDeAtaque >= resistencia)
		{
			cout << "\n Resistencia do territorio: " << resistencia;
			cout << "\n Ataque efectuado com sucesso!";
			return true;
		}
		else
		{
			cout << "\n Resistencia do territorio: " << resistencia;
			cout << "\n O imperio perdeu no ataque ao territorio!" << endl;
			return false;
		}
	}

}


string imperio::getAsString()
{
	ostringstream oss;

	oss << " Nome do  imeperio: " << nomeImperio << endl;
	oss << " Quantidade de ouro do imperio "<< "(MAX " << maxCofre << "): " << cofre << endl;
	oss << " Quantidade de produtos do imperio " << "(MAX " << maxArmazem << "): " << armazem << endl;
	oss << " Forca Militar do imperio " << "(MAX "<< maxForca << "): "<< forcaMilitar << endl;

	if (terras.empty())
	{
		oss << "\n O imperio ainda nao conquistou qualquer territorio!";
	}
	else
	{
		oss << "\n Lista de territorios conquistados: " << endl;

		for (unsigned int i = 0; i < terras.size(); i++)
		{
			oss << terras[i]->getAsString() << endl;
		}
	}


	if (tecnologias.empty())
	{
		oss << "\n O imperio nao adquiriu qualquer tecnologia!";
	}
	else
	{
		oss << "\n\n Lista de Tecnologias adquiridas: " << endl;

		for (unsigned int i = 0; i < tecnologias.size(); i++)
		{
			oss << "  " << tecnologias[i]->getNome() << endl;
		}
	}

	return oss.str();
}