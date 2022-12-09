#ifndef  TECNOLOGIAS_H
#define TECNOLOGIAS_H

#include <iostream>
#include <sstream>

using namespace std;

class tecnologia
{
	string nome;
	int custo;

public:

	tecnologia(string nome, int custo=0);
	~tecnologia();

	string getNome();
	int getCusto();

	void setCusto();

	string getAsString();
};
#endif // TECNOLOGIAS_H

