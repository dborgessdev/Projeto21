#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Constantes de limite para os poluentes
    const float LIM_PM10_MAX   = 200.0f;
    const float LIM_NO2_MAX    = 200.0f;
    const float LIM_CO2_MAX    = 2000.0f;
    const float AL_PM10_AM     =  80.0f;
    const float AL_PM10_VM     = 150.0f;
    const float AL_NO2_AM      = 100.0f;
    const float AL_NO2_VM      = 200.0f;
    const float AL_CO2_ALERTA  = 1000.0f;

    // Variáveis de entrada e controle
    char  e1, e2;
    int   hora;
    float pm10, no2, co2;
    int   blocos, i;
    char  repetir;

    // Loop principal
    do {
        // Validação da sigla do estado (mantido igual)
        printf("> UFRB - Universidade Ferderal do Reconcavo da Bahia\n> (BES) Disciplina de Programação de Computadores\n> Docs.: LEANDRO BRITO SANTOS & IURI SANTOS SOUZA , dsc.:Alando Matheus, Davi Borges.\n> Projeto21 v.1.0\nInforme a sigla do estado (2 letras, ex: SP): ");
        scanf(" %c%c", &e1, &e2);
        int sigla_valida = 0;
        while (!sigla_valida) {
            switch (e1) {
                case 'A':
                    if (e2=='C'|| e2=='L'|| e2=='P'|| e2=='M') sigla_valida = 1;
                    break;
                case 'B': 
                    if (e2=='A'|| e2=='C'|| e2=='A'|| e2=='A') sigla_valida = (e2=='A'); 
                    break;
                case 'C':
                    if (e2=='E'|| e2=='E') sigla_valida = (e2=='E');
                    break;
                case 'D': sigla_valida = (e2=='F'); break;
                case 'E': sigla_valida = (e2=='S'); break;
                case 'G': sigla_valida = (e2=='O'); break;
                case 'M':
                    if (e2=='A'|| e2=='T'|| e2=='S'|| e2=='G') 
                        sigla_valida = (e2=='A'|| e2=='T'|| e2=='S'|| e2=='G');
                    break;
                case 'P':
                    if (e2=='A'|| e2=='B'|| e2=='R'|| e2=='I'|| e2=='E')
                        sigla_valida = (e2=='A'|| e2=='B'|| e2=='R'|| e2=='I'|| e2=='E');
                    break;
                case 'R':
                    if (e2=='J'|| e2=='N'|| e2=='S'|| e2=='O')
                        sigla_valida = (e2=='J'|| e2=='N'|| e2=='S'|| e2=='O');
                    break;
                case 'S': sigla_valida = (e2=='C'|| e2=='P'|| e2=='E'); break;
                case 'T': sigla_valida = (e2=='O'); break;
                default: sigla_valida = 0;
            }
            if (!sigla_valida) {
                printf("Sigla inválida! Digite novamente (ex: RJ): ");
                scanf(" %c%c", &e1, &e2);
            }
        }

        // --- hora da coleta ---
        printf("Informe a hora da coleta (Utilize os valores inteiros de 0–23): ");
        scanf("%d", &hora);
        while (hora < 0 || hora > 23) {
            printf("Hora inválida! Digite novamente (0–23): ");
            scanf("%d", &hora);
        }

        // --- valores de poluentes ---
        printf("Digite PM10 (µg/m³): ");
        scanf("%f", &pm10);
        while (pm10 < 0.0f) {
            printf("Valor inválido! PM10 >= 0: ");
            scanf("%f", &pm10);
        }

        printf("Digite NO2 (µg/m³): ");
        scanf("%f", &no2);
        while (no2 < 0.0f) {
            printf("Valor inválido! NO2 >= 0: ");
            scanf("%f", &no2);
        }

        printf("Digite CO2 (ppm): ");
        scanf("%f", &co2);
        while (co2 < 0.0f) {
            printf("Valor inválido! CO2 >= 0: ");
            scanf("%f", &co2);
        }

        // --------------------------------------------------
        // Relatório e alertas
        // --------------------------------------------------
        printf("\n=== Relatório ===\n");
        printf("Estado: %c%c | Hora: %02d:00\n", e1, e2, hora);

        // PM10
        printf("PM10: %.2f µg/m³ - ", pm10);
        if      (pm10 > AL_PM10_VM) printf("ALERTA VERMELHO\n");
        else if (pm10 > AL_PM10_AM) printf("ALERTA AMARELO\n");
        else                         printf("NORMAL\n");

        // NO2
        printf("NO2 : %.2f µg/m³ - ", no2);
        if      (no2 > AL_NO2_VM)  printf("ALERTA VERMELHO\n");
        else if (no2 > AL_NO2_AM)  printf("ALERTA AMARELO\n");
        else                        printf("NORMAL\n");

        // CO2
        printf("CO2 : %.2f ppm   - ", co2);
        if (co2 > AL_CO2_ALERTA)    printf("PREOCUPANTE\n");
        else                        printf("ADEQUADO\n");

        // --------------------------------------------------
        // Gráficos de barras (até 30 blocos)
        // --------------------------------------------------
        printf("\n=== Gráficos Visuais ===\n");

        // PM10
        blocos = (int)((pm10 / LIM_PM10_MAX) * 30.0f);
        if (blocos > 30) blocos = 30;
        printf("PM10: %6.2f µg/m³ |", pm10);
        i = 0;
        while (i++ < blocos) printf("#");
        printf("\n");

        // NO2
        blocos = (int)((no2 / LIM_NO2_MAX) * 30.0f);
        if (blocos > 30) blocos = 30;
        printf("NO2 : %6.2f µg/m³ |", no2);
        i = 0;
        while (i++ < blocos) printf("#");
        printf("\n");

        // CO2
        blocos = (int)((co2 / LIM_CO2_MAX) * 30.0f);
        if (blocos > 30) blocos = 30;
        printf("CO2 : %6.2f ppm   |", co2);
        i = 0;
        while (i++ < blocos) printf("#");
        printf("\n");

        // ==================================================
        // Sugestões de Ações Mitigatórias
        // ==================================================
        printf("\n=== Sugestões de Ações Mitigatórias ===\n");
        int acoes_necessarias = 0;

        if (pm10 > AL_PM10_AM) {
            printf("- Controle de emissões industriais e umidificação de vias\n");
            acoes_necessarias++;
        }
        if (no2 > AL_NO2_AM) {
            printf("- Inspeção veicular obrigatória e incentivo a bicicletas\n");
            acoes_necessarias++;
        }
        if (co2 > AL_CO2_ALERTA) {
            printf("- Reflorestamento urbano e taxação de combustíveis fósseis\n");
            acoes_necessarias++;
        }

        if (acoes_necessarias == 0) {
            printf("Nenhuma ação urgente requerida. Mantenha o monitoramento.\n");
        }

        // --------------------------------------------------
        // Pergunta de repetição
        // --------------------------------------------------
        printf("\nDeseja realizar nova análise? (S/N): ");
        scanf(" %c", &repetir);
        while (repetir!='S' && repetir!='s' && repetir!='N' && repetir!='n') {
            printf("Opção inválida! Digite S ou N: ");
            scanf(" %c", &repetir);
        }

    } while (repetir=='S' || repetir=='s');

    return 0;
}