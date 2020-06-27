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
    int clavesEnUso;
    int factorDeCarga;

    public TablaHash(){
        claves = new ListaHash[37];
        this.tamanyo = new BigInteger("37");
        this.clavesEnUso=0;
        this.factorDeCarga=0;
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
                if(claves[i]!=null){
                    claves[i].insertar(new NodoHash(cliente));
                    break;
                }
                else{
                    claves[i] = new ListaHash("Lista"+i);
                    claves[i].insertar(new NodoHash(cliente));
                    clavesEnUso++;
                    break;
                }
            }
        }
        
        Double n1 = Double.parseDouble(clavesEnUso+"");
        Double n2 = Double.parseDouble(tamanyo+"");
        
        if((n1/n2)>=0.75){
            rehash();
        }
        
    }
    
    
    public void rehash(){
        
        int tamanyoAnterior = tamanyo.intValue();
        tamanyo = tamanyo.multiply(new BigInteger("2"));
        ListaHash nuevasClaves[] = new ListaHash[tamanyo.intValue()];
    
        for (int i = 0; i < tamanyoAnterior; i++) {
            nuevasClaves[i] = claves[i];
        }
        
        this.claves = nuevasClaves;
        
    }
    
    
    
    
}
