# include <stdio.h>

int main() {
    // 1. 使用fputc()写入单个字符
    FILE *example_2 = fopen("resources/example_2.txt", "w");
    fputc('H', example_2);
    fputc('e', example_2);
    fputc('l', example_2);
    fputc('l', example_2);
    fputc('o', example_2);
    fputc(' ', example_2);

    // 2. 使用fputs()写入字符串
    fputs("World!", example_2);

    fclose(example_2);

    return 0;
}