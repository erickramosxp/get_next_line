# Função get_next_line

A função `get_next_line` é uma função em C projetada para ler um arquivo linha por linha.

## Uso

Para usar a função `get_next_line`, inclua o cabeçalho `get_next_line.h` em seu código e compile-o com os arquivos fonte `get_next_line.c` e `get_next_line_utils.c`.

```c
#include "get_next_line.h"
#include <stdio.h>

int main() {
    int fd;
    char *line;

    fd = open("arquivo.txt", O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    while ((line = get_next_line(fd))) {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
```
# Assinatura da Função

```c
char *get_next_line(int fd);
```
A função get_next_line recebe um descritor de arquivo fd e retorna um ponteiro para a próxima linha lida do arquivo. Se não houver mais linhas para ler, a função retorna NULL.
