# include <stdio.h>
# include <string.h>

// 定义结构体
typedef struct {
    char city[20];
    char street[30];
    int number;
}Address;
typedef struct {
    char phone[20];
    char email[30];
}Contact_info;
typedef struct {
    int year;
    int month;
    int day;
}Birthday;

typedef struct {
    char name[20];
    char gender;
    Birthday birthday;
    Contact_info contact_info;
    Address address;
}Employee;

// 打印函数
void print_employee(Employee *p,int size){
    for (int i = 0 ; i < size ; i++){
        printf("Employee %d ->name:%s, gender:%c, Birthday:%d-%d-%d, Contact: Phone-%s, Email-%s, Address: %s-%s-%d\n",
               i+1,(p+i)->name,(p+i)->gender,(p+i)->birthday.year,(p+i)->birthday.month,(p+i)->birthday.day,
               (p+i)->contact_info.phone,(p+i)->contact_info.email,
               (p+i)->address.city,(p+i)->address.street,(p+i)->address.number);
    }
}

int main() {
    // 声明结构体成员
    //1
    Address addr1 = {"Shanghai","Nanjing Road",100};
    Contact_info info1 = {"(123)-456-789","12345@gmail.com"};
    Birthday birth1 = {1990,1,1};
    Employee emp1 = {"Jack",'M',birth1,info1,addr1};
    //2
    Address addr2 = {"Beijing","Wangfujing Street",200};
    Contact_info info2 = {"(456)-789-123","asdfc@gmail.com"};
    Birthday birth2 = {1995,2,2};
    Employee emp2 = {"Tom",'M',birth2,info2,addr2};
    // 创建结构体数组
    Employee emps[2] = {emp1,emp2};
    // 传递进打印函数
    print_employee(emps,2);


}