
public class Lampada {
    private double tensao;
    private String modelo;
    private boolean estadoLampada;
    private static int cont = 0;


    public Lampada(String modelo, double tensao){
        this.modelo =modelo;
        this.tensao = tensao;
        cont ++;
        apagar();;
    }

    public double getTensao() {
        return tensao;
    }
    public void setTensao(double tensao) {
        this.tensao = tensao;
    }

    public String getModelo() {
        return modelo;
    }
    public void setModelo(String modelo) {
        this.modelo = modelo;
    }
    public boolean isEstadoLampada() {
        return estadoLampada;
    }
    public void setEstadoLampada(boolean estadoLampada) {
        this.estadoLampada = estadoLampada;
    }
    public void acender(){
        this.estadoLampada = true;
    }

    public void apagar(){
        this.estadoLampada = false;
    }

    public void mostrarEstadoLampada(){
        System.out.println("\nModelo: "+this.modelo+"\nTensão: "+this.tensao);
        if(this.estadoLampada)
            System.out.println("A lâmpada está ligada.\n");
        else
            System.out.println("A lâmpada está desligada.\n");

       System.out.println("Inicialização: "+cont);
    }
    
    
}
