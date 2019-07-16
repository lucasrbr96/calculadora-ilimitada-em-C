typedef struct lista Lista;

Lista * criar();
void destruir(Lista * l);
void limpar(Lista * l);
int tamanho(Lista * l);
int esta_vazia(Lista * l);
int ler_pos(Lista * l, int p);
int primeiro(Lista * l);
int ultimo(Lista * l);
int buscar(Lista * l, int v);
void imprimir(Lista * l);
void escrever_pos(Lista * l, int p, int v);
void inserir_pos(Lista * l, int p, int v);
void inserir_primeiro(Lista * l, int v);
void inserir_ultimo(Lista * l, int v);
int remover_pos(Lista * l, int p);
int remover_primeiro(Lista * l);
int remover_ultimo(Lista * l);
void remover(Lista * l, int v);

Lista * concatenar(Lista * l1, Lista * l2);
