#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MS_LEN 20       // length of the ms values
#define NB_DIV 6        // number of div to display + 1

void printRow(char * cell1, char * cell2) {
    printf("%s\t|\t%s\n", cell1, cell2);
}

int main(int argc, char ** args) {
    double bpm = atof(args[1]);
    double ms[NB_DIV];
    char mschar[NB_DIV][MS_LEN];
    char divchar[NB_DIV][MS_LEN];

    // First row
    sprintf(divchar[0], "1/1");
    ms[0] = (bpm/60)*1000;
    sprintf(mschar[0], "%.0f ms", ms[0]);
    printRow("1/1", mschar[0]);

    // Other rows
    for(int i=1;i<NB_DIV;i++) {
        sprintf(divchar[i], "1/%.0f", pow(2, i));
        ms[i] = (ms[i-1]/2);
        sprintf(mschar[i], "%.0f ms", ms[i]);
        printRow(divchar[i], mschar[i]);
    }

    return 0;    
}