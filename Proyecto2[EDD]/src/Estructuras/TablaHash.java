/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Estructuras;

import java.math.BigInteger;
import Clases.Cliente;
import java.util.Formatter;
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
    
    
    public String formatoIndicesTablaHash(){
    
        String cadenaFormatosIndices ="subgraph cluster_R{ \n";
        String cadenaEnlaces ="";
        String cadenaFormatosContenido="";
        
        for (int i = 0; i < claves.length; i++) {
            if(claves[i]!=null){
                cadenaFormatosContenido+=claves[i].formatoContenidoablaHash();
                cadenaFormatosIndices+='"'+i+'"'+"[label="+'"'+"{"+i+"|}"+'"'+"]\n";
                cadenaEnlaces+='"'+i+'"'+"->"+'"'+claves[i].cabeza.cliente.getDPI()+'"'+"\n";
            }
        }
            
     
        cadenaFormatosIndices+="} \n";
        return cadenaFormatosContenido+cadenaFormatosIndices+cadenaEnlaces;
        
    }
    
    
    public void crearGrafica(){
    
        try {
            Formatter f = new Formatter("C:\\Users\\efrai\\Desktop\\GRAFICAS\\\\TablaHash\\tablaHash.txt");
            f.format("digraph G{ \n");
            
            f.format("rankdir=LR; \n");
            f.format("node [shape=record,height=.08,fontsize=11]; \n");
            
            f.format(this.formatoIndicesTablaHash());
            
            f.format("}");
            f.close();    
        }catch (Exception e) {
            System.out.println("Error");
        }
    
    }
    
    
    public Cliente buscar(BigInteger DPI){
    
        Integer posicion = dividir(DPI);
        
        for (int i = 0; i < claves.length; i++) {
            if(i==posicion){
                return claves[i].buscarUsuario(DPI);
            }
        }
        
        return null;
    }
    
    public Cliente editarCliente(BigInteger DPI, String nombres, String apellidos, String genero, String fecha, String telefono, String direccion){
    
        Integer posicion = dividir(DPI);
        Cliente cliente = null;
        
        for (int i = 0; i < claves.length; i++) {
            if(i==posicion){
                cliente = claves[i].editarCliente(DPI, nombres, apellidos, genero, fecha, telefono, direccion); 
            }
        }
        return cliente;
    }
    
    public void eliminarCliente(BigInteger DPI){
        
        Integer posicion = dividir(DPI);
        Cliente cliente = null;
        
        for (int i = 0; i < claves.length; i++) {
            if(i==posicion){
                
            }
        }
    }
    
    
    
}
