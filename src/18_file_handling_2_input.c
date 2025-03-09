# include <stdio.h>

typedef struct{
    char name[20];
    int age;
    char gender;
}Student;

int main() {
    // 1.通过fread()读取二进制文件到结构体
    FILE *students_bi = fopen("resources/students_bi.bin","rb");
    // 创建结构体数组，每3个结构体为一组
    int size = 3;
    Student stu_list[size];
    int number;
    while ( (number = fread(stu_list,sizeof(Student),size,students_bi)) != 0) {
        for (int i = 0 ; i < number ; i++) {
            printf("Name:%s, Age:%d, Gender:%c\n",(stu_list + i)->name, (stu_list + i)->age,(stu_list + i)->gender);
        }
    }

    fclose(students_bi);

    // 2. 通过fscanf()读取文本文件到结构体
    FILE *students_txt = fopen("resources/students.txt","r");
    int size2 = 20;
    Student stu_list2[size2];
    int count = 0;
    while (count<size2 && (fscanf(students_txt,"%s %d %c",(stu_list2 + count)->name,&(stu_list2 + count)->age,&(stu_list2 + count)->gender) == 3) ) {// 这里的3表示每次读取到的name,age,gender三个数据，与size2无关
        count++;
    }
    for (int i = 0 ; i < count ; i++) {
        printf("Name:%s, Age:%d, Gender:%c\n",(stu_list2 + i)->name,(stu_list2 + i)->age,(stu_list2 + i)->gender);
    }
    fclose(students_txt);


    return 0;
}