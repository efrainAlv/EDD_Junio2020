/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Estructuras.ListaAdyacencia;
import Clases.Ruta;
import Estructuras.Lista.*;
import java.util.Formatter;

/**
 *
 * @author efrai
 */
public class ListaAdyacencia {
 
    NodoInicio inicio;
    String nombreLista; 
    int cantidadElementos;
    
    
    public ListaAdyacencia(String nombreLista){
    
        this.inicio = null;
        this.nombreLista = nombreLista;
        this.cantidadElementos =0;
    }
    
    
    public boolean estaVacia(){
        return inicio==null;
    }
    
    
    public void insertar(Ruta ruta){
    
        NodoInicio aux = inicio;
    
        if(estaVacia()){
            inicio = new NodoInicio(ruta.getOrigen());
            inicio.lista.insertar(new Nodo(ruta));
            inicio.posicion= this.cantidadElementos;
            this.cantidadElementos++;
        }
        else{
         
            boolean existe=false;
            
            while(aux.abajo!=null){

                if(aux.origen.equals(ruta.getOrigen())){
                    aux.lista.insertar(new Nodo(ruta));
                    existe = true;
                    break;
                }
                aux = aux.abajo;
            }

            if(aux.origen.equals(ruta.getOrigen()) && !existe){
                aux.lista.insertar(new Nodo(ruta));
            }
            else if(!aux.origen.equals(ruta.getOrigen()) && !existe){
                aux.abajo = new NodoInicio(ruta.getOrigen());
                aux.abajo.lista.insertar(new Nodo(ruta));
                aux.abajo.posicion = this.cantidadElementos;
                this.cantidadElementos++;
            }
            
        }
        
    }
    
    
    public void crearGrafica(){
    
        try {
            Formatter f = new Formatter("C:\\Users\\efrai\\Desktop\\GRAFICAS\\ListaAdyacencia\\lista.txt");
            f.format("digraph G{ \n");
            
            f.format("rankdir=LR; \n");
            f.format("node [shape=record,height=.08,fontsize=11]; \n");
            
            f.format(this.formatoOrigenes());
            
            f.format("}");
            f.close();    
        }catch (Exception e) {
            System.out.println("Error");
        }
    
    }
    
    public String formatoOrigenes(){
    
        NodoInicio aux = inicio;
        String cadenaFormatos ="subgraph cluster_R{ \n";
        String cadenaEnlaces ="";
        String cadenaFormatosDestinos="";
        
        do{
            cadenaFormatosDestinos+=aux.lista.formatoDestinos();
            cadenaFormatos+='"'+aux.origen+'"'+"[label="+'"'+"{"+aux.posicion+"|"+aux.origen+"|}"+'"'+"]\n";
            if(aux!=null){
                String nombre=aux.lista.cabeza.ruta.getOrigen()+aux.lista.cabeza.ruta.getDestion();
                cadenaEnlaces+='"'+aux.origen+'"'+"->"+'"'+nombre+'"'+"\n";
            }
            aux = aux.abajo;
        }while(aux!=null);
    
        cadenaFormatos+="} \n";
        return cadenaFormatosDestinos+cadenaFormatos+cadenaEnlaces;
        
    }
    
    
    public void crearGrafo(){
    
        try {
            Formatter f = new Formatter("C:\\Users\\efrai\\Desktop\\GRAFICAS\\Grafo\\grafo.txt");
            f.format("digraph G{ \n");
            
            f.format("node [shape=circle,height=.08,fontsize=11]; \n");
            
            f.format(this.formatoGrafo());
            
            f.format("}");
            f.close();    
        }catch (Exception e) {
            System.out.println("Error");
        }
    
    }
    
    
    public String formatoGrafo(){
    
        NodoInicio aux = inicio;
        String cadenaEnlaces ="";
        
        do{
            cadenaEnlaces+=aux.lista.formatoGrafo(aux.origen);
            aux = aux.abajo;
        }while(aux!=null);
    
        return cadenaEnlaces;
        
    }
    
    
    
    
    
}
