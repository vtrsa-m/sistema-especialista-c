<div align="center">
  <img src="LINK_DA_SUA_IMAGEM_AQUI.png" alt="Logo do Sistema de Triagem" width="500">

  <br><br>

  <img src="https://img.shields.io/badge/LINGUAGEM-C-1565C0?style=for-the-badge">
  <img src="https://img.shields.io/badge/ESTRUTURA-ÁRVORES_BINÁRIAS-E53935?style=for-the-badge">
  <img src="https://img.shields.io/badge/CURSO-NOME_DO_SEU_CURSO-FFB300?style=for-the-badge">
  <br>
  <img src="https://img.shields.io/badge/INSTITUIÇÃO-NOME_DA_FACULDADE-FFFFFF?style=for-the-badge&logoColor=black">
</div>

<br><br>

![Sobre o Projeto](https://img.shields.io/badge/SOBRE_O_PROJETO-4E69FF?style=for-the-badge)
<br>

O **Sistema Especialista de Triagem Médica** é um software interativo desenvolvido inteiramente na linguagem **C**. Inspirado em lógicas de dedução rápida (como o Akinator), o programa atua como um sistema de triagem hospitalar. Ao iniciar, o sistema guiará o usuário através de perguntas de "Sim" ou "Não" sobre sintomas para tentar deduzir a doença provável do paciente.

A inteligência por trás do sistema é baseada em uma **Árvore Binária de Decisão**. O projeto foi estruturado com um algoritmo guloso dinâmico, onde cada nó interno representa a melhor pergunta diagnóstica a ser feita (aquela que elimina 50% das doenças restantes) e as folhas representam os diagnósticos finais.

Este projeto foi desenvolvido como requisito acadêmico para a disciplina de **[Nome da Matéria]**, sob a orientação do docente **[Nome do Professor]**.

<br>

![Tecnologias Utilizadas](https://img.shields.io/badge/TECNOLOGIAS_UTILIZADAS-FF1E1E?style=for-the-badge)
<br>

`Código`
* **Linguagem:** C padrão (`<stdio.h>`, `<stdlib.h>`, `<string.h>`).
* **Estruturas de Dados:** Árvores Binárias de Decisão, Structs Otimizados, Ponteiros e Alocação Dinâmica de Memória.
* **Lógica do Sistema:** Algoritmo matemático para cálculo de eficiência de perguntas e Recursividade.
* **Ambiente de Desenvolvimento:** GCC (GNU Compiler Collection).

`Interface Gráfica`
* **Interface Gráfica:** Raylib (biblioteca em C utilizada para a renderização visual, layout e interações do usuário).

<br>

![Como Executar](https://img.shields.io/badge/COMO_EXECUTAR-FFC000?style=for-the-badge)
<br>

`Pré-requisitos`

Ter o compilador `gcc` e a ferramenta `git` instalados no seu sistema (ambientes Linux/Debian).

`Como Instalar as Dependências`

```bash
sudo apt update
sudo apt install build-essential git
sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev
