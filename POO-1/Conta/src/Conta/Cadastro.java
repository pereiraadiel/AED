package Conta;

public class Cadastro {
	private final int MAX = 25;
	private String nomes[] = new String[MAX];
	private int cont;
	
	
	public Cadastro(String nome[]){
		if(nome.length < this.MAX)this.nomes = nome;
		else System.out.println("ERRO - Tamanho de vetor excedido.");
	}
	
	public void inicializaCont(){
		this.cont = 0;
	}
	public void atualizaCont(boolean tipo){
		if(tipo){//incrementa
			if(this.cont < this.MAX) this.cont++;
		}
		else if(this.cont < this.MAX) this.cont--;
	}
	
	public void inserirNome(String nome){
		this.nomes[cont] = nome;
		atualizaCont(true);
	}
	public String buscarNome(int posicao){
		if(posicao <= this.cont){
			return this.nomes[posicao];
		}
		else return "";
	}
	public boolean existeNome(String nome){
		int num = 0;
		while(num <= this.cont){
			if(this.nomes[num++].equals(nome)) return true;
		}
		return false;
	}
	public int posicaoNome(String nome){
		int pos = 0;
		while(pos <= this.cont){
			if(this.nomes[pos].equals(nome)) return pos;
			pos++;
		}
		return -1;
	}
	public void excluirNome(String nome){
		int pos = this.posicaoNome(nome);
		//System.out.println("posicao = "+pos);
		if(pos>=0)this.excluirNome(pos);
	}
	public void excluirNome(int posicao){
		int num = posicao;
		//System.out.println("posicao = "+posicao);
		if(posicao<this.cont){
			while(num<=cont-1){
				if(num != cont-1)this.nomes[num++]=this.nomes[num];
				else this.nomes[num++] = "";
			}
		}
		if(posicao>=0) atualizaCont(false);
		else System.out.println("ERRO - posicao invalida");
	}
	public void printf(String arg){
		System.out.print(arg);
	}
	public static void main(String[] args) {
		String str[] = new String[5];
		Cadastro c = new Cadastro(str);
		c.inicializaCont();
		System.out.println("==============================");
		for(int i=0;i<5;i++) System.out.println("Posicao ["+i+"]: "+c.buscarNome(i));
		System.out.println("==============================");
		c.inserirNome("-A-");
		c.inserirNome("-P-");
		c.inserirNome("-6-");
		c.inserirNome("-9-");
		c.inserirNome("---");
		for(int i=0;i<5;i++) System.out.println("Posicao ["+i+"]: "+c.buscarNome(i));
		c.excluirNome(2);
		c.excluirNome("-A-");
		System.out.println("==============================");
		for(int i=0;i<5;i++) System.out.println("Posicao ["+i+"]: "+c.buscarNome(i));
		System.out.println("==============================");
		int num= 0;
		c.printf("teste = "+num+"\n");

	}

}
