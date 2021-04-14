#include <stdio.h>
//Main
int main()
{
    int x; // Vari�vel que ir� servir para compara��o de bits e contadora
    int y; // Vari�vel que ir� servir para compara��o de bits e contadora
    int i; // Vari�vel contadora
    int tam; // Vari�vel que ir� receber a propor��o do tri�ngulo digitada pelo usu�rio

    printf("Digite a proporcao do triangulo: "); // Imrpime na tela a mensagem
    scanf("%d", &tam); // Atribui o valor digitado pelo usu�rio na vari�vel tamanho

    // Temos aqui um deslocamento de bits para a esquerda
    // A vari�vel tam est� recebendo o valor 1, ou seja os bits de 0001
    // e a mesma vari�vel est� deslocando os bits para a esquerda
    // Deslocamentos de bits a esquerda pega o valor antes da opera��o "<<"
    // pegam ele como pot�ncia
    // por exemplo, se tam for = 2, quando os bits de 1 forem deslocados para esquerda
    // tam ir� valer 4
    // No relat�rio � explicado por que o bit utilzado � o do numero 1(0001)
    tam = 1 << tam;

    // La�o que ir� efetuar os testes e impress�o do tri�ngulo de sierpinski
    // A vari�vel y recebe tam -1, para entrar no �ltimo la�o
    for(y=tam-1;y>=0;y--)
    {
        // Utilizado o comando putchar, pois ele apenas escreve no stdout(tela) o caracter,
        // no caso quebra de linha
        putchar('\n');
        // Este la�o serve para contar os espa�os e montar o tri�ngulo
        for(i=0;i<y;i++)
        {
            // Utilizado o comando putchar, pois ele apenas escreve no stdout(tela) o caracter,
            // no caso um espa�o
            putchar(' ');
        }
        // La�o que ir� testar ser efetaudo enquanto o valor x+y for menor que tam
        // Utilizando o exemplo anterior, supondo que tamanho valha 4
        // Na primeira linha do tri�ngulo ele ele vai ser x+y ou seja, 0+3=3
        // 3 � menor que 4 ent�o entra no la�o
        // Esse +y pode ser retirado, por�m � feito mais testes sem necessidade
        for(x=0;x+y<tam;x++)
        {
            // Esta � a parte onde a m�gica acontece
            // Continuando com o exemplo anterior, y vale 3
            // Dentro do printf estamos utilizando uma opera��o entre bits
            // o operador &(AND)
            // E usando a condi��o tern�ria
            // Que basicamente faz o seguinte, se a compara��o entre os bits de x e y
            // ou seja (0000&0011) isso � 0
            // e caso for 0 ele imprime um asterisco e um espa�o
            // quando a compara��o der algo diferente de 0
            // no caso for 1 ele imprime dois espa�os
            printf((x & y) ? "  " : "* ");
        }
    }
}
