string currentWeather = "Clear Sky"; 
int weatherMulti = 1;
int plantCount = 0;
int fertilizer = 0;
int weatherMod = 0;
bool fertilizerActive = false;

void openMarket(int &money, int &fertilizer, int &weatherMod) {
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
            if (money >= 200) { money -= 200; fertilizer++; }
            this_thread::sleep_for(chrono::milliseconds(600));
        } else if (mInput == '2') {
            if (money >= 300) { money -= 300; weatherMod++; }
            this_thread::sleep_for(chrono::milliseconds(600));
        } else if (mInput == 'b' || mInput == 'B') {
            break;
        }
    }
}

void updateWeather(int &plantCount, string &currentWeather, mt19937 &gen, uniform_int_distribution<> &dis) {
    plantCount++;
    if (plantCount % 2 == 0) {
        int wRng = dis(gen);
        if (wRng <= 40) currentWeather = "Clear Sky";
        else if (wRng <= 70) currentWeather = "Scorching Heatwave";
        else if (wRng <= 90) currentWeather = "Cryo Storm";
        else currentWeather = "Void Disturbance";
    }
}

void calculateBuffs(string currentWeather, int &finalMulti, string &finalBuff, int &finalColor, mt19937 &gen, uniform_int_distribution<> &dis) {
    int bRng = dis(gen);
    if (currentWeather == "Clear Sky") {
        if (bRng <= 20)      { finalBuff = "Diamond"; finalColor = 3;  finalMulti = 3; } 
        else if (bRng <= 50) { finalBuff = "Gold";    finalColor = 14; finalMulti = 2; } 
        else                 { finalBuff = "Normal";  finalColor = 15; finalMulti = 1; } 
    } 
    else if (currentWeather == "Scorching Heatwave") {
        if (bRng <= 20)      { finalBuff = "Fire";    finalColor = 12; finalMulti = 4; } 
        else if (bRng <= 35) { finalBuff = "Diamond"; finalColor = 3;  finalMulti = 3; } 
        else if (bRng <= 60) { finalBuff = "Gold";    finalColor = 14; finalMulti = 2; } 
        else                 { finalBuff = "Normal";  finalColor = 15; finalMulti = 1; } 
    }
    else if (currentWeather == "Cryo Storm") {
        if (bRng <= 15)      { finalBuff = "Ice";     finalColor = 11; finalMulti = 5; } 
        else if (bRng <= 30) { finalBuff = "Diamond"; finalColor = 3;  finalMulti = 3; } 
        else if (bRng <= 55) { finalBuff = "Gold";    finalColor = 14; finalMulti = 2; } 
        else                 { finalBuff = "Normal";  finalColor = 15; finalMulti = 1; } 
    }
    else if (currentWeather == "Void Disturbance") {
        if (bRng <= 5)       { finalBuff = "Blackhole"; finalColor = 13; finalMulti = 10; } 
        else if (bRng <= 20) { finalBuff = "Diamond";   finalColor = 3;  finalMulti = 3; }  
        else if (bRng <= 45) { finalBuff = "Gold";      finalColor = 14; finalMulti = 2; }  
        else                 { finalBuff = "Normal";    finalColor = 15; finalMulti = 1; }  
    }
}