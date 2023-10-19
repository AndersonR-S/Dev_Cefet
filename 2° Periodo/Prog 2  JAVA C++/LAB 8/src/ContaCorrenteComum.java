public class ContaCorrenteComum extends Conta{

    public ContaCorrenteComum() {
    }

    public ContaCorrenteComum(String nome, int numeroConta, float saldo) {
        super(nome, numeroConta, saldo);
    }

    public void saqueComum(float saldo) {
        float saldoNovo = super.getSaldo() - saldo;
        if (saldoNovo >= 0) {
             super.setSaldo(saldoNovo);
            System.out.println("Saque Efetuada\n");
        } else {
            System.out.println("O valor do saque é maior que o saldo da conta\n");
        }
    }

    public void extrato(){
        super.extrato();
    }


    
    
}
