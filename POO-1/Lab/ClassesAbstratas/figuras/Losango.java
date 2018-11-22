public class Losango extends FiguraPlana{
	private double distanciaHorizontal;
	private double distanciaVertical;
	private double lado;

	public Losango(double x, double y, double h, double v, double l){
		super(x,y);
		distanciaVertical = v;
		distanciaHorizontal = h;
		lado = l;
	}

	public double area(){
		return (distanciaHorizontal*distanciaVertical)/2;
	}

	public double perimetro(){
		return lado*4;
	}
	public void printInfo(){
		System.out.println("----------------------------");
		System.out.println("     -- Losango --");
		System.out.println("Tamanho dos lados: "+lado);
		System.out.println("Distancia Horizontal: "+distanciaHorizontal);
		System.out.println("Distancia Vertical: "+distanciaVertical);
		System.out.println("Area: "+area());
		System.out.println("Perimetro: "+perimetro());
		System.out.println("Coordenada X: "+super.getX());
		System.out.println("Coordenada Y: "+super.getY());
		System.out.println("----------------------------");
	}
}