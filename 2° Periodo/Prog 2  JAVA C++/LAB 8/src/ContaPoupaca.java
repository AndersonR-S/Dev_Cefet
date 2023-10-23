public class ContaPoupaca extends Conta{
    private int diaDaConta;

    public ContaPoupaca() {
    }

    public ContaPoupaca(String nome, int numeroConta, float saldo, int diaDaConta) {
        super(nome, numeroConta, saldo);
        this.diaDaConta = diaDaConta;
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
        System.out.println("Dia do Aniversario da Conta: "+ diaDaConta+"\n\n");
    }

    public int getDiaDaConta() {
        return diaDaConta;
    }
    public void setDiaDaConta(int diaDaConta) {
        this.diaDaConta = diaDaConta;
    }
    
}
