public class ContaInvestimento extends Conta{
    private float taxaAnual;

    public ContaInvestimento() {
    }

    public ContaInvestimento(String nome, int numeroConta, float saldo, float taxaAnual) {
        super(nome, numeroConta, saldo);
        this.taxaAnual = taxaAnual;
    }

    public void saqueComum(float saldo) {
        float saldoNovo = super.getSaldo() - saldo;
        if (saldoNovo >= 0) {
             super.setSaldo(saldoNovo);
             Transacao trans = new Transacao(getDateTime(), "Saque", saldo);
             super.setTrancacoes(trans);
            System.out.println("Saque Efetuada\n");
        } else {
            System.out.println("O valor do saque é maior que o saldo da conta\n");
        }
    }

    public void extrato(){
        super.extrato();
        System.out.println("Taxa de Retorno Anual: "+ taxaAnual+"\n\n");
    }

    public float getTaxaAnual() {
        return taxaAnual;
    }

    public void setTaxaAnual(float taxaAnual) {
        this.taxaAnual = taxaAnual;
    }
    
}
