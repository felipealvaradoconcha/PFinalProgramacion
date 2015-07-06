/*Felipe Alvarado Concha ICI 2015
  Lenguaje de Programación
  Profesor Sergio Baltierra Valenzuela*/

#include <stdio.h>
#define N 100

int main(){

	FILE *arch;//Variables
	FILE *resultado;
	int tam_array,i,j=0,k=1;
	int array[N];
	int suma=0,suma1=0,suma2=0,suma3=N;
	int *p;

	arch = fopen("entrada.ent", "r");//Se abre el archivo y si no está declara error

	if(arch==NULL)
         printf("Error al leer el archivo\n");

	fscanf(arch, "%d", &tam_array);//Lee los elementos del archivo en forma de enteros

	for(i=0; i<tam_array; i++){//Lee los elementos y los guarda en el arreglo sin contar los espacios
		fgetc(arch);
		array[i] = fgetc(arch) - '0';
	}

	fclose(arch);//Cierra el archivo

	for(i=0;i<tam_array;i++){
		printf("%2d",array[i]);
	}

	printf("\n");

    if(tam_array>=3){//Verifica que el arreglo es mayor a 3
        while(k<tam_array){//K va aumentando paulatinamente subdiviendo el arreglo
            p=&array[0];//se suma el valor del puntero y se cambia la dirrecion
            for(i=0;i<k;i++){
                suma=*p+suma;
                p++;
            }
            for(j=i;j<tam_array;j++){
                suma1=*p+suma1;
                p++;
            }

            if(suma-suma1>0){//Se verifica que la diferencia sea mayor que 0 y si no es asi se cambia a posistivo
                suma2=(suma-suma1);
            }else{
                suma2=(suma-suma1)*-1;
            }

            if(suma2<suma3)//Se guarda la minima diferencia
                suma3=suma2;
            suma=0;
            suma1=0;
            k++;
        }
        resultado=fopen("salida.sal","w+b");//Se abre o crea el archivo
        fprintf(resultado, "%d", suma3);//Se imprime la minima diferencia dentro del archivo
        printf("%d",suma3);
    }else printf("Arreglo menor a 3 o error");
}
