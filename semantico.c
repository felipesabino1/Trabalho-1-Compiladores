#include "semantico.h"

extern void yyerror(const char*);

void semantic(Node* root){
    Tabelas* tab = newTabelas();
    dfs(root,tab);
}
void dfs(Node* u, Tabelas* tab){
    if(!u) return;
    func[u->tipo](u,tab);
    for(int i=0; i<4; i++) dfs(u->f[i],tab);
    if(u->tipo == BlocoVar) pop(tab);
}

void semanticBlocoVar(Node* u, Tabelas *tab){
    push(tab,newTabela());
    
    
}
