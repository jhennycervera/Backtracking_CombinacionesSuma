/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: jhenn
 *
 * Created on 11 de diciembre de 2020, 11:08 AM
 */

#include <stdio.h>
int cont=0;
int soluciones[100][100];
/* x<>y<>z 9>x>0   */

int esvalido(int x,int y,int z,int total){
    int i;

    if(x==0 || y==0 || z==0 || x>9 || y>9 || z>9 || x+y+z>total)
            return 0;

    if(x+y+z==total){ //verificamos si encontramos sol repetidas
        for(i=0;i<=cont;i++) 
            if(soluciones[i][0]==x && soluciones[i][1]==y && soluciones[i][2]==z)
               return 0;	
    }
    return 1;		
}


int busca(int x,int y,int z,int total){
	
    if(!esvalido(x,y,z,total))  //corto el busca y ya no sigo aumentando sino retrocedo y aumento el otro y o z
            return 0;
    if(x!=y && x!=z && y!=z && x+y+z==total){ //si encontre una solucion, guardo en el arr y retorno 0 para que siga buscando mas sol
        soluciones[cont][0]=x;			
        soluciones[cont][1]=y;
        soluciones[cont][2]=z;
        cont++;
        printf("%d %d %d\n",x,y,z);
        return 0;
    }

    if(busca(x,y,z+1,total)){
    }
    else		
            if(busca(x,y+1,z,total)){
            }	
            else
                if(busca(x+1,y,z,total)){
            }
}

int main(int argc, char** argv) {
    int total =6;
    busca(1,1,1,total);
    return (0);
}

