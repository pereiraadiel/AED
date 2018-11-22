public class Retangulo implements ObjetoGeometrico{
	private Ponto2D verticeA, verticeB;

	public Retangulo(Ponto2D verticeA, Ponto2D verticeB){
		this.verticeA = verticeA;
		this.verticeB = verticeB;
	}

	public Ponto2D centro(){
		double x = (verticeA.getX()+verticeB.getX())/2;
		double y = (verticeA.getY()+verticeB.getY())/2;
		return new Ponto2D(x,y);
	}

	public double calculaArea(){
		return 0.0;
	}

	public double calculaPerimetro(){
		return 0.0;
	}

	public String toString(){
		return "Retangulo com vertices "+verticeA+" e "+verticeB;
	}
}