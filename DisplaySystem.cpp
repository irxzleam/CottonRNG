#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <random>
using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printCentered(string text, int width, int color = 7) {
    int padding = (width - text.length()) / 2;
    for (int i = 0; i < padding; i++) cout << " ";
    setColor(color);
    cout << text;
    setColor(7);
    for (int i = 0; i < (width - text.length() - padding); i++) cout << " ";
}

int main()
{
    //ช่องปลูก
        setColor(8);
        cout << "   [SLOT 1]    [SLOT 2]    [SLOT 3]    [SLOT 4]    [SLOT 5]   \n";
        cout << "\n";

        //ฝ้าย
        for (int row = 0; row < 5; row++) {
            for (int i = 0; i < 5; i++) {
                string line = "";
                //int currentColor = (row <= 2 && slots[i].isPlanted) ? slots[i].buffColor : 15; 
                int currentColor ;
                if (row <= 2 && slots[i].isPlanted) currentColor = slots[i].buffColor;
                else currentColor = 15;
                if (!slots[i].isPlanted) currentColor = 8; 

                if (!slots[i].isPlanted) {
                    if (row == 4) line = "[_____]"; else line = "|     |";
                } else {
                    if (slots[i].sizeType == "Giant") {
                        if (row == 0) line = "  *** "; else if (row == 1) line = " ***** ";
                        else if (row == 2) line = "*******"; else if (row == 3) line = "  |||  "; else line = "[|||||]";
                    } else if (slots[i].sizeType == "Huge") {
                        if (row == 0) line = "       "; else if (row == 1) line = "  ooo  ";
                        else if (row == 2) line = " ooooo "; else if (row == 3) line = "  |||  "; else line = "[_|||_]";
                    } else {
                        if (row == 0) line = "       "; else if (row == 1) line = "       ";
                        else if (row == 2) line = "   @   "; else if (row == 3) line = "   |   "; else line = "[__|__]";
                    }
                }
                printCentered(line, SLOT_WIDTH, currentColor);
            }
            cout << "\n";
        }
        cout << "\n";

        // textราคา 
        for (int i = 0; i < 5; i++) {
            if (slots[i].isPlanted) { printCentered("$" + to_string(slots[i].value), SLOT_WIDTH, 15); } 
            else { printCentered("-", SLOT_WIDTH, 8); }
        }
        cout << "\n"; 

        // บอกปุ่ม Maindisplay
        setColor(11);
        cout << "\n\n===============================================================\n";
        setColor(7);
        cout << " [ COMMANDS ]\n";
        cout << "  [1-5] Action (Plant/Harvest) | [S] Harvest All | [Q] Quit\n";
        cout << "  [B] Backpack                 | [M] Market\n";
        setColor(11);
        cout << "===============================================================\n";
        setColor(7);
        cout << " Awaiting Input >> ";

        //Market display
        while (true) {
                system("cls");
                setColor(10); 
                cout << "===============================================================\n";
                cout << "||                         MARKET                              ||\n";
                cout << "===============================================================\n";
                setColor(7);
                
                if (money < 0) { setColor(12); cout << " > Your Balance : -$" << abs(money) << "\n"; }
                else { setColor(14); cout << " > Your Balance : $" << money << "\n"; }
                
                setColor(7);
                cout << "---------------------------------------------------------------\n";
                cout << " [1] Fertilizer       | Price: $200 | (Forces next crop to be Giant)\n";
                cout << " [2] Weather Modifier | Price: $300 | (Change the global weather)\n";
                setColor(10);
                cout << "---------------------------------------------------------------\n";
                setColor(7);
                cout << " [B] Back to Farm \n";
                setColor(10);
                cout << "===============================================================\n";
                setColor(7);
                cout << " Input >> ";

                char mInput = _getch();
                if (mInput == '1') {
                    if (money >= 200) {
                        money -= 200;
                        fertilizer++;
                        cout << "\n\n [SYSTEM] Bought 1x Fertilizer!" << flush;
                    } else {
                        cout << "\n\n [SYSTEM] Not enough money!" << flush;
                    }
                    this_thread::sleep_for(chrono::milliseconds(600));
                } else if (mInput == '2') {
                    if (money >= 300) {
                        money -= 300;
                        weatherMod++;
                        cout << "\n\n [SYSTEM] Bought 1x Weather Modifier!" << flush;
                    } else {
                        cout << "\n\n [SYSTEM] Not enough money!" << flush;
                    }
                    this_thread::sleep_for(chrono::milliseconds(600));
                } else if (mInput == 'b' || mInput == 'B') {
                    break;
                }
            }

            // quit button pressed
            system("cls");
            setColor(10);
            cout << "\n\n";
            cout << "      =====================================================\n";
            cout << "      ||                                                 ||\n";
            printCentered("THANK YOU FOR PLAYING COTTON RNG!", 60, 10);
            setColor(10);
            cout << "\n      ||                                                 ||\n";
            printCentered("Quitting game...", 60, 7);
            setColor(10);
            cout << "\n      ||                                                 ||\n";
            setColor(10);
            cout << "      =====================================================\n";
            cout << "\n\n";


            this_thread::sleep_for(chrono::milliseconds(3000));
            setColor(15);
            break;

    
}