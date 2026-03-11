void printCentered(string text, int width, int color = 7) {
    int padding = (width - text.length()) / 2;
    for (int i = 0; i < padding; i++) cout << " ";
    setColor(color);
    cout << text;
    setColor(7);
    for (int i = 0; i < (width - text.length() - padding); i++) cout << " ";
}


void rollSeedAnimation(mt19937& gen, string finalSize, string finalBuff, int finalColor) {
    int spins = 25;
    int current_delay = 15;
    
    string sizes[] = {"Giant", "Huge", "Normal"};
    string buffs[] = {"Blackhole", "Ice", "Fire", "Diamond", "Gold", "Normal"};
    int colors[] = {13, 11, 12, 3, 14, 15};

    uniform_int_distribution<> sizeDis(0, 2);
    uniform_int_distribution<> buffDis(0, 5);

    cout << "\n"; 
    for(int i = 0; i < spins; i++) {
        int rSize = sizeDis(gen);
        int rBuff = buffDis(gen);
        
        cout << "\r [SYSTEM] Planting (-$100) & Rolling Seed... [ ";
        setColor(colors[rBuff]);
        cout << buffs[rBuff] << " " << sizes[rSize];
        setColor(7);
        cout << " ]       " << flush;

        this_thread::sleep_for(chrono::milliseconds(current_delay));

        if (i > spins * 0.8) current_delay += 80;
        else if (i > spins * 0.5) current_delay += 25;
        else current_delay += 5;
    }
    
    cout << "\r [SYSTEM] >> YOU GOT : [ ";
    setColor(finalColor);
    cout << finalBuff << " " << finalSize;
    setColor(7);
    cout << " ] << Placed in pot!          " << flush;
    
    this_thread::sleep_for(chrono::milliseconds(1500)); 
}