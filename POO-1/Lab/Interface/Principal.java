public class Principal{
	public static void main(String[] args) {
		Circulo c1 = new Circulo(new Ponto2D(0,0),100);
		Retangulo r1 = new Retangulo(new Ponto2D(-2,-2), new Ponto2D(2,2));
		imprimeTodosOsDados(c1);
		imprimeTodosOsDados(r1);
	}
	private static void imprimeTodosOsDados(ObjetoGeometrico obj){
		System.out.println(obj.toString());
		System.out.println("Perimetro: "+obj.calculaPerimetro());
		System.out.println("Area: "+obj.calculaArea());
		System.out.println();
	}
}