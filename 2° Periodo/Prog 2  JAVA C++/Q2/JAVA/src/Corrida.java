public class Corrida {
    private String Modelo;
    private String motor;
    private String fabricante;
    private String nome;
    private float inicioKm, finalKm;

    public void setModelo(String modelo){
        this.Modelo = modelo;
    }
    public String getModelo(){
        return this.Modelo;
    }

    public void setMotor(String motor){
        this.motor = motor;
    }
    public String getMotor(){
        return this.motor;
    }

    public void setFabricante (String fabricante){
        this.fabricante = fabricante;
    }
    public String getFabricante(){
        return this.fabricante;
    }

    public void setNome(String nome){
        this.nome = nome;
    }
    public String getNome (){
        return this.nome;
    }
   
    public void setInicioKm(float iniciokm){
        this.inicioKm = iniciokm;
    }
    public float getInicioKm(){
        return this.inicioKm;
    }

    public void setFinalKm(float finalKm){
        this.finalKm = finalKm;
    }
    public float getFinalKM(){
        return this.finalKm;
    }


    public float calcularQuilometragemPercorrida(){
        return this.finalKm - this.inicioKm;
    }

    public double valorFinal(){
        return calcularQuilometragemPercorrida() * 3.75;
    }


    public void imprimir(){
        System.out.println("------------------------------------------");
        System.out.println("\tMODELO: "+ this.Modelo);
        System.out.println("\tMOTOR: "+ this.motor);
        System.out.println("\tFABRICANTE: "+ this.fabricante);
        System.out.println("\tNOME: "+ this.nome);
        System.out.println("\tKM INICIAL: "+ this.inicioKm);
        System.out.println("\tKM FINAL: "+ this.finalKm);
        System.out.println("------------------------------------------");
        System.out.println("\tKM PERCURSO: " + calcularQuilometragemPercorrida());
        System.out.println("\tVALOR FINAL: " + valorFinal());
        System.out.println("------------------------------------------");

    }

}
