public class Triangulo extends FiguraPlana{
	private double ladoA;
	private double ladoB;
	private double ladoC;
	private short tipo; // equilatero / isosceles / escaleno
	private double base;
	private double altura;

	//int b (1,2 or 3)
	public Triangulo(double x, double y, double lA, double lB, double lC, double a, int b){
		super(x,y);
		ladoA = lA;
		ladoB = lB;
		ladoC = lC;
		if(lA==lB && lB==lC) tipo=1;//equilatero
		else if(lA==lB || lB==lC || lA==lC) tipo=2;//isosceles
		else tipo=3;// escaleno
		base = b==1?lA:b==2?lB:lC;
		altura = a;
	}

	public double perimetro(){
		return ladoA+ladoB+ladoC;
	}
	
	public double area(){
		return (base*altura)/2;
	}
	public void printInfo(){
		System.out.println("----------------------------");
		System.out.println("     -- Triangulo --");
		System.out.println("Tamanho do lado A: "+ladoA);
		System.out.println("Tamanho do lado B: "+ladoB);
		System.out.println("Tamanho do lado C: "+ladoC);
		System.out.println("Base: "+base);
		System.out.println("Altura: "+altura);
		System.out.println("Area: "+area());
		System.out.println("Perimetro: "+perimetro());
		System.out.printf ("Tipo de triangulo: %s\n",tipo==1?"Equilatero":tipo==2?"Isosceles":"Escaleno");
		System.out.println("Coordenada X: "+super.getX());
		System.out.println("Coordenada Y: "+super.getY());
		System.out.println("----------------------------");
	}
}