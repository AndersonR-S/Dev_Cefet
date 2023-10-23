import java.util.InputMismatchException;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        Consultorio consultorio = new Consultorio();
        while (true) {
            int opcao = 0;

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
                try {
                    System.out.print("\nEscolhe uma opcao: ");
                    opcao = scan.nextInt();
                } catch (InputMismatchException e) {
                    scan.nextLine();
                    continue;
                }
            } while (opcao < 1 && opcao > 11);

            System.out.println();

            switch (opcao) {
                case 1: {
                    String nome, endereco, cpf, especialidade;
                    char sexo;
                    int telefone, identidade, crm;
                    scan.nextLine();

                    System.out.print("Nome: ");
                    nome = scan.nextLine();

                    System.out.print("Endereco: ");
                    endereco = scan.nextLine();

                    System.out.print("Cpf: ");
                    cpf = scan.nextLine();

                    System.out.print("Especialidade: ");
                    especialidade = scan.nextLine();

                    while (true) {
                        try {
                            System.out.print("Identidade: ");
                            identidade = scan.nextInt();
                            break;
                        } catch (InputMismatchException e) {
                            scan.nextLine();
                        }
                    }

                    do {
                        System.out.print("Sexo (M/H): ");
                        sexo = scan.next().charAt(0);

                    } while (sexo != 'M' && sexo != 'm' && sexo != 'h' && sexo != 'H');

                    while (true) {
                        try {
                            System.out.print("Telefone: ");
                            telefone = scan.nextInt();
                            break;
                        } catch (InputMismatchException e) {
                            scan.nextLine();
                        }
                    }
                    while (true) {
                        try {
                            System.out.print("CRM: ");
                            crm = scan.nextInt();
                            break;
                        } catch (InputMismatchException e) {
                            scan.nextLine();
                        }
                    }

                    Medico medico = new Medico(nome, endereco, cpf, sexo, telefone, identidade, crm, especialidade);

                    System.out.println();
                    consultorio.cadastrarMedico(medico);
                    System.out.println();
                    break;
                }
                case 2: {
                    String nome, endereco, cpf, relato, medicacaoConsumidaRegulamente;
                    char sexo;
                    int telefone, identidade;

                    scan.nextLine();

                    System.out.print("Nome: ");
                    nome = scan.nextLine();

                    System.out.print("Endereco: ");
                    endereco = scan.nextLine();

                    System.out.print("Cpf: ");
                    cpf = scan.nextLine();

                    System.out.print("Relato: ");
                    relato = scan.nextLine();

                    System.out.print("Medicação Consumida Regulamente: ");
                    medicacaoConsumidaRegulamente = scan.nextLine();

                    while (true) {
                        try {
                            System.out.print("Identidade: ");
                            identidade = scan.nextInt();
                            break;
                        } catch (InputMismatchException e) {
                            scan.nextLine();
                        }
                    }

                    do {
                        System.out.print("Sexo (M/H): ");
                        sexo = scan.next().charAt(0);

                    } while (sexo != 'M' && sexo != 'm' && sexo != 'h' && sexo != 'H');
                    ;

                    while (true) {
                        try {
                            System.out.print("Telefone: ");
                            telefone = scan.nextInt();
                            break;
                        } catch (InputMismatchException e) {
                            scan.nextLine();
                        }
                    }

                    Paciente paciente = new Paciente(nome, endereco, cpf, sexo, telefone, identidade, relato,
                            medicacaoConsumidaRegulamente);

                    System.out.println();
                    consultorio.cadastrarPaciente(paciente);
                    System.out.println();

                    break;
                }
                case 3: {
                    String data, hora, cpfPaciente;
                    int crmMedico;

                    scan.nextLine();

                    System.out.print("Data: ");
                    data = scan.nextLine();

                    System.out.print("Hora: ");
                    hora = scan.nextLine();

                    System.out.print("Cpf do Paciente: ");
                    cpfPaciente = scan.nextLine();

                    while (true) {
                        try {
                            System.out.print("Crm do Médico: ");
                            crmMedico = scan.nextInt();
                            break;
                        } catch (InputMismatchException e) {
                            scan.nextLine();
                        }
                    }

                    Consulta consulta = new Consulta(data, hora, cpfPaciente, crmMedico);

                    System.out.println();
                    consultorio.cadastrarConsulta(consulta);
                    System.out.println();

                    break;
                }
                case 4: {
                    consultorio.imprimirListaMedicos();
                    break;
                }
                case 5: {
                    consultorio.imprimirListaConsultas();
                    System.out.println();
                    break;
                }
                case 6: {
                    consultorio.imprimirListaPacientes();
                    break;
                }
                case 7: {
                    String cpfPaciente;
                    int crmMedico, id;
                    scan.nextLine();

                    System.out.print("Digite o CPF do Paciente: ");
                    cpfPaciente = scan.nextLine();

                    while (true) {
                        try {
                            System.out.print("Digite o CRM do Médico: ");
                            crmMedico = scan.nextInt();
                            break;
                        } catch (InputMismatchException e) {
                            scan.nextLine();
                        }
                    }

                    while (true) {
                        try {
                            System.out.print("Digite o Id da consulta: ");
                            id = scan.nextInt();
                            break;
                        } catch (InputMismatchException e) {
                            scan.nextLine();
                        }
                    }
                    System.out.println();
                    consultorio.imprimirConsulta(cpfPaciente, crmMedico, id);
                    System.out.println();

                    break;
                }
                case 8: {
                    int crm;
                    while (true) {
                        try {
                            System.out.print("Digite o Crm do Médico: ");
                            crm = scan.nextInt();
                            break;
                        } catch (InputMismatchException e) {
                            scan.nextLine();
                        }
                    }

                    System.out.println();
                    consultorio.removerMedico(crm);
                    System.out.println();

                    break;
                }
                case 9: {
                    String cpf;
                    scan.nextLine();

                    System.out.print("Digite o Cpf do Paciente: ");
                    cpf = scan.nextLine();

                    System.out.println();
                    consultorio.removerPaciente(cpf);
                    System.out.println();
                    break;
                }
                case 10: {
                    String cpfPacinete;
                    int crmMedico, id;

                    scan.nextLine();

                    System.out.print("Digite o Cpf do Paciente: ");
                    cpfPacinete = scan.nextLine();

                    while (true) {
                        try {
                            System.out.print("Digite o Crm do Médico: ");
                            crmMedico = scan.nextInt();
                            break;
                        } catch (InputMismatchException e) {
                            scan.nextLine();
                        }
                    }

                    while (true) {
                        try {
                            System.out.print("Digite o Id da consulta: ");
                            id = scan.nextInt();
                            break;
                        } catch (InputMismatchException e) {
                            scan.nextLine();
                        }
                    }

                    System.out.println();
                    consultorio.removerConsulta(id, crmMedico, cpfPacinete);
                    ;
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
