public class Transacao {
    private String dataTransacao, descricaoTrasacao;
    private float valorTransacao;

    public Transacao() {
    }
    public Transacao(String dataTransacao , String descricaoTrasacao, float valorTransacao) {
        this.dataTransacao = dataTransacao;
        this.descricaoTrasacao = descricaoTrasacao;
        this.valorTransacao = valorTransacao;
    }

    @Override
    public String toString() {
        return "data: " + dataTransacao + "\tValor:" + valorTransacao  + "\nDescrição: " + descricaoTrasacao;
    }
    public String getDataTransacao() {
        return dataTransacao;
    }
    public void setDataTransacao(String dataTransacao) {
        this.dataTransacao = dataTransacao;
    }
    public String getDescricaoTrasacao() {
        return descricaoTrasacao;
    }
    public void setDescricaoTrasacao(String descricaoTrasacao) {
        this.descricaoTrasacao = descricaoTrasacao;
    }
    public float getValorTransacao() {
        return valorTransacao;
    }
    public void setValorTransacao(float valorTransacao) {
        this.valorTransacao = valorTransacao;
    }
}
