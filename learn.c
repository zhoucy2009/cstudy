#include <ctype.h>
#include <stdio.h>
#include <string.h>
// ------------------Name,age,number-----------------------
// int age = 16;
// int number = 11;
// int main() {
//   printf("My name is Bill\n");
//   printf("I am %d years old\n", age);
//       printf("My favourite number is: %d\n", number);
//       return 0;
// }
//-------------------Addition Calculation------------------------
// int a, b, c;
// int main() {
//   printf("Enter the first number:");
//   scanf("%d", &a);
//   printf("Enter the second number:");
//   scanf("%d", &b);
//   c = a + b;
//   printf("The sum is: %d\n", c);
//   return 0;
// }
//--------------------------Circumference of a circle
// calculation-----------------------
// double r;
// double area;
// int main(){
//     printf("Enter the radius of the circle:");
//     scanf("%lf",&r);
//     area = 3.1415926535 * (r * r);
//     printf("area of the circle = %.2f\n",area);
//     return 0;
// }
//-------------------------Grade Rating
// system------------------------------------
// int score;
// int main() {
//   printf("enter your score out of 100:");
//   while (1){
//     if (scanf("%d",&score)!=1){
//         printf("Invalid input,please enter a number:");
//         while (getchar() != '\n')
//           ;
//         continue;
//     }

//     else if(score < 0||score > 100){
//         printf("Invalid input, please enter a number within the range:");
//         continue;
//     }
//     break;
//   }
//   if (score >= 90) {
//     printf("grade A\n");
//   } else if (score >= 80) {
//     printf("grade B\n");
//   } else if (score >= 70) {
//     printf("grade C\n");
//   } else {
//     printf("grade D\n");
//   }
//   return 0;
// }
//-------------------------Calculator(using switch)----------------------------
// double a, b, c;
// int d;
// int main() {
//   printf("Please enter the first number:");
//   scanf("%2lf", &a);
//   printf("Please enter the second number:");
//   scanf("%lf", &b);
//   printf("\n1:+\n2:-\n3:*\n4:/\nPlease enter the sign:");
//   while (1) {
//     if (scanf("%d", &d) != 1) {
//       printf("Invalid input,please enter a number:");
//       while (getchar() != '\n')
//         ;
//       continue;
//     }

//     else if (d < 1 || d > 4) {
//       printf("Invalid input, please enter a number within the range:");
//       continue;
//     }
//     break;
//   }
//   switch (d) {
//   case 1:
//     c = a + b;
//     printf("%2lf + %2lf = %2lf\n", a, b, c);
//     break;
//   case 2:
//     c = a - b;
//     printf("%2lf - %2lf = %2lf\n", a, b, c);
//     break;
//   case 3:
//     c = a * b;
//     printf("%2lf * %2lf = %2lf\n", a, b, c);
//     break;
//   case 4:
//     if (b == 0) {
//       printf("Devisor cannot be 0");
//     } else {
//       c = a / b;
//       printf("%2lf / %2lf = %2lf\n", a, b, c);
//     }
//     break;
//   default:
//     printf("Invalid choice\n");
//     break;
//   }

//   return 0;
// }
// // --------------Even or Odd number determination------------------
// long a;
// int main() {
//   printf("Please enter a number:");
//   while (1) {
//     if (scanf("%ld", &a) != 1) {
//       printf("Invalid input,please enter a positive integer:");
//       while (getchar() != '\n')
//         ;
//       continue;
//     }

//     else if (a < 0) {
//       printf("Invalid input, please enter a positive integer:");
//       continue;
//     }
//     break;
//   }
//   if (a % 2 == 0) {
//     printf("Number %ld is an even number.\n", a);
//   } else {
//     printf("Number %ld is an odd number.\n", a);
//   }
//   return 0;
// }
//------------------Sum of 1 to n----------------------
// int n;
// int s = 0;
// int main(){
//     printf("Please enter a number n:");
//     scanf("%d",&n);
//     for (int i =1;i<=n;i++){
//         s += i;
//     }
//     printf("sum of number 1 to n is: %d\n",s);
//     return 0;
// }
//--------------99 multiply table------------------------
// int r;
// int i;
// int j;
// int main(){
//     for (i=1;i<=9;i++){
//         for (j=1;j<=i;j++){
//             r = i * j;
//             // printf("%d*%d=%2d  ",j,i,r);
//             if(r<10){
//                 printf("%d*%d=%d   ",j,i,r);
//             }
//             else{
//                 printf("%d*%d=%d  ",j,i,r);
//             }
//         }
//         printf("\n");
//     }
//     return 0;
// }
//-------------------Types of integer statistics--------------------
// int main(){
//     int a = 0;
//     int p = 0;
//     int n = 0;
//     int zero = 0;
//     while(1){
//         printf("Enter a number(enter 9999 to quit):");
//         scanf("%d",&a);
//         if (a==9999){
//             printf("Process ended");
//             printf("\nnegative number:%d\npositive
//             number:%d\nzero:%d\n",n,p,zero); break;
//         }
//         else if (a > 0){
//             p +=1;
//         }
//         else if (a < 0){
//             n += 1;
//         }
//         else if (a == 0){
//             zero += 1;
//         }
//     }
//     return 0;
// }
//-----------------------Simple events List----------------------
// int main() {
//   int a;
//   do {
//     printf("1.say hello\n");
//     printf("2.print name\n");
//     printf("3.Exit\n");
//     printf("Enter a choice(1/2/3):");
//     if (scanf("%d", &a) != 1) {
//       while (getchar() != '\n')
//         ;
//       printf("Invalid input, please choose a number between 1,2 and 3.\n");
//       a=0;
//       continue;
//     } else if (a == 1) {
//       printf("Hello!\n");
//     } else if (a == 2) {
//       printf("Bill!\n");
//     } else if(a == 3){
//         printf("Bye!\n");
//         break;
//     }
//     else{
//         printf("Invalid input, please enter an integer within the range.\n");
//     }
//   } while (a != 3);

//   return 0;
// }
//-------------------Enter 5 numbers and output the maximum,minimum and
// sum---------------------
// int main() {
//   int arr[5];
//   int sum = 0;
//   for (int i = 0; i < 5; i++) {
//     printf("please enter #%d element of the array:", i+1);
//     scanf("%d", &arr[i]);
//     sum += arr[i];
//   }
//   int max = arr[0];
//   int min = arr[0];
//   for (int j = 0; j < 5; j++) {
//     if (arr[j] > max) {
//       max = arr[j];
//     }
//     else if (arr[j] < min) {
//       min = arr[j];
//     }
//     else{
//         continue;
//     }
//   }
//   printf("maximum:%d\nminimum:%d\nsum:%d\n", max, min, sum);
//   return 0;
// }
//------------Enter names and print them out------------
// int main(){
//     char name [50];
//     printf("Please enter your name:");
//     fgets(name, sizeof(name), stdin);
//     int len = strlen(name);
//     if(len >0 && name[len-1]=='\n'){
//         name[len-1]='\0';
//         len --;
//     }
//     // for(int i=0;i<len;i++){
//     //     printf("%c",name[i]);
//     //     if (i == len-1){
//     //         printf("\n");
//     //     }
//     // }
//     printf("Hello!%s!\n",name);
//     return 0;
// }
//-------------------Enter 5 numbers and output the maximum,minimum and
// sum------------------
// int main(){
//     int arr[10];
//     for(int i=0;i<10;i++){
//         printf("please enter the #%d element of the array:",i+1);
//         scanf("%d",&arr[i]);
//     }
//     int max = arr[0];
//     int min = arr[0];
//     int sum = 0;
//     for(int j=0;j<10;j++){
//         if (arr[j]>max){
//             max = arr[j];
//         }
//         else if(arr[j]<min){
//             min = arr[j];
//         }
//         sum += arr[j];
//     }
//     printf("max:%d\nmin:%d\nsum:%d\n",max,min,sum);

// }
//-------------Enter two names, compare if they are the same---------------
// int main() {
//   char name1[50];
//   char name2[50];
//   printf("Please enter the first name:");
//   fgets(name1, sizeof(name1), stdin);
//   printf("Please enter the second name:");
//   fgets(name2, sizeof(name2), stdin);
//   int length1 = strlen(name1);
//   int length2 = strlen(name2);
//   if (length1 > 0 && name1[length1 - 1] == '\n') {
//     name1[length1 - 1] = '\0';
//     length1--;
//   }
//   int write1 = 0;
//    for (int read1 = 0; read1 < length1; read1++) {
//         if (isalpha(name1[read1])) {
//             name1[write1] = tolower(name1[read1]);
//             write1++;
//             continue;       // 条件：为字母

//         }
//     }
//     name1[write1] = '\0';
//     length1 = write1;
//     printf("%s\n",name1);
//   if (length2 > 0 && name2[length2 - 1] == '\n') {
//     name2[length2 - 1] = '\0';
//     length2--;
//   }
//   int write2 = 0;
//    for (int read2 = 0; read2 < length2; read2++) {
//         if (isalpha(name2[read2])) {
//             name2[write2] = tolower(name2[read2]);    // 把它往前挪
//             write2++;       // 条件：为字母
//             continue;
//         }
//     }
//     name2[write2]='\0';
//     length2 = write2;
//     printf("%s\n",name2);
// // 使用 read 指针 从头到尾扫描数组的每一个元素
// // （read 每次 +1）

// // 使用 write 指针 指向“下一个要写入的位置”
// // （初始为 0）

// // 如果元素符合“保留条件”
// // → 把它写到 arr[write]
// // → write++

// // 如果元素不符合条件
// // → 不写入，即 自动删除

// // 扫描结束后
// // → 数组前 write 个元素就是处理后的结果

// // 如果是字符串，还必须执行：
// // → arr[write] = '\0'（结束字符串）
//   while (1) {
//     if (length1 - length2 != 0) {
//       printf("two names are different.Because their length is different.\n");
//       break;
//     } else if (strcmp(name1, name2) != 0) {
//       printf("two names are different after comparison.\n");
//       break;
//     } else {
//       printf("two names are the same after comparison.\n");
//       break;
//     }
//   }
//   return 0;
// }
//-------------Enter information(name,age,favorite country) of three students
// and print ---------------
// typedef struct{
//         char name[50];
//         int age;
//         char country[50];

//     } student;
// int main(){
//     student stu[3];
//     for(int i=0;i<3;i++){
//         printf("Enter the %d student's info:\n",i+1);
//         printf("name:");
//         scanf("%s",stu[i].name);
//         printf("age:");
//         scanf("%d",&stu[i].age);
//         printf("country:");
//         scanf("%s",stu[i].country);
//     }
//     printf("--------Student's info-------\n");
//     for(int i=0;i<3;i++){
//         printf("Name:%s|Age:%d|Country:%s\n",stu[i].name,stu[i].age,stu[i].country);
//     }
// }
//----------------Score statistics and comparison----------------
// typedef struct{
//     char name[50];
//     double english;
//     double math;
//     double Chinese;
//     double total;
//     double average;
// } info;
// int main(){
//     info stu[5];
//     int index_total = 0;
//     int index_average = 0;
//     for(int i=0;i<5;i++){
//         printf("Enter the informations of %dstudents:\n",i+1);
//         printf("Name:");
//         scanf("%s",stu[i].name);
//         printf("English score:");
//         scanf("%lf",&stu[i].english);
//         printf("Math score:");
//         scanf("%lf",&stu[i].math);
//         printf("Chinese score:");
//         scanf("%lf",&stu[i].Chinese);
//         stu[i].total = stu[i].english + stu[i].math + stu[i].Chinese;
//         stu[i].average = stu[i].total/3;
//         double max_total = stu[0].total;
//         double max_average = stu[0].average;
//         if(stu[i].total>max_total){
//             max_total = stu[i].total;
//             index_total = i;
//         }
//         if(stu[i].average>max_average){
//             max_average = stu[i].average;
//             index_average = i;
//         }
//     }
//     printf("Highest
//     total:%.2lf,Owner:%s\n",stu[index_total].total,stu[index_total].name);
//      printf("Highest
//      average:%.2lf,Owner:%s\n",stu[index_average].average,stu[index_average].name);

//     return 0;
// }
//-------------print student information using functions-------------
// typedef struct{
//     char name[50];
//     int age;
//     double score;
// } Student;
// void print(Student s){
//     printf("Name:%s\nAge:%d\nScore:%.2lf\n",s.name,s.age,s.score);
// }
// void update(Student *s,double Newscore){
//     s->score = Newscore;

// }
// int main(){
//     Student stu[1];
//     int ns;
//     printf("enter the name of the student:");
//     scanf("%s",stu[0].name);
//     printf("enter the age of the student:");
//     scanf("%d",&stu[0].age);
//     printf("enter the score of the student:");
//     scanf("%lf",&stu[0].score);
//     print(stu[0]);
//     printf("Enter the new score:");
//     scanf("%d",&ns);
//     update(&stu[0],ns);
//     printf("Updated!\n");
//     print(stu[0]);
//     return 0;
// }
//---------------Student information menu---------------
// definitions
#define MAX_STUDENT 100
typedef struct {
  char name[50];
  char country[50];
  int age;
  double score;
} Student;
Student stu[MAX_STUDENT];
int stu_count = 0;
int dirty; // dirty flag, used to mark the state of the file(saved/unsaved)
// read functions
void clear_line(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}
void trim_newline(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}
#include <ctype.h>
#include <string.h>
#include <stdio.h>

void read_char(const char *prompt, char *n, size_t cap) {
    while (1) {
        printf("%s", prompt);

        if (fgets(n, (int)cap, stdin) == NULL) {
            clearerr(stdin);
            printf("Invalid input.\n");
            continue;
        }

        trim_newline(n);

        if (n[0] == '\0') {
            printf("Invalid input: cannot be empty.\n");
            continue;
        }

        int ok = 1;
        for (size_t i = 0; n[i] != '\0'; i++) {
            unsigned char c = (unsigned char)n[i];
            if (!(isalpha(c) || c == ' ')) {
                ok = 0;
                break;
            }
        }
        if (ok) return;

        printf("Invalid input: letters and spaces only.\n");
    }
}

void read_int(const char *prompt, int *n) {
  while (1) {
    if (scanf("%d", n) == 1) {
      if (*n >= 0 && *n <= 100){
        clear_line();
        return;
      }
      else {
        clear_line();
        printf("Invalid input, please enter an %s from 0~100:", prompt);
      }
    } else {
        clear_line();
      printf("Invalid input, please enter an %s from 0~100:", prompt);
    }
  }
}
void read_double(const char *prompt, double *n) {
  while (1) {
    if (scanf("%lf", n) == 1) {
        clear_line();
      return;
    } else {
        clear_line();
      printf("Invalid input, please enter the student's %s:", prompt);
    }
  }
}
// Add functions(Enter 1 to activiate)
void add(int number_of_students) {
  for (int i = 0; i < number_of_students && stu_count < MAX_STUDENT; i++) {
    int current = stu_count;
    printf("Please enter the #%d student's name:", i + 1);
    read_char("name", stu[current].name,sizeof(stu[current].name));
    printf("please enter the #%d student's country:", i + 1);
    read_char("country", stu[current].country,sizeof(stu[current].country));
    printf("Please enter the #%d student's age:", i + 1);
    read_int("integer", &stu[current].age);
    printf("Please enter the %d student's score:", i + 1);
    read_double("integer or a decimal", &stu[current].score);
    stu_count++;
  }
}
// View functions(Enter 2 to activate)
void view() {
  printf("-----Students List-----\n");
  for (int i = 0; i < stu_count; i++) {
    printf("Student #%d:\n", i + 1);
    printf("Name:%s\n", stu[i].name);
    printf("Country:%s\n", stu[i].country);
    printf("Age:%d\n", stu[i].age);
    printf("Score:%.2lf\n", stu[i].score);
  }
}

// Search functions(Enter 3 to activate)
int contains_icase(const char *text, const char *pat) {
    if (pat[0] == '\0') return 0; 
    for (int k = 0; text[k] != '\0'; k++) {  
        int j = 0;                            
        while (pat[j] != '\0' &&
               text[k + j] != '\0' &&
               tolower((unsigned char)text[k + j]) ==
               tolower((unsigned char)pat[j])) {
            j++;
        }
        if (pat[j] == '\0') return 1;         
    }
    return 0;
}
void search_by_name(const char *targeted_name) {
  int found_any = 0;

    for (int i = 0; i < stu_count; i++) {
        if (contains_icase(stu[i].name, targeted_name)) {
            printf("Student #%d:\nName:%s\nCountry:%s\nAge:%d\nScore:%.2lf\n",
                   i + 1, stu[i].name, stu[i].country, stu[i].age, stu[i].score);
            found_any = 1;
        }
    }

    if (!found_any) {
        printf("No results found\n");
    }
}
void search_by_country(const char *targeted_country) {
    int found_any = 0;

    for (int i = 0; i < stu_count; i++) {
        if (contains_icase(stu[i].country, targeted_country)) {
            printf("Student #%d:\nName:%s\nCountry:%s\nAge:%d\nScore:%.2lf\n",
                   i + 1, stu[i].name, stu[i].country, stu[i].age, stu[i].score);
            found_any = 1;
        }
    }

    if (!found_any) {
        printf("No results found\n");
    }
}
// get tenth digit
int get_tenth_digit(int number) { return (number / 10) * 10; }
// get hundred digit
int get_hun_digit(int number) { return (number / 100) * 10; }
// Sort&list functions(used in search by age&score)
void search_by_age() {
  int range[100];
  int g;
  int count = 0;
  for (int i = 0; i < stu_count; i++) {
    g = get_tenth_digit(stu[i].age);
    int exist = 0;
    for (int j = 0; j < count; j++) {
      if (g == range[j]) {
        exist = 1;
      }
    }
    if (!exist) {
      range[count++] = g;
    }
  }
  for (int i = 0; i < count - 1; i++) {
    for (int j = i + 1; j < count; j++) {
      if (range[j] > range[i]) {
        int temp = range[i];
        range[i] = range[j];
        range[j] = temp;
      }
    }
  }

  printf("Avaliable age groups:\n");
  for (int i = 0; i < count; i++) {
    printf("%d,Age above:%d\n", i + 1, range[i]);
  }
  int choice = 0;
  printf("Please enter your choice:\n");
  scanf("%d", &choice);
  clear_line();
  if (choice < 1 || choice > count) {
    printf("Invalid choice\n");
    return;
  }
  int selected = range[choice - 1];
  printf("Students above the age of %d:\n", selected);
  for (int i = 0; i < stu_count; i++) {
    if (stu[i].age >= selected) {
      printf("Name:%s\nCountry:%s\nAge:%d\nScore:%lf\n", stu[i].name,
             stu[i].country, stu[i].age, stu[i].score);
    }
  }
}
void search_by_score() {
  double range[100];
  double g;
  int count = 0;
  // get maximum
  double max = stu[0].score;
  for (int i = 0; i < stu_count; i++) {
    if (stu[i].score > max) {
      max = stu[i].score;
    }
  }
  if (max > 10) {
    for (int i = 0; i < stu_count; i++) {
      g = get_tenth_digit(stu[i].score);
      int exist = 0;
      for (int j = 0; j < count; j++) {
        if (g == range[j]) {
          exist = 1;
        }
      }
      if (!exist) {
        range[count++] = g;
      }
    }
  }
  if (max > 100) {
    for (int i = 0; i < stu_count; i++) {
      g = get_hun_digit(stu[i].score);
      int exist = 0;
      for (int j = 0; j < count; j++) {
        if (g == range[j]) {
          exist = 1;
        }
      }
      if (!exist) {
        range[count++] = g;
      }
    }
  }

  for (int i = 0; i < count - 1; i++) {
    for (int j = i + 1; j < count; j++) {
      if (range[j] > range[i]) {
        int temp = range[i];
        range[i] = range[j];
        range[j] = temp;
      }
    }
  }

  printf("Avaliable score groups:\n");
  for (int i = 0; i < count; i++) {
    printf("%d,Score above:%lf\n", i + 1, range[i]);
  }
  int choice = 0;
  printf("Please enter your choice:\n");
  scanf("%d", &choice);
  clear_line();
  if (choice < 1 || choice > count) {
    printf("Invalid choice\n");
    return;
  }
  double selected = range[choice - 1];
  printf("Students above the score of %.2lf:\n", selected);
  for (int i = 0; i < stu_count; i++) {
    if (stu[i].score >= selected) {
      printf("Name:%s\nCountry:%s\nAge:%d\nScore:%.2lf\n", stu[i].name,
             stu[i].country, stu[i].age, stu[i].score);
    }
  }
}
void delete_one_at(int pos) {
  if (pos < 0 || pos >= stu_count)
    return;
  for (int i = pos; i < stu_count - 1; i++) {
    stu[i] = stu[i + 1];
  }
  stu_count--;
}
void delete(int number_deleted) {
  int count = 0;
  int index[stu_count + 1];
  if (number_deleted > stu_count) {
    number_deleted = stu_count;
  }

  for (int i = 0; i < number_deleted; i++) {

    printf("Please enter the index of the #%d student you want to delete:",
           i + 1);
    scanf("%d", &index[i]);
    clear_line();
    if (index[i] < 1 || index[i] > stu_count) {
      printf("Invalid index, skip.\n");
      i--; // 这一轮作废，重新输
      continue;
    }
    count++;
  }
  for (int j = 0; j < count - 1; j++) {
    for (int k = j + 1; k < count; k++) {
      if (index[k] > index[j]) {
        int temp = index[k];
        index[k] = index[j];
        index[j] = temp;
      }
    }
  }
  for (int l = 0; l < count; l++) {
    delete_one_at(index[l] - 1);
  }
}
void name_update() {
  int s;
  printf("Please enter the index of the student you want to update:");
  scanf("%d", &s);
  clear_line();
  s--;
  if (s > stu_count) {
    printf("Invalid input");
    return;
  }
  char new_name[50];
  printf("Please enter the new name of this student:");
  fgets(new_name,sizeof(new_name),stdin);
  trim_newline(new_name);
  strcpy(stu[s].name, new_name);

  printf("Name updated successfully!\n");
}
void country_update() {
  int s;
  printf("Please enter the index of the student you want to update:");
  scanf("%d", &s);
  clear_line();
  s--;
  if (s > stu_count) {
    printf("Invalid input");
    return;
  }
  char new_country[50];
  printf("Please enter the new country of this student:");
  fgets(new_country,sizeof(new_country),stdin);
  trim_newline(new_country);
  strcpy(stu[s].country, new_country);

  printf("Country updated successfully!\n");
}
void age_update() {
  int s;
  printf("Please enter the index of the student you want to update:");
  scanf("%d", &s);
  s--;
  if (s > stu_count) {
    printf("Invalid input");
    return;
  }
  int new_age;
  printf("Please enter the new age of this student:");
  scanf("%d", &new_age);
  clear_line();
  stu[s].age = new_age;
  printf("Age updated successfully!\n");
}
void score_update() {
  int s;
  printf("Please enter the index of the student you want to update:");
  scanf("%d", &s);
  clear_line();
  s--;
  if (s > stu_count) {
    printf("Invalid input");
    return;
  }
  double new_score;
  printf("Please enter the new score of this student:");
  scanf("%lf", &new_score);
  clear_line();
  stu[s].score = new_score;
  printf("Score updated successfully!\n");
}
int save_list_to_file(const char *filename) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    printf("Error:Could not open file %s for writing.\n", filename);
    return 0;
  }
  fprintf(file, "----------------Student Information List--------------\n");
  for (int i = 0; i < stu_count; i++) {
    fprintf(file, "Student #%d:\nName: %s|Country: %s|Age: %d|Score: %.2lf|\n",
            i + 1, stu[i].name, stu[i].country, stu[i].age, stu[i].score);
  }

  fclose(file);
  return 1;
}
#include <stdio.h>

int handle_exit(const char *filename) {
  if (!dirty)
    return 1;

  printf("You have unsaved changes. Save now? (y/n): ");

  int c = getchar();
  while (c == '\n')
    c = getchar();
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF) {
  }

  if (c == 'y' || c == 'Y') {
    int ok = save_list_to_file("stu_info.txt");

    if (ok) {
      dirty = 0;
      printf("Saved. Exiting...\n");
      return 1;
    } else {
      printf("Save failed. Exit cancelled.\n");
      return 0;
    }
  }
  printf("Exiting without saving...\n");
  return 1;
}

int main() {
  int a;
  int ns;
  do {
    printf("1.Add students\n2.View all students\n3.Search students\n4.Update "
           "information\n5.Delete Student\n6.Save file\n7.Exit\n");
    printf("Enter your option(1/2/3/4/5/6/7):");
    if (scanf("%d", &a) != 1) {
        printf("Invalid choice, please enter a number between 1,2,3,4,5,6 and "
               "7\n");
        a = 0;
        clear_line();
        continue;
    } else if (a == 1) {
      printf("Please enter the number of students going to be added:");
      while (1) {
        if (scanf("%d", &ns) == 1 && ns > 0) {
          clear_line();
          break;
        } else {
          clear_line();
          printf("Invalid input, please enter a positive integer:");
        }
      }
      add(ns);
      dirty = 1;
      printf("Students' information successfully added!\n");
    } else if (a == 2) {
      if (stu_count != 0) {
        view();
      } else {
        printf("No students added to the list, add students first.\n");
      }

    } else if (a == 3) {
      int b;
      char tn[50]; // targeted_name
      char tc[50]; // targeted_country
      do {
        printf("1.Search by name\n2.Search by country\n3.Search by "
               "age\n4.Search by score\n5.Exit\n");
        printf("Enter your way of searching:");
        if (scanf("%d", &b) != 1) {
            clear_line();
          
            printf("Invalid choice, please enter a number between 1,2,3,4 and "
                   "5\n");
            continue;
        } 
        clear_line();
        if (b == 1) {
          printf("Please enter the targeted name:");
          fgets(tn,sizeof(tn),stdin);
          trim_newline(tn);
          search_by_name(tn);
        } else if (b == 2) {
          printf("Please enter the targeted country: ");
          fgets(tc,sizeof(tc),stdin);
          trim_newline(tc);
          search_by_country(tc);
        } else if (b == 3) {
          search_by_age();
        } else if (b == 4) {
          search_by_score();
        } else if (b == 5) {
          printf("Exited to the menu!\n");
          break;
        }

      } while (b != 5);
    } else if (a == 4) {
      int i;
      view();
      do {
        printf("1.Name\n2.Country\n3.Age\n4.Score\n5.Exit to the menu\nPlease "
               "enter the type of information you want to update:");
        scanf("%d", &i);
        clear_line();
        if (i == 1) {
          name_update();
        } else if (i == 2) {
          country_update();
        } else if (i == 3) {
          age_update();
        } else if (i == 4) {
          score_update();
        } else if (i == 5) {
          printf("Exited to the menu\n");
          break;
        } else {
          printf("Invalid input");
          continue;
        }
      } while (i != 5);
      dirty = 1;
    } else if (a == 5) {
      int nd;
      view();
      printf("Please enter the number of students going to be deleted:");
      scanf("%d", &nd);
      clear_line();
      delete(nd);
      printf("Students' information successfully deleted!\n");
      dirty = 1;
    } else if (a == 6) {
      save_list_to_file("stu_info.txt");
      printf("Student Information successfully saved!\n");
      dirty = 0;
    } else if (a == 7) {
      if (handle_exit("stu_info.txt"))
        break;
    } else {
      printf("Invalid input");
      a = 0;
      continue;
    }
  } while (a != 7);
  return 0;
}