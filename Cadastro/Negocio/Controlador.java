/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Negocio;

import Dados.AlunoDAO;
import Dados.RepositorioAluno;

/**
 *
 * @author Bacalá
 */
public class Controlador {
    
    private AlunoDAO daoAluno;
    
    public Controlador (){
        daoAluno = new AlunoDAO(new RepositorioAluno("ALUNOS"));        
    }

    public Aluno getNovoAluno() {
        return daoAluno.getNewElemento();
    }

    public void incluiAluno(Aluno a) {
        daoAluno.inclui(a);
    }

    public void salvar() {
        daoAluno.salvar();
    }

    public void listaAlunos() {
        daoAluno.listaAlunos();
    }
    
    
    
}
