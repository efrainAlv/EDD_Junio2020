/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package proyecto2.edd;
import Estructuras.Arbol_B;

/**
 *
 * @author efrai
 */
public class Proyecto2EDD {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Arbol_B arbol = new Arbol_B();
        arbol.insertar("dedo",null);
        arbol.insertar("arbol",null);
        arbol.insertar("gato",null);
        arbol.insertar("cabecera",null);
        arbol.insertar("elefante",null);
        arbol.insertar("helado",null);
        arbol.insertar("elegido",null);
        arbol.insertar("jarro",null);
        
        arbol.imprimirClavesRaiz();
        
    }
    
}
