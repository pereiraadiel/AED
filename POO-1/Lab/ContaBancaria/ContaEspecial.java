public class ContaEspecial extends ContaBancaria{
	private float limite;

	public ContaEspecial(String cliente, float limite){
		super(cliente);
		this.limite = limite;
	}
	public void setLimite(float limite){
		this.limite = limite;
	}
	public void sacar(float valor) throws Exception{ //aqui eh possivel sacar alem do saldo da conta ou seja negativar o saldo ate o limite
		if(super.getSaldo() >= this.limite)	super.sacar(valor);
		else throw new Exception("Saldo insulficiente!.");
	}
}