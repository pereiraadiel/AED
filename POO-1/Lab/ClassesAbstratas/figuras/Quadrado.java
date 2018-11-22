public class Quadrado extends FiguraPlana{
	private double lado;

	public Quadrado(double x, double y, double lado){
		super(x,y);
		this.lado = lado;
	}

	public double perimetro(){
		return lado*4;
	}

	public double area(){
		return  lado * lado;
	}

	public void printInfo(){
		System.out.println("----------------------------");
		System.out.println("     -- Quadrado --");
		System.out.println("Tamanho dos lados: "+lado);
		System.out.println("Area: "+area());
		System.out.println("Perimetro: "+perimetro());
		System.out.println("Coordenada X: "+super.getX());
		System.out.println("Coordenada Y: "+super.getY());
		System.out.println("----------------------------");
	}
}