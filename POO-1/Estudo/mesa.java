public class mesa{
	private static int id;//identificador da mesa
	private static int NClientes; //clientes na mesa
	private static boolean ocupada=false; //verificar se a mesa esta ocupada
	
	public static void main(String args[]){//metodo principal
		mesa m1 = new mesa();
		int id, clientes;
		boolean ocupada=false;
		//System.out.println("Digite o numero identificador da mesa: ");
		id = 1;
		//System.out.println("Digite o numero de clientes: ");
		clientes = 3;
		ocupada = true;
		print();
		
	}
	public int getID(){
		return this.id;
	}
	public int getNClientes(){
		return this.NClientes;
	}
	public boolean getOcupacao(){
		return this.ocupada;
	}
	public void setID(int id){
		this.id = id;
	}
	public void setNClientes(int NClientes){
		this.NClientes = NClientes;
	}
	public void setOcupacao(boolean ocupada){
		this.ocupada = ocupada;
	}
	public static void print(){
		System.out.println("ID: "+this.id);
		System.out.println("Numero Clientes: "+this.NClientes);
		System.out.println("Mesa esta ocupada: "+ this.ocupada);
		System.out.println("");
	}
}
