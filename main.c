#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//@author Andrei Baechle

// frees allocated memory for the triangle
void destroy_Pascal(unsigned long** P, unsigned N){

  for (int i = 0; i < N; ++i) {
    if (P[i] == NULL){
      break;
    }
    free(P[i]);
}
free(P);
}


unsigned long** build_Pascal(unsigned N){
  unsigned long** tArr;
	unsigned row, col;

  if (N <= 0){
    printf("error: the triagnle should have more than zero rows.");
    return NULL;
  }
  //allocate memory, destroy if fail
  tArr = (unsigned long **) malloc((N + 1) * sizeof(unsigned long **));
  if (tArr == NULL) {
    printf("malloc failed!");
    return NULL;
  }
  for (int i = 0; i <= N; i++) {
    tArr[i] = (unsigned long *) malloc((i + 1) * sizeof(unsigned long*));
    if (tArr[i] == NULL) {
      printf("malloc failed!");
      destroy_Pascal(tArr, N);
      return NULL;
    }
  }
  //fills first set of rows with default vals
  if (N >= 1) {
	tArr[0][0] = (unsigned)1;
  }
  if (N >= 2) {
  tArr[1][0] = (unsigned)1;
	tArr[1][1] = (unsigned)1;
  }


  //Fills in the other rows 
	for(row = 2; row < N; row++){
		tArr[row][0] = (unsigned)1;
		for(col = 1; col <= row; col++){
			 tArr[row][col] = (unsigned) tArr[row -1][col -1] + tArr[row - 1][col];
      
		}
    tArr[row][row] = (unsigned)1;
	}
 return tArr;
}

// format and print lines...probably not the most efficient way to do this but im out of time lol
void show_Pascal(unsigned long**P, unsigned N){
  unsigned row, col; 

	 for(row = 0; row < N; row++){
		for(col = 0; col <= row; col++){
        if (P[N-1][col] > 99999){
          if (P[row][col] < 10)
          printf("     %lu ", P[row][col]);
          else if (P[row][col] < 99)
          printf("    %lu ", P[row][col]);
          else if (P[row][col] < 999)
          printf("   %lu ", P[row][col]);
          else if (P[row][col] < 9999)
          printf("  %lu ", P[row][col]);
          else if (P[row][col] < 99999)
          printf(" %lu ", P[row][col]);
          else
          printf("%lu ", P[row][col]);
        }

        else if (P[N-1][col] > 9999){
          if (P[row][col] < 10)
          printf("    %lu ", P[row][col]);
          else if (P[row][col] < 99)
          printf("   %lu ", P[row][col]);
          else if (P[row][col] < 999)
          printf("  %lu ", P[row][col]);
          else if (P[row][col] < 9999)
          printf(" %lu ", P[row][col]);
          else
          printf("%lu ", P[row][col]);
        }

        else if (P[N-1][col] > 999){
          if (P[row][col] < 10)
          printf("   %lu ", P[row][col]);
          else if (P[row][col] < 99)
          printf("  %lu ", P[row][col]);
          else if (P[row][col] < 999)
          printf(" %lu ", P[row][col]);
          else
          printf("%lu ", P[row][col]);
        }

        else if (P[N-1][col] > 99){
          if (P[row][col] < 10)
          printf("  %lu ", P[row][col]);
          else if (P[row][col] < 99)
          printf(" %lu ", P[row][col]);
          else
          printf("%lu ", P[row][col]);
        }

        else if (P[N-1][col] > 9){
          if (P[row][col] < 10)
          printf(" %lu ", P[row][col]);
          else
          printf("%lu ", P[row][col]);
        }

        else{
        printf("%lu ", P[row][col]);
        }
      }
    printf("\n");
   }
}

int main(void) {
  unsigned userSize;
  //Prompts user for number and reads in
	printf("Enter the number of rows for Pascal's Triangle: ");
	scanf("%d", &userSize);

  if (userSize < 0){
    printf("error: the triagnle should have more than zero rows.");
    exit(1);
  }
    
	//Calls function to calculate and print Pascal's Triangle
	unsigned long** P = build_Pascal(userSize);
  show_Pascal(P, userSize);
  destroy_Pascal(P, userSize);

  return 0;
}
