public class ContaInvestimento extends Conta{
    private int taxaAnual;

    public ContaInvestimento() {
    }

    public ContaInvestimento(String nome, int numeroConta, float saldo, int taxaAnual) {
        super(nome, numeroConta, saldo);
        this.taxaAnual = taxaAnual;
    }

    public void saqueComum(float saldo) {
        float saldoNovo = super.getSaldo() - saldo;
        if (saldoNovo >= 0) {
             super.setSaldo(saldoNovo);
            System.out.println("Saque Efetuada");
        } else {
            System.out.println("O valor do saque é maior que o saldo da conta");
        }
    }

    public void extrato(){
        super.extrato();
        System.out.println("Taxa de Retorno Anual: "+ taxaAnual+"\n\n");
    }

    public int getTaxaAnual() {
        return taxaAnual;
    }

    public void setTaxaAnual(int taxaAnual) {
        this.taxaAnual = taxaAnual;
    }
    
}
