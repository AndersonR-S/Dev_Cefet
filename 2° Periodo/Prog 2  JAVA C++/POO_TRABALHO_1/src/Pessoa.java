public class Pessoa {
    private String nome, endereco, cpf;
    private char sexo;
    private int telefone, identidade;

    public Pessoa() {
    }

    public Pessoa(String nome, String endereco, String cpf, char sexo, int telefone, int identidade) {
        this.nome = nome;
        this.endereco = endereco;
        this.cpf = cpf;
        this.sexo = sexo;
        this.telefone = telefone;
        this.identidade = identidade;
    }

    public void imprimir() {
        System.out.println("Nome: " + nome);
        System.out.println("Sexo: " + sexo);
        System.out.println("CPF: " + cpf);
        System.out.println("Endereco: " + endereco);
        System.out.println("Telefone: " + telefone);
        System.out.println("Identidade" + identidade);
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

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public char getSexo() {
        return sexo;
    }

    public void setSexo(char sexo) {
        this.sexo = sexo;
    }

    public int getTelefone() {
        return telefone;
    }

    public void setTelefone(int telefone) {
        this.telefone = telefone;
    }

    public int getIdentidade() {
        return identidade;
    }

    public void setIdentidade(int identidade) {
        this.identidade = identidade;
    }

}
