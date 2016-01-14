Implementação do SST
====================

<!-- Assumindo uma explicação do teste, das medições realizadas e do porque realizá-las. -->

Concepção
---------

<!-- introdução -->
Para podermos implementar o SST, inicialmente fizemos um algoritmo do teste nos baseando nas descrições do teste encontradas na literatura.<!-- Citar descrições? --> A dizer, o teste consiste em um laço de repetição: por um número fixo de vezes, deve ser apresentado ao sujeito dois estímulos visuais diferentes. Quando lhe aparecer estas imagens, o sujeito pode ou não ser estimulado com um sinal sonoro. Se o sinal sonoro aparecer, o sujeito não deve reagir. Caso contrário, ele deve responder como for especificado. Os estímulos visuais devem ser apresentados em igual proporção e até que (1) o usuário responda (2) passe do tempo máximo permitido, enquanto que o sinal sonoro deve ser apresentado em uma parcela menor de vezes. No nosso caso, decidimos que

+ os estímulos visuais seriam setas apontando para a direita e para a esquerda, para que o sujeito pudesse responder usando as teclas do teclado de um computador em no máximo 1000ms.
+ som seria apresentado em somente 25% das vezes<!-- Citar porque 25%? -->.

<!-- lidando com tempo -->
Como o intuito do teste é medir o tempo de demora para que uma pessoa iniba uma ação já iniciada, o sinal sonoro deve ser apresentado depois das setas. Definiremos o tempo entre a apresentação das setas e a do som como `SSD`. A fim de estimar o tempo limítrofe entre o sujeito conseguir inibir ou não, o teste varia o `SSD` de acordo com o desempenho do sujeito: em caso de acerto, isto é, caso ele consiga inibir sua resposta, tornaremos o teste mais difícil aumentando o `SSD` em um valor fixo, que chamaremos de _passo_. Senão, subtraímos um passo do `SSD`, fazendo com que o sinal sonoro seja apresentado mais perto do sinal visual. Com esta perspectiva, devemos definir:

+ SSD inicial
+ SSD mínimo
+ SSD máximo
+ Passo

<!-- equação do ssrt, # de vezes -->
A partir da equação do `SSRT`, vamos abrir mão da estatística para podermos definir, por amostragem, qual o `SSRT` do sujeito. Assumindo<!-- citar porque podemos assumir isso --> que o `SSRT` obedece a uma distribuição normal em torno de um valor médio, que é o que queremos medir, temos que os parâmetros que tangem o SSD e o passo devem ser ajustados para podermos amostrar bem a faixa em torno do valor desejado. Da literatura, observamos que o laço principal do teste deve se repetir por cerca de 128 vezes, resultando em uma duração confortável para o sujeito e em um número de respostas grande o suficiente para podermos aferir o SSD médio. Assim, optamos pelos seguintes parâmetros de tempo para o teste:

+ SSD inicial: 250ms, no nosso caso.
+ SSD mínimo: 0ms, ou seja, o sinal pode aparecer junto com as setas, se for necessário.
+ SSD máximo: 750ms, por ser 75% do tempo máximo.
+ Passo: 50ms

<!-- conclusão para implementação -->
A partir deste entendimento, podemos escrever um pseudo-código para explicar a nossa implementação do SST:

``` html
instruções
para n = 1 até 128
    mostrar intervalo
    mostrar seta
    se tem estímulo sonoro
    se não
    fim se
fim para
```

<!-- conclusão para o processamento -->
Após cada aplicação do teste, aplicamos um processamento individual nas medidas geradas usando a equação do SST: <!-- como aplicar  a equação-->. Com um número suficientemente grande de sujeitos colaborando com o teste, podemos um estimar um `SSRT` coletivo.

Com isso, podemos finalmente começar a implemetar o SST. A ferramenta de escolha foi o software E-prime, por já ser utilizado em testes psicológicos. As imagens foram geradas usando o software Processing; o som, usando o software Pure Data. Os dados foram processados usando programas próprios do laboratório escritos. Todo o código-fonte pode ser acessado no site [](https://github.com/ishiikurisu/EEG/SST).

Implementação
-------------

aprendendo basic no e-prime. concepção da arte. concepção do som. processamento dos dados.

Adaptação do teste para idosos
------------------------------

número de ausências como motivação para (1) tornar o teste mais devagar; e (2) explicar melhor o teste, baseando-se em tutoriais de videogames.

Referências
-----------

+ Criar lista de referências
+ Sim, por favor
