#include "Consultorio.hpp"
#include <limits>

void cadastrarMedico(Consultorio *cons)
{
    cin.ignore();
    Medico novo;

    string nome, endereco, telefone, identidade, especialidade;
    char sexo;
    int cpf, crm;

    cout << "\n# ======= CADASTRO MEDICO ======= #\n";
    cout << "Nome: ";
    getline(cin, nome);
    novo.setNome(nome);

    cout << "Identidade: ";
    getline(cin, identidade);
    novo.setIdentidade(identidade);

    cout << "Telefone: ";
    getline(cin, telefone);
    novo.setTelefone(telefone);

    cout << "Endereco: ";
    getline(cin, endereco);
    novo.setEndereco(endereco);

    cout << "Especialidade: ";
    getline(cin, especialidade);
    novo.setEspecialidade(especialidade);

    while (true)
    {
        try
        {
            cout << "Sexo (M ou F): ";
            sexo = getchar();
            novo.setSexo(sexo);
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        catch (ExcecaoSexoInvalido &ex)
        {
            cerr << endl
                 << ex.what() << endl;
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    while (true)
    {
        cout << "CPF: ";
        cin >> cpf;
        novo.setCpf(cpf);

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            break;
    }

    while (true)
    {
        cout << "CRM: ";
        cin >> crm;
        novo.setCRM(crm);

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            break;
    }

    cons->cadastrarMedico(novo);

    cout << "\nCADASTRO CONCLUIDO\n"
         << endl;
    novo.imprimir();
    cout << "\n# ======================= #\n\n";
}

void removerMedico(Consultorio *cons)
{
    cin.ignore();
    int crm;
    cout << "\n# ======= REMOVER MEDICO ======= #\n";

    while (true)
    {
        cout << "CRM: ";
        cin >> crm;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            break;
    }
    cout << endl
         << "---------------------" << endl;
    try
    {
        cons->removerMedico(crm);
    }
    catch (ExcecaoMedicoInexistente &ex)
    {
        cerr << ex.what() << endl;
    }

    cout << "\n# ======================= #\n\n";
}

void cadastrarPaciente(Consultorio *cons)
{
    cin.ignore();
    Paciente novo;

    string nome, endereco, telefone, identidade, relato, data, novocacao;
    char sexo;
    int cpf;

    cout << "\n# ======= CADASTRO PACIENTE ======= #\n";
    cout << "Nome: ";
    getline(cin, nome);
    novo.setNome(nome);

    cout << "Identidade: ";
    getline(cin, identidade);
    novo.setIdentidade(identidade);

    cout << "Telefone: ";
    getline(cin, telefone);
    novo.setTelefone(telefone);

    cout << "Endereco: ";
    getline(cin, endereco);
    novo.setEndereco(endereco);

    cout << "Relato : ";
    getline(cin, relato);
    novo.setRelato(relato);

    cout << "Data da ultima consulta: ";
    getline(cin, data);
    novo.setDataUltimaConsulta(data);

    cout << "Medicacao que toma: ";
    getline(cin, novocacao);
    novo.setMedicacao(novocacao);

    while (true)
    {
        try
        {
            cout << "Sexo (M ou F): ";
            sexo = getchar();
            novo.setSexo(sexo);
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        catch (ExcecaoSexoInvalido &ex)
        {
            cerr << endl
                 << ex.what() << endl;
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    while (true)
    {
        cout << "CPF: ";
        cin >> cpf;
        novo.setCpf(cpf);

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            break;
    }

    cons->cadastrarPaciente(novo);

    cout << "\nCADASTRO CONCLUIDO\n"
         << endl;
    novo.imprimir();
    cout << "\n# ======================= #\n\n";
}

void removerPaciente(Consultorio *cons)
{
    cin.ignore();
    int cpf;
    cout << "\n# ======= REMOVER PACIENTE ======= #\n";

    while (true)
    {
        cout << "Cpf: ";
        cin >> cpf;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            break;
    }
    cout << endl
         << "---------------------" << endl;
    try
    {
        cons->removerPaciente(cpf);
    }
    catch (ExcecaoPacienteInexistente &ex)
    {
        cerr << ex.what() << endl;
    }

    cout << "\n# ======================= #\n\n";
}

void cadastrarConsulta(Consultorio *cons)
{
    cin.ignore();
    int cpf, crm;
    string data, hora;

    cout << "\n# ======= CADASTRO CONSULTA ======= #\n";
    cout << "Data: ";
    getline(cin, data);

    cout << "Hora: ";
    getline(cin, hora);

    while (true)
    {
        cout << "CPF do Paciente: ";
        cin >> cpf;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            break;
    }

    while (true)
    {
        cout << "CRM do Medico: ";
        cin >> crm;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            break;
    }

    Paciente paciente;
    try
    {
        paciente = cons->buscarPaciente(cpf);
    }
    catch (ExcecaoPacienteInexistente &ex)
    {
        cerr << ex.what() << endl;
        return;
    }

    Medico medico;
    try
    {
        medico = cons->buscarMedico(crm);
    }
    catch (ExcecaoMedicoInexistente &ex)
    {
        cerr << ex.what() << endl;
        return;
    }

    try
    {
        Consulta consulta = cons->buscarConsulta(cpf, crm, data);

        cout << "Consulta ja existe com Medico do CRM " + to_string(crm) + " e com o Pacinete do CPF " + to_string(cpf) + " na Data " + data << endl;
    }
    catch (ExcecaoConsultaInexistente &ex)
    {
        Consulta nova_consulta(paciente, medico, data, hora);
        cons->cadastrarConsulta(nova_consulta);
    }

    cout << "\n# ======================= #\n\n";
}

void removerConsulta(Consultorio *cons)
{
    cin.ignore();

    string data;
    int cpf;

    cout << "\n# ======= REMOVENDO CONSULTA ======= #\n";

    cout << "Data: ";
    getline(cin, data);

    while (true)
    {
        cout << "CPF do Paciente: ";
        cin >> cpf;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            break;
    }
    cout << endl
         << "---------------------" << endl;

    try
    {
        cons->removerConsulta(cpf, data);
    }
    catch (ExcecaoConsultaInexistente &ex)
    {
        cerr << ex.what() << endl;
    }

    cout << "\n# ======================= #\n\n";
}

void imprimirConsultas(Consultorio *cons)
{
    cin.ignore();
    cout << "\n# ======= IMPRIMINDO CONSULTAS ======= #\n";

    try
    {
        cons->imprimirConsultas();
    }
    catch (ExcecaoConsultaInexistente &ex)
    {
        cerr << ex.what() << endl;
    }

    cout << "\n# ======================= #\n\n";
}

void imprimirPacientes(Consultorio *cons)
{
    cin.ignore();
    cout << "\n# ======= IMPRIMINDO PACIENTES ======= #\n";

    try
    {
        cons->imprimirListaDeTodosOsPaciente();
    }
    catch (ExcecaoPacienteInexistente &ex)
    {
        cerr << ex.what() << endl;
    }

    cout << "\n# ======================= #\n\n";
}

void imprimirMedicos(Consultorio *cons)
{
    cin.ignore();
    cout << "\n# ======= IMPRIMINDO MEDICOS ======= #\n";

    try
    {
        cons->imprimirListaDeMedicos();
    }
    catch (ExcecaoMedicoInexistente &ex)
    {
        cerr << ex.what() << endl;
    }

    cout << "\n# ======================= #\n\n";
}

void imprimirConsultaUnica(Consultorio *cons)
{
    cin.ignore();
    string data;
    int cpf, crm;
    cout << "\n# ======= IMPRIMINDO CONSULTA ESPECIFICA ======= #\n";
    cout << "Data: ";
    getline(cin, data);

    while (true)
    {
        cout << "CPF do Paciente: ";
        cin >> cpf;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            break;
    }

    while (true)
    {
        cout << "CRM do Medico: ";
        cin >> crm;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            break;
    }

    Consulta consulta;
    try
    {
        cout << "\n------------------\n";
        consulta = cons->buscarConsulta(cpf, crm, data);

        cout << "Medico: \n";
        consulta.getMedico().imprimir();
        cout << "\nPaciente: \n";
        consulta.getPaciente().imprimir();
        cout << "\nConsulta: \n";
        cout << "Data: " << consulta.getData() << endl;
        cout << "Hora: " << consulta.getHora() << endl;
    }
    catch (ExcecaoConsultaInexistente &ex)
    {
        cerr << ex.what() << endl;
    }

    cout << "\n# ======================= #\n\n";
}

int main()
{
    Consultorio *consultorio = new Consultorio();
    while (true)
    {
        int opcao;

        cout << endl
             << "1. Cadastrar Medico\n"
             << "2. Cadastrar Paciente\n"
             << "3. Cadastrar Consulta\n"
             << "4. Imprimir dados do Medico\n"
             << "5. Imprimir Consultas\n"
             << "6. Imprimir dados do Paciente\n"
             << "7. Imprimir detalhes da Consulta\n"
             << "8. Remover Medico\n"
             << "9. Remover Paciente\n"
             << "10. Remover Consulta\n"
             << "11. Sair\n\n";

        while (true)
        {
            cout << "Escolha uma opcao: ";
            cin >> opcao;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            }
            else
                break;
        }

        switch (opcao)
        {
        case 1:
            cadastrarMedico(consultorio);
            break;
        case 2:
            cadastrarPaciente(consultorio);
            break;
        case 3:
            cadastrarConsulta(consultorio);
            break;
        case 4:
            imprimirMedicos(consultorio);
            break;
        case 5:
            imprimirConsultas(consultorio);
            break;
        case 6:
            imprimirPacientes(consultorio);
            break;
        case 7:
            imprimirConsultaUnica(consultorio);
            break;
        case 8:
            removerMedico(consultorio);
            break;
        case 9:
            removerPaciente(consultorio);
            break;
        case 10:
            removerConsulta(consultorio);
            break;
        case 11:
        {
            delete consultorio;
            return 0;
        }
        }
    }
    return 0;
}