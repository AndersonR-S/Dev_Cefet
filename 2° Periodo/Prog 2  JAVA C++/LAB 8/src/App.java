import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class App {
    static ArrayList<ContaCorrenteComum> contaCC;
    private static ArrayList<ContaCorrentePremium> contaCP;
    private static ArrayList<ContaInvestimento> contaI;
    private static ArrayList<ContaPoupaca> contaP;

    public App() {
        contaCC = new ArrayList<ContaCorrenteComum>();
        contaCP = new ArrayList<ContaCorrentePremium>();
        contaI = new ArrayList<ContaInvestimento>();
        contaP = new ArrayList<ContaPoupaca>();
    }

    
    public static void crirConta() {
        Scanner scan = new Scanner(System.in);
        String nome;
        int numeroConta;
        float saldo;

        System.out.println("Criando Conta:\n");
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
            System.out.println("4. Menu Principal");
        do{
            try {
                System.out.print("\nEscolhe uma opcao: ");
                opcao = scan.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("Por favor, Insira um número válido");
                scan.nextLine();
                continue;
            }
        }while(opcao<1 || opcao> 4);

        switch(opcao){
            case 1:{
                ContaCorrenteComum cc = new ContaCorrenteComum(nome, numeroConta, saldo);
                
                contaCC.add(cc);
                break;
            }

            case 2:{
                for(ContaCorrenteComum cc: contaCC){
                    cc.print();
                    System.out.println();
                }

            }


        }
        

    }

    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        while (true) {
            int opcao = 0;
            System.out.println("\n1. Criar Contas");
            System.out.println("2. Dépositar");
            System.out.println("3. Saque");
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
                    crirConta();
                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:
                    break;
                case 5:
                    System.out.println("Saindo do programa");
                    System.exit(0);
                    break;

            }

        }
    }
}
