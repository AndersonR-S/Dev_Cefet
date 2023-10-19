import java.util.ArrayList;

public class Conta {
    private String nome;
    private int numeroConta;
    private float saldo;
    private ArrayList<Transacao> trancacoes;

    public Conta() {
    }
    
    public Conta(String nome, int numeroConta, float saldo) {
        this.nome = nome;
        this.numeroConta = numeroConta;
        this.saldo = saldo;
        Transacao trans = new Transacao("", "Saldo ao Abrir a conta", saldo);
        this.trancacoes.add(trans);
    }

    public void print() {
        System.out.println("Nome: " + nome);
        System.out.println("Numero da Conta: " + numeroConta);
        System.out.println("Saldo: " + saldo);
    }

    public void deposito(int saldo) {
        this.saldo += saldo;
        System.out.println("Depósito Efetuada");

    }

    public void saqueComum(float saldo) {
        float saldoNovo = this.saldo - saldo;
        if (saldoNovo >= 0) {
            this.saldo = saldoNovo;
            System.out.println("Saque Efetuada");
        } else {
            System.out.println("O valor do saque é maior que o saldo da conta");
        }
    }

    public void extrato(){
        print();
        System.out.println("Transações");
        System.out.println("---------------------");

        for(Transacao i: this.trancacoes)
            System.out.println(i+"\n");
 
        System.out.println("---------------------");
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getNumeroConta() {
        return numeroConta;
    }

    public void setNumeroConta(int numeroConta) {
        this.numeroConta = numeroConta;
    }

    public float getSaldo() {
        return saldo;
    }

    public void setSaldo(float saldo) {
        this.saldo = saldo;
    }

    public ArrayList<Transacao> getTrancacoes() {
        return trancacoes;
    }

    public void setTrancacoes(Transacao trancacoes) {
        this.trancacoes.add(trancacoes);
    }

}
