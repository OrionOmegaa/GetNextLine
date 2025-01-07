#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int    main(void)
{
    int        fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Erreur d'ouverture du fichier");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Ligne lue : [%s]", line);
        free(line);
    }
    close(fd);
    return (0);
}