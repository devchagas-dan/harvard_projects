# Roadmap de Aprendizagem curso CS50 Introduction to Computer Science by HarvardX

Olá!! Me chamo Daniela Chagas, concluí o curso CS50 Introduction to Computer Science pela HarvardX University em apenas 6 meses no ano passado. Foi um curso muito intenso, que envolveu muita dedicação e abdicação. Graças a Deus e a ajuda do meu marido, eu consegui concluir o curso com sucesso. Este Roadmap pessoal foi criado para mostrar os projetos que criei como resolução dos problemas. Este Roadmap é somente consulta, mas espero que possa ajudar outros que irão fazer o curso. Amo aprender e ensinar. Estudar TI para mim tem sido maravilhoso, me desafio a cada dia, aprendo com meus erros e me motivo a cada dia a seguir em frente e não desistir. Às vezes, parece que a gente vai conseguir, mas nada como um dia após o outro.

## 🚀 Sobre mim
* **Interesses**: Desenvolvimento de Aplicativos Móveis, Java, Desenvolvimento de Software, Python
* **Nível de experiência**: Iniciante

### Projeto 1 -  mario.c
A ideia do projeto era criar uma escada de hashes na linguagem C, simbolizando a escada que o Mario sobre no jogo Super Mario Bros.

### Projeto 2 - cash.c
**Problema a ser resolvido:**
Suponha que você trabalhe em uma loja e um cliente lhe dê R$ 1,00 (100 centavos) por um doce que custa R$ 0,50 (50 centavos). Você precisará pagar a eles o “troco”, o valor que sobra depois de pagar o custo do doce. Ao fazer o troco, é provável que você queira minimizar o número de moedas que está distribuindo para cada cliente, para não acabar (ou irritar o cliente!). Implementar um programa em C que imprima as moedas mínimas necessárias para fazer um determinado valor de troco, em centavos.

### Projeto 3 - scrabble.c
**Problema a ser resolvido:**
o jogo Scrabble , os jogadores criam palavras para marcar pontos, e o número de pontos é a soma dos valores dos pontos de cada letra da palavra. Implementar um programa em C que determine o vencedor de um jogo curto do tipo Scrabble. Seu programa deve solicitar entrada duas vezes: uma vez para o “Jogador 1” inserir sua palavra e uma vez para o “Jogador 2” inserir sua palavra. Então, dependendo de qual jogador marcar mais pontos, seu programa deverá imprimir “Jogador 1 vence!”, “Jogador 2 vence!” ou “Empate!” (caso os dois jogadores marquem pontos iguais).

### Projeto 4 - readability.c
**Problema a ser resolvido:**
De acordo com a Scholastic , Charlotte's Web , de EB White está entre o nível de leitura da segunda e quarta série, e The Giver, de Lois Lowry , está entre o nível de leitura da oitava e décima segunda série. O que significa, porém, um livro estar em um determinado nível de leitura?
Bem, em muitos casos, um especialista humano pode ler um livro e tomar uma decisão sobre a série (ou seja, o ano escolar) para a qual acha que o livro é mais apropriado. Mas um algoritmo provavelmente também poderia descobrir isso!
Implementar um programa que calcula a nota aproximada necessária para compreender algum texto. Seu programa deve imprimir como saída “Nota X”, onde “X” é a série calculada, arredondada para o número inteiro mais próximo. Se a nota for 16 ou superior (equivalente ou superior a um nível de leitura de graduação sênior), seu programa deverá gerar “Grade 16+” em vez de fornecer o número de índice exato. Se o nível da série for inferior a 1, seu programa deverá gerar “Antes da 1ª série”.

### Projeto 5 - caesar.c
**Problema a ser resolvido:**
Supostamente, Caesar (sim, aquele Caesar) costumava “criptografar” (isto é, ocultar de forma reversível) mensagens confidenciais, deslocando cada letra delas em um certo número de lugares. Por exemplo, ele pode escrever A como B, B como C, C como D, …, e, em ordem alfabética, Z como A. E assim, para dizer OLÁ a alguém, César pode escrever IFMMP. Ao receber tais mensagens de César, os destinatários teriam que “descriptografá-las”, deslocando as letras na direção oposta pelo mesmo número de lugares.
Escreva um programa que permita criptografar mensagens usando a cifra de César. No momento em que o usuário executa o programa, ele deve decidir, fornecendo um argumento de linha de comando, qual deve ser a chave na mensagem secreta que fornecerá em tempo de execução. Não devemos necessariamente presumir que a chave do usuário será um número; embora você possa assumir que, se for um número, será um número inteiro positivo.

### Projeto 6 - substitution.c
**Problema a ser resolvido:**
Numa cifra de substituição, “criptografamos” (ou seja, ocultamos de forma reversível) uma mensagem substituindo cada letra por outra letra. Para isso, utilizamos uma chave : neste caso, um mapeamento de cada uma das letras do alfabeto à letra que deve corresponder quando a criptografamos. Para "descriptografar" a mensagem, o receptor da mensagem precisaria conhecer a chave, para que possa reverter o processo: traduzir o texto criptografado (geralmente chamado de texto cifrado ) de volta na mensagem original (geralmente chamado de texto simples ).

Uma chave, por exemplo, pode ser a string NQXPOMAFTRHLZGECYJIUWSKDVB. Esta chave de 26 caracteres significa que A(a primeira letra do alfabeto) deve ser convertida em N(o primeiro caractere da chave), B(a segunda letra do alfabeto) deve ser convertida em Q(o segundo caractere da chave), e assim por diante.

Uma mensagem como HELLO, então, seria criptografada como FOLLE, substituindo cada uma das letras de acordo com o mapeamento determinado pela chave.
Crie um programa que permita criptografar mensagens usando uma cifra de substituição. No momento em que o usuário executa o programa, ele deve decidir, fornecendo um argumento de linha de comando, qual deve ser a chave na mensagem secreta que fornecerá em tempo de execução.