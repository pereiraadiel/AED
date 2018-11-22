import java.util.ArrayList;
import java.util.Scanner;
public class Prog{
	private static double areaTotal;
	private static double perimetroTotal;
	public static void main(String[] args) {
		areaTotal = 0.0;
		perimetroTotal = 0.0;
		ArrayList<FiguraPlana> figuras = new ArrayList<FiguraPlana>();
		figuras.add(new Quadrado(12.3,14.3,16.7));
		figuras.add(new Triangulo(0,0,1,1,1,0.5,1));
		figuras.add(new Losango(0,0,5,3,7));
		figuras.add(new Circulo(1.5,23.3,18.9));
		int size = figuras.size();
		System.out.printf("Tamanho do Array: %d\n",size);
		for(int i=0;i<size;i++){
			System.out.println("============================");
			System.out.printf("Conteudo da posicao %d:\n",i);
			figuras.get(i).printInfo();
			System.out.println("\n");
			areaTotal += figuras.get(i).area();
			perimetroTotal += figuras.get(i).perimetro();
		}
		System.out.println("Area Total das Figuras: "+areaTotal);
		System.out.println("Perimetro Total das Figuras: "+perimetroTotal);
	}
}