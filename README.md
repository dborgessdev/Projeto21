Visão Geral
O Projeto 21 monitora a qualidade do ar em áreas urbanas, analisando NO₂, CO₂ e PM₁₀ por zona (sigla de estado) e horário, exibindo alertas e gráficos ASCII e sugerindo ações mitigatórias.

1. Objetivos e Escopo
Problema: Emissões de veículos e indústrias elevam poluentes na cidade.

Solução: Ferramenta CLI em C para:

Capturar sigla de estado (2 caracteres) e hora (0–23).

Ler valores de PM₁₀, NO₂ e CO₂ (floats ≥ 0).

Classificar níveis (normal/amarelo/vermelho) e gerar gráficos de barras.

Propor medidas como incentivo ao transporte limpo e expansão de áreas verdes.

2. Especificações Funcionais
Entrada: scanf para sigla, hora e três floats; validação com while.

Decisão: switch para sigla; if/else para alertas.

Gráficos: laço while para desenhar até 30 blocos proporcionalmente.

Loop geral: do…while que repete a análise se o usuário confirmar.

3. Requisitos Não Funcionais
Portabilidade: C padrão, compila em Linux/Windows.

Simplicidade: único ponto de entrada (main()), sem dependências.

Extensibilidade: pronto para WebAssembly/CGI em futura versão.

4. Estrutura de Pastas
bash
Copiar
Editar
Projeto21/
├── Projeto21.c        # Código fonte
├── build/             # Binários e objetos
└── README.md          # Esta documentação
5. Instruções de Uso
Compilar: gcc -o monitor Projeto21.c

Executar: ./monitor

Interagir: insira sigla, hora e valores; visualize resultados e repita conforme desejado.
