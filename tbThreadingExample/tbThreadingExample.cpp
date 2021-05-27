#include <iostream> 
#include <thread> 
#include <vector>
#include <string>
#include <mutex>
#include <Windows.h>

using namespace std;

mutex cout_mutex;

void print(int n, const string& str) {
    //this_thread::sleep_for(chrono::seconds(n+1));
    
    //L�s cout med ett unique_lock + mutex (som du sj�lv kan l�sa upp n�r t.ex. cout inte beh�vs l�ngre)
    unique_lock<mutex> unique(cout_mutex);
    cout << str << " ";
    unique.unlock();

    //l�sa cout med en lock_guard + mutex, s� att enbart en tr�d �t g�ngen kommer �t cout
    //lock_guard frig�r mutex:en n�r den g�r 'out-of-scope'
    /*lock_guard<mutex> guard(cout_mutex);
    cout << str << " ";*/


}

int main() {
    SetConsoleCP(1252); //���
    SetConsoleOutputCP(1252); //���

    vector<string> words = { //En vector (array som kan ut�kas) med olika ord
        "Hej",
        "jag",
        "heter",
        "Jonas",
        "Str�berg"
    };

    vector<thread> threads; //En vector med tr�dar

    //Skapa tr�dar (lika m�nga som det finns ord i vectorn 'words')
    for (int i = 0; i < words.size(); i++) {
        //varje tr�d anropar funktionen 'print' med ett index och ett ord fr�n 'words' som argument
        threads.push_back(thread(print, i, words[i]));
    }

    //huvudtr�den ska v�nta p� att varje respektive tr�d ska k�ras klart (blockerar huvudtr�den)
    for (auto& th : threads) {
        th.join();
    }

    return 0; //H�r avslutas huvudtr�den
}