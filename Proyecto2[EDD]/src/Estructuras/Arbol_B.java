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
        raiz.claves[0] = placa;
    }
    else{
        
        for (int i = 0; i<nodo.numeroClaves; i++) {
            
            if(!nodo.esPadre){
                nodo.claves[raiz.numeroClaves] = placa;
                nodo.numeroClaves++;
                nodo.claves  = this.ordenar(nodo.claves, nodo.numeroClaves);
                
                if(nodo.numeroClaves==5){
                    this.dividir(nodo);
                }
                
                break;
            }
            else{
             
                
                
            }
        }
        
    }
    
}


public String[] ordenar(String[] claves, int cantidadC){
    
    String aux;
    
    for (int i = 0; i<cantidadC-1; i++) {
        
        for (int j = 0; j < cantidadC-1; j++) {
            
            if(claves[j].compareTo(claves[j+1])> 0){
                
                aux = claves[j];
                claves[j] = claves[j+1];
                claves[j+1] = aux;
                
            }
            
        }
    }
    
    return claves;
}



public void imprimirClavesRaiz(){
    
    for (int i = 0; i < raiz.claves.length; i++) {
        
        System.out.println(raiz.claves[i]);
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
        
        nodo.hijos[0] = izquierdo;
        nodo.hijos[1]=derecho;
        
        izquierdo.padre = nodo;
        derecho.padre = nodo;
        
        nodo.esPadre = true;
        
    }
    else{
    
        int medio = nodo.claves.length/2;
        
        nodo.padre.claves[nodo.padre.numeroClaves] = nodo.claves[medio];
        
        nodo.claves[medio] = nodo.claves[medio+1];
        nodo.claves[medio+1] = nodo.claves[medio+2];
        nodo.claves[nodo.claves.length] = null;
        
        this.ordenar(nodo.padre.claves, nodo.padre.numeroClaves);
        
        
    
    }
    
    return nodo;
    
}


    
}
