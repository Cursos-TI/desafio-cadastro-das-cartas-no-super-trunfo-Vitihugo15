#include <stdio.h>
#include <string.h>

#define NUM_PAISES 8
#define CIDADES_POR_PAIS 4

// Estrutura para armazenar informações de uma cidade
typedef struct {
    char nome[50];
    int populacao;  // Em milhares de habitantes
    float area;     // Em km²
    float pib;      // Em bilhões de dólares
    char pontosTuristicos[100];
} Cidade;

// Estrutura para armazenar informações de um país
typedef struct {
    int codigo;
    char nome[50];
    Cidade cidades[CIDADES_POR_PAIS];
} Pais;
// Função para exibir as informações de uma cidade
void exibirCidade(Cidade c) {
    printf("\nCidade: %s", c.nome);
    printf("\nPopulação: %d mil habitantes", c.populacao);
    printf("\nÁrea: %.2f km²", c.area);
    printf("\nPIB: %.2f bilhões de dólares", c.pib);
    printf("\nPontos turísticos: %s\n", c.pontosTuristicos);
}

// Função para exibir as informações de um país e suas cidades
void exibirPais(Pais p) {
    printf("\n=====================");
    printf("\nPaís: %s (Código: %d)", p.nome, p.codigo);
    printf("\n=====================\n");
    for (int i = 0; i < CIDADES_POR_PAIS; i++) {
        exibirCidade(p.cidades[i]);
        printf("\n---------------------\n");
    }
}

// Função para buscar um país pelo código
Pais* buscarPaisPorCodigo(Pais paises[], int codigo) {
    for (int i = 0; i < NUM_PAISES; i++) {
        if (paises[i].codigo == codigo) {
            return &paises[i];
        }
    }
    return NULL;
}
int main() {
    // Banco de dados de países e cidades
    Pais paises[NUM_PAISES] = {
        {1, "Brasil", {
            {"Rio de Janeiro", 6740, 1182.3, 200.5, "Cristo Redentor, Pão de Açúcar"},
            {"São Paulo", 12300, 1521.1, 400.2, "Avenida Paulista, Museu do Ipiranga"},
            {"Salvador", 2900, 693.8, 90.4, "Pelourinho, Elevador Lacerda"},
            {"Brasília", 3050, 5802.0, 150.7, "Congresso Nacional, Catedral de Brasília"}
        }},
        {2, "Estados Unidos", {
            {"Nova York", 8410, 783.8, 1700.0, "Estátua da Liberdade, Times Square"},
            {"Los Angeles", 3980, 1213.9, 1000.5, "Hollywood, Calçada da Fama"},
            {"Chicago", 2716, 589.6, 700.3, "Willis Tower, Millennium Park"},
            {"Miami", 4780, 143.1, 350.2, "Praias de Miami, Little Havana"}
        }},
        {3, "França", {
            {"Paris", 2148, 105.4, 850.7, "Torre Eiffel, Museu do Louvre"},
            {"Marselha", 861, 240.6, 300.5, "Porto Velho, Basílica de Notre-Dame"},
            {"Lyon", 513, 47.9, 200.8, "Basilique de Fourvière, Vieux Lyon"},
            {"Nice", 342, 71.9, 180.6, "Promenade des Anglais, Colline du Château"}
        }},
        {4, "Alemanha", {
            {"Berlim", 3769, 891.8, 500.9, "Portão de Brandemburgo, Muro de Berlim"},
            {"Munique", 1471, 310.4, 400.7, "Marienplatz, Allianz Arena"},
            {"Hamburgo", 1841, 755.3, 350.6, "Elbphilharmonie, Miniatur Wunderland"},
            {"Colônia", 1080, 405.2, 250.3, "Catedral de Colônia, Museu do Chocolate"}
        }},
{5, "Itália", {
            {"Roma", 2870, 1285.0, 600.4, "Coliseu, Fontana di Trevi"},
            {"Milão", 1366, 181.8, 550.3, "Catedral de Milão, Galeria Vittorio Emanuele II"},
            {"Veneza", 261, 414.6, 200.9, "Canal Grande, Praça de São Marcos"},
            {"Florença", 382, 102.4, 180.5, "Cúpula de Brunelleschi, Ponte Vecchio"}
        }},
        {6, "Japão", {
            {"Tóquio", 13960, 2194.0, 1900.0, "Shibuya, Templo Senso-ji"},
            {"Osaka", 2750, 223.0, 900.2, "Castelo de Osaka, Dotonbori"},
            {"Quioto", 1475, 827.8, 500.6, "Templo Kinkaku-ji, Fushimi Inari"},
            {"Hiroshima", 1190, 906.7, 400.7, "Memorial da Paz, Castelo de Hiroshima"}
        }},
        {7, "Reino Unido", {
            {"Londres", 8980, 1572.0, 1600.0, "Big Ben, Palácio de Buckingham"},
            {"Manchester", 553, 115.6, 450.3, "Old Trafford, Museu da Ciência"},
            {"Edimburgo", 537, 264.0, 300.5, "Castelo de Edimburgo, Royal Mile"},
            {"Liverpool", 498, 111.8, 250.4, "The Beatles Story, Albert Dock"}
        }},
        {8, "Austrália", {
            {"Sydney", 5312, 1687.0, 1200.0, "Ópera de Sydney, Harbour Bridge"},
            {"Melbourne", 5070, 999.0, 1000.4, "Federation Square, Queen Victoria Market"},
            {"Brisbane", 2463, 1582.0, 600.2, "South Bank, Lone Pine Koala Sanctuary"},
            {"Perth", 2100, 6418.0, 550.6, "Kings Park, Cottesloe Beach"}
        }}
    };

    int escolha;
    printf("Bem-vindo ao Super Trunfo de Países e Cidades!\n");
    printf("Aluno: Victor Hugo de Oliveira - Matricula: 202501529321\n");
    printf("Escolha um código de país (1 a 8) para visualizar as cidades:\n");
    scanf("%d", &escolha);

    Pais *paisSelecionado = buscarPaisPorCodigo(paises, escolha);
    if (paisSelecionado != NULL) {
        exibirPais(*paisSelecionado);
    } else {
        printf("\nCódigo de país inválido.\n");
    }
    return 0;
}