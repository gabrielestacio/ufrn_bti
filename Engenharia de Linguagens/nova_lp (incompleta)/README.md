
## Um programa em geral nesta linguagem tem a seguinte estrutura:

**DECLARAÇÃO DE VARIÁVEIS GLOBAIS E CONSTANTES**
Seção para declaração de variáveis e constantes globais, que só podem ser declaradas aqui. O único tipo de atribuição permitido nessa seção é o simples ":=". Uma sentença de declaração segue o formato: "const" (apenas se estiver declarando uma constante), o tipo do dado seguido do nome do identificador, seguido das dimensões do identificador (pode ser omitido se o dado for único), seguido de uma expressão (que serão definidas mais abaixo), e terminando, necessariamente, com a ocorrência de um ponto e vírgula.

*Exemplo de declaração de constantes*
```
const int id0 := 2;
````

*Exemplos de declaração de variáveis e suas diferentes formas possíveis*
```
string id1, id2, id3 := "";
boolean id4 := false;
char id5, id6;
real id7;
```
*Exemplos de declaração de vetores*
```
string id8[] := {};
int id9[3][3];
char id10[][][];
```

**SUB-PROGRAMAS**
Sub-programas podem ser de qualquer tipo da linguagem e inclui também um tipo "void", para funções sem retorno. Eles semprem iniciam com a palavra reservada "function", seguida do tipo de retorno do sub-programa, do seu nome e de um par de parênteses, que contém uma lista de parâmetro da função, que pode ser vazia, ter um parâmetro só ou vários. Um parâmetro tem a forma: tipo do parâmetro seguido pelo nome dele no escopo da função.

Após esse par de parêntes, vem o par de chaves que delimitam o começo e o fim do corpo de qualquer função, seja a função "main" ou qualquer sub-programa. Dentro do corpo, existem algumas possibilidades. A primeira delas é não ter nada e a função ser vazia. A segunda é conter apenas declarações de variáveis (ou constantes) que existirão apenas no escopo desse sub-programa (apesar de não enxergar muita utilidade prática pra isso, é possível). A terceira possibilidade é conter apenas instruções (que serão definidas mais abaixo), sem nenhuma declaração. Nesse caso, a função só poderá fazer atribuições em variáveis globais, utilizando os valores delas, das constantes globais e das variáveis passadas por parâmetro. A quarta e última possibilidade é o caso ideal: que a função contenha declarações de variáveis (ou constantes) para seu escopo e uma lista de instruções.

É importante destacar que, para todo sub-programa que não seja do tipo "void", precisa haver uma (ou mais de uma, como no caso de um if/else, por exemplo) sentença de retorno que entregue um valor de tipo correspondente ao tipo do sub-programa. A única função que não exige isso é a função main, mas por ser necessariamente do tipo "void".

*Exemplos de sub-programas*
```
function void vazia(){

}

function int soDeclaracao(int id11){
	const int id12 := 3;
	int id13 := id11 * id12;
	return id13;
}

function string soInstrucao(string id14, string id15, string id16){
	id1 += id14 + id15;
	id2 := id16;
	return id1 + id2;
}

function boolean casoIdeal(){
	int id17 := 15;
	int id18 := id17++;

	if(id17 > id18){
		return false;
	}
	return true;
}
```

**A FUNÇÃO MAIN**
Essa é uma função especial, pois contém toda a parte principal do código. Ela é, naturalmente, de tipo "void" e não possui parâmetros, sem ser necessário explicitar isso em seu cabeçalho. Sua declaração segue o seguinte formato: as palavras reservadas "function" e "main" seguidas pelo par de chaves que delimitam o início e o fim do seu corpo.

Assim como qualquer sub-programa, a função main tem quatro possibilidades de uso: vazio, apenas com declarações de variáveis ou constantes locais, apenas com uma lista de instruções, e o caso ideal, com declarações e instruções.

Importante destacar que: 1) como essa função é naturalmente de tipo "void", ela não pode conter uma sentença de retorno dentro do seu corpo; e 2) a função main é única, isto é, não é permitido existir mais de uma função main no código.

*Exemplos de função main*
```
function main{

}

function main{
	char id19;
	boolean id20 := true;
	real id21, id22;
}

function main{
	id3 := "Hello, world!";
	id7 := 3.5;
	
	id3 += id1;
	id7--;
}

function main{
	int id23[4] := {8, 10, 12, 14};
	int i;
	
	for (i := 0) to 4{
		if((id23[i]/2) % id0) == 0){
			id4 := true
		}
		else{
			id4 := false;
		}
	}
}
```

**INSTRUÇÃO**
De modo geral, uma instrução pode estar presente no corpo de um sub-programa ou da função main (as instruções presentes na seção de declaração global nós chamamos declarações, e não instruções, mesmo que lá hajam sentenças de atribuição, porém, por serem de formato diferente de uma instrução de atribuição, não as consideramos instruções). Qualquer instrução fora desses dois contextos serão tratadas como erro.
Instruções pode ser senteças de: atribuição, laços condicionais (if/else e switch/case) ou laços de repetição (for e while), sendo todas, obrigatoriamente, terminadas com a ocorrência de um ponto e vírgula.
> **Sentenças de atribuição**
> Sentenças de atribuição são sempre do formato: 1) identificador, seguido pelo sinal de atribuição, seguido por uma expressão (será definida mais abaixo); ou 2) identificador, seguido por um sinal duplo. Importante destacar que essa instrução só é válida para identificadores já declarados anteriormente.
> 
> *Sinais de atribuição:* := (atribuição simples), +=, -=, *= e /=.
> *Sinais duplos:* ++ ou --.
> 
> *Exemplos de atribuição*
> ```
> int atr1, atr2;
> const int atr0 := 2;
> 
> function main{
	>  	atr1 := 10 + 4;
	> 	atr2 := 22;
	> 	atr1 += atr2;
	> 	atr1 -= 4;
	> 	atr1 /= 2;
	> 	atr1 *= atr2 % atr0 + 1 ** 5;
	> 	atr1++;
	> 	atr2--;
> }
> ```

> **Laço condicional if/else**
> Um laço if/else segue o formato: "if" seguido de um par de parênteses que contém uma comparação, seguido de um par de chaves que delimitam o início e o fim do bloco de instruções if. Opcionalmente, para condicionais não-binários, pode-se criar uma ou mais condições "else if" seguidas de um par de parênteses que contém uma comparação, seguido de um par de chaves que delimitam o início e o fim do bloco de instruções else if. Também opcionalmente, para qualquer tipo de condicional, pode-se criar uma condição "else" seguida de um par de chaves que delimitam o início e o fim do bloco de instruções else (que representa o caso onde nenhuma condição anterior é satisfeita).
>
> *Exemplos de if/else*
> ```
> function main{
	> 	int ie0, ie1 := 3;
	> 	boolean ie2, ie3 := false;
	>
	> 	if(ie0 == ie1){
	> 		ie2 := true
	> 	}
	>
	> 	ie0 := 5;
	> 	if(ie0 == ie1){
	> 		ie2 := false;
	> 	}
	> 	else{
	> 		ie3 := true;
	> 	}
	> 	
	> 	if((ie3 == true) && (ie0 > ie1)){
	> 		ie2 := true;
	> 	}
	> 	else if((ie3 == true) || (ie0 > ie1)){
	> 		ie3 := false;
	> 	}
	> 	else{
	> 		ie2 := true;
	> 		ie3 := false;
	> 	}
> }
> ```

> **Laço condicional switch/case**
> Um laço switch/case obedece ao formato: "switch" seguido de um par de parênteses que contém uma variável sobre a qual será feita a verificação condicional, seguido por um par de chaves que delimitam o início e o fim do bloco de instruções switch. Dentro do par de chaves, há, necessariamente, uma ou mais ocorrências da estrutura case ("case" seguido da expressão que satisfaz a condição, seguida de dois pontos, que indicam o início do bloco de instruções case, seguido da lista de instruções do bloco, terminando com a instrução break), e uma única ocorrência da estrutura default ("default" seguido de dois pontos, que indicam o início do bloco de instruções default, seguido da lista de instruções do bloco, terminando com a instrução break. Default representa o caso onde nenhuma das condições é satisfeita).
>
> *Exemplo de switch/case*
> ```
>function main{
	> 	boolean sc0;
	> 	char sc1 := a;
	> 	switch(sc1){
	> 		case 'a':
	> 			sc0 := true;
	> 			break;
	> 		default:
	> 			sc0 := false;
	> 			break;
	> 	}
> }
>```

> **Laço de repetição for**
> Um laço de repetição for obedece ao formato: "for" seguido de um par de parênteses, que contém uma atribuição simples com uma variável recebendo uma expressão, seguido de "to" e uma expressão, seguido de um par de chaves que delimitam o início e o fim do bloco de instruções for.
>
>*Exemplo de for*
> ```
>function main{
	> 	int i;
	> 	real f[5] := {};
	>
	> 	for(i := 0) to 5{
	> 		f[i] := i*50;
	> 	}
>}
> ```

> **Laço de repetição while**
> Um laço de repetição while obedece ao formato: "while" seguido de um par de parênteses, que contém uma comparação, seguido de um par de chaves que delimitam o início e o fim do bloco de instruções while.
>
> *Exemplo de while*
> ```
> function main{
	> 	boolean w0 := false;
	>  	int w1 := 0;
	> 	while(!(w0)){
	> 		if(w1 == 5){
	> 			w0 := true;
	> 		}
	> 		w1++;
	> 	}
> }
>```

> **Instruções Especiais**
>  Existem um tipo de instruções, chamadas de alteradores de fluxo, que são as **instruções de retorno e de interrupção**. A instrução de retorno está corretamente presente apenas em sub-programas de tipo diferente de "void" e obedece o formato: "return" seguido de uma expressão, seguida de um ponto e vírgula. Já a instrução de interrupção pode estar presente em qualquer bloco de instruções e obedece o formato: "break" seguido por um ponto e vírgula. Exemplos de utilização dessas instruções já apareceram em exemplos anteriores neste documento. 

**COMPARAÇÃO**
Uma comparação é uma espécie de expressão que utiliza uma combinação de operadores de comparação (obrigatórios numa comparação) e operadores lógicos (opcional na comparação, presente apenas se a comparação envolver mais de uma condição) para comparar o valor de um identificador com o resultado de uma expressão.

*Operadores de comparação:* == (igualdade), > (maior que), < (menor que), != (diferente), >= (maior ou igual que) e <= (menor ou igual que).
*Operadores Lógicos:* && (e), || (ou) e ! (not).

*Exemplos de comparação*
```
function main{
	string co0 := "";
	int co1, co2 := 0;
	boolean co3 := true;

	if(co0 == ""){
		co3 := false;
	}

	if(co1 > co2){
		co2 := co1;
	}
	else if(co1 < co2){
		co1 := co2;
	}

	if(!(co3)){ /*Equivale a dizer: if(co3 != true)*/
		co3 := true;
	}

	if(co1 != co2){
		co3 := false;
	}

	if((co1 >= co2) && (co3)){
		co2 := co1 + 2;
	}

	co2 := co1 + 5;
	if((co1 <= co2) || (co3 == false)){
		co1 := co2;
	}
}
```

**EXPRESSÃO**
Uma expressão tem quatro formas possíveis: uma operação aritmética, apenas um identificador, apenas um literal ou apenas uma chamada de função. É utilizada principalmente em instruções de atribuição.
> **Operações aritméticas**
> As operações aritméticas possíveis são: adição e subtração (+ e -); multiplicação, divisão e módulo (*, / e %); e potenciação (**). Elas respeitam uma ordem de precedência, para evitar ambiguidade, e podem aparecer como uma combinação de expressões. Os operandos são sempre outras expressões.
>
> **Identificador**
> Identificadores são nomes de variáveis ou constantes. Importante destacar que essa forma de expressão só é válida para variáveis já declaradas anteriormente.
> 
> **Literais**
> Literais são dados dos tipos suportados pela linguagem. 2 é um literal int, por exemplo. "Abc" é um literal string, enquanto "a" é um literal char, e assim por diante.
> 
> **Chamadas de função**
> Expressões que disparam a execução de sub-programas já definidos anteriormente e retornam o seu resultado quando o tipo do sub-programa não é "void". Essa chamada obedece o formato: nome do sub-programa seguido por um par de parêntes, que contém identificadores que serão passados para o sub-programa como argumentos, caso este possua parâmetros. Caso o sub-programa não possua parâmetros, o par de parêntes deve estar vazio.
>
> *Exemplos de operações aritméticas*
> ```
	> function int funcCall(){
	>	return 3;
	>}
	> 
	> function main{
	> 	int op0 := 1;
	> 	int op1 := 2;
	> 	int op2 := 3;
	>
	>	op0 := op0 + (4 + (op2**2) - (op0 * op2) + 6)/(op0 * 8) % funcCall();
	>	op1 := op2;
	>	op2 := 5;
	>	op0 := funcCall();
	>}
	> ```
