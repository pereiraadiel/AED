public abstract class FiguraPlana{
	private double x;
	private double y;

	public FiguraPlana(double x, double y){
		this.x = x;
		this.y = y;
	}
	//public void move(double x, double y);
	//public void mostra();
	public abstract double area();
	public abstract double perimetro();
	public abstract void printInfo();
	public double getX(){
		return x;
	}
	public double getY(){
		return y;
	}
}