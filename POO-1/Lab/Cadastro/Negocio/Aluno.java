/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Negocio;

import Dados.Generico.Elemento;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 *
 * @author Bacalá
 */
public class Aluno extends Elemento {
    
    private String nome, curso;
    private Date dtNasc;
    SimpleDateFormat formatData =
            new SimpleDateFormat("dd/MM/yyyy");

    public Aluno(int index) {
        super(index);
    }

    public String getDtnasc() {
        return formatData.format(dtNasc);
    }

    public void setDtnasc(String dtnasc)
            throws ParseException {
        this.dtNasc = formatData.parse(dtnasc);
    }

    public String getCurso() {
        return curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    public SimpleDateFormat getFormatData() {
        return formatData;
    }

    public void setFormatData(SimpleDateFormat formatData) {
        this.formatData = formatData;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String lista() {
        return "Id:" + this.getId() + "- Nome:" + this.nome;
    }

    
}
