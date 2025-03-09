#include <stdio.h>
#include <string.h>


int main() {
    // 打开文档
    FILE *example_file = fopen("resources/example.txt","r"); // 只读模式
    if (example_file == NULL) {
        printf("File not found\n");
        return 1;
    }
    // 1.使用三种方式读取文件
        // 1.1 fgetc()
    int data;
    while((data=fgetc(example_file)) != -1){
        printf("%c",data);
    }
    printf("\n");

        // 1.2 fgets()
    char buffer[1024];
    while (fgets(buffer,sizeof(buffer),example_file) != NULL) { // 只会读取sizeof(buffer)-1个字符,最后一个字符自动为'\0'
        // 如果末尾有换行符，去掉换行符
        if (*(buffer + strlen(buffer) -1) == '\n') {
            *(buffer + strlen(buffer) -1) = '\0';
        }
        printf("%s\n",buffer);
    }
    printf("\n");

        // 1.3 fread()
    char buffer2[1024];
    while (fread(buffer2,sizeof(char),sizeof(buffer2),example_file) != 0) {
        printf("%s",buffer2);
    }
        // 如果文件中存在中文，fread()会出现乱码，因为fread()是以字节为单位读取的，而中文占用两个字节
        // 解决方法：在遍历时，以字符为单位读取，而不是字符串
    FILE *example_cn = fopen("resources/example_cn.txt","r");
    char buffer_cn[1024];
    int number;
    while ((number = fread(buffer_cn,sizeof(char),sizeof(buffer_cn),example_cn)) != 0) {
        for (int i = 0 ; i < number ;i++) { // 内层循环的作用是每次读取到文件之后，以读取到的个数为界限，遍历读取到的字符
            printf("%c",*(buffer_cn + i));
        }
    }

        // 1.4 fscanf()
    char buffer3[1024];
    while (fscanf(example_file,"%s",buffer3) != EOF) {
        printf("%s\n",buffer3);
    }

    fclose(example_file); // 关闭文档

    return 0;
}