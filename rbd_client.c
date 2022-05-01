/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "rbd.h"

void cli_error(CLIENT *cnlt);

int
main (int argc, char *argv[])
{
	CLIENT *clnt;
	int  *result_1;
	char *inicializar_1_arg;
	int  *result_2;
	char * insere_1_arg;
	int  *result_3;
	char * remove_1_arg;
	int  *result_4;
	char * busca_1_arg;
	char *host;
	int opcao = 0;
	int sair = 0;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];

	clnt = clnt_create (host, RBDPROG, RDBVERS, "udp");
	
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}

	while (sair == 0) {
		printf("\nMenu de opções:\n");
		printf("\n1- Inicializar\n 2- Inserir\n 3- Remover\n 4- Buscar\n 5-Sair\n\n");
		scanf("%d", &opcao);
		char* palavra = malloc(32);
		char **arg; 

		switch (opcao)
		{
			case 1:
				result_1 = inicializar_1(NULL, clnt);
				if(result_1 == (int *)NULL) {
					cli_error(clnt);
				}

				if(*result_1)
					printf("INICIALIZADO!\n\n");
				break;
			case 2:
				printf("Informe a palavra: ");
				scanf("%s", palavra);
				arg = &palavra; 
				result_2 = insere_1(arg, clnt); 
				
				if (result_2 == (int *)NULL) {
					cli_error(clnt);
				}
				if(*result_2)
					printf("PALAVRA INSERIDA!\n");
				else
					printf("PALAVRA NÃO INSERIDA!\n");
				
				break;
			case 3:
				printf("Informe a palavra: ");
				scanf("%s", palavra);
				arg = &palavra;
				result_3 = remove_1(arg, clnt);

				if (result_3 == (int *)NULL) {
					cli_error(clnt);
				}

				if (*result_3)
					printf("PALAVRA REMOVIDA!\n");
				else
					printf("NÃO FOI POSSÍVEL REMOVER!\n");

				break;
			case 4:
				printf("Informe a palavra: ");
				scanf("%s", palavra);
  				arg = &palavra;
				result_4 = busca_1(arg, clnt);
				if (result_4 == (int *)NULL) {
					cli_error(clnt);
				}
				if (*result_4)
					printf("\nPALAVRA ENCONTRADA!\n");	
				else
					printf("\nPALAVRA NÃO ENCONTRADA!\n");	

				break;
			default:
				sair = 1;
				break;
		}
	}

	clnt_destroy (clnt);
	exit (0);
}

void cli_error(CLIENT *clnt)
{
   /* An error occurred while calling the server. */
   /* Print error message and die. */
   printf("RPC falhou\n");
   clnt_destroy( clnt );
   exit(1);
}
//gcc -o server rbd_sif.c rbd_svc.c rbd_srp.c rbd_xdr.c -I/usr/include/tirpc -ltirpc - compilacao de servidor
//gcc -o cliente rbd_cif.c rbd_clnt.c rbd_client.c rbd_xdr.c -I/usr/include/tirpc -ltirpc  - compilacao de cliente