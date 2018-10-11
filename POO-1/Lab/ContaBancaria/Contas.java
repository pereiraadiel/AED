public class Contas{
	public static void main(String[] args) throws Exception {
		ContaBancaria cb = new ContaBancaria("Ronaldo Munhoz");
		ContaPoupanca cp = new ContaPoupanca("Ronaldo Munhoz", 25);
		ContaEspecial ce = new ContaEspecial("Ronaldo Munhoz",-93.2f);

		cb.depositar(800f);
		cb.sacar(200f);
		cb.sacar(500f);
		System.out.println("Conta Simples\n-------------------");
		System.out.println("Titular: "+cb.getCliente());
		System.out.println("Numero Conta: "+cb.getNumConta());
		System.out.println("Saldo: "+cb.getSaldo());

		cp.depositar(800f);
		cp.calcularNovoSaldo(200f);
		cp.sacar(500f);
		System.out.println("Conta Poupanca\n-------------------");
		System.out.println("Titular: "+cp.getCliente());
		System.out.println("Numero Conta: "+cp.getNumConta());
		System.out.println("Saldo: "+cp.getSaldo());

		ce.setLimite(300f);
		ce.depositar(800f);
		ce.sacar(200f);
		ce.sacar(900f);
		System.out.println("Conta Especial\n-------------------");
		System.out.println("Titular: "+ce.getCliente());
		System.out.println("Numero Conta: "+ce.getNumConta());
		System.out.println("Saldo: "+ce.getSaldo());
		throw new Exception("Fim");

	}
}