#include <stdio.h>
#include <stdlib.h>
#include "ListaEncad.c"
#include <locale.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


Lista * soma(Lista * l1, Lista * l2){
	// criar a l3
	Lista * l3 = criar();
	//variavel que ira receber a soma
	double soma; 
	// se vai um
	int vaium=0;
	//pega a diferenca do tamanho da struct
	int m;
	//potencia para saber quantas algarismo iremos acrescentar
	int p =1;
	//verificcar se vai 1 ou vai -1
	int negativo = 0;
	
	//verificar se contem negativo
	int op = 1;
	if(primeiro(l1)<0 || primeiro(l2)<0){
		op = 0;
	}
	//pegar o tamanho l1 e l2
	int tam1, tam2;
	tam1 = tamanho(l1);
	tam2 = tamanho(l2);
	
	//quem e maior? e igualar
	if(tam1>tam2){
		m = tam1 - tam2;
		while(m !=0){
			inserir_primeiro(l2,0);
			m = m-1;
		}
	}else if(tam2>tam1){
		m = tam2 - tam1;
		while(m !=0){
			inserir_primeiro(l1,0);
			m = m-1;
		}
	}
	imprimir(l1);
	imprimir(l2);
	
	
	while(tamanho(l1)){
		printf("%d \t l1:",ultimo(l1));
		printf("%d \t l2:",ultimo(l2));
		
		
		if((op==0 && tamanho(l1) ==1) || op==1){
			soma = remover_ultimo(l1) + remover_ultimo(l2) + vaium;
		}else if(primeiro(l1)<0 && primeiro(l2)<0){
			soma = (remover_ultimo(l1)*-1)+ (remover_ultimo(l2)*-1)+ vaium;
		}else if(primeiro(l1)<0){
				if(ultimo(l1)<ultimo(l2)){
					// retiramos 1 e puxamos -10
					soma = (remover_ultimo(l1)*-1) + remover_ultimo(l2) + vaium -10;
					negativo = 1;
				}else
				soma = (remover_ultimo(l1)*-1) + remover_ultimo(l2) + vaium;
				
		}else{
			if(ultimo(l1)<ultimo(l2)){
				soma = remover_ultimo(l1) + (remover_ultimo(l2)*-1) + vaium + 10;
				negativo = -1;
			}else if(ultimo(l1)>ultimo(l2)){
			// antes de somar ele tem somar com 10 o ultimo l2 
				soma = remover_ultimo(l1) + ((remover_ultimo(l2)+10)*-1) + vaium;
				negativo = 1;
		
		}else
			soma = remover_ultimo(l1) + (remover_ultimo(l2)*-1) + vaium;
		}		
		
		//verifica se precisa de tirar 1 
		
		if(negativo ==1){
			vaium = 1;
			negativo = 0;
		}else if(negativo ==-1){
			negativo = 0;
			vaium = -1;
		}else if(soma>9){
			vaium = 1;
			soma = soma -10;
		}else if(soma<-9){
			vaium = -1;
			soma = soma + 10;
		}else{
			vaium =0;
		}
		

		
		//insere a soma ao l3
		inserir_primeiro(l3,soma);
		
	}
	
	//excedente da soma
	if(vaium ==1){
		inserir_primeiro(l3,1);
		vaium = 0;
	}
	//retorna o l3 ao final das somas
	return l3;
}


Lista * multiplicacao3(Lista * l1, Lista * l2){
	int i, v1 = 0, v2 = 1, j,resultado,k;
	long int p = 0;
	Lista * l = criar();
	inserir_primeiro(l,0);
	Lista * aux = criar();
	
		//pegar o tamanho l1 e l2
	int tam1, tam2;
	tam1 = tamanho(l1);
	tam2 = tamanho(l2);
	int m;
	//quem e maior? e igualar
	if(tam1>tam2){
		m = tam1 - tam2;
		while(m !=0){
			inserir_primeiro(l2,0);
			m = m-1;
		}
	}else if(tam2>tam1){
		m = tam2 - tam1;
		while(m !=0){
			inserir_primeiro(l1,0);
			m = m-1;
		}
	}
	

	imprimir(l1);
	imprimir(l2);
	
	for(j=tamanho(l2)-1;j >= 0;j--){
		
      for(i=tamanho(l1)-1; i >= 0;i--){
         //pego o ultimo da l2 e multiplico por todos da l1
      resultado =  (ler_pos(l1, i) * ler_pos(l2, j))+ resultado;
        //soma 
        if(resultado>=10 && i!=0){
            //inteira
        inserir_primeiro(aux, resultado % 10);
        // resto
        resultado = resultado/10;
        }
        else if(resultado>=10 && i==0){
            //inteira
        inserir_primeiro(aux,resultado % 10);
            //sobra
        inserir_primeiro(aux,resultado / 10);
        }
        else{
        inserir_primeiro(aux,resultado);
        resultado = 0;
        }
  
      }
      
      if(j!=tamanho(l2)-1){
        for(k=0;k>j-(tamanho(l2)-1);k--){
            inserir_ultimo(aux,0);
        }
      }
        

      l = soma(l,aux);
      limpar(aux);
      resultado=0;
    }
	
	

	imprimir(l);
//	converter2(l);
	return l;

}





void converter(Lista * l1){
	// i - valor; p - potencia;
	int i,p = 1;
	int v1;
	// descobre a potencia 
	for(i =1; i<=primeiro(l1);i*10){
		p = p*10;
	}
		p=p/10;
		
		printf("%d potencia", p);
	//vai retirando o maior algarismo ate o menor(no caso e a unidade) e reduzindo a portencia
		v1 = primeiro(l1);
		i=1;
		limpar(l1);
	while(p>=1){
		
		v1 = v1/p;
		inserir_ultimo(l1,abs(v1));
		printf("%d", abs(v1));
		v1 = v1- abs(v1);
		
	//	printf("%d",v1);
		
	
	//	printf("%d \t valor mult :",v1);
		p = p/10;
		v1 = v1*p;
		i++;
	
	}
	imprimir(l1);
//	imprimir(l2);

}


void capturavalor(Lista * l){
	limpar(l);
	char ch;
	int a = 1;
	int valor;
     while (a){
	 ch = getch();
	 valor = ch -'0';
	 // -35 valor <enter> ascii
	if(valor != -35){
		if(valor==-3){
		ch = getch();
	 	valor = (ch -'0')*-1;
		}
	printf("%d ",valor);
		inserir_ultimo(l,valor);
	}else{
		a = 0; 
		}	
	}
	printf("\n");
		
}



void menu(){
	printf("\t\t\t Codigo das operações \n");
	printf("1 - digite 1 valor\n");
	printf("2 - digite 2 valor\n");
	printf("3 - mostrar a soma\n");
	printf("4 - mostrar a multiplicação\n");
	printf("5 - sair\n");
}


int main(int argc, char *argv[]) { 
	setlocale(LC_ALL, "Portuguese");
	Lista * l1 = criar();
	Lista * l2 = criar();	
	Lista * l3 =criar();
	Lista * soma1;
	Lista * soma2;
	Lista * l4 = criar();
	// capturar o valor	

	menu();
	printf("digite uma operação \n");
	
	int n;
	
	while(n!=5){
	switch(n){
		case 1:
			capturavalor(l1);
			break;
		case 2:	
			capturavalor(l2);
			break;
		case 3:
			soma1 = l1;
			soma2 = l2;
			l3 = soma(soma1,soma2);
			imprimir(l3);
			break;
		case 4:
			
			l4 = multiplicacao3(l1,l2);
			imprimir(l4);
			break;
		case 5:
			exit(0);
	}
	printf("Digite outra operação \n");
	scanf("%d",&n);	
}
	
	
	destruir(soma2);
	destruir(soma1);
	destruir(l4);
	destruir(l1);
	destruir(l2);
	destruir(l3);
	system("pause");
	return 0;
}
