#ifndef DOCUMENTOS_HPP
#define DOCUMENTOS_HPP

#include "Documentos.hpp"

#include <cstring>
#include <iostream>

using namespace std;

class Documentos
{
private:
	int id;
	string nomeArquivo;
	int numeroPagina;
	int prioridade;
	Documentos *proximo;

public:
	Documentos();

	void setId(int id);
	void setNomeArquivo(string nomeArquivo);
	void setNumeroPagina(int numeroPagina);
	void setPrioridade(int prioridade);
	void setInserirProximo(Documentos *documento);

	int getId();
	int getNumeroPagina();
	int getPrioridade();
	string getNomeArquivo();
	Documentos *getProximo();
};
#endif
