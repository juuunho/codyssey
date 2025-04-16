#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JUDGES 100
#define MAX_LEN 500
#define INFO_FIELDS 7

char judges_array[MAX_JUDGES][MAX_LEN];

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len && str[len - 1] == '\n') str[len - 1] = '\0';
}

int count_commas(const char *str) {
    int count = 0;
    while (*str) {
        if (*str == ',') count++;
        str++;
    }
    return count;
}

void parse_and_print(const char *data, int idx) {
    char buffer[MAX_LEN];
    strcpy(buffer, data);
    char *token;
    const char *labels[INFO_FIELDS] = {
        "이름", "성별", "소속", "직함", "전문분야", "메일", "전화"
    };

    printf("[심사위원 %d]\n", idx + 1);
    token = strtok(buffer, ",");

    int i = 0;
    while (token != NULL && i < INFO_FIELDS) {
        char *sep = strchr(token, ':');
        if (sep != NULL) {
            sep++; // skip ':'
            printf("%s:%s\n", labels[i], sep);
        }
        token = strtok(NULL, ",");
        i++;
    }
    printf("-----------------------------------\n");
}

int main() {
    char project[100];
    int total, select;
    int input_count = 0;

    printf("####################################\n");
    printf("#      심사위원 명단 데이터 입력       #\n");
    printf("####################################\n");

    printf("> 참여 프로젝트: ");
    fgets(project, sizeof(project), stdin);
    trim_newline(project);

    printf("> 심사 총 인원: ");
    scanf("%d", &total);
    printf("> 선발 멤버 수: ");
    scanf("%d", &select);
    getchar(); // flush newline

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사위원 정보 입력을 시작합니다.\n", total);
    printf("++++++++++++++++++++++++++++++++++++\n");

    while (input_count < total) {
        printf("*심사위원 %d: ", input_count + 1);
        fgets(judges_array[input_count], MAX_LEN, stdin);
        trim_newline(judges_array[input_count]);

        if (count_commas(judges_array[input_count]) != INFO_FIELDS - 1) {
            printf("입력 항목이 정확하지 않습니다. 다시 입력해주세요.\n");
            continue;
        }

        input_count++;
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사위원 정보 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    char confirm;
    printf("\"%s\" 심사위원 정보를 확인할까요? (Y/N): ", project);
    scanf(" %c", &confirm);

    if (confirm == 'Y') {
        printf("####################################\n");
        printf("#        심사위원 데이터 출력        #\n");
        printf("####################################\n");

        for (int i = 0; i < total; i++) {
            parse_and_print(judges_array[i], i);
        }
    } else {
        printf("프로그램을 종료합니다.\n");
    }

    return 0;
}
