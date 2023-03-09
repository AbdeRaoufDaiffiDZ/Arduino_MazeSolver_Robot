#ifndef SHORT_PATH_H
#define SHORT_PATH_H
#include <string.h>
#include <Arduino.h>



/*   function to check the number of back in the path   */


int check(char array[], int size){
int number = 0;
for (int i = 0; i < size; i++){

    if (array[i] == 'B'){

        number ++;

    }
}
return number;




}


/*   function to check the path array issue           */

int check_final(char array[], int size){
int number = 0;
for (int i = 0; i < size; i++){

    if (array[i] == 'L' || array[i] == 'R' || array[i] == 'S' ){

        number ++;

    }
}
return number;

}


  





int path_logic(char path[],int size)
{   int j,bN,ISSUEprint;
    int i = 0;
    //char path[15] = {'L','B','L','L','L','B','S','B','L','L','B','S','L','L'};
 bN = check(path,size);

 /* if number of back is not 0 do again the loop */


while (bN != 0){
        int done = 0; /* to assure that the loop will do 1 DECITION each turn */
    for ( i =0; i< size; i++){

    if ( path[i] == 'B'){
            /* path will be optimized from LBL TO S*/

        if (path[i-1] == 'L' && path[i+1] == 'L' && done == 0){

            path[i-1] = 'S';

            /* rearrange the path */
            for(j = i; j< size; j++){

                path[j] = path [j+2];

            }
done =1;
        }
        /* path will be optimized from LBS TO R */
        if (path[i-1] == 'L' && path[i+1] == 'S' && done == 0){

            path[i-1] = 'R';
            for(j = i; j< size; j++){

                path[j] = path [j+2];

            }
            done =1;
        }

      /* path will be optimized from LBR TO B*/
        if (path[i-1] == 'L' && path[i+1] == 'R' && done == 0){

            path[i-1] = 'B';
            for(j = i; j< size; j++){

                path[j] = path [j+2];

            }
            done =1;
        }

  /* path will be optimized from RBL TO B*/
        if (path[i-1] == 'R' && path[i+1] == 'L' && done == 0){

            path[i-1] = 'B';
            for(j = i; j< size; j++){

                path[j] = path [j+2];

            }
            done =1;
        }


      /* path will be optimized from SBL TO R*/
        if (path[i-1] == 'S' && path[i+1] == 'L' && done == 0){

            path[i-1] = 'R';
            for(j = i; j< size; j++){

                path[j] = path [j+2];

            }
            done =1;
        }

      /* path will be optimized from SBS TO B*/
        if (path[i-1] == 'S' && path[i+1] == 'S' && done == 0){

            path[i-1] = 'B';
            for(j = i; j< size; j++){

                path[j] = path [j+2];

            }
            done =1;
        }


    }

    }



     bN = check(path,size);   /* check again the number of  backs in the path */

}

/* check the number of right char */

ISSUEprint = check_final(path,size);

printf("%d \n", ISSUEprint);


/* print the optimized path */

for(j = 0; j<ISSUEprint; j++){

                printf("%c ",path[j]);}
    return 0;
}



#endif