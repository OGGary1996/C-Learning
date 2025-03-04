# include <stdio.h>
# include <string.h>

// 验证用户名和密码，总共三次机会

int main() {
    const char *username = "admin";
    const char *password = "123456";
    char input_username[20];
    char input_password[20];

    int step = 0;
    while (step < 3) {
        printf("Enter username: \n");
        fgets(input_username,sizeof(input_username),stdin);
        if (*(input_username + strlen(input_username) -1) == '\n') {
            *(input_username + strlen(input_username) -1) = '\0';
        }
        printf("Enter password: \n");
        fgets(input_password,sizeof(input_password),stdin);
        if (*(input_password + strlen(input_password) -1) == '\n') {
            *(input_password + strlen(input_password) -1) = '\0';
        }
        if (strcmp(input_username,username) == 0 && strcmp(input_password,password) == 0){
            printf("Login successfully!\n");
            break;
        }else {
            printf("Login failed! Please try again.\n");
            step++;
        }
    }
    (step == 3) ? printf("You have tried 3 times, please try again later.\n") : printf("Welcome!\n");

    return 0;
}