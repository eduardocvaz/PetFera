# Projeto - Loja de Animais PetFera
Projeto da turma 02 de Linguagem de Programação 1 \
Sistema de cadastro de animais e profissionais responsáveis em uma loja de animais.
Nesse sistema é possível manipular todo o cadastro e filtros de animais segundo suas classes e algumas características específicas, assim como para seus profissionais responsáveis na loja.

## Grupo:
Silvestre Estalonge

## Alunos:
Dawerton Eduardo Carlos Vaz \
Leandro Silva Ferreira Junior

## Resumo
- Um fato comentado pelo professor durante a correção da versão 1.0 era sobre o uso de classes abstratas, onde em nosso programa apenas a classe "Animal" é abstrata, sendo possível instanciar um objeto do tipo "Ave", por exemplo. \
  Isso foi proposital, pois de acordo com nossa abstração, no exemplo, isso indica que o objeto é uma Ave Doméstica, por não ser nativa e nem silvestre. Isso vale para todas as classes que herdam diretamente da classe Animal.
  

- Encontramos um pouco de dificuldade ao trabalhar com casting de ponteiros, ponteiros inteligentes e com as notações para impressão no terminal. Isso demandou uma atenção especial na implementação. 


- No geral ficamos satisfeitos com o resultado do projeto.


- Tivemos problemas com o funcionamento da função de pausar a tela (usando sistema linux), por isso a sua chamada está comentada. Isso afeta a qualidade da interface durante a execução, mas no MacOS é possível que funcione normalmente se descomentada.

> Versão 2.0
> - Persistência de informações em arquivos .csv para os profissionais e para os animais ao final da execução.
> - Leitura de dados dos mesmos arquivos .csv e instanciamento dos objetos a partir desses dados no início da execução.
> - Uso de ponteiros inteligentes.
> - Correção de bug para voltar ao menu principal durante a listagem de animais por classe.
> - Correção do Makefile para criar a pasta "bin" caso não exista. 
> - Melhorias na interface.

> Versão 1.0
> - Cadastro de um novo animal a ser comercializado. 
> - Remoção de um animal da lista de disponíveis após a sua comercialização. 
> - Alteração dos dados cadastrais de um animal. 
> - Listagem dos dados cadastrais de um determinado animal ou de uma classe de animais. 
> - Listagem de animais sob a responsabilidade de um determinado veterinário ou tratador. 
> - Todas as atividades relacionadas ao cadastro (Inserção, Alteração, Remoção e Consulta) de veterinários e tratadores. 

## Vídeo Explicativo
> Versão 2.0
> https://youtu.be/D_JK3oYjOjI \

> Versão 1.0
> https://youtu.be/Q1BWgalnNpg 

## Documentação
https://eduardocvaz.github.io/PetFera/index.html

## Instruções

- Abrir o terminal dentro da pasta raiz do programa.
- Após a instalação, execute o programa.
- Ao executá-lo, o menu principal será exibido contendo as funcionalidades descritas.
- O comando "x" retorna para o menu principal durante qualquer momento da execução.



## Instalação e Compilação
Clone o repositório, abra o terminal dentro da raiz do projeto e execute o comando make:

> $ git clone https://github.com/eduardocvaz/Projeto-PARTE-I \
> $ make 

## Execução

> $ ./bin/petfera

## Limpar Compilação

> $ make clean
