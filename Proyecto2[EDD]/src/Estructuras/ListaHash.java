
package Estructuras;
import Clases.*;
import java.math.BigInteger;

/**
 *
 * @author efrai
 */
public class ListaHash {
    
    public NodoHash cabeza;
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
    
    
    public String formatoContenidoablaHash(){
    
        NodoHash aux = cabeza;
        String cadenaFormatos ="";
        String cadenaEnlaces ="";
        
        do{
            
            cadenaFormatos+='"'+aux.cliente.getDPI().toString()+'"'+"[label="+'"'+"{|"+aux.cliente.getDPI().toString()+"|"+aux.cliente.getNombres()+"|}"+'"'+"]\n";
            if(aux.siguiente!=null){
                cadenaEnlaces+='"'+aux.cliente.getDPI().toString()+'"'+"->"+'"'+aux.siguiente.cliente.getDPI().toString()+'"'+"\n";
            }
            
            aux = aux.siguiente;
        }while(aux!=null);
    
        return cadenaFormatos+cadenaEnlaces;
    }
    
    
    public Cliente buscarUsuario(BigInteger dpi){
    
        NodoHash aux = cabeza;
        
        do{
            if(aux.cliente.getDPI().equals(dpi)){
                return aux.cliente;
            } 
            aux = aux.siguiente;
        }while(aux!=null);
        
        return null;
    }
    
    
    public Cliente editarCliente(BigInteger DPI, String nombres, String apellidos, String genero, String fecha, String telefono, String direccion){
    
        NodoHash aux = cabeza;
        
        do{
            if(aux.cliente.getDPI().equals(DPI)){
                
                aux.cliente.setNombres(nombres);
                aux.cliente.setAppelidos(apellidos);
                aux.cliente.setGenero(genero);
                aux.cliente.setFechaNac(fecha);
                aux.cliente.setTelefono(telefono);
                aux.cliente.setDireccion(direccion);
                break;
            } 
            aux = aux.siguiente;
        }while(aux!=null);
        
        return aux.cliente;
    }
   
    
    public void eliminarCliente(BigInteger dpi){
    
        if(cabeza.cliente.getDPI().equals(dpi)){
            cabeza = cabeza.siguiente;
        }
        else{   
            NodoHash aux = cabeza;
        
            do{
                
                if(aux.siguiente==null){
                    if(aux.cliente.getDPI().equals(dpi)){ 
                    
                    }
                }
                
                aux = aux.siguiente;
            }while(aux!=null);
        }
        
        
    }
    
    
    
}
