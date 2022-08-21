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
	
	public ConversorTemperaturaTest(Temperatura temp, Temperatura exp) {
		this.temp = temp;
		this.exp = exp;
	}
	
	@Parameters
	public static Object[][] data(){
		return new Object[][] {
			{
		}
	}
}