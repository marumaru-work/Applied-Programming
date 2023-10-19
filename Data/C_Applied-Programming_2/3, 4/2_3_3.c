#include <stdio.h>

#define N 10

typedef struct
{
    int id;     // 学生番号
    int score;  // 点数
} Student;

void swap(Student a[], int i, int j)
{
    Student temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int compare(Student a[], int i, int j)
{
    if (a[i].score > a[j].score)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Student initStudent(int i, int s)
{
    Student student;
    student.id = i;
    student.score = s;
    return student;
}

void printStudents(Student students[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("id = %d, score = %d\n", students[i].id, students[i].score);
    }
}

void insertionSort(Student students[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && compare(students, j - 1, j); j--)
        {
            swap(students, j, j - 1);
        }
    }
}

int main(void)
{
    int scores[N] = {1, 4, 3, 5, 1, 5, 2, 3, 2, 2};  // 点数のリスト
    Student students[N];                             // 学生のリスト
    for (int i = 0; i < N; i++)
    {
        // i 番目の学生は i 番目の点数とする
        students[i] = initStudent(i, scores[i]);
    }
    printf("before sort\n");
    printStudents(students, N);  // ソート前の表示
    insertionSort(students, N);  // 挿入ソート
    printf("after sort\n");
    printStudents(students, N);  // ソート後の表示

    return 0;
}
