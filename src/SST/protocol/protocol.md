Implementa&ccedil;&atilde;o do SST
====================

<!-- Assumindo uma explica&ccedil;&atilde;o do teste, das medi&ccedil;&otilde;es realizadas e do porque realiz&aacute;-las. -->

Nota&ccedil;&atilde;o
-------

Vamos denotar `<M>` como a m&eacute;dia aritm&eacute;tica da medida `M`.

Concep&ccedil;&atilde;o
---------

<!-- introdu&ccedil;&atilde;o -->
Para podermos implementar o SST, inicialmente fizemos um algoritmo do teste nos baseando em suas descri&ccedil;&otilde;es encontradas na literatura.<!-- Citar descri&ccedil;&otilde;es? --> A dizer, ele consiste em um la&ccedil;o de repeti&ccedil;&atilde;o: por um n&uacute;mero fixo de vezes, deve ser apresentado ao sujeito dois est&iacute;mulos visuais diferentes. Quando lhe aparecer estas imagens, o sujeito pode ou n&atilde;o ser estimulado com um sinal sonoro. Se o sinal sonoro aparecer, o sujeito n&atilde;o deve reagir. Caso contr&aacute;rio, ele deve responder como lhe for especificado. Os est&iacute;mulos visuais devem ser apresentados em igual propor&ccedil;&atilde;o e at&eacute; que (1) o usu&aacute;rio responda; ou que (2) passe do tempo m&aacute;ximo permitido. J&aacute; o sinal sonoro deve ser apresentado em uma parcela menor de vezes. No nosso caso, decidimos que

+ os est&iacute;mulos visuais seriam setas apontando para a direita e para a esquerda, para que o sujeito pudesse responder usando as teclas do teclado de um computador em no m&aacute;ximo 1000ms.
+ som seria apresentado em somente 25% das vezes<!-- Citar porque 25%? -->.

<!-- lidando com tempo -->
Como o intuito do teste &eacute; medir o tempo de demora para que uma pessoa iniba uma a&ccedil;&atilde;o j&aacute; iniciada, o sinal sonoro deve ser apresentado depois das setas. Definiremos o tempo entre a apresenta&ccedil;&atilde;o das setas e a do som como `SSD`. A fim de estimar o tempo lim&iacute;trofe entre o sujeito conseguir inibir ou n&atilde;o, o teste varia o `SSD` de acordo com o desempenho do sujeito: em caso de acerto, isto &eacute;, caso ele consiga inibir sua resposta, tornaremos o teste mais dif&iacute;cil aumentando o `SSD` em um valor fixo, que chamaremos de _passo_. Sen&atilde;o, subtra&iacute;mos um passo do `SSD`, fazendo com que o sinal sonoro seja apresentado mais perto do sinal visual. Com esta perspectiva, devemos definir:

+ SSD inicial;
+ SSD m&iacute;nimo;
+ SSD m&aacute;ximo;
+ Passo.

<!-- equa&ccedil;&atilde;o do ssrt, # de vezes -->
A partir da equa&ccedil;&atilde;o do `SSRT`, vamos abrir m&atilde;o da estat&iacute;stica para podermos definir, por amostragem, qual o `SSRT` do sujeito. Assumindo<!-- citar porque podemos assumir isso --> que o `SSRT` obedece a uma distribui&ccedil;&atilde;o normal em torno de um valor m&eacute;dio, que &eacute; o que queremos medir, temos que os par&acirc;metros que tangem o SSD e o passo devem ser ajustados para podermos amostrar bem a faixa em torno do valor desejado. Da literatura, observamos que o la&ccedil;o principal do teste deve se repetir por cerca de 128 vezes, resultando em uma dura&ccedil;&atilde;o confort&aacute;vel para o sujeito e em um n&uacute;mero de respostas grande o suficiente para podermos aferir o SSD m&eacute;dio. Assim, optamos pelos seguintes par&acirc;metros de tempo para o teste:

+ SSD inicial: 250ms, no nosso caso;
+ SSD m&iacute;nimo: 0ms, ou seja, o sinal pode aparecer junto com as setas, se for necess&aacute;rio;
+ SSD m&aacute;ximo: 750ms, por ser 75% do tempo m&aacute;ximo;
+ Passo: 50ms.

<!-- considera&ccedil;&otilde;es com o sujeito -->
Para que o sujeito pudesse realizar o teste com sucesso, adicionamos ao come&ccedil;o do teste uma parte de instru&ccedil;&atilde;o e outra de treino. Originalmente, concebemos as instru&ccedil;&otilde;es como um breve texto explicativo, indicando o que o sujeito deveria fazer. A etapa de treinos, por sua vez, foi planejada para ser uma vers&atilde;o menor do teste, em que o `SSD` n&atilde;o se altera e em que h&aacute; menos repeti&ccedil;&otilde;es, cerca de 25% do teste original.

Al&eacute;m disso, adicionamos &agrave; cada itera&ccedil;&atilde;o do la&ccedil;o principal uma resposta do programa ao sujeito: caso ele acerte, o programa indica uma resposta correta; caso ele erre, uma resposta negativa; caso ele se ausente, uma mensagem indicando que ele deve tentar responder mais r&aacute;pido.

<!-- conclus&atilde;o para implementa&ccedil;&atilde;o -->
A partir deste entendimento, podemos escrever um pseudo-c&oacute;digo para explicar a nossa implementa&ccedil;&atilde;o do SST:

    instrucoes
    para n = 1 ate numero_de_vezes
        qual_seta <- aleatorio
        deve_apertar? <- aleatorio
        ha_resposta <- nao

        mostrar intervalo
        mostrar qual_seta

        enquanto (no ha_resposta) ou (dentro do limite de tempo)
            se nao deve_apertar?
                mostrar som quando for o tempo do SSD
            fim se
            ha_resposta <- checar por resposta
        fim enquanto

        se (houve resposta) e (nao deve_apertar?)
            SSD <- SSD - passo
        senao
            SSD <- SSD + passo
        fim se

        mostrar resposta do programa
    fim para

<!-- conclus&atilde;o para o processamento -->
Ap&oacute;s cada aplica&ccedil;&atilde;o do teste, processamos as medidas geradas pelo indiv&iacute;duo usando a equa&ccedil;&atilde;o do SST `SSRT = RT - SSD`. As medidas de interesse foram o tempo de rea&ccedil;&atilde;o m&eacute;dio `<RT>`; o _delay_ m&eacute;dio `<SSD>` do est&iacute;mulo sonoro; a porcentagem de inibi&ccedil;&atilde;o `<%I>`; e a porcentagem de aus&ecirc;ncias `<%A>`. Calculamos `<RT>` como sendo a soma de todos os `RT` dividida pelo n&uacute;mero de total de rea&ccedil;&otilde;es, ou seja, n&atilde;o levamos as aus&ecirc;ncias em conta. `<SSD>` foi calculado como sendo o valor m&eacute;dio de todos os `SSD` apresentados ao longo do teste. `<%I>` &eacute; obtido como sendo o n&uacute;mero de vezes que o sujeito conseguiu inibir a a&ccedil;&atilde;o divido pelo n&uacute;mero total de apresenta&ccedil;&otilde;es do est&iacute;mulo para inibi&ccedil;&atilde;o. `<%A>` foi calculado como sendo o n&uacute;mero de vezes que o sujeito deixou de responder quando ele deveria dividido pelo n&uacute;mero total de apresenta&ccedil;&otilde;es sem o sinal de parada.

Com um n&uacute;mero suficientemente grande de sujeitos colaborando com o teste, podemos um estimar um `SSRT` coletivo, calculando a diferen&ccedil;a entre a m&eacute;dia de todos os `<RT>` e a m&eacute;dia de todos os `<SSD>`.

<!-- finalmente... -->
Desta forma, podemos finalmente come&ccedil;ar a implemetar o SST. A ferramenta de escolha foi o software E-prime, por j&aacute; ser utilizado em testes psicol&oacute;gicos. As imagens foram geradas usando o software Processing; o som, usando o software Pure Data. Os dados foram processados usando programas pr&oacute;prios do laborat&oacute;rio. Todo o c&oacute;digo-fonte pode ser acessado no endere&ccedil;o web [](https://github.com/ishiikurisu/EEG/SST).

Implementa&ccedil;&atilde;o
-------------

<!-- aprendendo basic no e-prime. concep&ccedil;&atilde;o da arte. concep&ccedil;&atilde;o do som. processamento dos dados. -->
O pacote de programas _E-prime_ nos permite criar experimentos psicol&oacute;gicos com imagens; sons; e v&iacute;deos, com facilidades para medidas nos tempos de rea&ccedil;&atilde;o e exposi&ccedil;&atilde;o. O software _E-Studio_ possibilita ao usu&aacute;rio o uso destas ferramentas para a confec&ccedil;&atilde;o do teste, que, quando compilado, gera um _script_ em _Basic_, que ser&aacute; interpretado pelo _E-run_. Ap&oacute;s a execu&ccedil;&atilde;o do teste, o programa gera um arquivo, que pode ser traduzido para o formato `csv`, o qual usamos para poder analisar os dados por meio de programas escritos em C++ e em Java.

Para podermos organizar melhor o nosso c&oacute;digo-fonte, divimos o _loop_ principal do programa em dois procedimentos: o `PressProc`, que cont&eacute;m uma itera&ccedil;&atilde;o em que o sujeito deve responder a um est&iacute;mulo; e o `NotPressProc`, que consiste de uma repeti&ccedil;&atilde;o em que h&aacute; um sinal de parada indicando que o sujeito n&atilde;o deve apertar nenhum bot&atilde;o. Al&eacute;m disso, definimos uma vari&aacute;vel global para indicar qual a dura&ccedil;&atilde;o do `SSD` em uma dada itera&ccedil;&atilde;o. Essa vari&aacute;vel sempre come&ccedil;a o programa com o valor de 250ms.

O `PressProc` &eacute; executado em tr&ecirc;s passos:

+ mostrar uma tela vazia por 1000ms;
+ mostrar a seta enquanto o usu&aacute;rio n&atilde;o responde ou enquanto n&atilde;o se passar do tempo m&aacute;ximo;
+ mostrar o resultado da itera&ccedil;&atilde;o para o sujeito por 1000ms.

Definimos como par&acirc;metros do procedimento o caminho para a seta escolhida; e qual a tecla que corresponde &agrave; resposta correta. Caso o usu&aacute;rio responda corretamente, &eacute; lhe mostrado um s&iacute;mbolo de correto; em caso negativo, &eacute; lhe mostrado um `X` vermelho; caso ele se ausente, aparece uma mensagem na tela. Ap&oacute;s cada itera&ccedil;&atilde;o, o _script_ atualiza o arquivo de dados que cont&eacute;m as medidas realizadas pelo programa. Neste caso, optamos por verificar se houve ou n&atilde;o uma aus&ecirc;ncia por parte o sujeito; e, caso ele tenha respondido, medimos o seu tempo de rea&ccedil;&atilde;o.

Embora similar, o `NotPressProc` possui um passo a mais, e sua l&oacute;gica muda um pouco na hora de mostrar o resultado para o sujeito:

+ mostrar uma tela vazia por 1000ms;
+ mostrar a seta enquanto o usu&aacute;rio n&atilde;o responde ou enquanto n&atilde;o se passar do tempo m&aacute;ximo;
+ mostrar o sinal sonoro ap&oacute;s um tempo correspondente ao `SSD` atual;
+ mostrar o resultado da itera&ccedil;&atilde;o ao sujeito por 1000ms.

O &uacute;nico par&acirc;metro deste procedimento &eacute; o caminho para a imagem da seta escolhida, j&aacute; que &eacute; esperado que o sujeito iniba a a&ccedil;&atilde;o independe da dire&ccedil;&atilde;o da seta. Se ele responder, o teste devolve uma corre&ccedil;&atilde;o negativa; caso contr&aacute;rio, o ele mostra o s&iacute;mbolo de correto designado. O procedimento, por fim, atualiza o valor do `SSD` para a pr&oacute;xima itera&ccedil;&atilde;o em que for necess&aacute;rio inibir; adiciona ao arquivo com os resultados se houve inibi&ccedil;&atilde;o ou n&atilde;o, e qual a dura&ccedil;&atilde;o do `SSD` naquela repeti&ccedil;&atilde;o.

Estes procedimentos foram colocados em outros dois procedimentos maiores: a pr&aacute;tica e o experimento em si. Ambos s&atilde;o listas que cont&eacute;m 32 e 128 itens, respectivamente, populadadas com 3/4 de seus itens com `PressProc` e 1/4 de `NotPressProc`. Metade deles possuem setas para a esquerda; e a outra metade, para a direita. O _E-run_ ent&atilde;o gera, para cada execu&ccedil;&atilde;o do teste, uma permuta&ccedil;&atilde;o destas listas para que todos as aplica&ccedil;&atilde;o sigam uma ordem pr&oacute;pria, e com as propor&ccedil;&otilde;es que desejamos.

Finalmente, adicionamos as intru&ccedil;&otilde;es ao come&ccedil;o do teste e uma mensagem de agradecimento ao fim dele.

Adapta&ccedil;&atilde;o do teste para idosos
------------------------------

n&uacute;mero de aus&ecirc;ncias como motiva&ccedil;&atilde;o para (1) tornar o teste mais devagar; e (2) explicar melhor o teste, baseando-se em tutoriais de videogames.

Refer&ecirc;ncias
-----------

+ Criar lista de refer&ecirc;ncias
+ Sim, por favor
