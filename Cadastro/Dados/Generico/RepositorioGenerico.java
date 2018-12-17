/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Dados.Generico;

import java.io.*;
import java.util.ArrayList;

/**
 *
 * @author 100003377
 */
public abstract class RepositorioGenerico<T extends Elemento> {
    final protected String SEPARATOR = ";";
    private String filename;

    /*
     * O construtor deve receber o nome do arquivo que sera
     * utilizado para armazenar os objetos em forma textual
     * 
     */
    public RepositorioGenerico(String file) {
        this.filename = file;
    }
    
    /*
     * Grava um arquivo texto com uma instancia representada
     * em cada linha
     * 
     */

    public void salvar(ArrayList<T> elementos) {
        FileWriter fw = null;
        PrintWriter pw = null;
        try {

            fw = new FileWriter(filename);
            pw = new PrintWriter(fw);
            for (int i = 0; i < elementos.size(); i++) {
                // Monta uma linha com a instancia da lista
                String linha = getRegistro(elementos.get(i));
                pw.println(linha);
            }
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
        } finally {
            try {
                pw.close();
                fw.close();
            } catch (IOException ex) {
                System.out.println(ex.getMessage());
            }
        }
    }

    /*
     * Restaura os objetos a partir do arquivo texto grabado
     * 
     */
    public ArrayList<T> restaurar() {

        try {
            File arq = new File(filename);
            if (!arq.exists()) {
                arq.createNewFile();
            }
           
            FileReader file = new FileReader(arq);
            ArrayList<T> elementos = new ArrayList<T>();
            BufferedReader in = new BufferedReader(file);
            String str;
            while ((str = in.readLine()) != null && str.length() > 0) {
                // monta uma instancia com o conteúdo lido
                T e = getInstance(str);
                elementos.add(e);
            }
            in.close();
            return elementos;
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
        return null;
    }

    /* 
     * Deve retornar uma instancia preenchida com os 
     * tokens obtidos da string
     * 
     */
    abstract protected T getInstance(String st);
    
    /*
     * Deve retornar uma string produzida pela concatenação
     * dos campos da instancia informada
     * 
     */
    abstract protected String getRegistro(T e);
}