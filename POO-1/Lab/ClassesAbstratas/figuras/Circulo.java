public class Circulo extends FiguraPlana{
	private double raio;

	public Circulo(double x, double y, double raio){
		super(x,y);
		this.raio = raio;
	}

	public double perimetro(){
		return 2*3.141592655359*raio;
	}

	public double area(){
		return 3.141592655359*raio*raio;
	}
	public void printInfo(){
		System.out.println("----------------------------");
		System.out.println("     -- Circulo --");
		System.out.println("Raio: "+raio);
		System.out.println("Area: "+area());
		System.out.println("Perimetro: "+perimetro());
		System.out.println("Coordenada X: "+super.getX());
		System.out.println("Coordenada Y: "+super.getY());
		System.out.println("----------------------------");
	}
}