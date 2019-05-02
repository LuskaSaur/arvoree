#include "arvoreAVL.c"
#include <stdlib.h>
#include <stdio.h>


int avl_altura(No_avl *no){
    int esq, dir:

    
    if(no == NULL){
      return -1;
    }
    esq = avl_altura(no->esq);
    dir = avl_altura(no->dir);

    if(esq > dir){
      return esq + 1;

    }
    else
      return dir + 1;
}

AVL_Node *rotacao_direita ( AVL_Node *p ) 
/* Rotação simples para a direita */
{
    AVL_Node *q;
    
    q = p->esq;
    //----------------> Realiza a rotação
    p->esq = q->dir;
    if ( q->dir != NULL )
        q->dir->pai = p;
    q->dir = p;
    q->pai = p->pai;
    if ( p->pai != NULL )
        if ( p->pai->esq == p )
            p->pai->esq = q;
        else
            p->pai->dir = q;
    p->pai = q;
    //----------------> Rebalanceia
    q->bal = avl_height ( q->dir ) - avl_height ( q->esq );
    p->bal = avl_height ( p->dir ) - avl_height ( p->esq );    
    
    return q;
}
