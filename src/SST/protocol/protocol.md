Implementação do SST
====================

<!-- Assumindo uma explicação do teste, das medições realizadas e do porque realizá-las. -->

Notação
-------

Vamos denotar `<M>` como a média aritmética da medida `M`.

Concepção
---------

<!-- introdução -->
Para podermos implementar o SST, inicialmente fizemos um algoritmo do teste nos baseando em suas descrições encontradas na literatura.<!-- Citar descrições? --> A dizer, ele consiste em um laço de repetição: por um número fixo de vezes, deve ser apresentado ao sujeito dois estímulos visuais diferentes. Quando lhe aparecer estas imagens, o sujeito pode ou não ser estimulado com um sinal sonoro. Se o sinal sonoro aparecer, o sujeito não deve reagir. Caso contrário, ele deve responder como lhe for especificado. Os estimulos visuais devem ser apresentados em igual proporção e até que (1) o usuário responda; ou que (2) passe do tempo máximo permitido. Já o sinal sonoro deve ser apresentado em uma parcela menor de vezes. No nosso caso, decidimos que

+ os estímulos visuais seriam setas apontando para a direita e para a esquerda, para que o sujeito pudesse responder usando as teclas do teclado de um computador em no máximo 1000ms.
+ som seria apresentado em somente 25% das vezes<!-- Citar porque 25%? -->.

<!-- lidando com tempo -->
Como o intuito do teste é medir o tempo de demora para que uma pessoa iniba uma ação já iniciada, o sinal sonoro deve ser apresentado depois das setas. Definiremos o tempo entre a apresentação das setas e a do som como `SSD` (_stop signal delay_). A fim de estimar o tempo limítrofe entre o sujeito conseguir inibir ou não, o teste varia o `SSD` de acordo com o desempenho do sujeito: em caso de acerto, isto é, caso ele consiga inibir sua resposta, tornaremos o teste mais difícil aumentando o `SSD` em um valor fixo, que chamaremos de _passo_. Senão, subtraímos um passo do `SSD`, fazendo com que o sinal sonoro seja apresentado mais perto do sinal visual. Com esta perspectiva, devemos definir:

+ SSD inicial;
+ SSD mínimo;
+ SSD máximo;
+ Passo.

<!-- equação do ssrt, # de vezes -->
A partir da equação do `SSRT`, vamos abrir mão da estatística para podermos definir, por amostragem, qual o `SSRT` do sujeito. Assumindo<!-- citar porque podemos assumir isso --> que o `SSRT` obedece a uma distribuição normal em torno de um valor médio, que é o que queremos medir, temos que os parâmetros que tangem o SSD e o passo devem ser ajustados para podermos amostrar bem a faixa em torno do valor desejado. Da literatura, observamos que o laço principal do teste deve se repetir por cerca de 128 vezes, resultando em uma duração confortável para o sujeito e em um número de respostas grande o suficiente para podermos aferir o SSD médio. Assim, optamos pelos seguintes parâmetros de tempo para o teste:

+ SSD inicial: 250ms, no nosso caso;
+ SSD minimo: 0ms, ou seja, o sinal pode aparecer junto com as setas, se for necessário;
+ SSD máximo: 750ms, por ser 75% do tempo máximo;
+ Passo: 50ms.

<!-- considerações com o sujeito -->
Para que o sujeito pudesse realizar o teste com sucesso, adicionamos ao começo do teste uma parte de instrução e outra de treino. Originalmente, concebemos as instruções como um breve texto explicativo, indicando o que o sujeito deveria fazer. A etapa de treinos, por sua vez, foi planejada para ser uma versão menor do teste, em que o `SSD` não se altera e em que há menos repetições, cerca de 25% do teste original.

Além disso, adicionamos à cada iteração do laço principal uma resposta do programa ao sujeito: caso ele acerte, o programa indica uma resposta correta; caso ele erre, uma resposta negativa; caso ele se ausente, uma mensagem indicando que ele deve tentar responder mais rápido.

<!-- conclusão para implementação -->
A partir deste entendimento, podemos escrever um pseudo-código para explicar a nossa implementação do SST:

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

<!-- conclusão para o processamento -->
Após cada aplicação do teste, processamos as medidas geradas pelo individuo usando a equação do SST: `SSRT = RT - SSD`. As medidas de interesse foram o tempo de reação médio `<RT>`; o _delay_ médio `<SSD>` do estimulo sonoro; a porcentagem de inibição `<%I>`; e a porcentagem de ausências `<%A>`. Calculamos `<RT>` como sendo a soma de todos os `RT` dividida pelo número de total de reações, ou seja, não levamos as ausências em conta. `<SSD>` foi calculado como sendo o valor médio de todos os `SSD` apresentados ao longo do teste. `<%I>` é obtido como sendo o número de vezes que o sujeito conseguiu inibir a ação divido pelo número total de apresentações do estímulo para inibição. `<%A>` foi calculado como sendo o número de vezes que o sujeito deixou de responder quando ele deveria dividido pelo número total de apresentações sem o sinal de parada.

Com um número suficientemente grande de sujeitos colaborando com o teste, podemos um estimar um `SSRT` coletivo, calculando a diferença entre a média de todos os `<RT>` e a média de todos os `<SSD>`.

<!-- finalmente... -->
Desta forma, podemos finalmente começar a implemetar o SST. A ferramenta de escolha foi o software _E-prime_, por já ser utilizado em testes psicológicos. As imagens foram geradas usando o software _Processing_; o som, usando o software _Pure Data_. Os dados foram processados usando programas próprios do laboratório. Todo o código-fonte pode ser acessado no endereço web [](https://github.com/ishiikurisu/EEG/SST).

Implementação
-------------

<!-- aprendendo basic no e-prime. concepção da arte. concepção do som. processamento dos dados. -->
O pacote de programas _E-prime_ nos permite criar experimentos psicológicos com imagens; sons; e videos, com facilidades para medidas nos tempos de reação e exposição. O software _E-Studio_ possibilita ao usuário o uso destas ferramentas para a confecção do teste, que, quando compilado, gera um _script_ em _Basic_, que será interpretado pelo _E-run_. Após a execução do teste, o programa gera um arquivo, que pode ser traduzido para o formato `csv`, o qual usamos para poder analisar os dados por meio de programas escritos em C++ e em Java.

Para podermos organizar melhor o nosso código-fonte, divimos o _loop_ principal do programa em dois procedimentos: o `PressProc`, que contém uma iteração em que o sujeito deve responder a um estimulo; e o `NotPressProc`, que consiste de uma repetição em que há um sinal de parada indicando que o sujeito não deve apertar nenhum botão. Além disso, definimos uma variável global para indicar qual a duração do `SSD` em uma dada iteração. Essa variável sempre começa o programa com o valor de 250ms.

O `PressProc` é executado em três passos:

+ mostrar uma tela vazia por 1000ms;
+ mostrar a seta enquanto o usuário não responde ou enquanto não se passar do tempo máximo;
+ mostrar o resultado da iteração para o sujeito por 1000ms.

Definimos como parâmetros do procedimento o caminho para a seta escolhida; e qual a tecla que corresponde à resposta correta. Caso o usuário responda corretamente, é lhe mostrado um simbolo de correto <!-- um 'V verde'-->; em caso negativo, um `X` vermelho; caso ele se ausente, aparece uma mensagem na tela. Após cada iteração, o _script_ atualiza o arquivo de dados que contém as medidas realizadas pelo programa. Neste caso, optamos por verificar se houve ou não uma ausência por parte o sujeito; e, caso ele tenha respondido, medimos o seu tempo de reação.

Embora similar, o `NotPressProc` possui um passo a mais, e sua lógica muda um pouco no momento de mostrar o resultado para o sujeito:

+ mostrar uma tela vazia por 1000ms;
+ mostrar a seta enquanto o usuário não responde ou enquanto não se passar do tempo máximo;
+ mostrar o sinal sonoro após um tempo correspondente ao `SSD` atual;
+ mostrar o resultado da iteração ao sujeito por 1000ms.

O único parâmetro deste procedimento é o caminho para a imagem da seta escolhida, já que é esperado que o sujeito iniba a ação independe da direção da seta. Se ele responder, o teste devolve uma correção negativa; caso contrário, o ele mostra o simbolo de correto designado. O procedimento, por fim, atualiza o valor do `SSD` para a próxima iteração em que for necessário inibir; adiciona ao arquivo com os resultados se houve inibição ou não, e qual a duração do `SSD` naquela repetição.

Estes procedimentos foram colocados em outros dois procedimentos maiores: a prática e o experimento em si. Ambos são listas que contém 32 e 128 itens, respectivamente, populadadas com 3/4 de seus itens com `PressProc` e 1/4 de `NotPressProc`. Metade deles possuem setas para a esquerda; e a outra metade, para a direita. O _E-run_ então gera, para cada execução do teste, uma permutação destas listas para que todos as aplicação sigam uma ordem própria, e com as proporções que desejamos.

Finalmente, adicionamos as intruções ao começo do teste e uma mensagem de agradecimento ao fim dele.

A arte do teste foi criada de forma a ser o mais claro e conciso possível. As setas foram desenhadas baseando-se na sinalização de rua, usando proporções e formas. Em especial, os ângulos usados nas setas foram os mesmos usados nos símbolos de certo e errado, e eles são equivalentes a `2/(1+sqrt(5))` radianos. A saber, este número é a o inverso da razão áurea, e é muito usado para proporções em produtos.

O sinal sonoro composto para o teste é uma onda senoidal com frequência 750Hz e duração 50ms. Estes valores se repetem em algumas outras implementações, e julgamos que, entre todos os valores comumente empregados para o som, estes se mostraram os mais confortáveis para o sujeito.

Adaptação do teste para idosos
------------------------------

Para testar a implementação inicial do _SST_, aplicamos, a princípio, o protocolo com jovens para podermos procurar por possíveis ajustes a serem feitos. A principal adaptação a ser feita no começo foi uma mudança no texto apresentado quando o sujeito não responde a tempo. Muitos se queixaram que a instrução dada contradizia a explicação dada pelo teste, então altermos o texto.

Os resultados preliminares mostraram que nossa implementação do SST estava de acordo com as outras aplicações encontradas na literatura, haja visto que os números que encontramos se encontraram dentro da mesma faixa dos obtidos por outros pesquisadores.

Em seguida, aplicamos o mesmo teste com idosos, e os primeiros resultados já mostraram que seriam necessárias adaptações para que o SST pudesse, de fato, avaliá-los. Isso se mostrou claro quando vimos que a variável `<%A>` estava muito alta, chegando a ser próxima de 80% em alguns casos, mostrando que os sujeitos estavam tendo problemas tão sérios que simplesmente não prosseguiam. Observando-os enquanto realizavam o teste, notamos que os idosos consideravam o teste muito rápido, e que muitos deles esqueciam as instruções durante a execução da tarefa.

Assim, optamos por fazer duas adaptações principais no teste:

+ Aumentamos todas as durações de tempo, para que eles pudessem reagir com mais calma.
+ Mudamos a parte de instrução do teste, a fim de que eles se familiarizassem mais facilmente com o protocolo.

Todas as medidas de tempo, com exceção do passo, foram aumentadas em 50%. Escolhemos este valor pois esperamos, a partir da análise preliminar com os idosos, que o `SSRT` deles seria em torno de 50% maior do que o dos jovens.

A instrução do teste foi expandida e se tornou mais didática: baseando-se em instruções para jogos de videogame com muitos comandos<!-- lembrar citação para este trecho -->, reescrevemos a introdução de tal forma que o sujeito só poderia prosseguir se ele executasse as instruções corretamente. Por exemplo, a primeira instrução dada a ele é a de que, quando lhe aparecer uma seta na tela apontando para a direita, ele deverá apertar a tecla correspondente. Em seguida, aparece uma seta para a direita, e o sujeito só consegue continuar se ele acertar o que é esperado dele.

Estas duas adaptações fizeram com que a `<%A>` diminuísse drasticamente, alcançando a mesma marca que a dos jovens. Ou seja, os idosos passaram a concluir o teste, e a hipótese de que o `SSRT` deles é maior está se mostrando verdadeira.

Referências
-----------

+ Criar lista de referências
+ Sim, por favor
