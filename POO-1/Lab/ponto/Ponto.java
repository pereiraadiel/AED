import java.util.Scanner;
import java.lang.Math.pow;
import java.lang.Math.sqrt;

public class Ponto{
	private double x,y;
	
	public double getX(){
		return this.x;
	}
	public double getY(){
		return this.y;
	}
	public void setY(double y){
		this.y = y;
	}
	public void setX(double x){
		this.x = x;
	}
	public void setPonto(double x, double y){
		this.x = x;
		this.y = y;
	}
	/*public void setX(double a){
		this.x = a;
	}
	public void setY(double a){
		this.y = a;
	}*/
	public static void main(String[] args){
		Ponto a = new Ponto();
		Ponto b = new Ponto();
		Scanner leitura = new Scanner(System.in);
		double xis, yps;
		System.out.println("Digite as coordenadas do ponto A:");
		System.out.print("X: ");
		xis = leitura.nextDouble();
		System.out.print("Y: ");
		yps = leitura.nextDouble();
		a.setPonto(xis,yps);

		System.out.println("Digite as coordenadas do ponto B:");
		System.out.print("X: ");
		xis = leitura.nextDouble();
		System.out.print("Y: ");
		yps = leitura.nextDouble();
		b.setPonto(xis,yps);

		System.out.println("Ponto A: ("+a.getX()+","+a.getY()+")");
		System.out.println("Ponto B: ("+b.getX()+","+b.getY()+")");

		System.out.println("Distancia entre os dois pontos: "+a.Distancia(b));

	}
	

	public double Distancia(Ponto b){
		return Math.sqrt(Math.pow(this.x - b.getX(),2)+Math.pow(this.y - b.getY(),2));
	}
	public double Distancia(double x, double y){
		return Math.sqrt(Math.pow(this.x - x,2)+Math.pow(this.y - y,2));
	}
}