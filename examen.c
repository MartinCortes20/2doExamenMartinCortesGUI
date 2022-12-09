#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	printf("\t\t                  Tiendita de Martin Busque sus productos             \n \n ");
	int colision=0;	// colisiones
	int funcion=75; // numero de  datos 
	int Datos[75][4]={{01,110322,356,12},{02,120722,568,32},{03,220124,567,45},{04,280922,980,45},{05,220323,900,67},{06,230623,464,92},{07,220924,1234,15},{8,240623,907,37},{9,160723,430,32},{10,221212,5000,450},{11,281224,98,67},{12,240722,890,689},{13,221212,590,45},{14,101224,98,697},{15,141227,93,900},{16,261022,439,89},{17,240722,754,86},{18,230223,4000,80},{19,220323,670,34},{20,270722,267,38},{21,180227,800,95},{22,261022,650,869},{23,240722,74,660},{24,190824,50,800},{25,120823,580,38},{26,170225,832,302},{27,290724,943,90},{28,110225,654,889},{29,180623,754,696},{30,250825,1267,80},{31,190523,5000,30},{32,110523,90,372},{33,120324,78,900},{34,220323,653,89},{35,240422,784,66},{36,290824,4000,8},{37,250926,400,3200},{38,221224,560,45},{39,141124,90,67},{40,130223,76,90},{41,121224,63,890},{42,231225,72,660},{43,260424,421,80},{44,221226,500,340},{45,121225,123,320},{46,150823,592,340},{47,270729,589,32},{48,250926,489,780},{49,220123,515,450},{50,140125,900,100},{51,230923,967,90},{52,230325,600,880},{53,240425,700,66},{54,180122,500,807},{55,101024,567,340},{56,130727,5800,200},{57,251222,4000,2},{58,221128,5600,4},{59,230822,90,6700},{60,180425,96,900},{61,150624,89,890},{62,240123,732,666},{63,121125,41,432},{64,150128,5900,30},{65,170222,530,320},{66,150529,4000,300},{67,221130,9000,1},{68,210526,100,8900},{69,141227,70,900},{70,100124,650,1000},{71,230422,700,676},{72,190129,4900,80},{73,130522,500,340},{74,170126,20,3200},{75,110422,400,650}};	// Clave, fecha de caducidad, precio y unidades 
	int hash[75][5]; // Clave, fecha de caducidad, precio, unidades y status
	int resultado=0, i, j, numero,k,l;
	int res=0;
	int r=0;
			
	//reproduce tabla hash
	for(i=0;i<funcion;i++){
		for(j=0;j<5;j++){
				hash[i][j]=0;
		}
	}
	for(i=0;i<=funcion-1;i++){
		resultado=Datos[i][0]%funcion;
		// colisiones
		while((hash[resultado][4])!=0){	// continua mientras el status es distinto de 0 (cierto)
			fflush(stdin);
			resultado++;
			colision=colision+1;
			if(resultado>funcion-1){
				resultado=0;
			}
		}
		
		for(k=0;k<=funcion-1;k++){
		res=Datos[i][0]%funcion;
		while((hash[res][4])!=0){	// continua mientras el status es distinto de 0 (cierto)
			fflush(stdin);
			res++;
			colision=colision+1;
			if(res>funcion-1){
				res=0;
			}
		}

		for(l=0;l<=funcion-1;l++){
		r=Datos[i][0]%funcion;
		while((hash[r][4])!=0){	// continua mientras el status es distinto de 0 (cierto)
			fflush(stdin);
			r++;
			colision=colision+1;
			if(r>funcion-1){
				r=0;
			}
		}
	}
}
		hash[resultado][0]=Datos[i][1];	//Fecha de caducidad
		hash[resultado][1]=Datos[i][0];	//clave
		hash[resultado][2]=Datos[i][-1]; //Unidades Disponibles
		hash[resultado][3]=Datos[i][-2]; //Precio
		hash[resultado][4]=1;	//Estado de Produccion
		// hash[]=valor clave status
	}
	printf("\tFecha De Caducidad(D/M/A)     \tClave \t\tUnidades Disponibles \t Precio(pesos) \t   Estado de produccion \n");
	for(i=0;i<funcion;i++){
		for(j=0;j<5;j++){
			printf("\t%d           \t ",hash[i][j]);
				
		}
		printf("\n ");
	}
	//Pedimos la clave del producto a buscar
	// y lo busca en la tabla
		
	int VB;
	printf("Dame la clave a buscar \n");
	scanf("%d",&VB);
	resultado=VB%funcion;
	while(hash[resultado][1]!=VB){
		resultado++;
	
		if(resultado>funcion-1){
			resultado=0;
		}
	}
	printf("\n Colsiones=  %d\n", colision);
	printf("\tFecha De Caducidad(D/M/A)     \tClave \t\tUnidades Disponibles \t Precio(pesos) \t   Estado de produccion \n");
	printf("\t %d \t                  %d \t\t        %d \t\t        %d \t       \t  %d \t", hash[resultado][0],hash[resultado][1],hash[resultado][2],hash[resultado][3],hash[resultado][4]);
	return 0;
}
