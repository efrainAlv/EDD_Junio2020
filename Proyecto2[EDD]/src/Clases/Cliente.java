/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Clases;

import java.math.BigInteger;


/**
 *
 * @author efrai
 */
public class Cliente {
    
    private BigInteger DPI;
    private String nombres;
    private String appelidos;
    private String genero;
    private String fechaNac;
    private String telefono;
    private String direccion;
    
    
    public Cliente(BigInteger DPI, String nombres, String apellidos, String genero, String fechaNac, String telefono, String direccion){
        this.DPI = DPI;
        this.nombres = nombres;
        this.appelidos = apellidos;
        this.genero = genero;
        this.direccion = direccion;
        this.fechaNac = fechaNac;
        this.telefono = telefono;
    }

    public BigInteger getDPI() {
        return DPI;
    }

    public String getNombres() {
        return nombres;
    }

    public String getAppelidos() {
        return appelidos;
    }

    public String getGenero() {
        return genero;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDPI(BigInteger DPI) {
        this.DPI = DPI;
    }

    public void setNombres(String nombres) {
        this.nombres = nombres;
    }

    public void setAppelidos(String appelidos) {
        this.appelidos = appelidos;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public String getFechaNac() {
        return fechaNac;
    }

    public void setFechaNac(String fechaNac) {
        this.fechaNac = fechaNac;
    }

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }
    
    
    
    
}
