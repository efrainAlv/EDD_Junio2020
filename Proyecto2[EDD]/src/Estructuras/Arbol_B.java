/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Estructuras;

/**
 *
 * @author efrai
 */
public class Arbol_B {
    
    
public NodoArbol raiz;
public int altura;


public Arbol_B(){
    
    this.altura = 0;
    this.raiz = null;
    
}


public boolean estaVacio(){
    return raiz==null;
}


public void insertar(String placa, NodoArbol nodo){
    
    if(nodo==null){
        nodo = raiz;
    }
    if(estaVacio()){
        raiz = new NodoArbol();
        raiz.numeroClaves++;
        raiz.claves[0] = new Clave(placa);
    }
    else{
        
        if(!nodo.esPadre){
            nodo.claves[nodo.numeroClaves] = new Clave(placa);
            nodo.numeroClaves++;
            nodo.claves  = this.ordenar(nodo.claves, nodo.numeroClaves);

            if(nodo.numeroClaves==5){
                this.dividir(nodo);
            }

        }
        else{

            boolean esMayor=false;
            
            for (int i = 0; i<nodo.numeroClaves || nodo.claves[i]!=null; i++) {
                
                if(nodo.claves[i].placa.compareTo(placa)>0){   
                    this.insertar(placa, nodo.claves[i].izquierdo);
                    esMayor=true;
                    break;
                }
            }
            
            if(esMayor){
                this.insertar(placa, nodo.claves[nodo.numeroClaves-1].derecho);
            }
            
        }
    }
    
}



public void insertarAPadre(NodoArbol nodo){

    NodoArbol izquierdo = new NodoArbol();
    NodoArbol derecho = new NodoArbol();

    int medio = nodo.claves.length/2;

    for (int i = 0; i < nodo.claves.length; i++) {

        if(i<medio){
            izquierdo.claves[i] = nodo.claves[i];
            nodo.claves[i]=null;
        }
        else if(i>medio){
            derecho.claves[i-3] = nodo.claves[i];
            nodo.claves[i]=null;
        }
        
    }
    
    Clave nuevaClave = new Clave(nodo.claves[medio].placa);
    nuevaClave.izquierdo = izquierdo;
    nuevaClave.derecho = derecho;
    
    nodo.padre.claves[nodo.padre.numeroClaves] = nuevaClave;
    nodo.padre.numeroClaves++;
    
    this.ordenar(nodo.padre.claves, nodo.padre.numeroClaves);
    
    if(nodo.padre.numeroClaves==5){
        this.dividir(nodo.padre);
    }
    
    nodo = null;

}






public Clave[] ordenar(Clave[] claves, int cantidadC){
    
    String aux;
    
    for (int i = 0; i<cantidadC-1; i++) {
        
        for (int j = 0; j < cantidadC-1; j++) {
            
            if(claves[j].placa.compareTo(claves[j+1].placa)> 0){
                
                aux = claves[j].placa;
                claves[j].placa = claves[j+1].placa;
                claves[j+1].placa = aux;
                
                claves[j+1].derecho = claves[i].izquierdo;
                claves[j].izquierdo = claves[i].derecho;
                
            }
            
        }
    }
    
    return claves;
}



public void imprimirClavesRaiz(){
    
    for (Clave clave : raiz.claves) {
        if (clave != null) {
            System.out.println(clave.placa);
        }
    }
    
}









public NodoArbol dividir(NodoArbol nodo){

    if(nodo.padre==null){
    
        NodoArbol izquierdo = new NodoArbol();
        NodoArbol derecho = new NodoArbol();
        
        int medio = nodo.claves.length/2;
        
        for (int i = 0; i < nodo.claves.length; i++) {
            
            if(i<medio){
                izquierdo.claves[i] = nodo.claves[i];
                nodo.claves[i]=null;
            }
            else if(i>medio){
                derecho.claves[i-3] = nodo.claves[i];
                nodo.claves[i]=null;
            }
            else{
                nodo.claves[0]=nodo.claves[medio];
                nodo.claves[medio]=null;
            }
            
        }
        
        nodo.claves[0].izquierdo = izquierdo;
        nodo.claves[0].derecho = derecho;
        
        izquierdo.padre = nodo;
        derecho.padre = nodo;
        
        nodo.esPadre = true;
        
    }
    else{
    
        this.insertarAPadre(nodo);
    
    }
    
    return nodo;
    
}







    
}
