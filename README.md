<div align="center">
  <br>
  <img src="https://img.shields.io/badge/Linguagem-C-1565C0?style=for-the-badge&logo=c">
  <img src="https://img.shields.io/badge/Estrutura-Árvores_Dinâmicas-E53935?style=for-the-badge">
  <img src="https://img.shields.io/badge/Interface-Raylib-4E69FF?style=for-the-badge">
  <br>
  <img src="https://img.shields.io/badge/Curso-Engenharia_de_Computação-FFB300?style=for-the-badge">
  <img src="https://img.shields.io/badge/Instituição-IFMS-FFFFFF?style=for-the-badge&logoColor=black">
</div>

<br>

# 🏥 Triagem Inteligente: Sistema Especialista Hospitalar

Este projeto é um software interativo desenvolvido como requisito acadêmico para o curso de **Engenharia de Computação** do **IFMS**. O sistema utiliza lógica de inteligência artificial para realizar triagens médicas preliminares através de uma interface gráfica amigável.

## 📌 Sobre o Projeto

Este software não utiliza um questionário fixo (escrito à mão). Em vez disso, ele possui um **Motor de Inferência Dinâmico**. A partir de uma Base de Conhecimento (um "banco de dados" de doenças e seus respectivos sintomas), o algoritmo calcula matematicamente qual é a melhor pergunta a ser feita a cada etapa, construindo uma **Árvore de Decisão** em tempo real.

## 🧠 Como Funciona o Algoritmo?

O diferencial deste software é a construção **dinâmica** da árvore de decisão:
1. **Análise de Dados:** O sistema lê todas as doenças e sintomas disponíveis.
2. **Cálculo de Eficiência:** Para cada pergunta, o algoritmo calcula quantas doenças seriam eliminadas.
3. **Divisão Ótima:** Ele escolhe sempre a pergunta que divide a lista de doenças o mais próximo possível de 50%, garantindo que o diagnóstico seja encontrado no menor número de passos possível.

## 🚀 Tecnologias Utilizadas

* **Linguagem C:** Para o processamento lógico e gerenciamento de memória.
* **Biblioteca Raylib:** Para a criação da interface visual e detecção de interações.
* **Árvores Binárias:** Estrutura de dados principal para a navegação lógica.
* **Automação (Makefile):** Script inteligente multiplataforma para detecção de SO, compilação e execução automatizadas.


## ⚙️ Preparando o Ambiente (Dependências)

Para compilar e testar o código, é necessário ter o compilador GCC e a biblioteca Raylib configurados.

### 🐧 No Linux (Mint / Ubuntu / Debian)
O projeto conta com um script automatizado. Abra o terminal na pasta do projeto e digite:
```bash
make setup
```
*(Este comando instalará automaticamente todas as dependências gráficas e de compilação necessárias via `apt`).*

### 🪟 No Windows
Utilizamos a versão da Raylib que já vem com o compilador embutido para evitar conflitos de arquitetura:
1. Acesse a página de [Releases da Raylib](https://github.com/raysan5/raylib/releases).
2. Baixe a versão `w64devkit` (MinGW).
3. Extraia a pasta rigorosamente no diretório `C:\raylib\`.
4. Abra o terminal `w64devkit.exe` que está dentro dessa pasta para compilar o projeto.

---

## 🛠️ Como Compilar e Executar

Esqueça os comandos gigantes do GCC. Este projeto possui um `Makefile` inteligente que detecta automaticamente se você está no Windows ou no Linux e aplica as regras corretas de compilação!

Abra o terminal na pasta do projeto e utilize um dos comandos abaixo:

| Comando | O que faz |
| :--- | :--- |
| `make` | Apenas compila o código fonte gerando o executável (`.exe` no Windows ou binário no Linux). |
| `make run` | **(Recomendado)** Compila o projeto e inicia a interface gráfica imediatamente. |
| `make clean` | Apaga os arquivos compilados antigos para limpar a pasta do projeto. |

*(Nota: Certifique-se de que o arquivo `arial.ttf` está sempre na mesma pasta que o código fonte).*

---

## 👨‍💻 Autores
* **Vitor Amâncio** - Engenharia de Computação
* **Pablo Felipe** - Engenharia de Computação
* **Bruno Brito** - Engenharia de Computação
