#include <stdio.h>
#include <sys/_types/_null.h>

char *READ(char name[]) { return name; }
char *EVAL(char name[]) { return name; }
char *PRINT(char name[]) { return name; }
char *rep(char name[]) {
  char *read = READ(name);
  char *eval = EVAL(read);
  char *print = PRINT(eval);

  return print;
}

int main() {
  char input[1000];
  while (1) {
    printf("user> ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
      break;
    }

    printf("%s", rep(input));
  }

  puts("\nBYE!");

  return 0;
}
