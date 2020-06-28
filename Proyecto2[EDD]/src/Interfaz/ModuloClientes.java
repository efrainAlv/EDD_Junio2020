/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Interfaz;

import Clases.*;
import static java.awt.Image.SCALE_DEFAULT;
import java.io.*;
import java.util.Scanner;
import javax.swing.ImageIcon;
import javax.swing.JFileChooser;
import proyecto2.edd.Proyecto2EDD;
import java.math.BigInteger;
import javax.swing.JOptionPane;

/**
 *
 * @author efrai
 */
public class ModuloClientes extends javax.swing.JFrame {

    /**
     * Creates new form ModuloClientes
     */
    public ModuloClientes() {
        initComponents();
        this.establecerImagenes();
    }

    
    private void establecerImagenes(){
        ImageIcon icon = new ImageIcon(getClass().getResource("/IMAGENES/cargar.png"));
        ImageIcon icono = new ImageIcon(icon.getImage().getScaledInstance(jButton1.getWidth()-10, jButton1.getHeight()-10, SCALE_DEFAULT));
        jButton1.setIcon(icono);
        
        ImageIcon icon2 = new ImageIcon(getClass().getResource("/IMAGENES/agregar.png"));
        ImageIcon icono2 = new ImageIcon(icon2.getImage().getScaledInstance(jButton2.getWidth()-10, jButton2.getHeight()-10, SCALE_DEFAULT));
        jButton2.setIcon(icono2);
        
        ImageIcon icon3 = new ImageIcon(getClass().getResource("/IMAGENES/buscar.png"));
        ImageIcon icono3 = new ImageIcon(icon3.getImage().getScaledInstance(jButton3.getWidth()-10, jButton3.getHeight()-10, SCALE_DEFAULT));
        jButton3.setIcon(icono3);
        
        ImageIcon icon5 = new ImageIcon(getClass().getResource("/IMAGENES/mostrar.png"));
        ImageIcon icono5 = new ImageIcon(icon5.getImage().getScaledInstance(jButton5.getWidth()-10, jButton5.getHeight()-10, SCALE_DEFAULT));
        jButton5.setIcon(icono5);
        
    }
    
    
    private void cargaMasiva(){
    
        boolean paso= true;
        JFileChooser fc = new JFileChooser();
        fc.setCurrentDirectory(new File("C:\\Users\\efrai\\Desktop\\CARGAS"));
        fc.showDialog(this, "SELECCIONE EL ARCHIVO DE CARGA");
    
        File archivo = fc.getSelectedFile();
        FileReader fr = null;
        BufferedReader br = null;
        
        try {
         // Apertura del fichero y creacion de BufferedReader para poder
         // hacer una lectura comoda (disponer del metodo readLine()).
         fr = new FileReader (archivo);
         br = new BufferedReader(fr);

         // Lectura del fichero
         String linea;
         int n=0;
         while((linea=br.readLine())!=null){
         
         String[] cadenas = linea.split(";");

            for (int j = 0; j < cadenas.length; j++) {
                String[] datos = cadenas[j].split(",");

                try{
                    BigInteger DPI = new BigInteger(datos[0].trim());
                    String nombres = datos[1];
                    String apellidos = datos[2];
                    String genero = datos[3].trim();
                    String fechaNac = datos[4].trim();
                    String telefono = datos[5].trim();
                    String direccion = datos[6].trim();

                    Proyecto2EDD.tablaH.insertar(new Cliente(DPI, nombres, apellidos, genero, fechaNac, telefono, direccion));
                }
                catch(NumberFormatException e){
                    n++;
                }
            }
         }
        
         if(paso){
            Proyecto2EDD.tablaH.crearGrafica();
         }
        
        }
        catch(Exception e){
           e.printStackTrace();
        }
        finally{
           // En el finally cerramos el fichero, para asegurarnos
           // que se cierra tanto si todo va bien como si salta 
           // una excepcion.
           try{                    
              if( null != fr ){   
                 fr.close();     
              }                  
           }catch (Exception e2){ 
              e2.printStackTrace();
           }
        }
        
    
    }
    
    
    private void agregarCliente(){
    
    boolean paso =true; 
        
    BigInteger dpi = null;
    
    do{
        
        try{
            dpi = new BigInteger(JOptionPane.showInputDialog("INGRESE EL DPI DEL CLIENTE"));
        
            if(dpi.toString().length()!=13){
                paso=false;
                JOptionPane.showMessageDialog(this, "EL DPI INGRESADO NO ES VALIDO");
                dpi = null;
            }
            else{
                paso=true;
            }
        }
        catch(NullPointerException e){
            break;
        }
        
    }while(!paso);
    
    if(dpi!=null){
        System.out.println("SU DPI ES: "+dpi); 
        
        boolean paso1 = true;
        String nombre = null;
        String apellido = null;
        String genero = null;
        String telefono = null;
        String direccion = null;
        String fecha = null;
        
        try{
            
            nombre = JOptionPane.showInputDialog("INGRESE EL NOMBRE DEL CLIENTE");
            apellido = JOptionPane.showInputDialog("INGRESE EL APELLIDO DEL CLIENTE");
            genero = JOptionPane.showInputDialog("INGRESE EL GENERO DEL CLIENTE");
            telefono = JOptionPane.showInputDialog("INGRESE EL TELEFONO DEL CLIENTE");
            direccion = JOptionPane.showInputDialog("INGRESE EL DIRECCION DEL CLIENTE");
            fecha = JOptionPane.showInputDialog("INGRESE EL FECHA DE NACIMIENTO DEL CLIENTE");
            
        }
        catch(NullPointerException e){
            JOptionPane.showMessageDialog(this,"EL CLIENTE NO SE AGREGO");
            paso1=false;
        }
        
        if(paso1){
            Proyecto2EDD.tablaH.insertar(new Cliente(dpi,nombre,apellido,genero,fecha,telefono,direccion)); 
            JOptionPane.showMessageDialog(this,"CLIENTE AGREGADO CON EXITO");
        }
        
    }
    
    
    }
    
    
    private void buscarCliente(){
    
    boolean paso =true; 
        
    BigInteger dpi = null;
    
    do{
        
        try{
            dpi = new BigInteger(JOptionPane.showInputDialog("INGRESE EL DPI DEL CLIENTE A BUSCAR"));
        
            if(dpi.toString().length()<13){
                paso=false;
                JOptionPane.showMessageDialog(this, "EL DPI INGRESADO NO ES VALIDO");
                dpi = null;
            }
            else{
                paso=true;
            }
        }
        catch(NullPointerException e){
            break;
        }
        
    }while(!paso);
    
        if(dpi!=null){
            
            Cliente cl = Proyecto2EDD.tablaH.buscar(dpi);
            
            if(cl!=null){
                DatosCliente dc = new DatosCliente();
                dc.setVisible(true);
                dc.establecerCampos(cl);
            }
            else{
                JOptionPane.showMessageDialog(this, "CLIENTE NO ENCONTRADO");
            }
            
        }
    
    }
    
    
    
    
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jButton5 = new javax.swing.JButton();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jButton1.setBackground(new java.awt.Color(255, 255, 255));
        jButton1.setForeground(java.awt.Color.white);
        jButton1.setBorder(new javax.swing.border.LineBorder(new java.awt.Color(0, 0, 0), 2, true));
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setBackground(new java.awt.Color(255, 255, 255));
        jButton2.setForeground(java.awt.Color.white);
        jButton2.setBorder(new javax.swing.border.LineBorder(new java.awt.Color(0, 0, 0), 2, true));
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jButton3.setBackground(new java.awt.Color(255, 255, 255));
        jButton3.setForeground(java.awt.Color.white);
        jButton3.setBorder(new javax.swing.border.LineBorder(new java.awt.Color(0, 0, 0), 2, true));
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        jButton5.setBackground(new java.awt.Color(255, 255, 255));
        jButton5.setForeground(java.awt.Color.white);
        jButton5.setBorder(new javax.swing.border.LineBorder(new java.awt.Color(0, 0, 0), 2, true));
        jButton5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton5ActionPerformed(evt);
            }
        });

        jLabel3.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        jLabel3.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel3.setText("CARGAR");
        jLabel3.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);

        jLabel4.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        jLabel4.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel4.setText("AGREGAR");
        jLabel4.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);

        jLabel6.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        jLabel6.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel6.setText("MOSTRAR");
        jLabel6.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);

        jLabel7.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        jLabel7.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel7.setText("BUSCAR");
        jLabel7.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);

        jLabel1.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("CLIENTES");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(36, 36, 36)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 454, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, 101, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jButton2, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel7, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jButton3, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jButton5, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel6, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addContainerGap(34, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 52, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(28, 28, 28)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jButton5, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton3, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton2, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel3)
                        .addComponent(jLabel4))
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel6)
                        .addComponent(jLabel7)))
                .addContainerGap(153, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        this.cargaMasiva();
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        this.agregarCliente();
    }//GEN-LAST:event_jButton2ActionPerformed

    private void jButton5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton5ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jButton5ActionPerformed

    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
        this.buscarCliente();
    }//GEN-LAST:event_jButton3ActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(ModuloClientes.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(ModuloClientes.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(ModuloClientes.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(ModuloClientes.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ModuloClientes().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton5;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    // End of variables declaration//GEN-END:variables
}
