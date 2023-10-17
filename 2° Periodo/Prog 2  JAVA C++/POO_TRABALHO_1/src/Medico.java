public class Medico extends Pessoa {
    private int crm;
    private String especialidade;
    

    @Override
    protected Object clone() throws CloneNotSupportedException {
        // TODO Auto-generated method stub
        return super.clone();
    }

    public Medico() {
    }

    public Medico(String nome, String endereco, String cpf, char sexo, int telefone, int identidade, int crm, String especialidade) {
        super(nome, endereco, cpf, sexo, telefone, identidade);
        this.crm = crm;
        this.especialidade = especialidade;
    }

    public void imprimir(){
        super.imprimir();
        System.out.println("CRM: "+crm+"\nEspecialidade: "+ especialidade);
    }

    public int getCrm() {
        return crm;
    }

    public void setCrm(int crm) {
        this.crm = crm;
    }

    public String getEspecialidade() {
        return especialidade;
    }

    public void setEspecialidade(String especialidade) {
        this.especialidade = especialidade;
    }

}
