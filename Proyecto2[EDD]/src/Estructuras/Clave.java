
package Estructuras;

/**
 *
 * @author efrai
 */
public class Clave {
    
    public String placa;
    public NodoArbol izquierdo;
    public NodoArbol derecho;
    
    
    public Clave(String placa){
        this.placa = placa;
        izquierdo = null;
        derecho = null;
    }
    
    
}
