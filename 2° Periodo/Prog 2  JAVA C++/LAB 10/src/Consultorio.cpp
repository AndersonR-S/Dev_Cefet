#include "Consultorio.hpp"

Consultorio::Consultorio(){
    lista_consulta = new list<Consulta>();
    lista_medico = new list<Medico>();
    lista_paciente= new list<Paciente>();
    contPaciente = 0;
}

void Consultorio::cadastrarMedico(Medico m){
    lista_medico->push_back(m);
}

void Consultorio::removerMedico(int crm){
    list<Medico>::iterator aux;

    for(aux = lista_medico->begin(); aux != lista_medico->end(); aux++)
        if(aux->getCRM()==crm){
            aux->imprimir();
            lista_medico->erase(aux);
            return;
        }

    throw ExcecaoMedicoInexistente();
}

void Consultorio::cadastrarPaciente(Paciente p){
    lista_paciente->push_back(p);
    contPaciente++;
}

void Consultorio::removerPaciente(int cpf){
    list<Paciente>::iterator aux;

    for(aux = lista_paciente->begin(); aux != lista_paciente->end(); aux++)
        if(aux->getCpf()==cpf){
            aux->imprimir();
            lista_paciente->erase(aux);
            contPaciente--;
            return;
        }

    throw ExcecaoPacienteInexistente();
}

void Consultorio::cadastrarConsulta(Consulta co){
    lista_consulta->push_back(co);
}

void Consultorio::removerConsulta(int cpf, string data){
    list<Consulta>::iterator aux;

    for(aux = lista_consulta->begin();aux != lista_consulta->end(); aux ++)
        if(aux->getData()==data && aux->getPaciente().getCpf()==cpf){
            cout<<"\nNome do Paciente: "<<aux->getPaciente().getNome()
            <<" do CPF "<<aux->getPaciente().getCpf()<<endl;
             cout<<"Nome do Medico: "<<aux->getMedico().getNome()
            <<" do CRM "<<aux->getMedico().getCRM()<<endl;
            cout<<"Data: "<< aux->getData()<<endl;
            cout<<"Horas: "<< aux->getHora()<<endl;
            lista_consulta->erase(aux);
            return;
        }

    throw ExcecaoConsultaInexistente("Impossível remover Consulta. Paciente " + to_string(cpf) + " não tem consulta agendada para a data " + data);

}

Paciente Consultorio::buscarPaciente(int cpf) {
    list<Paciente>::iterator aux;

    for (aux = lista_paciente->begin(); aux != lista_paciente->end(); ++aux) {
        if (aux->getCpf() == cpf) {
            return *aux;
        }
    }

    throw ExcecaoPacienteInexistente("Paciente com CPF " + to_string(cpf) + " não encontrado");
}

Medico Consultorio::buscarMedico(int crm){
     list<Medico>::iterator aux;

     for(aux = lista_medico->begin(); aux != lista_medico->end(); aux++){
        if (aux->getCRM()==crm){
            return *aux;
        }
     }

    throw ExcecaoMedicoInexistente("Medico do CRM " + to_string(crm) + " não encontrado");

}

Consulta Consultorio::buscarConsulta(int cpf,int crm, string data){
    list<Consulta>::iterator aux;

    for(aux = lista_consulta->begin(); aux != lista_consulta->end(); aux++){
        if(aux->getMedico().getCRM() == crm && aux->getPaciente().getCpf()==cpf && aux->getData()==data){
            return *aux;
        }
    }

throw ExcecaoConsultaInexistente("Consulta não encontrado");

}

void Consultorio::imprimirConsultas(){
    if(lista_consulta->empty())
        throw ExcecaoConsultaInexistente("Lista de Consultas esta vazia");

    list<Consulta>::iterator aux;

    for(aux = lista_consulta->begin();aux != lista_consulta->end(); aux ++){
        cout<<"\nNome do Paciente: "<<aux->getPaciente().getNome()
            <<" do CPF "<<aux->getPaciente().getCpf()<<endl;
        cout<<"Nome do Medico: "<<aux->getMedico().getNome()
            <<" do CRM "<<aux->getMedico().getCRM()<<endl;
        cout<<"Data: "<< aux->getData()<<endl;
        cout<<"Horas: "<< aux->getHora()<<endl;
        cout<<"\n---------------\n";
    }
}

void Consultorio::imprimirListaDeMedicos(){
    if(lista_medico->empty())
        throw ExcecaoMedicoInexistente("Lista de Medicos esta vazia");

    list<Medico>::iterator aux;

    for(aux = lista_medico->begin();aux != lista_medico->end(); aux ++){
        aux->imprimir();
        cout<<"\n---------------\n";
    }
}

void Consultorio::imprimirListaDeTodosOsPaciente(){
    if(lista_paciente->empty())
        throw ExcecaoPacienteInexistente("Lista de Pacientes esta vazia");

    list<Paciente>::iterator aux;

    for(aux = lista_paciente->begin();aux != lista_paciente->end(); aux ++){
        aux->imprimir();
        cout<<"\n---------------\n";
    }
}