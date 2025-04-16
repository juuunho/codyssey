#include <stdio.h>
#include <stdlib.h>

#define NUM 6

struct member_info {
    char name[50];
    int year, month, day;
    char gender;
    char email[50];
    char nationality[30];
    float bmi;
    char main_skill[30];
    char sub_skill[50];
    int topik;
    char mbti[5];
    char intro[200];
};

int get_age(int y, int m, int d) {
    int cy = 2025, cm = 4, cd = 16;
    int age = cy - y;
    if (cm < m || (cm == m && cd < d)) age--;
    return age;
}

int main() {
    struct member_info candidate01, candidate02, candidate03,
                        candidate04, candidate05, candidate06;

    struct member_info* list[NUM] = {
        &candidate01, &candidate02, &candidate03,
        &candidate04, &candidate05, &candidate06
    };

    char group[50];
    printf("오디션 그룹명 입력: ");
    fgets(group, sizeof(group), stdin);
    for (int i = 0; group[i]; i++)
        if (group[i] == '\n') group[i] = 0;

    printf("####################################\n");
    printf("[%s] 오디션 후보자 데이터 입력\n", group);
    printf("####################################\n");

    for (int i = 0; i < NUM; i++) {
        struct member_info* c = list[i];
        printf("%d번째 후보자 정보 입력\n", i + 1);
        printf("1. 성명: "); fgets(c->name, sizeof(c->name), stdin); c->name[strcspn(c->name, "\n")] = 0;
        printf("2. 생일(YYYY/MM/DD): "); scanf("%d/%d/%d", &c->year, &c->month, &c->day); getchar();
        printf("3. 성별(F/M): "); scanf(" %c", &c->gender); getchar();
        printf("4. 메일: "); fgets(c->email, sizeof(c->email), stdin); c->email[strcspn(c->email, "\n")] = 0;
        printf("5. 국적: "); fgets(c->nationality, sizeof(c->nationality), stdin); c->nationality[strcspn(c->nationality, "\n")] = 0;
        printf("6. BMI: "); scanf("%f", &c->bmi); getchar();
        printf("7. 주 스킬: "); fgets(c->main_skill, sizeof(c->main_skill), stdin); c->main_skill[strcspn(c->main_skill, "\n")] = 0;
        printf("8. 보조 스킬: "); fgets(c->sub_skill, sizeof(c->sub_skill), stdin); c->sub_skill[strcspn(c->sub_skill, "\n")] = 0;
        printf("9. TOPIK: "); scanf("%d", &c->topik); getchar();
        printf("10. MBTI: "); fgets(c->mbti, sizeof(c->mbti), stdin); c->mbti[strcspn(c->mbti, "\n")] = 0;
        printf("11. 소개: "); fgets(c->intro, sizeof(c->intro), stdin); c->intro[strcspn(c->intro, "\n")] = 0;
        printf("=================================\n");
    }

    printf("\n####################################\n");
    printf("[%s] 오디션 후보자 데이터 조회\n", group);
    printf("####################################\n");
    printf("=============================================================================================\n");
    printf("성명(나이)     | 생일       | 성 | 이메일               | 국적 | BMI  | 주스킬 | 보조스킬   | TOPIK | MBTI |\n");
    printf("=============================================================================================\n");

    for (int i = 0; i < NUM; i++) {
        struct member_info* c = list[i];
        int age = get_age(c->year, c->month, c->day);
        printf("%-12s(%2d) | %04d%02d%02d | %c  | %-20s | %-5s | %.1f | %-6s | %-10s | ",
               c->name, age, c->year, c->month, c->day,
               c->gender, c->email, c->nationality, c->bmi,
               c->main_skill, c->sub_skill);
        if (c->topik == 0) printf("원어민");
        else printf("%d급", c->topik);
        printf(" | %-4s |\n", c->mbti);
        printf("---------------------------------------------------------------------------------------------\n");
        printf("%s\n", c->intro);
        printf("---------------------------------------------------------------------------------------------\n");
    }

    return 0;
}
