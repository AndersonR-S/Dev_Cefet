#include "Documentos.hpp"

Documentos::Documentos(){
    
}   

void Documentos::setId(int id){
    this->id = id;
}
void Documentos::setNomeArquivo(string nomeArquivo){
    this->nomeArquivo = nomeArquivo;
}
void Documentos::setNumeroPagina(int numeroPagina){
    this->numeroPagina = numeroPagina;
}
void Documentos::setPrioridade(int prioridade){
    this->prioridade = prioridade;
}
void Documentos::setInserirProximo(Documentos *documento){
    this->proximo = documento;
}


int Documentos::getId(){
    return this->id;
}
int Documentos::getNumeroPagina(){
    return this->numeroPagina;
}
int Documentos::getPrioridade(){
    return this->prioridade;
}
string Documentos::getNomeArquivo(){
    return this->nomeArquivo;
}
Documentos *Documentos::getProximo(){
    return this->proximo;
}
