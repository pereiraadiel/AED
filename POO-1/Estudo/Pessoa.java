import java.util.Scanner;
import java.util.Date;

public class Pessoa{
	private static String nome;
	private static int dia,mes,ano;
	private static float altura;
		
	public static void main(String []args){
		String nome;
		int dia,mes,ano;
		float altura;
		System.out.println("Digite seu nome: ");
		Scanner in = new Scanner(System.in);
		nome = in.next();

		System.out.println("Digite seu aniversario (DD MM AAAA): ");
		dia = in.nextInt();
		mes = in.nextInt();
		ano = in.nextInt();
		
		System.out.println("Digite sua altura: ");
		altura = in.nextFloat();
		
		setNome(nome);
		setNasc(dia,mes,ano);
		setAltura(altura);
		imprimir_dados();
	}
	public static void setNome(String name){
		Pessoa.nome = name;
	}
	public static void setNasc(int dia,int mes,int ano){
		Pessoa.dia = dia;
		Pessoa.mes = mes;
		Pessoa.ano = ano;
	}
	public static void setAltura(float altura){
		Pessoa.altura = altura;
	}

	public static String getNome(){
		return Pessoa.nome;
	}
	public static int getNasc(){
		return Pessoa.ano;
	}
	public static float getAltura(){
		return Pessoa.altura;
	}
	
	public static void imprimir_dados(){
		int idade = calcular_idade();
		System.out.println("\n\n\n---------------------------\n");
		System.out.println("Nome: "+Pessoa.nome+"\n");
		System.out.println("Data Nasc: "+Pessoa.dia+"/"+Pessoa.mes+"/"+Pessoa.ano+"\n");
		System.out.println("Altura: "+Pessoa.altura+"\n");
		System.out.println("Idade:"+idade+" \n");
		System.out.println("---------------------------\n\n\n");
	}
	public static int calcular_idade(){
		Scanner in = new Scanner(System.in);
		int dia,mes,ano;
		System.out.println("Hoje é: DD MM AAAA");
		dia = in.nextInt();
		mes = in.nextInt();
		ano = in.nextInt();
		
		int ret=0;
		ret = (ano - Pessoa.ano);
		if(mes < Pessoa.mes) ret = ret -1;
		else if(dia < Pessoa.dia) ret = ret -1;
		return ret;
	}

}