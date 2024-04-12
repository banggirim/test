#include <stdio.h>
#include <string.h>

#define MAX_TRIES 5 // 최대 시도 횟수
#define MAX_WORD_LENGTH 20 // 최대 단어 길이

int main() {
    char word[MAX_WORD_LENGTH + 1]; // 최대 20자의 단어를 저장할 수 있는 배열 (+1은 널 종료 문자를 위한 공간)
    char unknown[MAX_WORD_LENGTH + 1]; // 단어의 길이만큼 '_'로 채워진 배열
    int length; // 단어의 길이
    int tries = 0; // 시도 횟수
    int i;

    // 단어를 입력 받은 후에 널 종료 문자를 추가하여 문자열을 완성합니다.
    printf("단어를 입력하세요: ");
    if (scanf("%s", word) != 1) {
        printf("입력 오류가 발생했습니다. 프로그램을 종료합니다.\n");
        return 1; // 오류 코드 반환
    }

    // 단어의 길이를 구하고, unknown 배열을 '_'로 초기화
    length = strlen(word);
    for (i = 0; i < length; i++) {
        unknown[i] = '_';
    }
    unknown[length] = '\0'; // 널 종료 문자 추가

    // 행맨 게임 진행
    while (tries < MAX_TRIES) {
        printf("현재 단어: %s\n", unknown);

        char guess;
        printf("알파벳 하나를 추측하세요: ");
        if (scanf(" %c", &guess) != 1) {
            printf("입력 오류가 발생했습니다. 프로그램을 종료합니다.\n");
            return 1; // 오류 코드 반환
        }

        // 입력 버퍼 비우기
        while (getchar() != '\n');

        int found = 0; // 추측한 글자가 단어에 있는지 여부를 나타내는 플래그
        for (i = 0; i < length; i++) {
            if (word[i] == guess) {
                unknown[i] = guess;
                found = 1;
            }
        }

        if (!found) {
            printf("틀렸습니다!\n");
            tries++;
        }
        else {
            printf("정답입니다!\n");
        }

        // 모든 글자를 맞춘 경우
        if (strcmp(word, unknown) == 0) {
            printf("축하합니다! 단어를 맞췄습니다: %s\n", word);
            break;
        }
    }

    if (tries == MAX_TRIES) {
        printf("게임 오버! 단어를 맞추지 못했습니다. 정답은 %s입니다.\n", word);
    }

    return 0;
}
