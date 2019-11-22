#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Biblioteca que permite usar os caracteres em pt-br
#include <math.h>

// Vari�veis
float icms, pis, cofins, tarifa, consumo_total_setor, consumo_total, valor_total_setor, valor_total;
float pt_arc, qtshrs_arc, consumo_arc; // Se��o Arcondicionados
float pt_comp, qtshrs_comp, consumo_comp; // Se��o Computador
float pt_gela, qtshrs_gela, consumo_gela; // Se��o geladeira
float pt_lamp, qtshrs_lamp, consumo_lamp; // Se��o Lampada
float pt_tv, qtshrs_tv, consumo_tv; // Se��o TV
float val_arc, val_comp, val_gela, val_lamp, val_tv; //Vari�veis de valores
float icms_real, pis_real, cofins_real, valor_total_real;
char nomedosetor[50]; // Nome do setor
int qts_comp, qts_arc, qts_gela, dias_comp, dias_arc, dias_gela, qts_lamp, dias_lamp, qts_tv, dias_tv, i; // �rea de quantidadem dias dos equipamentos



/*Legenda*/
    // qts =  quantidade total
    // pt = pot�ncia
    // qtshrs = quantidade de horas
    // val = valores

//Fun��o Principal
int main (){
    icms = 0.27;
    pis = 0.0165;
    cofins = 0.0761;

    // Com a inser��o desse comando, os valores reais ser�o representados agora com v�gula
    setlocale(LC_ALL, "portuguese");

    printf("---------------------------------------------------------- \n");
    printf("Seja bem vindo ao simulador \n");
    printf("---------------------------------------------------------- \n");
    printf("Informe o pre�o da Tarifa Residencial de Baixa Tens�o: \n");
    scanf("%f", &tarifa);

    /* printf("Informe o nome do setor:  \n");
    scanf("%s", &nomedosetor); */

    do {
        printf("Digite a quantidade de arcondicionados \n");
        scanf("%d", &qts_arc);

        if (qts_arc > 0){
            printf("Digite as seguintes informa��es \n");
            printf("Os dados s�o no m�s respectivamente \n");
            printf("Pot�ncia \n");
            scanf("%f", &pt_arc);
            printf("Quantidade de Horas \n");
            scanf("%f", &qtshrs_arc);
            printf("Quantidade de dias \n");
            scanf("%d", &dias_arc);

            consumo_arc = (((qtshrs_arc*dias_arc)*pt_arc)*qts_arc)/1000;
            // OS CONSUMOS SER�O DIVIDOS POR 1000 PARA FAZER A CONVERS�O DE WATTS PARA KW
        }


        printf("Digite a quantidade de computadores \n");
        scanf("%d", &qts_comp);

        if (qts_comp > 0){
            printf("Digite as seguintes informa��es \n");
            printf("Os dados s�o no m�s respectivamente \n");
            printf("Pot�ncia \n");
            scanf("%f", &pt_comp);
            printf("Quantidade de Horas \n");
            scanf("%f", &qtshrs_comp);
            printf("Quantidade de dias \n");
            scanf("%d", &dias_comp);

            consumo_comp = (((qtshrs_comp*dias_comp)*pt_comp)*qts_comp)/1000;
        }

        printf("Digite a quantidade de geladeiras \n");
        scanf("%d", &qts_gela);

        if (qts_gela > 0){
            printf("Digite as seguintes informa��es \n");
            printf("Os dados s�o no m�s respectivamente \n");
            printf("Pot�ncia \n");
            scanf("%f", &pt_gela);
            printf("Quantidade de Horas \n");
            scanf("%f", &qtshrs_gela);
            printf("Quantidade de dias \n");
            scanf("%d", &dias_gela);

            consumo_gela = (((qtshrs_gela*dias_gela)*pt_gela)*qts_gela)/1000;
        }

        printf("Digite a quantidade de lampadas\n");
        scanf("%d", &qts_lamp);

        if (qts_lamp > 0){
            printf("Digite as seguintes informa��es \n");
            printf("Os dados s�o no m�s respectivamente \n");
            printf("Pot�ncia \n");
            scanf("%f", &pt_lamp);
            printf("Quantidade de Horas \n");
            scanf("%f", &qtshrs_lamp);
            printf("Quantidade de dias \n");
            scanf("%d", &dias_lamp);

            consumo_lamp = (((qtshrs_lamp*dias_lamp)*pt_lamp)*qts_lamp)/1000;
        }

        printf("Digite a quantidade de TVS \n");
        scanf("%d", &qts_tv);

        if (qts_tv > 0){
            printf("Digite as seguintes informa��es \n");
            printf("Os dados s�o no m�s respectivamente \n");
            printf("Pot�ncia \n");
            scanf("%f", &pt_tv);
            printf("Quantidade de Horas \n");
            scanf("%f", &qtshrs_tv);
            printf("Quantidade de dias \n");
            scanf("%d", &dias_tv);

            consumo_tv = (((qtshrs_tv*dias_tv)*pt_tv)*qts_tv)/1000;


        }

        // Se��o de valores
        val_arc = consumo_arc*tarifa;
        val_comp = consumo_comp*tarifa;
        val_gela = consumo_gela*tarifa;
        val_lamp = consumo_lamp*tarifa;
        val_tv = consumo_tv*tarifa;


        consumo_total_setor = consumo_arc + consumo_comp + consumo_gela + consumo_lamp + consumo_tv;
        valor_total_setor = val_arc + val_comp + val_gela + val_lamp + val_tv;

        consumo_total += consumo_total_setor;
        valor_total += valor_total_setor;

        // Valor parcial
        printf("SETOR:\n");
        printf("O valor total gasto no setor foi %.2f R$ \n", valor_total_setor);
        printf("O consumo total no setor foi %.2f KWH \n", consumo_total_setor);


        printf("ATEN��O! \n");
        printf("Voc� deseja calcular outro setor? \n");
        printf("[1] para sim e [0] para n�o\n");
        scanf("%d", &i);

    } while (i != 0);


        icms_real = valor_total*icms;
        pis_real = valor_total*pis;
        cofins_real = valor_total*cofins;

        // Valor total
        valor_total_real = valor_total + icms_real + pis_real + cofins_real;
        printf("O valor total com a adi��o das taxas ICMS, PIS, COFINS � %.2f R$ \n", valor_total_real);
        printf("O Consumo total foi de %.2f KWH \n", consumo_total);

        system("pause");




    return 0;
}


