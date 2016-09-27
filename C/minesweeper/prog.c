#include <stdio.h>
#include <stdlib.h>

void clearField();
void displayField(int nField);
void increment(int i, int j);
int isInsideBounds(int i, int j);
void setMine(int i, int j);

char field[101][101] = {0}; // We allocate a 100 bytes more to handle the field display
int m,n; // M x N active field

int main(int argc, char const *argv[]) {

  int nField = 1;

  for (;;) {

    scanf("%d %d", &n, &m);
    ((m==0 && n==0) ? exit(0) : 0); // stopping conditionnal statement

    // initialization loop
    for (size_t i = 0; i < n; i++) {
      scanf("%s", field[i]);
    }

    clearField(); // replacing all the '.' by '0'

    // processing loop
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        (field[i][j] == '*' ? setMine(i,j) : 0);
      }
    }

    // display the result
    displayField(nField);

    nField++;

  }

  return 0;
}

void clearField()
{
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      (field[i][j] == '.' ? field[i][j] = '0' : 0);
    }
  }
}

void displayField(int nField)
{
  printf("Field #%d:\n", nField);
  for (size_t i = 0; i < n; i++) {
    /*
      Here, we need the field to be [101][101] because in case of a 100x100 field
      it needs to know when to stop
    */
    printf("%s\n", field[i]);
  }
  printf("\n");
}

void increment(int i, int j)
{
  if (isInsideBounds(i,j) && field[i][j] != '*') // check if the position in in the field, and if it's not a star
    field[i][j]++;
}

int isInsideBounds(int i, int j)
{
  return (i>=0 && i<n && j>=0 && j<m);
}

void setMine(int i, int j)
{
  for (int k = -1; k <= 1; k++) {
    for (int l = -1; l <= 1; l++) {
      increment(i+k,j+l); // increment the surroundings positions
    }
  }
}
