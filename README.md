***

## 📋 Código do README.md Final (Copie e Cole)

```markdown
<div align="center">
  <img src="LINK_DA_IMAGEM_LOGO_GERADA.png" alt="Logo Triagem Inteligente" width="400">

  <br><br>

  <img src="https://img.shields.io/badge/Linguagem-C-1565C0?style=for-the-badge&logo=c">
  <img src="https://img.shields.io/badge/Estrutura-Árvores_Dinâmicas-E53935?style=for-the-badge">
  <img src="https://img.shields.io/badge/Interface-Raylib-4E69FF?style=for-the-badge">
  <br>
  <img src="https://img.shields.io/badge/Curso-Engenharia_da_Computação-FFB300?style=for-the-badge">
  <img src="https://img.shields.io/badge/Instituição-IFMS-FFFFFF?style=for-the-badge&logoColor=black">
</div>

<br><br>

# 📌 Sobre o Projeto

O **Triagem Inteligente: Sistema Especialista Hospitalar** é um software interativo desenvolvido como parte dos requisitos acadêmicos do curso de **Engenharia da Computação** do **IFMS**. 

O sistema simula uma triagem hospitalar dinâmica, agindo como um oráculo de diagnóstico médico. O programa guia o usuário através de perguntas de "Sim" ou "Não" sobre sintomas específicos para deduzir qual é a doença mais provável do paciente.

<br>

# 🚀 Tecnologias e Conceitos Utilizados

* **Linguagem C:** Padrão ouro para desenvolvimento de sistemas especialistas eficientes.
* **Árvores Binárias de Decisão:** Estrutura de dados fundamental onde cada nó é uma pergunta e cada folha é um diagnóstico final.
* **[Raylib](https://www.raylib.com/):** Biblioteca gráfica leve e poderosa utilizada para renderizar a interface gráfica e gerenciar a interação do usuário.

<br>

# 🧠 O Motor de Inferência (O Cérebro)

O grande diferencial deste projeto é que ele não utiliza um questionário fixo. Ele constrói a árvore de decisão **dinamicamente** ao iniciar.

O algoritmo "guloso" analisa todas as doenças cadastradas e seus sintomas. Ele calcula, matematicamente, qual pergunta (sintoma) divide o monte de doenças restantes o mais próximo possível da metade (50% SIM e 50% NÃO). Essa é a pergunta ideal, pois elimina metade das doenças erradas com uma única resposta, garantindo o diagnóstico no menor número de cliques possível.

<br>

# ⚙️ Dependências (Como Instalar)

Para compilar este projeto, você precisa ter a biblioteca **Raylib** instalada e configurada no seu ambiente de desenvolvimento.

## 🐧 No Linux (Mint / Ubuntu / Debian)
Você pode instalar a Raylib e as ferramentas de compilação diretamente pelo terminal:

```bash
# 1. Instalar compilador e ferramentas base
sudo apt update
sudo apt install build-essential git cmake

# 2. Instalar dependências gráficas e de áudio da Raylib
sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
```

## 🪟 No Windows (Usando VS Code + w64devkit)
No Windows, o processo geralmente envolve configurar o compilador GCC e as pastas da Raylib manualmente. Siga os tutoriais oficiais ou use o instalador da Raylib se necessário. **Certifique-se de ter o GCC (`gcc`) e o linker configurados no seu PATH.**

<br>

# 🛠️ Como Compilar e Executar

Este repositório foi unificado para rodar com **UM ÚNICO CÓDIGO FONTE** (`main.c`), independentemente do sistema operacional. O arquivo de fonte (`arial.ttf`) deve estar na mesma pasta do código.

## Passo 1: Preparação
Certifique-se de que sua pasta do projeto contém:
* `main.c`
* `arial.ttf`
* `README.md`

## Passo 2: Compilação

Abra o terminal na pasta do projeto e rode o comando específico para o seu sistema:

#### 🐧 Comando para LINUX:
```bash
gcc main.c -o sistema_triagem -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

#### 🪟 Comando para WINDOWS (Usando w64devkit):
*(Ajuste os caminhos se sua instalação da Raylib for diferente)*
```bash
C:\raylib\w64devkit\bin\gcc.exe main.c -o sistema_triagem.exe -B C:\raylib\w64devkit\bin -I C:\raylib\raylib\src -L C:\raylib\raylib\src -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows
```

## Passo 3: Execução

#### 🐧 Executar no LINUX:
```bash
./sistema_triagem
```

#### 🪟 Executar no WINDOWS:
Basta dar um duplo clique no arquivo `sistema_triagem.exe` gerado na pasta.

<br>

# 👨‍💻 Autores
* **Vitor Silva Amâncio** - Engenharia da Computação
* **Pablo Felipe dos Santos** - Engenharia da Computação
* **Bruno Brito** - Engenharia da Computação
```

***

### 💡 Como colocar a logo gerada no README:

1. Pegue a imagem da logo que gerei (ela está abaixo).
2. Arraste essa imagem para dentro do corpo do seu repositório lá no GitHub (na página onde você edita o README direto pelo navegador). O GitHub vai gerar um link automaticamente (ex: `https://github.com/usuario/projeto/assets/...`).
3. Pegue esse link gerado e cole na linha 3 do código acima, substituindo `LINK_DA_IMAGEM_LOGO_GERADA.png`.

Sua apresentação está pronta e irretocável! Boa sorte com o projeto no IFMS!
