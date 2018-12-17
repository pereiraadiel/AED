/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Dados;

import Negocio.Aluno;
import Dados.Generico.RepositorioGenerico;
import Dados.Generico.CadastroGenerico;
import Dados.Generico.Elemento;

/**
 *
 * @author Bacalá
 */
public class AlunoDAO extends CadastroGenerico<Aluno> {
    
    public AlunoDAO( RepositorioGenerico<Aluno> r ){
        super( r );
        this.ler();
    }
    
    public void listaAlunos() {
        System.out.println("\nLista alunos (" + this.nroElementos() + ")\n");
        for (Elemento a : super.buscaTodos()) {
            System.out.println(((Aluno) a).lista());
        }
    }

    @Override
    public Aluno getNewElemento() {
        Aluno a = new Aluno(super.nroElementos()+1);
        this.inclui(a);   // reserva a vaga do elemento na lista
        return a;
    }
    
    
}
