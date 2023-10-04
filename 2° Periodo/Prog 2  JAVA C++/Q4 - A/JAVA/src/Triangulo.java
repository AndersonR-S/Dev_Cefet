import java.lang.Math;

public class Triangulo {
    private float a, b, c;
    private String tipoTriangulo;
    private static int cont = 0;

    public Triangulo(float a, float b, float c) {
        this.a = a;
        this.b = b;
        this.c = c;
        triangulo();
        cont++;
    }

    public void triangulo() {
        if (this.a==this.b && this.b==this.c)
            this.tipoTriangulo = "Equilátero";
        else if(this.a == this.b || this.a == this.c || this.b ==this.c)
            this.tipoTriangulo = "Isóscele";
        else
            this.tipoTriangulo = "Escaleno";
    }

    public boolean verificar() {
        // • | 𝑏 − 𝑐 | < 𝑎 < 𝑏 + 𝑐
        // • | 𝑎 − 𝑐 | < 𝑏 < 𝑎 + 𝑐
        // • | 𝑎 − 𝑏 | < 𝑐 < 𝑎 + 𝑏
 
        if ((Math.sqrt(Math.pow(this.b - this.c, 2))) < this.a && this.a < (this.b + this.c)) 
            if ((Math.sqrt(Math.pow(this.a - this.c, 2))) < this.b && this.b < (this.a + this.c)) 
                if ((Math.sqrt(Math.pow(this.a - this.b, 2))) < this.c && this.c < (this.a + this.b)) 
                    return true;
        
        return false;
    }

    public float getA() {
        return a;
    }

    public void setA(float a) {
        this.a = a;
    }

    public float getB() {
        return b;
    }

    public void setB(float b) {
        this.b = b;
    }

    public float getC() {
        return c;
    }

    public void setC(float c) {
        this.c = c;
    }

    public String getTipoTriangulo() {
        return tipoTriangulo;
    }

    public void setTipoTriangulo(String tipoTriangulo) {
        this.tipoTriangulo = tipoTriangulo;
    }

    public static int getCont() {
        return cont;
    }

    public static void setCont(int cont) {
        Triangulo.cont = cont;
    }

    
    
}
