# include <stdio.h>
# include <string.h>

// 1.先定义内部结构体，在定义外部结构体; 这种方式可以复用内部结构体
typedef struct {
    char phone[20];
    char email[30];
}contact_info;

typedef struct {
    char name[20];
    int age;
    contact_info info;
}Students;

typedef struct {
    char name[20];
    int age;
    contact_info info;
}Staff;

// 2.直接定义内部结构体, 这种方式不可以复用内部结构体
typedef struct {
    char name[20];
    int age;
    struct {
        int year;
        int month;
        int day;
    }birthday;
}employee;


int main () {
    // 声明结构体变量1
    contact_info info1;
    strcpy(info1.phone,"(123)-456-789");
    strcpy(info1.email,"123456@gmail.com");
    Students stu1;
    strcpy(stu1.name,"Tom");
    stu1.age = 20;
    stu1.info = info1;
    printf("Student name:%s, age:%d; contact_info: phone:%s, email:%s\n",
           stu1.name,stu1.age,stu1.info.phone,stu1.info.email);

    // 声明结构体变量2
    employee emp1 = {"Jack",30,{1990,1,1}};
    printf("Employee name:%s, age:%d; birthday: %d-%d-%d\n",
           emp1.name,emp1.age,emp1.birthday.year,emp1.birthday.month,emp1.birthday.day);

    return 0;
}