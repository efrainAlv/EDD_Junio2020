
package Estructuras;

/**
 *
 * @author efrai
 */
public class ListaHash {
    
    NodoHash cabeza;
    String nombreLista;
    
    public ListaHash(String nombreLista){
    
        this.nombreLista = nombreLista;
        this.cabeza = null;
    }
    
    public boolean estaVacia(){
        return cabeza==null;
    }
    
    public void insertar(NodoHash nodo){
    
        NodoHash aux = cabeza;
    
        if(estaVacia()){
            cabeza = nodo;
        }
        else{
            
         while(aux.siguiente != null){
             aux = aux.siguiente;
         }   
            aux.siguiente = nodo;
        }
        
    }
   
    
    
    
}
