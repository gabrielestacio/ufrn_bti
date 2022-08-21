package fila;

import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class FilaTest{
	@Test
	public void testTamanhoBemSucedido() {
		Fila f = new Fila(3);
		
		assertEquals(f.tamanho(), -1);
	
		f.insereNaFila(1);
		assertEquals(f.tamanho(), 0);
	}
	
	@Test
	public void testEstaVaziaOuCheiaBemSucedido() {
		Fila f = new Fila(3);
		
		assertEquals(f.estaVazia(), true);
		
		f.insereNaFila(1);
		assertEquals(f.estaVazia(), false);
	}
	
	@Test
	public void testInserirBemSucedido() {
		Fila f = new Fila(2);
		
		f.insereNaFila(1);
		f.insereNaFila("a");
		
		assertEquals(f.getFim(), 1);
		assertEquals(f.getCapacidade(), 5);
	}
	
	@Test
	public void testRemoverBemSucedido() {
		Fila f = new Fila(2);
		
		f.insereNaFila(1);
		f.insereNaFila("a");
		f.insereNaFila("s");
		
		//
	}
	
	@Test
	public void testLimparBemSucedido() {
		Fila f = new Fila(2);
		
		f.insereNaFila(1);
		f.insereNaFila("a");
		f.insereNaFila("s");
		
		f.limpaFila();
		
		assertEquals(f.getFim(), -1);
	}
	
	
	
}