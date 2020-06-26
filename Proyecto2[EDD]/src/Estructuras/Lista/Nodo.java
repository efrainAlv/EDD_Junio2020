/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Estructuras.Lista;
import Clases.Ruta;


/**
 *
 * @author efrai
 */
public class Nodo {
 
    Nodo siguiente;
    public Ruta ruta;
    
    
    public Nodo(Ruta ruta){
        this.siguiente = null;
        this.ruta = ruta;
    }
    
    
}
