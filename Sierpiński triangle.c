#include <stdio.h>
//Main
int main()
{
    int x; // Variável que irá servir para comparação de bits e contadora
    int y; // Variável que irá servir para comparação de bits e contadora
    int i; // Variável contadora
    int tam; // Variável que irá receber a proporção do triângulo digitada pelo usuário

    printf("Digite a proporcao do triangulo: "); // Imrpime na tela a mensagem
    scanf("%d", &tam); // Atribui o valor digitado pelo usuário na variável tamanho

    // Temos aqui um deslocamento de bits para a esquerda
    // A variável tam está recebendo o valor 1, ou seja os bits de 0001
    // e a mesma variável está deslocando os bits para a esquerda
    // Deslocamentos de bits a esquerda pega o valor antes da operação "<<"
    // pegam ele como potência
    // por exemplo, se tam for = 2, quando os bits de 1 forem deslocados para esquerda
    // tam irá valer 4
    // No relatório é explicado por que o bit utilzado é o do numero 1(0001)
    tam = 1 << tam;

    // Laço que irá efetuar os testes e impressão do triângulo de sierpinski
    // A variável y recebe tam -1, para entrar no último laço
    for(y=tam-1;y>=0;y--)
    {
        // Utilizado o comando putchar, pois ele apenas escreve no stdout(tela) o caracter,
        // no caso quebra de linha
        putchar('\n');
        // Este laço serve para contar os espaços e montar o triângulo
        for(i=0;i<y;i++)
        {
            // Utilizado o comando putchar, pois ele apenas escreve no stdout(tela) o caracter,
            // no caso um espaço
            putchar(' ');
        }
        // Laço que irá testar ser efetaudo enquanto o valor x+y for menor que tam
        // Utilizando o exemplo anterior, supondo que tamanho valha 4
        // Na primeira linha do triângulo ele ele vai ser x+y ou seja, 0+3=3
        // 3 é menor que 4 então entra no laço
        // Esse +y pode ser retirado, porém é feito mais testes sem necessidade
        for(x=0;x+y<tam;x++)
        {
            // Esta é a parte onde a mágica acontece
            // Continuando com o exemplo anterior, y vale 3
            // Dentro do printf estamos utilizando uma operação entre bits
            // o operador &(AND)
            // E usando a condição ternária
            // Que basicamente faz o seguinte, se a comparação entre os bits de x e y
            // ou seja (0000&0011) isso é 0
            // e caso for 0 ele imprime um asterisco e um espaço
            // quando a comparação der algo diferente de 0
            // no caso for 1 ele imprime dois espaços
            printf((x & y) ? "  " : "* ");
        }
    }
}
