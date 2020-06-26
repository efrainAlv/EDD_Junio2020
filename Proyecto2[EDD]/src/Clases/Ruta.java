/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Clases;

/**
 *
 * @author efrai
 */
public class Ruta {
    
    private String origen;
    private String destion;
    private int tiempo;
    
    
    public Ruta(String origen, String destino, int tiempo){
    
        this.origen=origen;
        this.destion=destino;
        this.tiempo= tiempo;
    }

    public String getOrigen() {
        return origen;
    }

    public void setOrigen(String origen) {
        this.origen = origen;
    }

    public String getDestion() {
        return destion;
    }

    public void setDestion(String destion) {
        this.destion = destion;
    }

    public int getTiempo() {
        return tiempo;
    }

    public void setTiempo(int tiempo) {
        this.tiempo = tiempo;
    }
    
    
}
