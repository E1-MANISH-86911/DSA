#include <stdio.h>
#include <string.h>
struct Students {
    int rollno;
    char name[30];
    int marks;
};
void display(struct Students s[], int n);
void sort(struct Students s[], int n);
int main() {
    struct Students s[10];
    for (int i = 0; i < 10; i++) {
        printf("Enter the roll number of student %d: ", i + 1);
        scanf("%d", &s[i].rollno);
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", s[i].name);
        printf("Enter the marks of student %d: ", i + 1);
        scanf("%d", &s[i].marks);
    }
    sort(s, 10);
    printf("\nSorted list of students by marks:\n");
    display(s, 10);
    return 0;
}
void sort(struct Students s[], int n) {
    struct Students temp;   
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].marks > s[j + 1].marks) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
void display(struct Students s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d) Roll number: %d\n", i + 1, s[i].rollno);
        printf("   Name: %s\n", s[i].name);
        printf("   Marks: %d\n", s[i].marks);
    }
}
