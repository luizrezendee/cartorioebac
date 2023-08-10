#include <stdio.h> //biblioteca de comunicaçao do usuario
#include <stdlib.h> //biblioteca de alocaçao de espaco de memoria 
#include <locale.h> //biblioteca de alocaçoes de texto por regiao 
#include <string.h> // blioteca responsável por cuidar das string

int registro()//funçao responsavel por cadastrar os usuarios no sistema
{
   //inicio das variaveis/string
   char arquivo[40];
   char cpf [40];
   char nome [40];
   char sobrenome [40];
   char cargo[40];
   //final da criacao das variaveis/string
   
   printf("Digite o CPF a ser cadastrador ");//coletando informaçoes do usuario 
   scanf("%s",cpf);//%s refere-se a string
   strcpy(arquivo, cpf);//Responsoval por copiar os valores das strings
   
   FILE * file; //cria o arquivo
   file = fopen(arquivo,"w");//cria o arquivo e o "w" significa escrever 
   fprintf(file,cpf);//salva o valor da variavel 
   fclose(file);//fecha o arquivo 
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("digite o nome a ser cadastrado: ");
   scanf("%s",nome);
   
   file = fopen(arquivo,"a");
   fprintf(file,nome);
   fclose(file);
   
   printf("digite osobrenome a ser cadastrado: ");
   scanf("%s",sobrenome);
   
   file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("digite o cargo a ser cadastrado: ");
   scanf("%s", cargo);
   
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);



}

int consulta()
{
   setlocale(LC_ALL, "portuguese");// definindo linguagem 
    
   char cpf[40];
   char conteudo[200];
   
   printf("digite o cpf a ser consultado: ");
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
   {
       printf("nao foi possivel abrir o arquivo, nao localizado!./n");    
   }
   
   while(fgets(conteudo, 200, file)!= NULL);
   {
     printf("/n essas sao as informaçoes do usuario:");
     printf("%s", conteudo );
     printf("\n\n");
   }
   
}

int deletar()
{
    char cpf[40];
    
    printf("digite o cpf que deseja deletar");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
       printf("o usuario nao se encontra no sistema!./n");    
       system("pause");
    }
}

int main()
{
    int opcao=0; // definindo variaveis
    int laco=1;
    
    for(laco=1;laco=1;)
   {

    setlocale(LC_ALL, "portuguese");// definindo linguagem 
    
    printf("### cartorio da EBAC ### \n \n");// inicio do menu 
    printf("escolha a opçao desejada do menu: \n\n");
    printf("\t1 - registrar nomes\n");
    printf("\t2 - consultar nomes\n");
    printf("\t3 - deletar nomes\n");
    printf("opçao: ");// fim do menu 
    scanf("%d" ,&opcao);// armazenamento a escolha do usuario 
    
    system("cls");//responsavel por limpar a tela 
    
    switch(opcao)// inicio da seleçao do menu 
    {
       case 1:
       registro();//chamada de funçoes 
       break;
       
       case 2:
       consulta();  
       break;
       
       case 3:
       deletar();
       break;
       
       default:
       printf("essa opcao nao esta disponivel \n");
       system("pause");
       break;         
    } // fim da seleçao
   }
}    
