#include "linenoise/linenoise.h"
#include <stdio.h>
#include <sys/_types/_null.h>

char *READ(char in[]) { return in; }
char *EVAL(char in[]) { return in; }
char *PRINT(char in[]) { return in; }
char *rep(char in[]) {
  char *read = READ(in);
  char *eval = EVAL(read);
  char *print = PRINT(eval);

  return print;
}

int main() {
  char *line;
  linenoiseSetMultiLine(0);
  linenoiseHistoryLoad("history.txt");
  while ((line = linenoise("user> ")) != NULL) {
    printf("%s\n", rep(line));
    linenoiseHistoryAdd(line);
    linenoiseHistorySave("history.txt");

    linenoiseFree(line);
  }

  puts("\nBYE!");

  return 0;
}
