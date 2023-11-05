#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 10

// Estrutura para representar um contato
struct Contato {
    char nome[50];
    char telefone[15];
};

// Função para exibir um contato
void exibirContato(struct Contato contato) {
    printf("Nome: %s\n", contato.nome);
    printf("Telefone: %s\n", contato.telefone);
    printf("\n");
}

// Função para encontrar um contato pelo nome
int encontrarContato(struct Contato lista[], int numContatos, const char *nome) {
    for (int i = 0; i < numContatos; i++) {
        if (strcmp(lista[i].nome, nome) == 0) {
            return i; // Retorna o índice do contato encontrado
        }
    }
    return -1; // Retorna -1 se o contato não for encontrado
}

int main() {
    struct Contato listaContatos[MAX_CONTATOS]; // Lista de contatos
    int numContatos = 0; // Número atual de contatos na lista

    int opcao;

    do {
        printf("Menu:\n");
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Editar contato\n");
        printf("4. Deletar contato\n");
        printf("5. Pesquisar contato por nome\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (numContatos < MAX_CONTATOS) {
                    struct Contato novoContato;
                    printf("Nome: ");
                    scanf("%s", novoContato.nome);
                    printf("Telefone: ");
                    scanf("%s", novoContato.telefone);
                    listaContatos[numContatos] = novoContato;
                    numContatos++;
                    printf("Contato adicionado com sucesso!\n\n");
                } else {
                    printf("A lista de contatos está cheia. Remova um contato antes de adicionar mais.\n\n");
                }
                break;

            case 2:
                if (numContatos > 0) {
                    printf("Lista de Contatos:\n");
                    for (int i = 0; i < numContatos; i++) {
                        exibirContato(listaContatos[i]);
                    }
                    printf("\n");
                } else {
                    printf("A lista de contatos está vazia.\n\n");
                }
                break;

            case 3:
                if (numContatos > 0) {
                    char nomeEditar[50];
                    printf("Digite o nome do contato que deseja editar: ");
                    scanf("%s", nomeEditar);
                    int indiceEditar = encontrarContato(listaContatos, numContatos, nomeEditar);
                    if (indiceEditar != -1) {
                        printf("Digite o novo nome: ");
                        scanf("%s", listaContatos[indiceEditar].nome);
                        printf("Digite o novo telefone: ");
                        scanf("%s", listaContatos[indiceEditar].telefone);
                        printf("Contato editado com sucesso!\n\n");
                    } else {
                        printf("Contato não encontrado.\n\n");
                    }
                } else {
                    printf("A lista de contatos está vazia.\n\n");
                }
                break;

            case 4:
                if (numContatos > 0) {
                    char nomeDeletar[50];
                    printf("Digite o nome do contato que deseja deletar: ");
                    scanf("%s", nomeDeletar);
                    int indiceDeletar = encontrarContato(listaContatos, numContatos, nomeDeletar);
                    if (indiceDeletar != -1) {
                        // Substitui o contato a ser deletado pelo último contato na lista
                        listaContatos[indiceDeletar] = listaContatos[numContatos - 1];
                        numContatos--;
                        printf("Contato deletado com sucesso!\n\n");
                    } else {
                        printf("Contato não encontrado.\n\n");
                    }
                } else {
                    printf("A lista de contatos está vazia.\n\n");
                }
                break;

            case 5:
                if (numContatos > 0) {
                    char nomePesquisar[50];
                    printf("Digite o nome do contato que deseja pesquisar: ");
                    scanf("%s", nomePesquisar);
                    int indicePesquisar = encontrarContato(listaContatos, numContatos, nomePesquisar);
                    if (indicePesquisar != -1) {
                        printf("Contato encontrado:\n");
                        exibirContato(listaContatos[indicePesquisar]);
                    } else {
                        printf("Contato não encontrado.\n\n");
                    }
                } else {
                    printf("A lista de contatos está vazia.\n\n");
                }
                break;

            case 6:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n\n");
        }
    } while (opcao != 6);

    return 0;
}