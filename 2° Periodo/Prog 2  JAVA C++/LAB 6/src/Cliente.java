import java.util.ArrayList;
import java.util.List;

public class Cliente {
    private String nome, endereco, numeroTelefone;
    private List<Pedido> listaPedido = new ArrayList<Pedido>();

    public Cliente(String nome, String endereco, String numeroTelefone) {
        this.nome = nome;
        this.endereco = endereco;
        this.numeroTelefone = numeroTelefone;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getEndereco() {
        return endereco;
    }
    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }
    public String getNumeroTelefone() {
        return numeroTelefone;
    }
    public void setNumeroTelefone(String numeroTelefone) {
        this.numeroTelefone = numeroTelefone;
    }
    public List<Pedido> getListaPedido() {
        return listaPedido;
    }
    public void setListaPedido(Pedido listaPedido) {
            this.listaPedido.add(listaPedido);
    }

}
