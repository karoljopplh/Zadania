#include <iostream>
#include <ctime>
 
using namespace std;
 
int main() {
  // Definiujemy napis do wygenerowania
  string napis = "Nigger ";
 
  // Definiujemy zakres kolorów RGB
  int min_r = 0;
  int max_r = 255;
  int min_g = 0;
  int max_g = 255;
  int min_b = 0;
  int max_b = 255;
 
  // Iterujemy po wszystkich kolorach RGB
  for (int r = min_r; r <= max_r; r++) {
    for (int g = min_g; g <= max_g; g++) {
      for (int b = min_b; b <= max_b; b++) {
        // Ustawiamy kolor wydruku
        cout << "\033[38;2;" << r << ";" << g << ";" << b << "m" << napis << "\033[0m";
        usleep(100);
      }
    }
  }
 
  return 0;
}