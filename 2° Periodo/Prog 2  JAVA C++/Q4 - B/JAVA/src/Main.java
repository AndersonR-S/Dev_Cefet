import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        
        String modelo;
        double tensao;

        System.out.print("Informe o modelo da lâmpada: ");
        modelo = scan.nextLine();

        System.out.print("Informe a tensão da lâmpada: ");
        tensao = scan.nextDouble();

        Lampada luz = new Lampada(modelo,tensao);

        int opcao;
        
        while (true) {
            System.out.println("\n\n1 - Acender\n2 - Apagar\n3 - Mostrar estado da lâmpda\n4 - Sair");
            do {
                System.out.print("Escolhe uma opção: ");
                opcao = scan.nextInt();

            } while (opcao < 1 && opcao > 4);

            switch (opcao) {
                case 1:
                    luz.acender();
                    break;

                case 2:
                    luz.apagar();
                    break;

                case 3:
                    luz.mostrarEstadoLampada();
                    break;

                case 4:
                    System.exit(0);
                    scan.close();
                    break;
            }
        }

    }
}
