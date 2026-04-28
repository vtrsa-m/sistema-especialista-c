#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOENCAS 50
#define MAX_SINTOMAS_POR_DOENCA 20

// ================= SINTOMAS =================
typedef enum {
    FEBRE, ESPIRROS, DOR_OLHOS, DOR_CORPO, PERDA_OLFATO,
    DOR_FACIAL, TOSSE, CORIZA, FALTA_AR, MANCHAS,
    GARGANTA, CANSACO, NAUSEA, VOMITO, DIARREIA,
    CALAFRIOS, CONGESTAO, DOR_PEITO, OLHOS_VERMELHOS, COCEIRA,
    TOTAL_SINTOMAS
} Sintoma;

char *nomesSintomas[TOTAL_SINTOMAS] = {
    "Febre alta","Espirros","Dor atras dos olhos","Dor no corpo",
    "Perda de olfato/paladar","Dor facial","Tosse","Coriza",
    "Falta de ar","Manchas na pele","Dor de garganta","Cansaco",
    "Nausea","Vomito","Diarreia","Calafrios","Congestao nasal",
    "Dor no peito","Olhos vermelhos","Coceira"
};

// ================= ESTRUTURAS ARVORE =================

typedef struct {
    char nome[50];
    int sintomas[MAX_SINTOMAS_POR_DOENCA];
    int qtd;
} Doenca;

typedef struct Node {
    int sintoma;
    char diagnostico[50];
    struct Node *sim;
    struct Node *nao;
} Node;

Doenca banco[MAX_DOENCAS];
int totalDoencas = 0;

// ================= LÓGICA DO SISTEMA ESPECIALISTA =================

// Função para registrar uma nova doença e seus sintomas no banco de dados.
void adicionarDoenca(char *nome, int sintomas[], int qtd) {
    strcpy(banco[totalDoencas].nome, nome);
    for (int i = 0; i < qtd; i++)
        banco[totalDoencas].sintomas[i] = sintomas[i];
    banco[totalDoencas].qtd = qtd;
    totalDoencas++;
}

int temSintoma(Doenca d, int sintoma) {
    for (int i = 0; i < d.qtd; i++)
        if (d.sintomas[i] == sintoma) return 1;
    return 0;
}

// Popula o sistema com todas as doenças da base de dados.
void carregarBase() {
    int gripe[] = {FEBRE, DOR_CORPO, TOSSE, CANSACO};
    int dengue[] = {FEBRE, DOR_CORPO, DOR_OLHOS, MANCHAS};
    int covid[] = {FEBRE, TOSSE, FALTA_AR, PERDA_OLFATO};
    int alergia[] = {ESPIRROS, CORIZA, COCEIRA};
    int sinusite[] = {DOR_FACIAL, CONGESTAO, TOSSE};
    int resfriado[] = {ESPIRROS, CORIZA, TOSSE};
    int bronquite[] = {TOSSE, FALTA_AR, CANSACO};
    int pneumonia[] = {FEBRE, TOSSE, FALTA_AR, DOR_PEITO};
    int gastrite[] = {NAUSEA, VOMITO};
    int gastroenterite[] = {NAUSEA, VOMITO, DIARREIA};
    int asma[] = {TOSSE, FALTA_AR, DOR_PEITO};
    int rinite[] = {ESPIRROS, CORIZA, CONGESTAO, COCEIRA};
    int faringite[] = {GARGANTA, CANSACO};
    int amigdalite[] = {FEBRE, GARGANTA};
    int conjuntivite[] = {OLHOS_VERMELHOS, COCEIRA};
    int zika[] = {MANCHAS, CANSACO, DOR_CORPO};
    int chikungunya[] = {FEBRE, DOR_CORPO, CANSACO};
    int tuberculose[] = {TOSSE, CANSACO, FALTA_AR, DOR_PEITO};
    int sinusite_aguda[] = {DOR_FACIAL, CONGESTAO, FEBRE};
    int infeccao_viral[] = {FEBRE, CANSACO};
    int intoxicacao[] = {NAUSEA, VOMITO, DIARREIA, CANSACO};
    int enxaqueca[] = {DOR_OLHOS, NAUSEA, CANSACO};
    int virose[] = {FEBRE, NAUSEA, DIARREIA};
    int alergia_pele[] = {MANCHAS, COCEIRA};
    int pneumonia_grave[] = {FEBRE, TOSSE, FALTA_AR, DOR_PEITO, CANSACO};

    adicionarDoenca("Gripe", gripe, 4);
    adicionarDoenca("Dengue", dengue, 4);
    adicionarDoenca("COVID-19", covid, 4);
    adicionarDoenca("Alergia", alergia, 3);
    adicionarDoenca("Sinusite", sinusite, 3);
    adicionarDoenca("Resfriado", resfriado, 3);
    adicionarDoenca("Bronquite", bronquite, 3);
    adicionarDoenca("Pneumonia", pneumonia, 4);
    adicionarDoenca("Gastrite", gastrite, 2);
    adicionarDoenca("Gastroenterite", gastroenterite, 3);
    adicionarDoenca("Asma", asma, 3);
    adicionarDoenca("Rinite", rinite, 4);
    adicionarDoenca("Faringite", faringite, 2);
    adicionarDoenca("Amigdalite", amigdalite, 2);
    adicionarDoenca("Conjuntivite", conjuntivite, 2);
    adicionarDoenca("Zika", zika, 3);
    adicionarDoenca("Chikungunya", chikungunya, 3);
    adicionarDoenca("Tuberculose", tuberculose, 4);
    adicionarDoenca("Sinusite Aguda", sinusite_aguda, 3);
    adicionarDoenca("Infeccao Viral", infeccao_viral, 2);
    adicionarDoenca("Intoxicacao Alimentar", intoxicacao, 4);
    adicionarDoenca("Enxaqueca", enxaqueca, 3);
    adicionarDoenca("Virose", virose, 3);
    adicionarDoenca("Alergia de Pele", alergia_pele, 2);
    adicionarDoenca("Pneumonia Grave", pneumonia_grave, 5);

    int nenhum[1];
    adicionarDoenca("Sem sintomas relevantes", nenhum, 0);
}

// Função que escolhe a pergunta que divide a lista atual de doenças na metade.
int escolherMelhor(Doenca lista[], int n, int usados[]) {
    int melhor = -1;
    int menor = 9999;
    for (int s = 0; s < TOTAL_SINTOMAS; s++) {
        if (usados[s]) continue;

        int sim = 0, nao = 0;
        for (int i = 0; i < n; i++) {
            if (temSintoma(lista[i], s)) sim++;
            else nao++;
        }
        
        if (sim == 0 || nao == 0) continue;

        int diff = abs(sim - nao);
        if (diff < menor) { menor = diff; melhor = s; }
    }
    return melhor;
}
// Função recursiva que constrói a árvore de decisão separando as doenças 
Node* construir(Doenca lista[], int n, int usados[]) {
    if (n == 0) return NULL;
    if (n == 1) {
        Node *folha = malloc(sizeof(Node));
        folha->sintoma = -1;
        strcpy(folha->diagnostico, lista[0].nome);
        folha->sim = folha->nao = NULL;
        return folha;
    }
    int melhor = escolherMelhor(lista, n, usados);

    if (melhor == -1) {
        Node *folha = malloc(sizeof(Node));
        folha->sintoma = -1;
        strcpy(folha->diagnostico, lista[0].nome);
        folha->sim = folha->nao = NULL;
        return folha;
    }

    Doenca grupoSim[MAX_DOENCAS], grupoNao[MAX_DOENCAS];
    int nSim = 0, nNao = 0;

    for (int i = 0; i < n; i++) {
        if (temSintoma(lista[i], melhor)) grupoSim[nSim++] = lista[i];
        else grupoNao[nNao++] = lista[i];
    }

    Node *no = malloc(sizeof(Node));
    no->sintoma = melhor;

    int usadosNovo[TOTAL_SINTOMAS];
    memcpy(usadosNovo, usados, sizeof(usadosNovo));
    usadosNovo[melhor] = 1;

    no->sim = construir(grupoSim, nSim, usadosNovo);
    no->nao = construir(grupoNao, nNao, usadosNovo);

    return no;
}

// ================= FUNÇÕES DE INTERFACE GRÁFICA =================

void Escrever(Font f, const char *t, float x, float y, float tam, Color c) {
    DrawTextEx(f, t, (Vector2){ x, y }, tam, 0.5f, c);
}

// Função para desenhar a árvore com Scroll
void DesenharArvoreVisual(Node *no, int nivel, int *linha, Font f, float scrollY, int ramo) {
    if (no == NULL) return; 

    float xBase = 50 + (nivel * 45); 
    float yBase = 120 + (*linha * 28) + scrollY; 

    // Função de otimização, só desenha o que está visível na tela
    if (yBase > 50 && yBase < 800) {
        
        // Desenha as Tags Visuais de Caminho
        if (ramo == 1) { 
            DrawRectangle(xBase - 38, yBase + 2, 32, 18, (Color){ 219, 234, 254, 255 });
            Escrever(f, "SIM", xBase - 34, yBase + 5, 11, (Color){ 30, 58, 138, 255 });
        } else if (ramo == 2) { 
            DrawRectangle(xBase - 38, yBase + 2, 32, 18, (Color){ 254, 226, 226, 255 });
            Escrever(f, "NAO", xBase - 34, yBase + 5, 11, (Color){ 153, 27, 27, 255 });
        }

        if (no->sintoma == -1) {
            // Desenho do Diagnóstico (Folha)
            DrawRectangle(xBase, yBase, 300, 22, (Color){ 220, 252, 231, 255 });
            Escrever(f, TextFormat("-> %s", no->diagnostico), xBase + 5, yBase + 3, 16, (Color){ 22, 101, 52, 255 });
        } else {
            // Desenho da Pergunta (Nó)
            Escrever(f, TextFormat("? %s", nomesSintomas[no->sintoma]), xBase, yBase, 18, (Color){ 15, 23, 42, 255 });
        }
    }
    
    (*linha)++;

    if (no->sintoma != -1) {
        DesenharArvoreVisual(no->sim, nivel + 1, linha, f, scrollY, 1);
        DesenharArvoreVisual(no->nao, nivel + 1, linha, f, scrollY, 2);
    }
}

// ================= MAIN (CONTROLE DE TELAS) =================

int main() {
    // 1. Constrói a árvore automaticamente no fundo
    carregarBase();
    int usados[TOTAL_SINTOMAS] = {0};
    Node *raiz = construir(banco, totalDoencas, usados);
    Node *atual = raiz;

    // 2. Inicializa o motor gráfico
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(1000, 750, "SISTEMA ESPECIALISTA HOSPITALAR");
    SetTargetFPS(60);

    Font arial = LoadFontEx("arial.ttf", 64, 0, 250);
    GenTextureMipmaps(&arial.texture);
    SetTextureFilter(arial.texture, TEXTURE_FILTER_BILINEAR);

    bool modoEstrutura = false;
    float scrollArvore = 0.0f; // Variável que controla a rolagem do mouse

    while (!WindowShouldClose()) {
        Vector2 mouse = GetMousePosition();
        
        Rectangle btnSim = { 180, 480, 250, 75 };
        Rectangle btnNao = { 530, 480, 250, 75 };
        Rectangle btnEstrutura = { 750, 20, 220, 40 };
        Rectangle btnVoltar = { 400, 680, 200, 45 };
        Rectangle btnReset = { 400, 580, 200, 45 };

        // Lógica de Cliques
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(mouse, btnEstrutura)) {
                modoEstrutura = !modoEstrutura;
            } else if (modoEstrutura) {
                if (CheckCollisionPointRec(mouse, btnVoltar)) modoEstrutura = false;
            } else {
                if (atual && atual->sintoma != -1) {
                    if (CheckCollisionPointRec(mouse, btnSim)) atual = atual->sim;
                    else if (CheckCollisionPointRec(mouse, btnNao)) atual = atual->nao;
                } else {
                    if (CheckCollisionPointRec(mouse, btnReset)) atual = raiz;
                }
            }
        }

        BeginDrawing();
        ClearBackground((Color){ 241, 245, 249, 255 });

        if (!modoEstrutura) {
            // --- TELA 1: INTERFACE DE TRIAGEM ---

            // 1. Cabeçalho
            DrawRectangle(0, 0, 1000, 80, (Color){ 30, 58, 138, 255 }); 
            Escrever(arial, "SISTEMA ESPECIALISTA - TRIAGEM DINAMICA", 30, 25, 26, WHITE);
            
            // 2. Botão para alternar para a Tela 2
            bool hEst = CheckCollisionPointRec(mouse, btnEstrutura);
            DrawRectangleRec(btnEstrutura, hEst ? (Color){ 51, 65, 85, 255 } : (Color){ 15, 23, 42, 255 });
            Escrever(arial, "VER ESTRUTURA", 790, 32, 16, WHITE);

            // 3. Fundo branco do painel principal
            DrawRectangle(50, 120, 900, 320, WHITE);
            DrawRectangleLinesEx((Rectangle){ 50, 120, 900, 320 }, 1, LIGHTGRAY);

            if (atual != NULL) {
                if (atual->sintoma != -1) {
                    // 4. Exibição da pergunta atual
                    Escrever(arial, "O PACIENTE APRESENTA O SEGUINTE SINTOMA:", 80, 150, 16, (Color){ 100, 116, 139, 255 });
                    Escrever(arial, TextFormat("%s", nomesSintomas[atual->sintoma]), 80, 250, 32, (Color){ 15, 23, 42, 255 });

                    // 5. Botões de resposta (Sim e Não)
                    bool hSim = CheckCollisionPointRec(mouse, btnSim);
                    DrawRectangleRec(btnSim, hSim ? (Color){ 20, 50, 150, 255 } : (Color){ 30, 64, 175, 255 });
                    Escrever(arial, "SIM", 285, 505, 22, WHITE);

                    bool hNao = CheckCollisionPointRec(mouse, btnNao);
                    DrawRectangleRec(btnNao, hNao ? (Color){ 200, 210, 230, 255 } : (Color){ 226, 232, 240, 255 });
                    Escrever(arial, "NAO", 635, 505, 22, (Color){ 71, 85, 105, 255 });
                } else {
                    // 6. Exibição do resultado final
                    DrawRectangle(50, 120, 900, 8, (Color){ 30, 64, 175, 255 });
                    Escrever(arial, "IMPRESSAO DIAGNOSTICA ENCONTRADA:", 80, 150, 16, (Color){ 100, 116, 139, 255 });
                    Escrever(arial, atual->diagnostico, 80, 210, 40, (Color){ 30, 64, 175, 255 });
                    
                    Escrever(arial, "Resultado gerado com base no cruzamento estatistico da base de dados.", 80, 320, 18, GRAY);

                    // 7. Botão para reiniciar o fluxo de triagem
                    bool hRes = CheckCollisionPointRec(mouse, btnReset);
                    DrawRectangleRec(btnReset, hRes ? BLACK : DARKGRAY);
                    Escrever(arial, "NOVA TRIAGEM", 435, 592, 16, WHITE);
                }
            }
        } else {
            // --- TELA 2: VISUALIZAÇÃO DA ÁRVORE ---
            
            // 1. Atualiza a rolagem com o Mouse
            scrollArvore += GetMouseWheelMove() * 35.0f;
            if (scrollArvore > 0) scrollArvore = 0; 
            if (scrollArvore < -2000) scrollArvore = -2000; 

            // 2. Cabeçalho 
            DrawRectangle(0, 0, 1000, 80, (Color){ 15, 23, 42, 255 });
            Escrever(arial, "ESTRUTURA HIERARQUICA DA ARVORE GERADA", 30, 25, 26, WHITE);

            // 3. Fundo Branco da Árvore
            DrawRectangle(30, 100, 940, 560, WHITE);
            DrawRectangleLinesEx((Rectangle){ 30, 100, 940, 560 }, 1, LIGHTGRAY);
            
            // MÁSCARA DE RECORTE
            BeginScissorMode(30, 100, 940, 560); 
            
            int linha = 0;
            DesenharArvoreVisual(raiz, 0, &linha, arial, scrollArvore, 0); 
            
            EndScissorMode();
            // 4. Barra visual de rolagem
            DrawRectangle(960, 105, 5, 550, (Color){ 235, 240, 245, 255 });
            DrawRectangle(960, 105 + (-scrollArvore / 2000.0f) * 450, 5, 100, (Color){ 160, 175, 190, 255 });

            // 5. Botão Voltar 
            bool hVol = CheckCollisionPointRec(mouse, btnVoltar);
            DrawRectangleRec(btnVoltar, hVol ? (Color){ 30, 58, 138, 255 } : (Color){ 59, 130, 246, 255 });
            Escrever(arial, "VOLTAR", 465, 692, 18, WHITE);
        }

        Escrever(arial, "Desenvolvido por: Vitor Amancio, Pablo Felipe e Bruno Brito", 20, 725, 14, GRAY);

        EndDrawing();
    }

    UnloadFont(arial);
    CloseWindow();
    return 0;
}
