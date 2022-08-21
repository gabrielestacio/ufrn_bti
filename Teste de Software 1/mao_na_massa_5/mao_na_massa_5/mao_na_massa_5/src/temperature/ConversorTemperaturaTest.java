package temperature;

import static org.junit.Assert.*;
import org.junit.Test;
import org.junit.runner.*;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameters;

@RunWith(Parameterized.class)
public class ConversorTemperaturaTest{
	private Temperatura temp;
	private Temperatura exp;
	private ConversorTemperatura conv = new ConversorTemperatura();
	
	/*public ConversorTemperaturaTest(Temperatura temp, Temperatura exp) {
		this.temp = temp;
		this.exp = exp;
	}*/
	
	public ConversorTemperaturaTest(double e, double t, int type) throws TempException {
		Fahrenheit f = new Fahrenheit();
		Celsius c = new Celsius();
		
		if(type == 1) {
			f.setValue(t);
			c.setValue(e);
			temp = f;
			exp = c;
		}
		else {
			c.setValue(t);
			f.setValue(e);
			temp = c;
			exp = f;
		}
	}
	
	@Parameters
	public static Object[][] data(){
		return new Object[][] {
			{0, 32, 1},
			{-4, -20, 2},
			{-273, -459, 1},
			{-459, -273, 2},
			{-273, -470, 1},
			{-459.4, -275, 2},
		};
	}
	
	@Test
	public void test() throws TempException {
		assertEquals(exp, conv.converte(temp));
	}
}