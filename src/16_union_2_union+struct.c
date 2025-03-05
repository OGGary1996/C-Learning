# include <stdio.h>
# include <string.h>

// 使用union处理不同的数据类型
union Value {
    int int_value;
    double double_value;
    char str_value[20];
};
void print_value(union Value value , char type){
    switch (type){
        case 'i':
            printf("Value: %d\n",value.int_value);
            break;
        case 'd':
            printf("Value: %f\n",value.double_value);
            break;
        case 's':
            printf("Value: %s\n",value.str_value);
            break;
        default:
            printf("Unknown type.\n");
    }
};


// 结合struct使用
typedef struct {
    char type;
    union {
        int int_value;
        double double_value;
        char str_value[20];
    }Data_value;
}Data;
void print_data(Data data){
    switch(data.type) {
        case 'i':
            printf("Data: %d\n",data.Data_value.int_value);
            break;
        case 'd':
            printf("Data: %f\n",data.Data_value.double_value);
            break;
        case 's':
            printf("Data: %s\n",data.Data_value.str_value);
            break;
        default:
            printf("Unknown type.\n");
    }
}



int main() {
    // 访问union的成员
    union Value value1;
    value1.int_value = 100;
    print_value(value1,'i');
    value1.double_value = 100.0;
    print_value(value1,'d');
    // value1.str_value = "100"; // 不能直接赋值
    strncpy(value1.str_value,"100",sizeof(value1.str_value) - 1);
    (value1.str_value + sizeof(value1.str_value) - 1)[0] = '\0'; // 保证字符串的结尾
    print_value(value1,'s');

    // 结合struct使用, 通过type来区分不同的数据类型
    Data data1;
    data1.type = 'i';
    data1.Data_value.int_value = 100;
    print_data(data1);
    data1.type = 'd';
    data1.Data_value.double_value = 100.0;
    print_data(data1);
    data1.type = 's';
    strncpy(data1.Data_value.str_value,"100",sizeof(data1.Data_value.str_value) - 1);
    (data1.Data_value.str_value + sizeof(data1.Data_value.str_value) - 1)[0] = '\0'; // 保证字符串的结尾
    print_data(data1);

    return 0;
}