/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Estructuras.Lista;

/**
 *
 * @author efrai
 */
public class Lista {
    
    public Nodo cabeza;
    public String nombreLista;
    
    public Lista(String nombreLista){
    
        this.nombreLista = nombreLista;
        this.cabeza = null;
    }
    
    public boolean estaVacia(){
        return cabeza==null;
    }
    
    public void insertar(Nodo nodo){
    
        Nodo aux = cabeza;
    
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
    
    
    public String formatoDestinos(){
    
        Nodo aux = cabeza;
        String cadenaFormatos ="";
        String cadenaEnlaces ="";
        
        
        do{
            
            cadenaFormatos+='"'+aux.ruta.getOrigen()+aux.ruta.getDestion()+'"'+"[label="+'"'+"{|"+aux.ruta.getDestion()+"|}"+'"'+"]\n";
            if(aux.siguiente!=null){
                cadenaEnlaces+='"'+aux.ruta.getOrigen()+aux.ruta.getDestion()+'"'+"->"+'"'+aux.ruta.getOrigen()+aux.siguiente.ruta.getDestion()+'"'+"\n";
            }
            
            aux = aux.siguiente;
        }while(aux!=null);
    
        return cadenaFormatos+cadenaEnlaces;
        
    }
    
    
    public String formatoGrafo(String origen){
    
        Nodo aux = cabeza;
        String cadenaEnlaces ="";
        do{
            if(aux!=null){
                cadenaEnlaces+='"'+origen+'"'+"->"+'"'+aux.ruta.getDestion()+'"'+"[label="+'"'+aux.ruta.getTiempo()+'"'+"]\n";
                aux = aux.siguiente;
            }
            
        }while(aux!=null);
    
        return cadenaEnlaces;
    }
    
    
    
}
