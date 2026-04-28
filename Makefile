# Nome do executável gerado
EXEC = sistema_triagem

# ==========================================
# 1. DETECÇÃO DE SISTEMA E CONFIGURAÇÃO
# ==========================================
ifeq ($(OS),Windows_NT)
	# --- CONFIGURAÇÕES PARA WINDOWS ---
	SISTEMA = Windows
	EXEC := $(EXEC).exe
	
	# Usando o caminho completo do compilador que você tem no W11
	CC = C:/raylib/w64devkit/bin/gcc.exe
	
	# Avisando onde estão os arquivos da Raylib no Windows
	INCLUDES = -I C:/raylib/raylib/src
	LINKS = -L C:/raylib/raylib/src
	
	BIBLIOTECAS = -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows
else
	# --- CONFIGURAÇÕES PARA LINUX ---
	SISTEMA = $(shell uname -s)
	
	# No Linux o gcc é global
	CC = gcc
	
	INCLUDES = 
	LINKS = 
	BIBLIOTECAS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
endif

# ==========================================
# 2. REGRA DE COMPILAÇÃO
# ==========================================
all: $(EXEC)

$(EXEC): main.c
	@echo " Compilando o projeto para $(SISTEMA)..."
	$(CC) main.c -o $(EXEC) $(INCLUDES) $(LINKS) $(BIBLIOTECAS)
	@echo " Compilacao concluída com sucesso!"

# ==========================================
# 3. REGRA DE INSTALAÇÃO
# ==========================================
setup:
ifeq ($(SISTEMA),Linux)
	@echo "Verificando e instalando dependências no Linux Mint/Ubuntu..."
	sudo apt update
	sudo apt install -y build-essential git cmake libasound2-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
	@echo " Todas as bibliotecas estão prontas!"
else
	@echo " O comando 'make setup' automatizado eh exclusivo para Linux."
	@echo " No Windows, voce precisa configurar o ambiente manualmente:"
	@echo " 1. Clique aqui: https://github.com/raysan5/raylib/releases"
	@echo " 2. Baixe a versao do Windows (w64devkit / MinGW)."
	@echo " 3. Extraia os arquivos exatamente na pasta C:\raylib"
endif

# ==========================================
# 4. REGRA PARA RODAR
# ==========================================
run: all
	@echo " Iniciando o Sistema Especialista..."
ifeq ($(SISTEMA),Linux)
	./$(EXEC)
else
	$(EXEC)
endif

# ==========================================
# 5. REGRA DE LIMPEZA
# ==========================================
clean:
	rm -f $(EXEC) $(EXEC).exe
	@echo " Arquivos compilados foram apagados."