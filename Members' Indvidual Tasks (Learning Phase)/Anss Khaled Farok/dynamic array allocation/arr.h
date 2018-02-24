#ifndef _ARR_H
#define _ARR_H


/* ** PROTOTYPES ** */
void initArr(Arr *s );

void pushArr(Arr *s , uint8_t a);

char popArr(Arr *s , uint8_t index);

void freeArr(Arr *s);

uint8_t sizeArr(Arr *s);


#endif