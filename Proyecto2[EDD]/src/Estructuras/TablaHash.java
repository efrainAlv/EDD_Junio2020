/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Estructuras;

import java.math.BigInteger;
import Clases.Cliente;
/**
 *
 * @author efrai
 */
public class TablaHash {

    ListaHash[] claves;
    BigInteger tamanyo;
    int densidad;
    int clavesEnUso;
    int densidadDeCarga;
    int numeroRegistros;

    public TablaHash(){
        claves = new ListaHash[37];
        this.tamanyo = new BigInteger("36");
    }
    
    public Integer dividir(BigInteger DPI){
        return DPI.remainder(this.tamanyo).intValue();
    }
    
    
    public void insertar(Cliente cliente){
    
    Integer posicion = this.dividir(cliente.getDPI());
        
    if(posicion>tamanyo.intValue()){
        posicion = posicion - tamanyo.intValue();
    }
    
        for (int i = 0; i < tamanyo.intValue(); i++) {
            if(i == posicion){
                claves[i] = new ListaHash("Lista"+i);
                claves[i].insertar(new NodoHash(cliente));
            }
        }
    
    }
    
    
    
}
