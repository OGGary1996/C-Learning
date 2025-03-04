#include <stdio.h>
#include <string.h>

// 字符串的相关操作

int main() {
    //1.计算字符串长度- strlen()
    char str[12] = "hello world";
    printf("Length of string: %lu.\n",strlen(str)); // 11,不包含\0
        // 通过这个操作，来去除使用fgets读取字符串时，字符串末尾的换行符
    char name[20];
    printf("Enter User name: \n");
    fgets(name,sizeof(name),stdin);
    printf("Length of name: %lu.\n",strlen(name)); // 区别于sizeof(name)，sizeof(name)是数组的总大小，strlen(name)是字符串的长度
    if (*(name + strlen(name) -1) == '\n') {
        *(name + strlen(name) -1) = '\0';
    }
    printf("Username: %s,welcome!\n",name);

    // 2.拷贝字符串- strcpy() & strncpy()
        // 1. strcpy()，这种方式不会检测目标数组的大小，可能会导致缓冲区溢出：
    char src[] = "Hello World!";
    char dest[6];
    // strcpy(dest,src);
    // printf("dest: %s\n",dest); // 此时无法打印，导致缓冲区溢出
        // 2. strncpy()，这种方式更安全，可以指定拷贝的长度：
        // 如果源数组的长度小于了目标数组，则会在自动填充\0
        // 如果源数组的长度大于了目标数组，则会截断，且不会添加\0
        // 首先保证要复制的长度小于一个单位的目标数组长度，以便于在最后添加\0
    strncpy(dest,src,sizeof(dest)-1);
    *(dest + sizeof(dest) - 1) = '\0';
    printf("dest: %s\n",dest);

    // 3. 连接字符串到目标数组- strcat() & strncat()
        // 1. strcat()，这种方式不检测目标数组的大小，可能会导致缓冲区溢出：
    char src_2[] = "World!";
    char dest_2[20] = "Hello,";
    // strcat(dest_2,src_2); // 这种方式会导致缓冲区溢出
        // 2. strncat()，这种方式更安全，在函数第三个参数中传递确切的剩余长度，并且会自动添加\0，所以-1 预留给\0
    strncat(dest_2,src_2, sizeof(dest_2) - 1 - strlen(dest_2));
    printf("dest_2: %s\n",dest_2);

    // 4. 比较字符串- strcmp() & strncmp()
        // 1. strcmp()，比较两个字符串是否相等（比较ASC II码），如果相等返回0。返回正数则前者大，区分大小写
    char str_1[] = "apple pie";
    char str_2[] = "apple cider";
    switch (strcmp(str_1,str_2)) {
        case 1:
            printf("String 1 is greater than string 2.\n");
            break;
        case 0:
            printf("String 1 is equal to string 2.\n");
            break;
        case -1:
            printf("String 1 is less than string 2.\n");
            break;
        default:;
    }
        // 2.strncpm()，比较两个字符串的前n个字符是否相等
    int result = strncmp(str_1,str_2,5); // 比较两个字符串的前5个字符是否相等
    (result == 0) ? printf("The first 5 characters of the two strings are the same.\n") : printf("The first 5 characters of the two strings are different.\n");

    // 5. 查找字符串- strchr() & strrchr()
        // 1. strchr()，查找字符串中第一次出现的指定字符的位置
    char str_3[] = "hello world";
    char *p = strchr(str_3,'l');
    (p != NULL) ? printf("First fund at index:%ld",p-str_3) : printf("Not found.\n");
        // 2. strrchr()，查找字符串中最后一次出现的指定字符的位置
    char *last_p = strrchr(str_3,'l');
    (last_p != NULL) ? printf("Last found at index:%ld",last_p-str_3) : printf("Not found.\n");

    // 6.查找字符串- strstr()
        // strstr()，查找字符串中第一次出现的指定字符串的位置
    char str_4[] = "hello,world!";
    char str_5[] = "world";
    char *p_2 = strstr(str_4,str_5);
    (p_2 != NULL) ? printf("Found at index:%ld\n",p_2-str_4) : printf("Not found.\n");

    // 7. 字符串分割- strtok()
    char str_6[] = "hello,world,how,are,you";
    char *token = strtok(str_6,",");
    while (token != NULL) {
        printf("%s ",token);
        token = strtok(NULL,",");
    }
    printf("\n");

    return 0;
}