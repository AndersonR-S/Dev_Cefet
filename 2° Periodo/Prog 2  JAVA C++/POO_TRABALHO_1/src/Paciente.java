public class Paciente extends Pessoa{
    private String relato;
    private String medicacaoConsumidaRegulamente;
    
    public Paciente(){
    }

    public Paciente(String nome, String endereco, String cpf, char sexo, int telefone, int identidade, String relato,String medicacaoConsumidaRegulamente) {
        super(nome, endereco, cpf, sexo, telefone, identidade);
        this.relato = relato;
        this.medicacaoConsumidaRegulamente = medicacaoConsumidaRegulamente;
    }

    public void imprimir(){
        super.imprimir();
        System.out.println("Relato: "+relato+"\nMedicação Consumida Regulamente: "+medicacaoConsumidaRegulamente);
    }

    
}
