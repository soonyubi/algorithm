#include <stdio.h>
#include <ctype.h>
#include<bits/stdc++.h>
using namespace std;
/*
���� : 15�� ������ ���ڿ��� �־��� ��, �� ���ڿ��� Opposite�� ���ڿ����� ���Ѵ�. �̷��� ���ڿ��� ���ڿ����� ���ĺ��� �͵���
������ �Ͱ� ¦�� ���� �� �ִ� ���̴�. ������ ���� A-Z, B-Y, ... M-N ���� ���̴�. ��ҹ��ڴ� �������� �ʴ´�.
�ذ� ��� : ���ڿ����� ���ĺ��� ������ �� ���ĺ��� ������ ����. �� ����, ������ ���ʿ������� Ȯ���ϸ�
���� ���ĺ��� ������ ��� ������ Ȯ���Ѵ�. �ϳ��� �ٸ��ٸ� opposite ���� ���� ���̰�, ���� ���ٸ� opposite�� ���̴�.
�ֿ� �˰��� : ����, ���ڿ�
��ó : PLU 2014N 7��
*/

char s[32];
int cnt[26];

int main(void) {
    int t, r;
    scanf_s("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf_s("%s", s);
        for (int i = 0; s[i]; i++) {
            if (isupper(s[i])) cnt[s[i] - 'A']++;
            else if (islower(s[i])) cnt[s[i] - 'a']++;
        }
        r = 1;
        for (int i = 0; i < 26; i++) cout << cnt[i] << " "; cout << "\n";
        for (int i = 0; i < 13; i++) {
            if (cnt[i] != cnt[25 - i]) r = 0;
            cnt[i] = 0, cnt[25 - i] = 0;
        }
        printf("%s\n", r ? "Yes" : "No");
    }
    return 0;
}