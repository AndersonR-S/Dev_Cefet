import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        float a,b,c;

        System.out.print("Digite o lado A: ");
        a = scan.nextFloat();
        System.out.print("Digite o lado B: ");
        b = scan.nextFloat();
        System.out.print("Digite o lado C: ");
        c = scan.nextFloat();

        Triangulo triangulo = new Triangulo(a,b,c);
        
        if(triangulo.verificar())
            System.out.println("\nO triângulo de lados "+triangulo.getA()+", "+triangulo.getB()+", "+triangulo.getC()+" é um "+triangulo.getTipoTriangulo());
        else
            System.out.println("\nLados informados não forma um trangulo"); 

        System.out.println("\nInicialização: "+triangulo.getCont()); 

    }
}
