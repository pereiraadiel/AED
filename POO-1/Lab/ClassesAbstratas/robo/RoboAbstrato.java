public abstract class RoboAbstrato{
	private String nomeDoRobo;
	private int posicaoAtualX;
	private int posicaoAtualY;
	private short direcaoAtual;

	public RoboAbstrato(String nome, int px, int py, short direcao){
		nomeDoRobo = nome;
		posicaoAtualY = py;
		posicaoAtualX = px;
		direcaoAtual = direcao;
	}

	public void move(){move(1);}
	public void move(int passos);
	public void moveX(int passos);
	public void moveY(int passos);
	public void mudaDirecao(short novaDirecao);
	public short qualDirecaoAtual();
	public String toString();
}