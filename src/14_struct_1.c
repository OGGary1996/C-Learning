# include <stdio.h>
# include <string.h>

// 1. 定义结构体
struct Student {
    char name[50];
    char gender;
    int age;
    float score;
};

struct Person {
    char name[50];
    char gender;
    int age;
};

void print_info (struct Student *p_Student) {
    // 通过结构体的指针访问结构体的成员,也可以使用(*p_Student).name
    printf("Name: %s\n",p_Student->name);
    printf("Gender: %c\n",p_Student->gender);
    printf("Age: %d\n",p_Student->age);
    printf("Score: %.1f\n",p_Student->score);
}

int main () {
// 2. 结构体初始化
    // 1. 直接初始化
    struct Student s1 = {"Tom",'M',18,90.5};
    printf("Name: %s\n",s1.name);
    printf("Gender: %c\n",s1.gender);
    printf("Age: %d\n",s1.age);
    printf("Score: %.1f\n",s1.score);
    // 2. 逐个初始化
    struct Student s2;
        // s2.name = "Ke Zhang"; 在后赋值时，需要使用strcpy函数
    strncpy(s2.name,"Ke Zhang",sizeof(s2.name) - 1);
    *(s2.name + sizeof(s2.name) - 1) = '\0';
    s2.gender = 'M';
    s2.age = 28;
    s2.score = 95.5;

// 3. 获取结构体的指针，传递指针到函数,否则只会传递副本进去，不会改变原来的值
    // 结构体不能直接传递，需要传递指针
    struct Student *p_Student = &s2;
    print_info(p_Student);

// 4. 结构体数组
    // 将多个相同结构的结构体放在一个数组中
    struct Student students[2] = {s1,s2};
    for (int i = 0 ; i < sizeof(students)/sizeof(students[0]) ; i++) {
        // printf("Name: %s; Gender: %c; Age: %d; Score: %.1f\n", // 通过数组索引访问结构体的成员
        //     students[i].name,students[i].gender,students[i].age,students[i].score);

        printf("Name: %s; Gender: %c; Age: %d; Score: %.1f\n",// 通过结构体的指针访问结构体的成员
            (students + i)->name,(students + i)->gender,(students + i)->age,(students + i)->score);
    }

    //example 2:
    struct Person p1;
    struct Person p2 = {"Tom",'M',18};
    struct Person p3 = {"Gerry",'F',20};
    strncpy(p1.name,"Ke Zhang",sizeof(p1.name)-1);
    *(p1.name + sizeof(p1.name) - 1) = '\0';
    p1.gender = 'M';
    p1.age = 28;

    struct Person person[3] = {p1,p2,p3};
    for (int i = 0 ; i < sizeof(person)/sizeof(person[0]) ; i++) {
        printf("Person %d -> name: %s, gender: %c, age: %d\n",
            i+1, (person + i)->name,(person + i)->gender,(person + i)->age);
    }




    return 0;
}