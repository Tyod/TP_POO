#include "Tecnologias.h"

using namespace std;

tecnologia::tecnologia(string nome, int custo)
{
	this->nome = nome;
	this->custo = custo;
}


tecnologia::~tecnologia()
{
}



string tecnologia::getNome()
{
	return nome;
}

int tecnologia::getCusto()
{
	return custo;
}


void tecnologia::setCusto()
{
	this->custo = custo;
}




string tecnologia::getAsString()
{
	ostringstream oss; 

	oss << " Nome: " << nome << "  Custo: " << custo;

	return oss.str();
}