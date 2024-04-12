#include <stdio.h>
#include <string.h>

#define MAX_TRIES 5 // �ִ� �õ� Ƚ��
#define MAX_WORD_LENGTH 20 // �ִ� �ܾ� ����

int main() {
    char word[MAX_WORD_LENGTH + 1]; // �ִ� 20���� �ܾ ������ �� �ִ� �迭 (+1�� �� ���� ���ڸ� ���� ����)
    char unknown[MAX_WORD_LENGTH + 1]; // �ܾ��� ���̸�ŭ '_'�� ä���� �迭
    int length; // �ܾ��� ����
    int tries = 0; // �õ� Ƚ��
    int i;

    // �ܾ �Է� ���� �Ŀ� �� ���� ���ڸ� �߰��Ͽ� ���ڿ��� �ϼ��մϴ�.
    printf("�ܾ �Է��ϼ���: ");
    if (scanf("%s", word) != 1) {
        printf("�Է� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.\n");
        return 1; // ���� �ڵ� ��ȯ
    }

    // �ܾ��� ���̸� ���ϰ�, unknown �迭�� '_'�� �ʱ�ȭ
    length = strlen(word);
    for (i = 0; i < length; i++) {
        unknown[i] = '_';
    }
    unknown[length] = '\0'; // �� ���� ���� �߰�

    // ��� ���� ����
    while (tries < MAX_TRIES) {
        printf("���� �ܾ�: %s\n", unknown);

        char guess;
        printf("���ĺ� �ϳ��� �����ϼ���: ");
        if (scanf(" %c", &guess) != 1) {
            printf("�Է� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.\n");
            return 1; // ���� �ڵ� ��ȯ
        }

        // �Է� ���� ����
        while (getchar() != '\n');

        int found = 0; // ������ ���ڰ� �ܾ �ִ��� ���θ� ��Ÿ���� �÷���
        for (i = 0; i < length; i++) {
            if (word[i] == guess) {
                unknown[i] = guess;
                found = 1;
            }
        }

        if (!found) {
            printf("Ʋ�Ƚ��ϴ�!\n");
            tries++;
        }
        else {
            printf("�����Դϴ�!\n");
        }

        // ��� ���ڸ� ���� ���
        if (strcmp(word, unknown) == 0) {
            printf("�����մϴ�! �ܾ ������ϴ�: %s\n", word);
            break;
        }
    }

    if (tries == MAX_TRIES) {
        printf("���� ����! �ܾ ������ ���߽��ϴ�. ������ %s�Դϴ�.\n", word);
    }

    return 0;
}
