import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class App {
    private ArrayList<ContaCorrenteComum> contaCC;
    private ArrayList<ContaCorrentePremium> contaCP;
    private ArrayList<ContaInvestimento> contaI;
    private ArrayList<ContaPoupaca> contaP;

    public App() {
        this.contaCC = new ArrayList<ContaCorrenteComum>();
        this.contaCP = new ArrayList<ContaCorrentePremium>();
        this.contaI = new ArrayList<ContaInvestimento>();
        this.contaP = new ArrayList<ContaPoupaca>();
    }

    public void crirConta() {
        Scanner scan = new Scanner(System.in);
        String nome;
        int numeroConta;
        float saldo;

        System.out.println("Criando Conta:\n");/*  */
        System.out.print("Nome: ");
        nome = scan.nextLine();
        while (true) {
            try {
                System.out.print("Número da Conta: ");
                numeroConta = scan.nextInt();
                break;
            } catch (InputMismatchException e) {
                System.out.println("Por favor, Insira um número válido");
                scan.nextLine();
            }
        }
        ;
        while (true) {
            try {
                System.out.print("Saldo: ");
                saldo = scan.nextFloat();
                break;
            } catch (InputMismatchException e) {
                System.out.println("Por favor, Insira um número válido");
                scan.nextLine();
            }
        }
        ;
        int opcao = 0;
        System.out.println("\n1. Criar Conta Corrente Comum (CCC)");
        System.out.println("2. Conta Corrente Premium (CCP)");
        System.out.println("3. Conta Poupança (CP)");
        System.out.println("4. Conta de Investidor (CI)");
        System.out.println("5. Menu Principal");
        do {
            try {
                System.out.print("\nEscolhe uma opcao: ");
                opcao = scan.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("Por favor, Insira um número válido");
                scan.nextLine();
                continue;
            }
        } while (opcao < 1 || opcao > 5);

        switch (opcao) {
            case 1: {
                for (ContaCorrenteComum c : contaCC) {
                    if (c.getNumeroConta() == numeroConta) {
                        System.out.println("\nNúmero de Conta da Utilizado");
                        return;
                    }
                }
                ContaCorrenteComum cc = new ContaCorrenteComum(nome, numeroConta, saldo);
                contaCC.add(cc);
                System.out.println("Cadastrado com Sucesso");

                break;
            }

            case 2: {
                // Conta Corrente Premium (CCP)
                scan.nextLine();
                float limite = 0;

                for (ContaCorrentePremium cp : contaCP) {
                    if (cp.getNumeroConta() == numeroConta) {
                        System.out.println("\nNúmero de Conta da Utilizado");
                        return;
                    }
                }

                while (true) {
                    try {
                        System.out.print("Digite o limite da conta: ");
                        limite = scan.nextFloat();
                        break;

                    } catch (InputMismatchException e) {
                        scan.nextLine();

                    }

                }

                ContaCorrentePremium ccp = new ContaCorrentePremium(nome, numeroConta, saldo, limite);
                contaCP.add(ccp);
                System.out.println("Cadastrado com Sucesso");

                break;

            }
            case 3: {
                // Conta Poupança (CP)
                int diaAniversario = 0;
                for (ContaPoupaca p : contaP) {
                    if (p.getNumeroConta() == numeroConta) {
                        System.out.println("\nNúmero de Conta da Utilizado");
                        return;
                    }
                }
                while (true) {
                    try {
                        System.out.print("Digite dia do aniversário da conta: ");
                        diaAniversario = scan.nextInt();
                        break;
                    } catch (InputMismatchException e) {
                        scan.nextLine();

                    }
                }

                ContaPoupaca cp = new ContaPoupaca(nome, numeroConta, saldo, diaAniversario);
                contaP.add(cp);
                System.out.println("Cadastrado com Sucesso");
                break;
            }
            case 4: {
                float taxaAnual = 0;
                for (ContaInvestimento p : contaI) {
                    if (p.getNumeroConta() == numeroConta) {
                        System.out.println("\nNúmero de Conta da Utilizado");
                        return;
                    }
                }
                while (true) {
                    try {
                        System.out.print("Digite a taxa anual: ");
                        taxaAnual = scan.nextFloat();
                        break;
                    } catch (InputMismatchException e) {
                        scan.nextLine();

                    }
                }
                ContaInvestimento I = new ContaInvestimento(nome, numeroConta, saldo, taxaAnual);
                contaI.add(I);
                System.out.println("Cadastrado com Sucesso");

                break;
            }
            case 5: {
                break;
            }

        }

    }

    public void saque() {
        Scanner scan = new Scanner(System.in);
        int opcao = 0;
        int conta = 0;
        float sacar = 0;

        System.out.println("\nSacar:\n");/*  */

        while (true) {
            try {
                System.out.print("Digite o numero da Conta: ");
                conta = scan.nextInt();
                break;
            } catch (InputMismatchException e) {
                scan.nextLine();
            }
        }

        while (true) {
            try {
                System.out.print("Digite o valor do Saque: ");
                sacar = scan.nextFloat();
                break;
            } catch (InputMismatchException e) {
                scan.nextLine();
            }
        }

        System.out.println("\n1. Conta Corrente Comum");
        System.out.println("2. Conta Corrente Premium");
        System.out.println("3. Conta Poupança");
        System.out.println("4. Conta Investimento");
        System.out.println("5. Menu Principal");
        do {
            try {
                System.out.print("\nEscolhe uma opção: ");
                opcao = scan.nextInt();

            } catch (InputMismatchException e) {
                scan.nextLine();
                continue;
            }
        } while (opcao < 1 || opcao > 5);
        switch (opcao) {
            case 1: {
                for (ContaCorrenteComum cc : contaCC) {
                    if (cc.getNumeroConta() == conta) {
                        cc.saqueComum(sacar);
                        return;
                    }
                }
                System.out.println("Conta não Encontrado");

                break;
            }
            case 2: {
                for (ContaCorrentePremium cc : contaCP) {
                    if (cc.getNumeroConta() == conta) {
                        cc.saqueEspecial(sacar);
                        return;
                    }
                }
                System.out.println("Conta não Encontrado");

                break;
            }
            case 3: {
                for (ContaPoupaca cc : contaP) {
                    if (cc.getNumeroConta() == conta) {
                        cc.saqueComum(sacar);
                        return;
                    }
                }
                System.out.println("Conta não Encontrado");

                break;
            }
            case 4: {
                for (ContaInvestimento cc : contaI) {
                    if (cc.getNumeroConta() == conta) {
                        cc.saqueComum(sacar);
                        return;
                    }
                }
                System.out.println("Conta não Encontrado");

                break;
            }
            case 5: {
                break;
            }
        }

    }

    public void deposito() {
        Scanner scan = new Scanner(System.in);
        int opcao = 0;
        int conta = 0;
        float sacar = 0;

        System.out.println("\nDeposito:\n");/*  */

        while (true) {
            try {
                System.out.print("Digite o numero da Conta: ");
                conta = scan.nextInt();
                break;
            } catch (InputMismatchException e) {
                scan.nextLine();
            }
        }

        while (true) {
            try {
                System.out.print("Digite o valor do Deposito: ");
                sacar = scan.nextFloat();
                break;
            } catch (InputMismatchException e) {
                scan.nextLine();
            }
        }

        System.out.println("\n1. Conta Corrente Comum");
        System.out.println("2. Conta Corrente Premium");
        System.out.println("3. Conta Poupança");
        System.out.println("4. Conta Investimento");
        System.out.println("5. Menu Principal");
        do {
            try {
                System.out.print("\nEscolhe uma opção: ");
                opcao = scan.nextInt();

            } catch (InputMismatchException e) {
                scan.nextLine();
                continue;
            }
        } while (opcao < 1 || opcao > 5);
        switch (opcao) {
            case 1: {
                for (ContaCorrenteComum cc : contaCC) {
                    if (cc.getNumeroConta() == conta) {
                        cc.deposito(conta);
                        return;
                    }
                }
                System.out.println("Conta não Encontrado");

                break;
            }
            case 2: {
                for (ContaCorrentePremium cc : contaCP) {
                    if (cc.getNumeroConta() == conta) {
                        cc.deposito(sacar);
                        return;
                    }
                }
                System.out.println("Conta não Encontrado");
                break;
            }
            case 3: {
                for (ContaPoupaca cc : contaP) {
                    if (cc.getNumeroConta() == conta) {
                        cc.deposito(sacar);
                        return;
                    }
                }
                System.out.println("Conta não Encontrado");

                break;
            }
            case 4: {
                for (ContaInvestimento cc : contaI) {
                    if (cc.getNumeroConta() == conta) {
                        cc.deposito(sacar);
                        return;
                    }
                }
                System.out.println("Conta não Encontrado");

                break;
            }
            case 5: {
                break;
            }
        }

    }

    public void extrato(){
        Scanner scan = new Scanner(System.in);
        int opcao = 0;
        int conta = 0;

        System.out.println("\nExtrato:\n");/*  */

        while (true) {
            try {
                System.out.print("Digite o numero da Conta: ");
                conta = scan.nextInt();
                break;
            } catch (InputMismatchException e) {
                scan.nextLine();
            }
        }

        System.out.println("\n1. Conta Corrente Comum");
        System.out.println("2. Conta Corrente Premium");
        System.out.println("3. Conta Poupança");
        System.out.println("4. Conta Investimento");
        System.out.println("5. Menu Principal");
        do {
            try {
                System.out.print("\nEscolhe uma opção: ");
                opcao = scan.nextInt();

            } catch (InputMismatchException e) {
                scan.nextLine();
                continue;
            }
        } while (opcao < 1 || opcao > 5);
        switch (opcao) {
            // exibe número da conta, nome do titular, transações e saldo. 
            case 1: {
                for (ContaCorrenteComum cc : contaCC) {
                    if (cc.getNumeroConta() == conta) {
                        cc.extrato();;
                        return;
                    }
                }
                System.out.println("Conta não Encontrado");

                break;
            }
            case 2: {
                for (ContaCorrentePremium cc : contaCP) {
                    if (cc.getNumeroConta() == conta) {
                        cc.extrato();
                        return;
                    }
                }
                System.out.println("Conta não Encontrado");
                break;
            }
            case 3: {
                for (ContaPoupaca cc : contaP) {
                    if (cc.getNumeroConta() == conta) {
                        cc.extrato();
                        return;
                    }
                }
                System.out.println("Conta não Encontrado");

                break;
            }
            case 4: {
                for (ContaInvestimento cc : contaI) {
                    if (cc.getNumeroConta() == conta) {
                        cc.extrato();
                        return;
                    }
                }
                System.out.println("Conta não Encontrado");

                break;
            }
            case 5: {
                break;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        App app = new App();
        Scanner scan = new Scanner(System.in);
        while (true) {
            int opcao = 0;
            System.out.println("\n1. Criar Contas");
            System.out.println("2. Saque");
            System.out.println("3. Dépositar");
            System.out.println("4. Extrato");
            System.out.println("5. Sair");
            do {
                try {
                    System.out.print("\nEscolha uma opção: ");
                    opcao = scan.nextInt();
                } catch (InputMismatchException e) {
                    System.out.println("Por favor, Insira um número válido");
                    scan.nextLine();
                    continue;
                }
            } while (opcao < 1 || opcao > 5);

            scan.nextLine();
            System.out.println();

            switch (opcao) {
                case 1:
                    app.crirConta();
                    break;
                case 2:
                    app.saque();

                    break;
                case 3:
                    app.deposito();
                    break;
                case 4:
                    app.extrato();
                    break;
                case 5:
                    System.out.println("Saindo do programa");
                    System.exit(0);
                    break;

            }

        }
    }
}
