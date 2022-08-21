package temperature;


public class ConversorTemperatura{  
  
    public ConversorTemperatura(){ }  
  
    public Temperatura converte(Temperatura temp) throws TempException{
       Temperatura retorno;
    	
       if(temp instanceof Celsius) {
    	   retorno = converteToFahrenheit(temp);  
       }
       else {
    	   retorno = converteToCelsius(temp);
       }
       return retorno;
    }  
  
    private Temperatura converteToFahrenheit(Temperatura celsius) throws TempException{  
       Fahrenheit f = new Fahrenheit();  
       double cvalue = celsius.getValue();   
       double fvalue = 1.8*cvalue+f.getFREEZE(); // formula 1  
       f.setValue(fvalue);  
       return f;  
    }  
  
    private Temperatura converteToCelsius(Temperatura fahrenheit) throws TempException{  
       Celsius c = new Celsius();  
       double fvalue = fahrenheit.getValue();   
       double cvalue = (5/9)*(fvalue-fahrenheit.getFREEZE());
       c.setValue(cvalue);  
       return c;  
    }  
}  