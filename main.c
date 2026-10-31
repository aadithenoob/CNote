#include <stdio.h>
#include <string.h>

#define HELP_FLAG "Usage: ./cnote <flag> <filepath>\n" \
                  "\nFlags:\n" \
                  "  -c, --create   create a note with filepath\n" \
                  "  -h, --help     display this text and exit\n"

int eval_args(char *flag, FILE *fp) {
    if (strcmp(flag, "-c") || strcmp(flag, "--create")) {
        char line_buffer[256];
        printf("Enter content (type 'END' to finish):\n\n");

        while (fgets(line_buffer, sizeof(line_buffer), stdin) != NULL) {
            if (strcmp(line_buffer, "END\n") == 0) {
                break;
            }
            fputs(line_buffer, fp);
        }

        if (ferror(fp)) {
            printf("\nError: Could not write into file.\n");
            return 1;
        }
    }

    printf("\nNote created.\n");
    return 0;
}

int main(int argc, char** argv) {
    if (argc > 2) {
        char *flag = argv[1];
        char *filepath = argv[2];
        filepath[strcspn(filepath, "\n")] = '\0';

        if (flag == NULL || strcmp(filepath, "") == 0) {
            printf(HELP_FLAG);
            return 1;
        }
        
        flag[strcspn(flag, "\n")] = '\0';
        FILE *fp = fopen(filepath, "wx");
        if (fp == NULL) {
            printf("Error: Could not open file or file already exists.\n");
            return 1;
        }

        if (eval_args(flag, fp) != 0) {
            return 1;
        }

        fclose(fp);
    } else {
        char *flag = argv[1];
        if (flag == NULL) {
            printf(HELP_FLAG);
            return 1;
        }

        flag[strcspn(flag, "\n")] = '\0';

        if (strcmp(flag, "-h") == 0 || strcmp(flag, "--help") == 0) {
            printf(HELP_FLAG);
            return 0;
        } else {
            printf("Error: Please enter a valid flag (-c/--create or -h/--help).\n");
            return 1;
        }
    }
}
