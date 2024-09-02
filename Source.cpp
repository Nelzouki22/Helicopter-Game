#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

// دالة لتحريك المؤشر في وحدة التحكم
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// دالة لتغيير لون النص
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// دالة لرسم الهليكوبتر
void drawHelicopter(int x, int y) {
    setColor(10); // لون أخضر
    gotoxy(x, y);
    cout << "    ======     ";
    gotoxy(x, y + 1);
    cout << "====|    |==== ";
    gotoxy(x, y + 2);
    cout << "   //\\   ";
    gotoxy(x, y + 3);
    cout << "  ||   \\  ";
    gotoxy(x, y + 4);
    cout << "  \\\\___/  ";
    gotoxy(x, y + 5);
    cout << "     ||    ";
    setColor(7); // إعادة اللون إلى الافتراضي
}

// دالة لمسح الهليكوبتر
void clearHelicopter(int x, int y) {
    for (int i = 0; i < 6; i++) {
        gotoxy(x, y + i);
        cout << "                ";
    }
}

// دالة لمعالجة الإدخال ومنطق اللعبة
void playGame() {
    int x = 10, y = 10; // الموقع الأولي للهليكوبتر
    char ch;
    bool gameOver = false;

    while (!gameOver) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 72 && y > 0) y--; // مفتاح السهم لأعلى
            if (ch == 80 && y < 20) y++; // مفتاح السهم لأسفل
            if (ch == 75 && x > 0) x--; // مفتاح السهم لليسار
            if (ch == 77 && x < 70) x++; // مفتاح السهم لليمين
            if (ch == 'x' || ch == 'X') gameOver = true; // للخروج من اللعبة
        }

        clearHelicopter(x, y);
        drawHelicopter(x, y);

        Sleep(50); // للتحكم في سرعة اللعبة
    }
}

// الدالة الرئيسية
int main() {
    system("cls"); // تنظيف وحدة التحكم

    cout << "Press any key to start the game...\n";
    _getch(); // انتظار الضغط على أي مفتاح

    playGame();

    cout << "Game Over!\n";
    return 0;
}


