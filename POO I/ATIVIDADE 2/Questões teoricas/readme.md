### 1- Qual a diferença entre tipagem dinâmica e tipagem estática?

Trata-se de uma tipagem estática linguagens em que é preciso informar no momento da criação de uma variável o seu tipo de dado.
Enquanto tipagem dinâmica são linguagens em que o tipo de dado da variável é determinado automaticamente de acordo com o valor da mesma,
sem necessariamente explicitar o seu tipo

2-Qual o principal problema do uso de tipagem dinâmica?

O principal problema de uma tipagem dinâmica é a sua alta flexibilidade na sua definição de tipos.
Isso pode gerar problemas no código e dificultar sua manutenção futura

3-Pesquise um exemplo na internet em que a tipagem dinâmica pode ser problemático.


4-Pesquise e exemplifique com um exemplo porque dizemos que a linguagem C, mesmo tendo tipagem estática, possui tipagem fraca.

Em C seria possivel alterar a tipagem de uma variavel anteriomente declarada sem que o programador realize manualmente,por isso em alguns casos a mesma seria considerada fraca no quesito tipagem.

5-Pesquise e, se encontrar, um exemplo onde o tipo any seria benéfico.

Quando o TypeScript não é capaz de inferir o tipo da variável, ele automaticamente atribui a ela, o tipo any.

6-Poderíamos dizer que a tipagem do TypeScript é fraca por uma variável do tipo number aceitar tanto inteiros como ponto flutuante?

Nao, pois um numero de tipo ponto flutuante podera se tornar um numero de tipo inteiro caso seja interesse do programador o realizar.
