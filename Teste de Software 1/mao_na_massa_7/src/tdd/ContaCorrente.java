package tdd;

import java.util.ArrayList;

public class ContaCorrente {
	private int saldo_ini = 0;
	private int saldo_atualizado = saldo_ini;
	private ArrayList<Deposito> depositos = new ArrayList<>();
	private String nome = new String("James Grenning");
	
	public ContaCorrente(String nome, int valor) {
		this.nome = nome;
		this.saldo_ini = valor;
	}
	
	public ContaCorrente(String nome) {
		this.nome = nome;
	}
	
	public ContaCorrente(int valor) {
		this.saldo_ini = valor;
	}
	
	public ContaCorrente() {
		
	}
	
	public int saldo() {
		return 0;
	}
	
	public void creditar(Deposito deposito) {
		this.saldo_atualizado += deposito.valor();
		depositos.add(deposito);
	}
	
	public String extrato() {
		String extrato = new String("Conta de " + nome + "\nSaldo Inicial $" + saldo_ini + "\nSaldo Final $" + saldo_atualizado + "\n");
		for(int i = 0; i < depositos.size(); i++) {
			extrato += depositos.get(i).data + "\tDeposito\t$" + depositos.get(i).valor + "\n";
		}
		return extrato;
	}
}
