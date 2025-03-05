# include <stdio.h>
# include <string.h>

// 使用typedef关键字定义结构体别名
typedef struct Student {
    char name[50];
    char gender;
    int age;
    float score;
}Class1;

void print_struct_info (Class1 *p) {
    printf("Student info-> name:%s, gender:%c, age:%d, score:%.1f\n",
        p->name, p->gender, p->age, p->score);
}

void print_struct_array(Class1 *p , int size) {
    for (int i = 0 ; i < size ; i++) {
        printf("Student %d -> name: %s, gender: %c, age:%d, score: %.1f\n",
            i+1,(p+1)->name, (p+1)->gender, p->age, p->score);
    }
}

int main() {
    // 使用别名来声明结构体成员
    Class1 stu1 = {"Ke Zhang",'M',28,95.5};
    Class1 stu2;
    strncpy(stu2.name,"Tom",sizeof(stu2.name) - 1);
    *(stu2.name + sizeof(stu2.name) - 1) = '\0';
    stu2.gender = 'M';
    stu2.age = 18;
    stu2.score = 90.58;

    // 传递指针到函数
    Class1 *pinter_struct = &stu2;
    print_struct_info(pinter_struct);

    // 使用别名来声明结构体数组
    Class1 students[2] = {stu1,stu2};
    // 直接遍历打印结构体数组
    for (int stu = 0 ; stu < sizeof(students)/sizeof(students[0]) ; stu++){
        printf("Student %d -> name: %s, gender: %c, age:%d, score: %.1f\n",
               stu+1,(students+stu)->name,(students+stu)->gender,(students+stu)->age,(students+stu)->score);
    }
    // 传递指针到函数，在函数中打印结构体数组
    Class1 *pinter_struct_array = students;
    int size = sizeof(students)/sizeof(students[0]);
    print_struct_array(pinter_struct_array,size);



    return 0;
}