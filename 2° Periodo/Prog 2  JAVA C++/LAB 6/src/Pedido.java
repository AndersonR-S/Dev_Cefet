public class Pedido {
  private String descricao;
  private int  numeroPedido;
  private float valor;

  
public Pedido(String descricao, int numeroPedido, float valor) {
    this.descricao = descricao;
    this.numeroPedido = numeroPedido;
    this.valor = valor;
}

public String getDescricao() {
    return descricao;
}
public void setDescricao(String descricao) {
    this.descricao = descricao;
}
public int getNumeroPedido() {
    return numeroPedido;
}
public void setNumeroPedido(int numeroPedido) {
    this.numeroPedido = numeroPedido;
}
public float getValor() {
    return valor;
}
public void setValor(float valor) {
    this.valor = valor;
}
 

}
