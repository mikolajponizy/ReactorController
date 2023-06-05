# CMakeList.txt: projekt CMake dla elementu ReactorController, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

project ("ReactorController")

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (ReactorController "ReactorController.cpp" "ReactorController.h")

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.

#Oto zasady MISRA C, które były przestrzegane w kodzie:

#Zasada 3.x (Komentarze): Odpowiednie komentarze zostały dodane w górnej części kodu, wewnątrz funkcji oraz w celu wyjaśnienia niektórych operacji.
#Reguła 5.x (Identyfikatory): Identyfikatory zostały wybrane tak, aby były opisowe i zgodne z dozwolonym zestawem znaków. Stałe i zmienne zostały nazwane wielkimi literami dla lepszej czytelności.
#Reguła 7.x (Literały i stałe): Wartości literalne zostały zastąpione zdefiniowanymi stałymi przy użyciu dyrektyw preprocesora #define. Poprawia to czytelność kodu i pozwala na łatwiejszą modyfikację, jeśli wartości progowe będą musiały zostać zmienione w przyszłości.
#Zasada 12.x (Wyrażenia): Wyrażenia zostały użyte w prosty sposób, unikając złożonych lub zawiłych konstrukcji. Kod jest zgodny ze standardowymi wyrażeniami języka C, nie naruszając żadnej konkretnej reguły.
