package banco;

import static org.junit.Assert.*;
import org.junit.Test;

public class ContaTest {
	@Test
	public void testTransferirBemSucedido() throws OperacaoIlegalException {
		Conta c1 = new Conta("1", 2);
		Conta c2 = new Conta("2", 2);
		
		c1.transferir(c2, 1);
		assertEquals(c2.getSaldo(), 3, 0);
	}
	
	@Test
	public void testTransferirMalSucedido1() throws OperacaoIlegalException {
		Conta c1 = new Conta("1", 2);
		Conta c2 = new Conta("2", 2);
		
		c1.transferir(c2, 0);
		assertEquals(c2.getSaldo(), 2, 0);
	}
	
	//Corrigir pra não permitir valores maiores que o saldo
	@Test
	public void testTransferirMalSucedido2() throws OperacaoIlegalException {
		Conta c1 = new Conta("1", 2);
		Conta c2 = new Conta("2", 2);
		
		c1.transferir(c2, 3);
		fail("Valor a ser transferido maior que o saldo!");
	}
	
	@Test
	public void testTransferirMalSucedido3() throws OperacaoIlegalException {
		Conta c1 = new Conta("1", 2);
		Conta c2 = new Conta("2", 2);
		
		c1.transferir(c2, -2);
		assertEquals(c2.getSaldo(), 5, 0);
		assertEquals(c1.getSaldo(), 0, 0);
	}
}