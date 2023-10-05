/*
Створіть новий "тип" - матрицю і напишіть набір функцій, які реалізують основний функціонал:
Створення і видалення матриці з пам'яті; +
Зміна розмірів матриці зі збереженням вмісту; +
Визначення кількості рядків, + стовбців, + встановлення значення елемента матриці та визначення його величини;
Виведення матриці на екран, збереження матриці у файлі та читання її з файлу;
Основні операції матричної арифметики (додавання, віднімання, множення на число, множення матриць).
Напишіть програму, яка демонструє роботу цих процедур.
 */

#include <stdio.h>
#include <stdlib.h>

int** ptr = nullptr;
int M, N;

void createMatrix(int m, int n){
    ptr = static_cast<int **>(malloc(m * sizeof(int*)));
    for (int i = 0; i < m; ++i) {
        ptr[i] = static_cast<int *>(malloc(n * sizeof(int)));
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            *(ptr[j] + i) = rand()%10;
        }
    }
    if(ptr != nullptr) printf("Успішно створено.\n");
    M = m;
    N = n;
}

void clearMatrix(){
    printf("#33\n");
    if (ptr != nullptr){
        printf("#35\n");
        for (int i = 0; i < M; ++i) {
            printf("#37.%d\n", i);
            free(ptr[i]);
        }
        printf("#40\n");
        free(ptr);
        printf("Матрицю стерто.\n");
    }
    else printf("Матриці не існує.\n");
    M=0; N=0;
}

int getElement(int m, int n){
    if (ptr != nullptr){
        if (m<M && n<N){
            return *(ptr[n] + m);
            }
        else
            printf("Вихід за розмірність.\n");
        }
    else printf("Матриці не існує.\n");
}

void changeSize(){
    int m, n;
    int** new_ptr;
    if (ptr != nullptr) {
        printf("M: ");
        scanf("%d", &m);
        printf("N: ");
        scanf("%d", &n);
        new_ptr = static_cast<int **>(malloc(m * sizeof(int*)));
        for (int i = 0; i < m; ++i) {
            new_ptr[i] = static_cast<int *>(malloc(n * sizeof(int)));
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                new_ptr[i][j] = 0;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i <= M-1 && j <= N-1) new_ptr[i][j] = ptr[i][j];
            }
        }
        ptr = new_ptr;
        M = m;
        N = n;
    }
    else printf("Матриці не існує.\n");
}

void print(){
    if (ptr != nullptr) {
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                printf("%d ", ptr[i][j]);
            }
            printf("\n");
        }
    }
    else printf("Матриці не існує.\n");
}

void printSize(){
    if (ptr != nullptr) {
    printf("%dx%d\n", M, N);
    }
    else printf("Матриці не існує.\n");
}

void setElement(int m, int n, int item){
    if (ptr != nullptr) {
        if (m < M && n < N) {
            *(ptr[n] + m) = item;
        }
    }
    else printf("Матриці не існує.\n");
}

int main(){

    int choose, i, j, item;
        do {
            printf("\n1. Create matrix\n");
            printf("2. Delete matrix*\n", M, N);
            printf("3. Change size of matrix*\n");
            printf("4. Actual size*\n");
            printf("5. Set element value*\n");
            printf("6. Get element value*\n");
            printf("0. ВИХІД\n");
            printf("*-----------------------\n");
            printf("\t\t\t*if exist\n");
            printf("ВИБІР: ");
            scanf("%d", &choose);
            switch (choose) {
                case 1:
                    printf("M: ");
                    scanf("%d", &i);
                    M = i;
                    printf("N: ");
                    scanf("%d", &j);
                    N = j;
                    createMatrix(M, N);
                    print();
                    break;
                case 2:
                    clearMatrix();
                    print();
                    break;
                case 3:
                    changeSize();
                    print();
                    break;
                case 4:
                    printSize();
                    break;
                case 5:
                    printf("[_][j]: ");
                    scanf("%d", &i);
                    printf("[%d][_]: ", i);
                    scanf("%d", &j);
                    printf("[%d][%d] = ", i, j);
                    scanf("%d", &item);
                    setElement(i, j, item);
                    print();
                    break;
                case 6:
                    printf("[_][j]: ");
                    scanf("%d", &i);
                    printf("[%d][_]: ", i);
                    scanf("%d", &j);
                    printf("[%d][%d] = %d\n", i, j, getElement(i, j));
                    print();
                    break;
                default:
                    break;
            }
    } while (choose != 0);

}