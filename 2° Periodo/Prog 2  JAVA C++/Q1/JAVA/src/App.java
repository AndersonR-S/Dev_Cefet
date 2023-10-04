
import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String texto;
        String TextoTrocado = "";
        int aux, aux1;
        aux = aux1 = 0;

        texto = scan.nextLine();
        while (!(texto.equals("EOF"))) {

            for (int i = 0; i < texto.length(); i++) {
                texto.charAt(i);
                if (texto.charAt(i) == '*') {
                    if (aux1 == 0) {
                        aux1++;
                        TextoTrocado += "<b>";
                    } else {
                        aux1--;
                        texto += "</b>";
                    }

                } else if (texto.charAt(i) == '_') {
                    if (aux == 0) {
                        aux++;
                        TextoTrocado += "<i>";
                    } else {
                        aux--;
                        TextoTrocado += "</i>";
                    }

                } else if (Character.isWhitespace(texto.charAt(i)) || Character.isLetter(texto.charAt(i))
                        || Character.getType(texto.charAt(i)) == Character.OTHER_PUNCTUATION) {
                    TextoTrocado += texto.charAt(i);
                }

            }
            TextoTrocado += "\n";
            texto = scan.nextLine();
        }
        scan.close();
        System.out.println(TextoTrocado);

    }
}