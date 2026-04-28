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

Este projeto é um software interativo desenvolvido como requisito acadêmico para o curso de **Engenharia da Computação** do **IFMS**. O sistema utiliza lógica de inteligência artificial para realizar triagens médicas preliminares através de uma interface gráfica amigável.

## 📌 Sobre o Projeto

O programa atua como um "Akinator Médico". Através de uma série de perguntas de "Sim" ou "Não", ele analisa os sintomas relatados pelo usuário para chegar a uma conclusão diagnóstica entre as doenças cadastradas na sua base de conhecimento.

## 🧠 Como Funciona o Algoritmo?

O diferencial deste software é a construção **dinâmica** da árvore de decisão:
1. **Análise de Dados:** O sistema lê todas as doenças e sintomas disponíveis.
2. **Cálculo de Eficiência:** Para cada pergunta, o algoritmo calcula quantas doenças seriam eliminadas.
3. **Divisão Ótima:** Ele escolhe sempre a pergunta que divide a lista de doenças o mais próximo possível de 50%, garantindo que o diagnóstico seja encontrado no menor número de passos possível.

## 🚀 Tecnologias Utilizadas

* **Linguagem C:** Para o processamento lógico e gerenciamento de memória.
* **Biblioteca Raylib:** Para a criação da interface visual e detecção de interações.
* **Árvores Binárias:** Estrutura de dados principal para a navegação lógica.

## ⚙️ Instalação de Dependências (Linux Mint/Ubuntu)

Antes de compilar, você deve instalar as bibliotecas necessárias para o funcionamento da Raylib:

```bash
sudo apt update
sudo apt install build-essential git cmake libasound2-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
```

### 🪟 No Windows (w64devkit)
Para o Windows, utilizamos a versão da Raylib que já vem com o compilador embutido:
1. Acesse a página de [Releases da Raylib no GitHub](https://github.com/raysan5/raylib/releases).
2. Baixe a versão para Windows com MinGW embutido (ex: `raylib-X.X_win64_mingw-w64.zip` ou o instalador `.exe`).
3. Extraia ou instale os arquivos **exatamente** na pasta `C:\raylib\`.
4. Isso garantirá que o compilador e as dependências estejam no local correto.

## 🛠️ Como Compilar e Executar

O projeto foi unificado para funcionar com um único arquivo fonte. Certifique-se de que o arquivo `arial.ttf` está na mesma pasta que o código.

### 🐧 No Linux:
```bash
gcc main.c -o sistema_triagem -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./sistema_triagem
```

### 🪟 No Windows (w64devkit):
```bash
C:\raylib\w64devkit\bin\gcc.exe main.c -o sistema_triagem.exe -B C:\raylib\w64devkit\bin -I C:\raylib\raylib\src -L C:\raylib\raylib\src -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows
```

## 👨‍💻 Autores
* **Vitor Amâncio** - Engenharia de Computação
* **Pablo Felipe** - Engenharia de Computação
* **Bruno Brito** - Engenharia de Computação
