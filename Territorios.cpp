#include "Territorios.h"

using namespace std;

territorio::territorio(string nome, string categoria, int resistencia, int criacaoDeOuro, int criacaoDeProdutos, int pontosDeVitoria)
{
	this->nome = nome;
	this->categoria = categoria;
	this->resistencia = resistencia;
	this->criacaoDeOuro = criacaoDeOuro;
	this->criacaoDeProdutos = criacaoDeProdutos;
	this->pontosDeVitoria = pontosDeVitoria;
}


territorio::~territorio()
{

}


string territorio::getNome()
{
	return nome;
}

string territorio::getCategoria()
{
	return categoria;
}

int territorio::getResistencia()
{
	return resistencia;
}

int territorio::getPontosDeVitoria()
{
	return pontosDeVitoria;
}

int territorio::getCriacaoDeOuro()
{
	return criacaoDeOuro;
}

int territorio::getCriacaoDeProdutos()
{
	return criacaoDeProdutos;
}


void territorio::setResistencia(int quantidade)
{
	this->resistencia = quantidade;
}


string territorio::getAsString()
{
	ostringstream oss;

	oss << " Nome: " << nome << "  Resistencia: " << resistencia << "  Criacao ouro: " << criacaoDeOuro << "  Criacao de produtos: " << criacaoDeProdutos << " Pontos de vitoria: " << pontosDeVitoria;

	return oss.str();
}




