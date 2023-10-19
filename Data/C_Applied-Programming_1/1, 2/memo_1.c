#include <stdio.h>
#include <math.h>

int main(void) {
    // 32を加算･減算することで大文字と小文字の変換を実現できる．
    char c1 = 'a';
    printf("%c\n", c1 - 32); // A が表示される

    // 文字型の数字を
    // ASCIIコードで表したときに，その値から48を減算すれば，対応する数値
    // (int)を得ることが可能である．
    char c2 = '8';
    printf("%d\n", c2 - '0'); // 8 が表示される

    char c3 = '0';
    printf("%d\n", c3);
    printf("%d\n", pow(10, 1));
    return 0;
}
