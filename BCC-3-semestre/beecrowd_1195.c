#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
  int info;
  struct arv *dir;
  struct arv *esq;
}Arv;

Arv *ins_abb(int c, Arv*raiz){
  if(raiz == NULL){
    Arv*n=(Arv*)malloc(sizeof(Arv));
    n->info = c;
    n->dir = n->esq = NULL;
    return n;
  }else
  if (c < raiz->info) //anda a esquerda
    raiz->esq = ins_abb(c,raiz->esq);
  else                //anda a direita
    raiz->dir = ins_abb(c,raiz->dir);
    
   return raiz;
}

Arv *remover(Arv*raiz)
{
    if (raiz)   
    {
        raiz->esq = remover(raiz->esq);
        raiz->dir = remover(raiz->dir);
        free(raiz);
        raiz=NULL;
    }else{
        return NULL;
    }
    return raiz;
}

void impr_pre(Arv * a){
  if (a!=NULL) {
    printf(" %d",a->info);   //raiz
    impr_pre(a->esq);         //sub esq
    impr_pre(a->dir);         //sub dir
  }
}

void impr_ord(Arv * a){
  if (a!=NULL) {
    impr_ord(a->esq);         //sub esq
    printf(" %d",a->info );   //raiz
    impr_ord(a->dir);         //sub dir
  }
}

void impr_pos(Arv * a){
  if (a!=NULL) {
    impr_pos(a->esq);         //sub esq
    impr_pos(a->dir);         //sub dir
    printf(" %d",a->info );   //raiz
  }
}

int main()
{
    int opc, val, runs, qtd;

    Arv*a=NULL;

    scanf("%d",&runs);

    for (int z = 0; z < runs; z++)
    {
        scanf("%d",&qtd);
        for (int x = 0; x < qtd; x++)
        {
            scanf(" %d",&val);
            a=ins_abb(val,a);
    
        }
        printf("Case %i:",z+1);
        printf("\nPre.:"); 
        impr_pre(a);

        printf("\nIn..:"); 
        impr_ord(a);

        printf("\nPost:"); 
        impr_pos(a);

        printf ("\n\n");
    
        a = remover(a);

    }
    
    return 0;
}
