# include <stdio.h>

typedef struct {
    char name[20];
    int age;
    char gender;
}Student;

int main() {
    // 1.使用fwrite() + fread() 读写入二进制数据
        // 1.1 准备二进制数据，首先使用fscanf()读取txt文件中的数据，并存储在结构体数组中
    int capacity = 10;
    Student students[capacity];
    int count = 0;
    FILE *students_2 = fopen("resources/students_2.txt", "r");
    while ( count < capacity && fscanf(students_2,"%s %d %c",(students + count)->name,&(students + count)->age,&(students + count)->gender) == 3){
        count++;
    }
    printf("Read %d students from students_2.txt\n",count);
    fclose(students_2);
        // 1.2 使用fwrite()将结构体数组写入二进制文件
    FILE *students_2_bin = fopen("resources/students_2_bi.bin", "wb");
    fwrite(students,sizeof(Student),count,students_2_bin);
    printf("Write %d students to students_2_bi.bin\n",count);
    fclose(students_2_bin);
        // 1.3 使用fread()读取二进制文件
    FILE *students_2_bin_r = fopen("resources/students_2_bi.bin","rb");
    int new_capacity = 3;
    Student new_students[new_capacity];
    int new_count;
    while( (new_count = fread(new_students,sizeof(Student),new_capacity,students_2_bin_r)) != 0) {
        for (int j = 0 ; j < new_count ; j++) {
            printf("Name:%s, Age:%d, Gender:%c\n",(new_students + j)->name,(new_students + j)->age,(new_students +j)->gender);
        }
    }

    fclose(students_2_bin_r);
    return 0;
}

