#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

  FILE *fp;
  long int pola_sekunde = 50000L;

  while(1){

    fp = fopen("/dev/led","w");

    if(fp == NULL){

      printf("Problem pri otvaranju /dev/led\n");
      return -1;
    }

    fputs("0x0F\n",fp);

    if(fclose(fp)){

      printf("Problem pri zatvaranju /dev/led\n");
      return -1;
    }

    usleep(pola_sekunde);

    fp = fopen("/dev/led","w");

    if(fp == NULL){

      printf("Problem pri otvaranju /dev/led\n");
      return -1;
    }

    fputs("0x00\n",fp);

    if(fclose(fp)){

      printf("Problem pri zatvaranju /dev/led\n");
      return -1;
    }

    usleep(pola_sekunde);
  }

}
