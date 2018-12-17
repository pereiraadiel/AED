/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Dados.Generico;

/**
 *
 * @author Bacalá
 */
public abstract class Elemento {
    
    private int id;

    /*
     * Construtor acessivel para os descendentes.
     * Deve receber um id para ser isntanciado
     */
    protected Elemento(int id) {
        this.id = id;
    }
    
    /*
     * @return the id
     */
    public int getId() {
        return id;
    }

    /**
     * @param id the id to set
     */
    public void setId(int id) {
        this.id = id;
    }

    
    /*
     * Metodo usaod para listar o conteúdo do objeto 
     * descendente de Elemento
     * 
     */
    abstract public String lista();
    
}
