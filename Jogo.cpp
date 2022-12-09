#include "Jogo.h"

//Construtor e Destrutor
jogo::jogo(int turno, int ano)
{
	this->turno = turno;
	this->ano = ano;
}

jogo::~jogo()
{

}



//Funções get da class jogo
int jogo::getTurno()
{
	return turno;
}

int jogo::getAno()
{
	return ano;
}



//Funções de averiguação da continuidade do programa
void jogo::GereTempo()
{
	if (turno == 6)
	{
		ano++;
		turno = 1;
	}
	else
		turno++;
}

bool jogo::termina_Tempo()
{
	if (ano == 3)
	{
		return true;
	}
	else
		return false;
}

bool jogo::TerraNatalConquistada()
{
	return m1.terraConquistada("Territorio Inicial");
}



//Funções inicializadoras dos vetores de tecnologias e eventos presentes no mundo bem como do fator aleatório
void jogo::init_tech()
{
	m1.carrega_tech();
}

void jogo::init_eventos()
{
	m1.carrega_eventos();
}

void jogo::init_rand()
{
	srand((unsigned)time(NULL));
}




//Funções de utilidade relativa a geração de recursos e efeitos de eventos
void jogo::geraRecursos()
{
	m1.geraRecursosMund(ano, turno);
}

void jogo::adcionaEfeitoEventoJog(string nome)
{
	m1.adicionaEfeitosEventos(nome, ano);
}

void jogo::conquistaJog(string nome)
{
	m1.ConquistaIMP(nome);
}





//Funções de leitura de comandos
void jogo::leitura_FaseInicial(string comando)
{
	static int flag = 1;
	if (comando == "carrega")
	{
		if (flag == 1)
		{
			m1.carregaTerras_nConq();
			cout << " Territorios carregados com sucesso!";
			flag++;
		}
	}
	
	if (comando.substr(0, 4) == "cria")
	{
		m1.cria_terras_nConq(comando.substr(5, comando.length() - 7), stoi(comando.substr(comando.length() - 1, comando.length())));
		cout << " Territorios criados com sucesso!";
	}

	if (comando == "avanca")
		flag = 1;

}



void jogo::leitura_PrimeiraFase(string comando)
{
	static int flag = 1;
	if (comando.substr(0, 9) == "conquista")
	{
		if (flag == 1)
		{
			if (m1.terraExiste(comando.substr(10, comando.length())) == true && m1.terraConquistada(comando.substr(10, comando.length())) == false)
			{
				conquistaJog(comando.substr(10, comando.length()));
				flag++;
			}
			else
				cout << "\n O territorio a conquistar nao existe ou ja foi conquistado!" << endl;
		}

		else
			cout << "\n Ja atacou este turno!" << endl;
	}

	if (comando == "lista")
	{
		cout << "\n\n ESTADO ATUAL DO IMPERIO:\n\n";
		cout << m1.getAsStringIMP();
		cout << m1.getAsString();
	}

	if (comando == "passa")
		flag = 1;
}



void jogo::leitura_SegundaFase(string comando)
{
	if (comando == "maisouro")
	{
		if (m1.adquiriu_tech("Bolsa de valores") == true && m1.getArmazemIMP() < 2)
			cout << "\n\n O imperio nao possui produtos suficientes para a troca!" << endl;

		if (m1.adquiriu_tech("Bolsa de valores") == true && m1.getArmazemIMP() >= 2)
		{
			if (m1.getMaxCofreIMP() == m1.getCofreIMP())
				cout << "\n Maxima capacidade  de ouro atingida!" << endl;
			else
			{
				cout << "\n Foi adicionado ao seu cofre 1 unidade de ouro em troca de duas unidades de produtos!" << endl;
				m1.atualizaArmazemIMP(-2);
				m1.atualizaCofreIMP(1);
			}
		}

		if (m1.adquiriu_tech("Bolsa de valores") == false)
			cout << "\n\n Nao possui ainda a Bolsa de valores!" << endl;
	}




	if (comando == "maisprod")
	{
		if (m1.adquiriu_tech("Bolsa de valores") == true && m1.getCofreIMP() < 2)
			cout << "\n\n O imperio nao possui ouro suficiente para a troca!" << endl;


		if (m1.adquiriu_tech("Bolsa de valores") == true && m1.getCofreIMP() >= 2)
		{
			if (m1.getForcaIMP() == m1.getArmazemIMP())
				cout << "\n Maxima capacidade de produtos atingida!";
			else
			{
				cout << "\n Foi adicionado ao seu armazem 1 unidade de produtos em troca de duas unidades de ouro!" << endl;
				m1.atualizaCofreIMP(-2);
				m1.atualizaArmazemIMP(1);
			}
		}

		if (m1.adquiriu_tech("Bolsa de valores") == false)
			cout << "\n\n Nao possui ainda a Bolsa de valores! " << endl;
	}





	if (comando == "lista")
	{
		cout << "\n\n ESTADO ATUAL DO IMEPERIO:\n\n";
		cout << m1.getAsStringIMP();
	}
}





void jogo::leitura_TerceiraFase(string comando)
{
	static int flag = 1;
	if (comando == "maismilitar")
	{
		if (m1.getArmazemIMP() >= 1 && m1.getCofreIMP() >= 1)
		{
			if (m1.getMaxForcaIMP() == m1.getForcaIMP())
			{
				cout << "\n Maxima forca militar atingida!" << endl;
			}
			else
			{
				cout << "\n Foi adicionada uma unidade de forca militar ao imperio em troca de uma unidade de ouro e de produtos!" << endl;
				m1.atualizaCofreIMP(-1);
				m1.atualizaArmazemIMP(-1);
				m1.atualizaForcaMilitarIMP(1);
			}
		}
		else
		{
			if (m1.getArmazemIMP() < 1)
				cout << "\n\n O imperio nao possui produtos suficentes!" << endl;
			if (m1.getCofreIMP() < 1)
				cout << "\n\n O imperio nao possui ouro suficiente!" << endl;
		}
	}



	if (comando.substr(0, 7) == "adquire")
	{
		if (flag == 2)
		{
			cout << " Ja adquiriu uma tecnologia este turno!";
		}
		else
		{
			if (m1.adquiriu_tech(comando.substr(8, comando.length())) == false && m1.existe_tech(comando.substr(8, comando.length())) == true && m1.procura_Custo_Tecnologia(comando.substr(8, comando.length())) <= m1.getCofreIMP())
			{
				cout << " Adquiriu a tecnologia:  " << comando.substr(8, comando.length()) << endl << endl;
				m1.adicionaEfeitosTechIMP(comando.substr(8, comando.length()));
				m1.removeTecnologia_nConqMund(comando.substr(8, comando.length()));
				flag++;
			}
			else
			{
				if (m1.procura_Custo_Tecnologia(comando.substr(8, comando.length())) > m1.getCofreIMP())
					cout << "\n O imperio nao possui ouro suficente para comprar a tecnologia indicada!";

				else
					cout << "\n A Tecnologia  a adquirir nao existe ou ja foi adquirida!";
			}
		}
	}

	if (comando == "lista")
	{
		cout << "ESTADO ATUAL DO IMEPERIO: \n\n";
		cout << m1.getAsStringIMP();
	}

	if (comando == "avanca")
		flag = 1;
}


void jogo::leitura_QuartaFase(string comando)
{
	if (comando == "lista")
	{
		cout << "\n\n ESTADO ATUAL DO IMPERIO:\n\n";
		cout << m1.getAsStringIMP();
	}
}




//Função encarregada de preparar para a finalização do jogo
int jogo::Finalizacao_de_jogo()
{
	int totalPontos = 0;

	totalPontos += m1.totalPontosIMP();

	totalPontos += m1.contaTechIMP();

	if (m1.contaTechIMP() == 5)
	{
		cout << "\n [ACHIVEMENT] CIENTISTA EMPENHADO! (+1 PONTO BONUS)" << endl;
		cout << " Todas as tecnologias foram adquiridas." << endl << endl;
		totalPontos++;
	}

	if (m1.conta_terrasnConq() == 0)
	{
		cout << "\n [ACHIVEMENT] IMPERADOR SUPREMO! (+3 PONTOS BONUS)" << endl;
		cout << " Todos os territorios disponiveis foram conquistados." << endl << endl;
		totalPontos += 3;
	}

	m1.getAsStringIMP();

	return totalPontos;
}

void jogo::debug()
{
	m1.atualizaCofreIMP(3);
	m1.atualizaArmazemIMP(3);
}