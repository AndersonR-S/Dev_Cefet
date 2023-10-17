import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        Consultorio consultorio = new Consultorio();
        while (true) {
            int opcao;

            System.out.println("1. Cadastrar Médico");
            System.out.println("2. Cadastrar Paciente");
            System.out.println("3. Cadastrar Consulta");
            System.out.println("4. Imprimir Dados dos Médico");
            System.out.println("5. Imprimir Consultas");
            System.out.println("6. Imprimir Dados dos Paciente");
            System.out.println("7. Imprimir Dados uma Consulta Especifica");
            System.out.println("8. Remover Médico");
            System.out.println("9. Remover Paciente");
            System.out.println("10. Remover Consulta");
            System.out.println("11. Sair");

            do {
                System.out.print("\nEscolhe uma opcao: ");
                opcao = scan.nextInt();
            } while (opcao < 1 && opcao > 11);

            System.out.println();

            switch (opcao) {
                case 1: {
                    String nome, endereco, cpf, especialidade;
                    char sexo;
                    int telefone, identidade, crm;
                    scan.nextLine();

                    System.out.print("Nome:");
                    nome = scan.nextLine();

                    System.out.print("Endereco: ");
                    endereco = scan.nextLine();

                    System.out.print("Cpf: ");
                    cpf = scan.nextLine();

                    System.out.print("Especialidade: ");
                    especialidade = scan.nextLine();

                    System.out.print("Identidade: ");
                    identidade = scan.nextInt();

                    System.out.print("Sexo (M/H): ");
                    sexo = scan.next().charAt(0);

                    System.out.print("Telefone: ");
                    telefone = scan.nextInt();

                    System.out.print("CRM: ");
                    crm = scan.nextInt();

                    Medico medico = new Medico(nome, endereco, cpf, sexo, telefone, identidade, crm, especialidade);
                    
                    System.out.println();
                    consultorio.cadastrarMedico(medico);
                    System.out.println();
                    break;
                }
                case 2:{
                    String nome, endereco, cpf, relato, medicacaoConsumidaRegulamente;
                    char sexo;
                    int telefone, identidade;

                    scan.nextLine();

                    System.out.print("Nome:");
                    nome = scan.nextLine();

                    System.out.print("Endereco: ");
                    endereco = scan.nextLine();

                    System.out.print("Cpf: ");
                    cpf = scan.nextLine();

                    System.out.print("Relato: ");
                    relato = scan.nextLine();

                    System.out.print("Medicação Consumida Regulamente: ");
                    medicacaoConsumidaRegulamente = scan.nextLine();

                    System.out.print("Identidade: ");
                    identidade = scan.nextInt();

                    System.out.print("Sexo (M/H): ");
                    sexo = scan.next().charAt(0);

                    System.out.print("Telefone: ");
                    telefone = scan.nextInt();

                    Paciente paciente = new Paciente(nome, endereco, cpf, sexo, telefone, identidade, relato, medicacaoConsumidaRegulamente);

                    System.out.println();
                    consultorio.cadastrarPaciente(paciente);
                    System.out.println();

                    break;
                }
                case 3:{
                    String data, hora, cpfPaciente;
                    int crmMedico;

                    scan.nextLine();

                    System.out.print("Data: ");
                    data = scan.nextLine();

                    System.out.print("Hora: ");
                    hora = scan.nextLine();

                    System.out.print("Cpf do Paciente: ");
                    cpfPaciente = scan.nextLine();

                    System.out.print("Crm do Médico: ");
                    crmMedico = scan.nextInt();

                    Consulta consulta =new Consulta(data, hora, cpfPaciente, crmMedico);

                    System.out.println();
                    consultorio.cadastrarConsulta(consulta);
                    System.out.println();
                    
                    break;
                }
                case 4: {
                    consultorio.imprimirListaMedicos();
                    break;
                }
                case 5:{
                    consultorio.imprimirListaConsultas();
                    break;
                }
                case 6:{
                    consultorio.imprimirListaPacientes();
                    break;
                }
                case 7:
                    System.out.println("Opção 7 selecionada");
                    break;
                case 8:{
                    int crm;
                    
                    System.out.print("Digite o Crm do Médico: ");
                    crm = scan.nextInt();

                    System.out.println();
                    consultorio.removerMedico(crm);
                    System.out.println();

                    break;
                }
                case 9:{
                    String cpf;
                    scan.nextLine();

                    System.out.println("Digite o Cpf do Paciente: ");
                    cpf = scan.nextLine();

                    System.out.println();
                    consultorio.removerPaciente(cpf);
                    System.out.println();
                    break;}
                case 10:{
                    String cpfPacinete;
                    int crmMedico;

                    scan.nextLine();

                    System.out.print("Digite o Cpf do Paciente: ");
                    cpfPacinete = scan.nextLine();

                    System.out.print("Digite o Crm do Médico: ");
                    crmMedico = scan.nextInt();

                    System.out.println();
                    consultorio.removerConsulta(cpfPacinete, crmMedico);
                    System.out.println();
                    break;
                }
                case 11:
                    scan.close();
                    System.exit(0);
                    break;

            }

        }

    }
}
