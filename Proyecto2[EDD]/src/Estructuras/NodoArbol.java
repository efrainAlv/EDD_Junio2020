/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Estructuras;



public class NodoArbol {
    

public int numeroClaves;
public String[] claves;
public NodoArbol[] hijos;
public NodoArbol padre;

public boolean esPadre;

public NodoArbol(){
    
    this.numeroClaves=0;
    this.claves = new String[5];
    this.hijos = new NodoArbol[5];
    this.padre = null;
    
    this.esPadre = false;
}










    
}
