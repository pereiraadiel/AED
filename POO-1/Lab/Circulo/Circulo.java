// package Circulo;
import java.text.DecimalFormat;   

public class Circulo{
	private Ponto centro;
	private Double raio;
	private String nome;
	private final double PI = 3.14159265359;

	public Circulo(Double raio,Ponto centro,String nome){
		this.nome = nome;
		this.raio = raio;
		this.centro = centro;
	}
	public double diametro(){
		return 2*this.raio;
	}
	public double area(){
		return PI*Math.pow(this.raio,2);
	}
	public double circunferencia(){//Calcular
		return 2*PI*this.raio;
	}
	public String getNome(){
		return this.nome;
	}
	public void setNome(String nome){
		if(!nome.equals("")) this.nome = nome;
		else System.out.printf("ERRO - O nome nao pode estar vazio\n");
	}
	public Ponto getCentro(){
		return this.centro;
	}
	public void setCentro(Ponto p){
		this.centro = p;
	}
	public Double getRaio(){
		return this.raio;
	}
	public void setRaio(Double raio){
		this.raio = raio;
	}
	public void exibirDados(){
		DecimalFormat df = new DecimalFormat("0.##");
		
		System.out.printf("=================================\n");
		String dx = df.format(this.raio);
		System.out.println(" Dados do circulo de raio "+dx);
		dx = df.format(this.diametro());
		System.out.println(" Diametro      : "+dx);
		dx = df.format(this.circunferencia());
		System.out.println(" Circunferencia: "+dx);
		dx = df.format(this.area());
		System.out.println(" Area          : "+dx);
	}
	public static void main(String[] args) {
		Ponto p = new Ponto();
		p.setPonto(3.5,4.2);
		Circulo circ = new Circulo(5.00,p,"Teste");
		circ.exibirDados();
	}
}