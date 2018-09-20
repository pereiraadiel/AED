package Conta;
public class Conta {

	private String nome;
	private int senha;
	private double saldo;
	
	public Conta(String nome, int senha){
		this.setNome(nome);
		this.setSenha(senha);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	public void setSenha(int senha){
		this.senha = senha;
	}
	public void setNome(String nome){
		this.nome = nome;
	}
	public void iniciarSaldo(){
		this.saldo = 0.0;
	}
	public void modificaSaldo(double movimentacao, boolean acao){
		if(acao){//saque
			if(this.saldo >= movimentacao) this.saldo -= movimentacao;
		}
		else{//deposito
			this.saldo += movimentacao;
		}
	}

}
