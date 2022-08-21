package param;

import static org.junit.Assert.*;
import org.junit.Test;
import org.junit.runner.*;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameters;

@RunWith(Parameterized.class)
public class CalculoImpostoRendaTest{
	private double valor = 0;
	private double total = 0;
	
	public CalculoImpostoRendaTest(double total, double value)
	{
		this.total = total;
		this.valor = value;
	}
	
	@Parameters
	public static Object[][] data(){
		return new Object[][] {
			{1201*0.1, 1201},
			{5001*0.15, 5001},
			{10001*0.2, 10001},
			{0, 1199}
		};
	}
	
	@Test
	public void test() {
		assertEquals(total, CalculoImpostoRenda.calculaImposto(valor), 0);
	}
}