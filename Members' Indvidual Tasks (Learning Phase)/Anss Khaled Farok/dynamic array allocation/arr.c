#include "arr.h"

typedef struct arr
{
	uint8_t *str;	/* pointer to base of array */
	uint8_t size;	/* size of elements & index of last element to be occupied   */

}Arr;

void initArr(Arr *s ){ /* initialize array */
	s->size = 0;	
	s->str = (uint8_t *)malloc(sizeof(s->str));	/* allocate space in memory of type uint8_t */
}

void pushArr(Arr *s , uint8_t a){ /* add items to array */

	s->str = (uint8_t *)realloc(s->str , sizeof(s->str)); /* allocate new space in memory */
	s->str[(s->size)++] = a;
	s->str[(s->size)] = '\0'; /* last element of array always = NULL */
}

char popArr(Arr *s , uint8_t index){ /* pop element from array with specific index  */
	return s->str[index];
}

void freeArr(Arr *s){ /* free all allocated space & initialize Arr */
	s->size = 0;
	free(s->str);
	s->str = (uint8_t *)malloc(sizeof(s->str));
}

uint8_t sizeArr(Arr *s){
	return (s->size - 1); /* Number of element in array **Neglecting NULL index** */ 
}
