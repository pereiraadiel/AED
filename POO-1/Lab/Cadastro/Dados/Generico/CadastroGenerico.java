/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Dados.Generico;

import java.util.ArrayList;

/**
 *
 * @author Bacalá
 */
public abstract class CadastroGenerico <T extends Elemento> {

    private ArrayList<T> lista;
    protected RepositorioGenerico<T> rep;

    /*
     * Deve recebero repositorio de objetos T
     * 
     */
    public CadastroGenerico(RepositorioGenerico<T> repo ) {
        lista = new ArrayList<T>();
        this.rep = repo;
    }
    
    /*
     * Devera retornar uma instancia do descendente de Elemento.
     * Esse elemento deve ocupar um lugar na lista em funcao de 
     * ter de possuir um id
     * 
     */
    abstract public T getNewElemento();
    
    /*
     * retorna o id do último elemento na lista
     */
    protected int getIdLast(){
        return lista.get(lista.size()).getId()+1;
    }

    /*
     * inclui um elemento no cadastro
     */
    public boolean inclui(T e) {
        if(lista.contains(e))
            return false;
        System.out.print("incluido "+e.getId());
        return lista.add(e);
        
    }

    /*
     * Exlcui i elemento que possui o id informado
     */
    public void exclui(int index) {
        T e = this.busca(index);
        if (e != null)
            lista.remove(e);
    }
    
    /*
     * recupera o elemento com o id informado
     */
    public T busca(int index) {
        for (T elemento : lista) {
            if (elemento.getId() == index)
                return elemento;
        }
        return null;
    }
    
    /*
     * recupera todos os elementos
     */
    public  ArrayList<T> buscaTodos() {
        return lista;
    }
    
    /*
     * retorna o numero de elementos da lista
     */   
    
    public int nroElementos() {
        return lista.size();
    }
    
    /*
     * gravar os elementos da lista no repositorio
     */
    public void salvar(){
        rep.salvar(lista);
    }
    
    /*
     * recupera a lista de elementos do mrepositorio
     */
    public void ler(){
        lista = rep.restaurar();
    }
}
