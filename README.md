Projeto 21
Sistema de Monitoramento de Qualidade do Ar em Áreas Urbanas

Um utilitário de linha de comando em C para capturar e analisar dados de poluentes (NO₂, CO₂, PM₁₀) por região e horário, exibindo alertas, gráficos ASCII e sugestões de ação.

1. 🔭 Objetivos e Escopo
Problema
Emissões de veículos e indústrias elevam os níveis de poluentes em áreas urbanas, afetando a saúde pública.

Solução
Ferramenta em C que:

• Coleta dados sobre poluentes atmosféricos (NO₂, CO₂, PM10) 
    Captura sigla de estado (2 letras) e hora da coleta (0–23).
    Lê valores de PM₁₀, NO₂ e CO₂ (floats ≥ 0).
• Analisa os dados por zonas geográficas e horários 
    Classifica níveis como Normal, Alerta Amarelo ou Alerta Vermelho.
• Exibe gráficos e alertas de poluição
    Gera gráficos de barras ASCII proporcionais.
• Propõe ações para a melhoria da qualidade do ar 
    Sugere medidas mitigatórias (transporte limpo, mais áreas verdes etc.).


2. ⚙️ Especificações Funcionais
  Entrada de dados

  scanf para sigla do estado, hora e três valores float.

  Validação de formato via while.

  Decisões

  switch + while para validar sigla de estado.

  if/else para definir alertas de cada poluente.

  Gráficos ASCII

  Laço while para desenhar até 30 blocos (#) proporcionalmente ao valor máximo.

  Fluxo geral

  do…while permite repetir toda a análise conforme resposta do usuário.

3. 📋 Requisitos Não Funcionais

Simplicidade: Único ponto de entrada (main()), sem dependências externas.

4. 📂 Estrutura de Pastas
Projeto21/

├── Projeto21.c        # Código-fonte principal

├── build/             # Binários e objetos gerados

└── README.md          # Documentação do projeto

6. 🚀 Instruções de Uso
 Interagir
#    - Informe a sigla do estado (ex: SP)
#    - Informe a hora (0–23)
#    - Insira os valores de PM10, NO2 e CO2
#    - Veja alertas, gráficos e repita conforme desejar

