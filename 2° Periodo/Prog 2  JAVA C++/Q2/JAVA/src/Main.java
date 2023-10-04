
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Corrida cor = new Corrida();

        System.out.print("DIGITE O MODELO DO CARRO: ");
        cor.setModelo(scan.nextLine());
        
        System.out.print("DIGITE O MOTORIZAÇÃO DO CARRO: ");
        cor.setMotor(scan.nextLine());

        System.out.print("DIGITE O FABRICANTE DO CARRO: ");
        cor.setFabricante(scan.nextLine());

        System.out.print("DIGITE O NOME DO CARRO: ");
        cor.setNome(scan.nextLine());

        System.out.print("\nDIGITE O KM INICIAL: ");
        cor.setInicioKm(scan.nextFloat());

        System.out.print("DIGITE O KM FINAL: ");
        cor.setFinalKm(scan.nextFloat());

        cor.imprimir();

    }
}