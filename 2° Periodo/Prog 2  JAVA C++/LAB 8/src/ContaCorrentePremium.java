
public class ContaCorrentePremium extends Conta{
    private float limiteDeCredito;

    public ContaCorrentePremium() {
    }

    public ContaCorrentePremium(String nome, int numeroConta, float saldo, float limiteDeCredito) {
        super(nome, numeroConta, saldo);
        this.limiteDeCredito = limiteDeCredito;
    }
    public void saqueEspecial(float saldo) {
        float saldoNovo = super.getSaldo() - saldo;
        if(saldoNovo >= this.limiteDeCredito *(-1)){
            super.setSaldo(saldoNovo);
            Transacao trans = new Transacao(super.getDateTime(), "Saque", saldo);
            super.setTrancacoes(trans);
            System.out.println("Saque Efetuada\n");
        }
        else{
            System.out.println("Limite de Crédito Ultrapassado\n");
        }

    }

    public void extrato(){
        super.extrato();
        System.out.println("Limite de Credito: "+ limiteDeCredito+"\n\n");

    }

    public float getLimiteDeCredito() {
        return limiteDeCredito;
    }

    public void setLimiteDeCredito(float limiteDeCredito) {
        this.limiteDeCredito = limiteDeCredito;
    }

    
}
