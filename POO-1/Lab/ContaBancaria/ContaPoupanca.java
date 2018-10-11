public class ContaPoupanca extends ContaBancaria{
	private int dia_rendimento;

	public ContaPoupanca(String cliente, int dia_rendimento){
		super(cliente);
		this.dia_rendimento = dia_rendimento;
	}
	public void calcularNovoSaldo(float taxaRendimento) throws Exception{
		float saldo = getSaldo();
		super.depositar(taxaRendimento);
		float confere = getSaldo();
		if(confere != saldo) throw new Exception("Algo de errado nao esta certo!");
	}
	public float getSaldo(){
		return super.getSaldo();
	}
	public void sacar(float valor) throws Exception{
		float saldo = getSaldo();
		super.sacar(valor);
		float confere = getSaldo();
		if(confere != saldo) throw new Exception("Algo de errado nao esta certo!");
	}
}