/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Estructuras.ListaAdyacencia;

import Estructuras.Lista.Lista;

/**
 *
 * @author efrai
 */
public class NodoInicio {

public NodoInicio abajo;
public int posicion;
public Lista lista;
public String origen;


public NodoInicio(String origen){
    this.abajo = null;
    this.posicion=0;
    this.lista = new Lista("Lista de "+origen);
    this.origen = origen;
}


}
