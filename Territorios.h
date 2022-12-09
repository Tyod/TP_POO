#ifndef TERRITORIOS_H
#define TERRITORIOS_H

#include <iostream>
#include <sstream>

using namespace std;


class territorio
{

protected:
	string nome;
	string categoria;
	int resistencia;
	int criacaoDeOuro;
	int criacaoDeProdutos;
	int pontosDeVitoria;

public:

	territorio(string nome, string categoria, int resistencia, int criacaoDeOuro, int criacaoDeProdutos, int pontosDeVitoria);
	~territorio();

	virtual string getNome();
	virtual string getCategoria();
	virtual int getResistencia();
	virtual int getCriacaoDeOuro();
	virtual int getCriacaoDeProdutos();
	virtual int getPontosDeVitoria();
	
	virtual void setResistencia(int quantidade);
	virtual void setCriacaoDeOuro(int turno, int ano)=0;
	virtual void setCriacaoDeProdutos(int turno, int ano)=0;


	virtual string getAsString();
};

#endif // !TERRITORIOS_H

