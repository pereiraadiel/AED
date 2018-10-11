public class ContaBancaria{
	private String cliente;
	private int numero_conta;
	private static int contador;
	private float saldo;

	public ContaBancaria(String cliente){
		this.cliente = cliente;
		this.numero_conta = contador++;
		this.saldo = 0.0f;
	}
	public void sacar(float valor) throws Exception{//nao pode ficar negativo
		if(this.saldo >= valor)	this.saldo -= valor;
		else throw new Exception("Saldo insulficiente!.");
	}
	public void depositar(float valor) throws Exception{
		if(valor > 0) this.saldo += valor;
		else throw new Exception("Valor invalido para deposito");
	}
	public float getSaldo(){
		return this.saldo;
	}
	public String getCliente(){
		return this.cliente;
	}
	public int getNumConta(){
		return this.numero_conta;
	}
}