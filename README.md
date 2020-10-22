# Algoritmos Numéricos 🧮📚

## Objetivo 📝
Estudar e implementar algoritmos numéricos para resolver problemas representados através de modelos matemáticos, aplicados nas diversas áreas do conhecimento humano.

## Algoritmos 📂
- [Método da Bisseção](https://github.com/thaina-gomes/numerical-algorithms/blob/master/algorithms/MetodoBissecao.c) 

O **método da bisseção**  é um método de busca de raízes que bissecta repetidamente um intervalo e então seleciona um subintervalo contendo a raiz para processamento adicional. Por este motivo, ele é usado frequentemente para obter uma primeira aproximação de uma solução, a qual é então utilizada como ponto inicial para métodos que convergem mais rapidamente.

- [Método Regula-Falsi](https://github.com/thaina-gomes/numerical-algorithms/blob/master/algorithms/MetodoRegulaFalsi.c)

**Método da posição falsa** ou _**regula falsi**_ é um método numérico usado para resolver equações lineares definidas em um intervalo [a, b], partindo do pressuposto de que haja uma solução em um subintervalo contido em [a, b]. E assim, diminuindo esse subintervalo em partes cada vez menores, a solução estará onde a função tem sinais opostos, segundo o Teorema do Valor Intermediário. A determinação do tamanho do subintervalo é definida pelo critério de exatidão.

- [Método de Illinois](https://github.com/thaina-gomes/numerical-algorithms/blob/master/algorithms/MetodoIllinois.c)

O **Método de Illinois** segue o Regula Falsi, exceto que as estimativas escolhidas para a próxima iteração são selecionadas de acordo com as seguintes regras:

i) se f (i + 1) f (i) <0, então (x (i-1), f (i-1)) é substituído por (x (i), f (i))

ii) se f (i + 1) f (i)> O, então (x (i-1), f (i-1)) é substituído por (x (i-1), f (i-1) / 2).

Como antes, (x (i + 1), f (i + 1)) substitui (x (i), f (i)). Os valores da função usados em cada iteração novamente sempre terão sinais opostos e a introdução do valor f (i-1) / 2 para f (i-1) é uma modificação projetada para acelerar a convergência evitando a retenção de um ponto final.

- [Método de Pégaso](https://github.com/thaina-gomes/numerical-algorithms/blob/master/algorithms/MetodoPegaso.c)

Assim como o Método Illinois, o **Método de Pégaso** é baseado no método Regula-Falsi, mas, com algumas modificações.
Como o método _Regula Falsi_ garante a convergência  mantendo uma solução entre parênteses. O método _Pegasus_ , no entanto, deve convergir muito mais rápido do que o método _Regula Falsi_ original . Além disso, esta implementação do método _Pegasus_ não deve sofrer os mesmos problemas de implementação que o método _Regula Falsi_ , que pode falhar na convergência em certos casos. Além disso, o método _Pegasus_ deve convergir mais rápido do que o Método _Illinois_.

- [Método do Ponto Fixo](https://github.com/thaina-gomes/numerical-algorithms/blob/master/algorithms/MetodoPontoFixo.c)

Um método iterativo do tipo Xk+1 = ϕ(Xk) é dito método do ponto fixo, ou também método iterativo simples. É fácil construir um método do ponto fixo, dada uma qualquer função ϕ(X) e um ponto Xo pode sempre construir o método : 
X1 = ϕ(X0) −→ X2 = ϕ(X1) −→ · · · Xk = ϕ(Xk−1) −→ Xk+1 = ϕ(Xk) −→ · · ·

- [Método de Newton-Raphson](https://github.com/thaina-gomes/numerical-algorithms/blob/master/algorithms/MetodoNewtonRaphson.c)

É um algoritmo de localização de raízes que produz aproximações sucessivamente melhores para as raízes (ou zeros) de uma função de valor real. 
