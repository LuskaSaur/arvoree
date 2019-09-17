#include <stdio.h>
#include <stdlib.h>

_Bool vis[6];

typedef struct tipoNo{
    int u;
    struct tipoNo *prox;
}tipoNo;

typedef struct grafo{
    tipoNo *adj;
}Grafo;

Grafo *g;

Grafo * criarGrafo(int n){
    int i;
    Grafo *g = (Grafo *) malloc(sizeof(Grafo));
    g->adj = (tipoNo *) malloc(sizeof(tipoNo)*n);
    for (i =0; i<n; i++){
        g->adj[i].prox = NULL;
    }
    return g;
}

tipoNo* alocarNo(int u){
    tipoNo * no = (tipoNo *) malloc(sizeof(tipoNo));
    no->u = u;
    no->prox = NULL;
    return no;
}

void inserir(Grafo *g, int u, int v){
    tipoNo *novo_no = alocarNo(v);
    novo_no->prox = g->adj[u].prox;
    g->adj[u].prox = novo_no;
}

int dfs(int u){
    tipoNo * i;
    vis[u] = 1;
    for (i= g->adj[u].prox; i != NULL; i = i->prox){
        int v = i->u;
        if (!vis[v]){
            dfs(v);
        }
        else{
            return 1;
        }
    }

}


int main(){
  g = criarGrafo(5);
	inserir(g, 2, 3);
	inserir(g, 3, 4);
	inserir(g, 4, 2);
	inserir(g, 1, 3);
	printf("%d", dfs(1));
}