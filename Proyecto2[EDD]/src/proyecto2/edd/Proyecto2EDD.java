/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package proyecto2.edd;
import Estructuras.*;
import Clases.*;
import java.math.BigInteger;
import Estructuras.ListaAdyacencia.*;

/**
 *
 * @author efrai
 */
public class Proyecto2EDD {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        /*
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
        */
        
        
        TablaHash tabla = new TablaHash();
        
        tabla.insertar(new Cliente(new BigInteger("3004107780101"),"Helmut","Najarro","M","Direccion"));
        tabla.insertar(new Cliente(new BigInteger("4564876545644"),"Helmut","Najarro","M","Direccion"));
        tabla.insertar(new Cliente(new BigInteger("3613548456852"),"Helmut","Najarro","M","Direccion"));
        tabla.insertar(new Cliente(new BigInteger("1679845642354"),"Helmut","Najarro","M","Direccion"));
        tabla.insertar(new Cliente(new BigInteger("1136768546546"),"Helmut","Najarro","M","Direccion"));
        
        
        Ruta ruta0 = new Ruta("Origen1","Destino1",20);
        Ruta ruta1 = new Ruta("barca","guate",20);
        Ruta ruta2 = new Ruta("guate","usa",20);
        Ruta ruta3 = new Ruta("guate","mexico",20);
        Ruta ruta4 = new Ruta("mexico","usa",20);
        Ruta ruta5 = new Ruta("mexico","barca",20);
        Ruta ruta6 = new Ruta("barca","usa",20);
        Ruta ruta7 = new Ruta("usa","Destino8",20);
        Ruta ruta8 = new Ruta("Origen4","Destino9",20);
        Ruta ruta9 = new Ruta("Origen1","Destino9",20);
        Ruta ruta10 = new Ruta("Origen10","Destino9",20);
        
        ListaAdyacencia tablaA = new ListaAdyacencia("Lista");
        tablaA.insertar(ruta0);
        tablaA.insertar(ruta1);
        tablaA.insertar(ruta2);
        tablaA.insertar(ruta3);
        tablaA.insertar(ruta4);
        tablaA.insertar(ruta5);
        tablaA.insertar(ruta6);
        tablaA.insertar(ruta7);
        tablaA.insertar(ruta8);
        tablaA.insertar(ruta9);
        tablaA.insertar(ruta10);
        
        tablaA.crearGrafica();
        tablaA.crearGrafo();
        
    }
    
}
