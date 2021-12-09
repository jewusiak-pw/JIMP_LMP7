#include <stdio.h>  // wiadomo po co
#include <stdlib.h>
#include <string.h> // strstr

#include "list.h"
#include "skorowidz.h"

#define BUFSIZE 8192   // zakładamy, że linie będą krótsze niż 8kB

int main(int argc, char **argv) {
    int i;
    int nr_linii;
    char buf[BUFSIZE];



    FILE *in = argc > 1 ? fopen(argv[1], "r") : stdin;

    skorowidz_t skorowidz;

    zainicjuj_skorowidz(argc, argv, &skorowidz);

    if (skorowidz.ile_slow == 0) {
        fprintf(stderr, "%s: błąd: proszę podać słowa do wyszukiwania\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (in == NULL) {
        fprintf(stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }

    nr_linii = 0;
  char *p;
  int dl;
  int ile;
  int j;
  int k;
  while( fgets( buf, BUFSIZE, in ) != NULL )
  {
    nr_linii++;
    dl=strlen(buf);
    for( i= 0; i < skorowidz.ile_slow; i++ )
    {
        p=strstr(buf,skorowidz.slowa[i]);
        while(p!=NULL)
        {
                ile=0;
                j=0;
                for(j;j<strlen(p);j++)
                {
                        if( (p[j]>=65 && p[j]<=90) || (p[j]>=97 && p[j]<=122) )
                        {
                                ile+=1;
                        }
                        else
                        {
                                break;
                        }
                }
                if( strlen(skorowidz.slowa[i])==ile )
                {
                        k=(dl-strlen(p)-1);
                        if( strlen(p)==dl )
                        {
                                dodaj_pozycje_skorowidza( &skorowidz,i,nr_linii );
                                break;
                        }
                        if ( p[k]<65 || (p[k]>90 && p[k]<97) || p[k]>122 )
                        {
                                dodaj_pozycje_skorowidza( &skorowidz,i,nr_linii );
                                break;
                        }
                }
                p+=1;
                p=strstr(p,skorowidz.slowa[i]);
        }
    }
  }


    wypisz_skorowidz(&skorowidz);

    return EXIT_SUCCESS;
}
