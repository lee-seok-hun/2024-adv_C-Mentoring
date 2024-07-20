#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* fp = fopen("menu.txt", "r");
    char** menu = (char**)malloc(sizeof(char*));
    int* cost = (int*)malloc(sizeof(int));
    int Number = 0;
    int result = 0;
    while (!feof(fp)) {
        char food[101];
        int price;
        fscanf(fp, "%[^:]:%d\n", food, &price);
        menu[Number] = (char*)malloc(sizeof(char) * (strlen(food) + 1));
        strcpy(menu[Number], food);
        menu = (char**)realloc(menu, sizeof(char*) * (Number + 2));
        cost[Number] = price;
        cost = (int*)realloc(cost, sizeof(int) * (Number + 2));
        Number++;
    }
    int* count = (int*)calloc(Number, sizeof(int));
    printf("�޴� ����\n");
    for (int i = 0; i < Number; i++) {
        printf("%d�� %s ����:%d��\n", i + 1, menu[i], cost[i]);
    }
    int order;
    while (1) {
        int sign = 0;
        printf("�ֹ��Ͻ� �޴� ��ȣ�� �Է����ּ���.(0�� ���ý� �ֹ��� ����˴ϴ�):");
        scanf("%d", &order);
        if (order == 0) {
            printf("�ֹ��� ����Ǿ����ϴ�. �������� receipt.txt���� Ȯ�����ּ���");
            break;
        }
        for (int i = 0; i < Number; i++) {
            if (order == i + 1) {
                count[i]++;
                sign++;
                break;
            }
        }
        if (sign == 0) {
            printf("�߸��� �޴� ��ȣ�Դϴ�. �ٽ� �Է����ּ���.\n");
        }
    }
    fclose(fp);
    FILE* FP = fopen("receipt.txt", "w");
    fprintf(FP, "========���� ����========\n");
    for (int i = 0; i < Number; i++) {
        if (count[i] > 0) {
            fprintf(FP, "%d�� %s ����:%d�� x %d\n", i + 1, menu[i], cost[i], count[i]);
            result += cost[i] * count[i];
        }
    }
    fprintf(FP, "�� ���� �ݾ�:%d��", result);
    fclose(FP);
    for (int i = 0; i < Number; i++) {
        free(menu[i]);
        free(cost[i]);
        free(count[i]);
    }
    free(menu);
    free(cost);
    free(count);
    return 0;
}
