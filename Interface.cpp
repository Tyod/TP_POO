#include "Interface.h"

//Construtor e Destrutor
interface::interface(string nome)
{
	this->nomeInterface = nome;
}

interface::~interface()
{

}


//Funções Responsaveis pela interação com o utilizador em cada uma das fases
void interface::Fase_incial()
{
	j1.init_tech();
	j1.init_eventos();
	j1.init_rand();
	string opcao;
	
	cout << " CLASH OF IMPIRES\n\n\n\n" << endl;

	do {
		cout << " \n\n\n CRIACAO DO MUNDO";
		cout << " \n\n\n 'carrega'                  --> Carregar territorios de ficheiro." << endl;
		cout << " 'cria <tipo> <numero>'     --> Adicionar manualmente territorios(MAX 9 por tipo de territorio)" << endl;
		cout << " 'avanca'                   --> Avanca para a proxima fase" << endl;


		cout << "\n Comando: ";
		getline(cin, opcao);

		cout << "\n\n";

		j1.leitura_FaseInicial(opcao);
	} while (opcao != "avanca");

	cout << "\n\n\n\n\n\n\n\n\n ASSIM COMECA A SUA JORNADA....\n\n";
	cout << " \n ANO 1";
}


void interface::Primeira_Fase()
{
	string opcao;

	do {
		cout << "\n\n\n\n FASE 1 (ANO " << j1.getAno() << " Turno " << j1.getTurno() << ") - CONQUISTAR/PASSAR\n\n\n";

		cout << " 'conquista <nome>'  --> Conquistar um territorio especificando o seu nome." << endl;
		cout << " 'passa'             --> Nao atacar ninguem este turno." << endl;
		cout << " 'lista'             --> Mostra informacao relativa ao imeperio" << endl;

		cout << " \n Comando: ";
		getline(cin, opcao);

		j1.leitura_PrimeiraFase(opcao);
	} while (opcao != "passa");

}



void interface::Segunda_Fase()
{

	j1.geraRecursos();
	string opcao;
	int i=1;

	do {
		cout << "\n\n\n\n\n\n FASE 2 (ANO " << j1.getAno() << " Turno " << j1.getTurno() << ") - RECOLHA DE PRODUTOS E OURO\n\n";

		if (i == 1)
		{
			cout << " \n Ouro produzido Recolhido!";
			cout << " \n\n Produtos produzidos Recolhidos!\n\n";
		}
		

		cout << " 'maisouro' --> Obtem mais 1 de ouro, perdendo 2 de produtos" << endl;
		cout << " 'maisprod' --> Obtem mais 1 de produtos, perdendo 2 de ouro" << endl;
		cout << " 'lista'    --> Mostra informacao relativa ao imperio" << endl;
		cout << " 'avanca'   --> Avanca para a proxima fase" << endl;

		cout << "\n Comando: ";
		getline(cin, opcao);
		j1.leitura_SegundaFase(opcao);
		i++;
	} while (opcao != "avanca");
}



void interface::Terceira_Fase()
{
	string opcao;
	do {
		cout << "\n\n\n\n FASE 3 (ANO " << j1.getAno() << " Turno " << j1.getTurno() << ") - COMPRA DE UNIDADES MILITARES E TECNOLOGIA\n\n\n";

		cout << " 'maismilitar'    --> Aumentar em 1 unidade a forca militar do imperio. (Custo: 1 Ouro & 1 Produto)" << endl;
		cout << " 'adquire <tipo>' --> Adquirir um tipo de tecnologia." << endl;
		cout << " 'lista'          --> Mostra a informacao relativa ao imperio" << endl;
		cout << " 'avanca'         --> Avancar para a proxima fase" << endl << endl;

		cout << " \n TIPOS DE TECNOLOGIA: \n\n" << endl;
		cout << " Drones militares -  Esta tecnologia faz passar o limite maximo da forca militar para 5. Custa 3 unidades de ouro." << endl << endl;
		cout << " Misseis teleguiados - Esta tecnologia e necessaria para conquistar ilhas. Custa 4 unidades de ouro." << endl << endl;
		cout << " Defesas territoriais - E um equipamento especial de defesa que acrescenta 1 unidade a resistencia do territorio \n                        invadido durante um evento de invasao. Custa 4 unidades de ouro." << endl << endl;
		cout << " Bolsa de valores - Sistema comercial que torna possiveis as trocas entre produtos eouro, conforme referido na \n                    descricao da fase 2 do turno (Recolher produtos e ouro). Custa 2 unidades de ouro" << endl << endl;
		cout << " Banco Central - Esta tecnologia permite aumentar em duas unidades a capacidade de armazenamento do armazem e do \n                 cofre do imperio: passa a poder armazenar ate 5 de produtos e 5 unidades de ouro, respetivamente. \n                 Custa 2 unidades de ouro.";


		cout << " \n\n\n\n\n Comando: ";
		getline(cin, opcao);

		j1.leitura_TerceiraFase(opcao);
	} while (opcao != "avanca");
}



void interface::Quarta_Fase()
{
	int evento;
	string acontecimento;

	cout << "\n\n\n\n\n\n FASE 4 (ANO " << j1.getAno() << " Turno " << j1.getTurno() << ") - FASE DE EVENTOS\n\n\n";

	evento = rand() % 4 + 1;

	if (evento == 1)
	{
		cout << "\n\n Foi encontrado um recurso Abandonado!" << endl;
		acontecimento = "recurso";
	}

	if (evento == 2)
	{
		cout << "\n\n Decorreu um invasao!" << endl;
		acontecimento = "invasao";
	}

	if (evento == 3)
	{
		cout << "\n\n Foi establecida uma alianca!" << endl;
		acontecimento = "alianca";
	}

	if (evento == 4)
	{
		cout << "\n\n Nao decorreu nenhum evento este turno!" << endl;
		acontecimento = "nada";
	}

	j1.adcionaEfeitoEventoJog(acontecimento);

	string opcao;
	do {
		cout << "\n\n\n";
		cout << " lista  --> Mostra a informacao relativa ao imperio." << endl;
		cout << " avanca --> Avancar para a proxima fase." << endl;

		cout << "\n Comando: ";
		cin >> opcao;

		j1.leitura_QuartaFase(opcao);
	} while (opcao != "avanca");

}





//Função finalizadora do jogo
void interface::Finaliza_jogo()
{
	int pontos; 

	cout << "\n\n\n\n ESTATISTICAS FINAIS DE JOGO:\n\n";

	pontos = j1.Finalizacao_de_jogo();

	cout << " PONTUACAO FINAL: " << pontos;

	cout << "\n\n\n\n\n FIM DO JOGO \n\n\n\n\n";
}




//Função que gere todo o ciclo de fases do jogo
void interface::executa()
{
	Fase_incial();
	do {
		//j1.debug();
		Primeira_Fase();
		Segunda_Fase();
		Terceira_Fase();
		Quarta_Fase();
		j1.GereTempo();
	} while(j1.termina_Tempo() != true || j1.TerraNatalConquistada() == false);

	Finaliza_jogo();

	return;
}



