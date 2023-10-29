import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

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
        this.trancacoes = new ArrayList<Transacao>(); // Inicialize a lista de transações
        Transacao trans = new Transacao(getDateTime(), "Saldo ao Abrir a conta", saldo);
        this.trancacoes.add(trans);
    }

    public void print() {
        System.out.println("Nome: " + nome);
        System.out.println("Numero da Conta: " + numeroConta);
        System.out.println("Saldo: " + saldo);
    }

    public void deposito(float saldo) {
        this.saldo += saldo;
        Transacao trans = new Transacao(getDateTime(), "Déposito", saldo);
        setTrancacoes(trans);
        System.out.println("Depósito Efetuada");

    }


    public void extrato() {
        System.out.println();
        print();
        System.out.println("Transações");
        System.out.println("---------------------");

        for (Transacao i : this.trancacoes)
            System.out.println(i + "\n");

        System.out.println("---------------------");
    }

    public String getDateTime() {
        DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");
        Date date = new Date();
        return dateFormat.format(date);
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
