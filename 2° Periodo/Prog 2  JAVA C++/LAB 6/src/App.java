import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class App {
    static List<Cliente> listaCliente = new ArrayList<Cliente>();

    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);

        while (true) {
            int opcao = 0;
            System.out.println(
                    "\n1-CADASTRAR CLIENTE\n2-CADASTRAR PEDIDO\n3-LISTAR PEDIDO DE CLIENTE\n4-LISTAR CLIENTE\n5-LISTAR TODOS OS PEDIDOS\n6-CALCULAR GASTO\n7-SAIR");
            while (opcao < 1 || opcao > 7) {
                System.out.print("\nEscolhe uma opcao: ");
                opcao = scan.nextInt();
            }
            switch (opcao) {
                case 1: {
                    scan.nextLine();
                    String nome, endereco, telefone;
                    System.out.print("DIGITE O NOME: ");
                    nome = scan.nextLine();
                    System.out.print("DIGITE O ENDERECO: ");
                    endereco = scan.nextLine();
                    System.out.print("DIGITE O TELEFONE: ");
                    telefone = scan.nextLine();

                    Cliente cliente = new Cliente(nome, endereco, telefone);

                    boolean verificar = true;
                    for (Cliente i : listaCliente) {
                        if (i.getNome() == nome) {
                            verificar = false;
                            break;
                        }
                    }

                    if (verificar)
                        listaCliente.add(cliente);
                    else {
                        System.out.println("NOME JA UTILIZADO!\n");
                       

                    }

                    break;
                }
                case 2: {
                    scan.nextLine();
                    String nome;
                    System.out.print("DIGITE O NOME: ");
                    nome = scan.nextLine();

                    boolean verificar = true;
                    for (Cliente i : listaCliente) {
                        if(i.getNome().equalsIgnoreCase(nome)){
                            int numeroPedido;
                            float valor;
                            String descricao;

                            System.out.print("\nDIGITE O NUMERO DO PEDIDO: ");
                            numeroPedido = scan.nextInt();
                            scan.nextLine();
                            System.out.print("DIGITE A DESCRICAO: ");
                            descricao = scan.nextLine();
                            System.out.print("DIGITE O VALOR DO PEDIDO: ");
                            valor = scan.nextFloat();

                            Pedido pedido = new Pedido(descricao, numeroPedido, valor);

                            i.setListaPedido(pedido);
                            verificar = false;
                            
                            break;
                        }
                    }
                    if (verificar)
                        System.out.println("\nCLIENTE NÃO CADASTRDO!\n");

                    break;

                }
                case 3: {
                    scan.nextLine();
                    String nome;
                    System.out.print("DIGITE O NOME: ");
                    nome = scan.nextLine();

                    boolean verificar = true;
                    for (Cliente i : listaCliente)
                        if (i.getNome().equalsIgnoreCase(nome)) {
                            for(Pedido j: i.getListaPedido()){
                                System.out.println("\nNUMERO DE PEDIDO: "+j.getNumeroPedido());
                                System.out.println("DESCRICAO: "+j.getDescricao());
                                System.out.println("VALOR: "+j.getValor());
                            }
                                
                            verificar = false;
                            break;
                        }
                    if (verificar)
                        System.out.println("\nCLIENTE NÃO ESCONTARDO\n");

                    break;
                }
                case 4: {
                    scan.nextLine();
                    for (Cliente i : listaCliente)
                        System.out.println(i.getNome());
                    break;
                }
                case 5: {
                    for (Cliente i : listaCliente) {
                        System.out.println(i.getNome());
                        for (Pedido j : i.getListaPedido())                      {
                                System.out.println("\nNUMERO DE PEDIDO: "+j.getNumeroPedido());
                                System.out.println("DESCRICAO: "+j.getDescricao());
                                System.out.println("VALOR: "+j.getValor());
                            }
                        System.out.println("\n\n");
                    }
                    break;
                }
                case 6: {
                    scan.nextLine();
                    float valor = 0;
                    String nome;
                    System.out.print("\nDIGITE O NOME: ");
                    nome = scan.nextLine();

                    boolean verificar = true;
                    for (Cliente i : listaCliente)
                        if (i.getNome().equalsIgnoreCase(nome)) {
                            verificar = false;
                            for (Pedido j : i.getListaPedido())
                                valor += j.getValor();
                            break;
                        }
                    if (verificar)
                        System.out.println("\nCLIENTE NÃO ESCONTARDO\n");
                    else
                        System.out.println("\nVALOR A PAGAR: "+ valor);
                    break;
                }
                case 7: {
                    scan.close();
                    listaCliente.clear();
                    System.exit(0);
                    break;
                }
            }
        }
    }
}
