# Projekt cpp 

System hotelarski, z poziomu recepcjonisty, dla niedużego obiektu 

I RAPORT (20.10.2020)

Używane technologie:

- C++ 10.1
- MySQL (biblioteka mysql.h)
- QT
- Windows.h

Główne założenia:

- stworzenie aplikacji okienkowej z dopracowanym interfejsem graficznym
- stworzenie bazy danych
- połączenie aplikacji z bazą danych

Możliwe wykonywane zadania:

- dodawanie kartoteki gościa
- tworzenie rezerwacji 
- zmiana statusu pokoi (brudny, czysty, wolny, zajety)
- przypisywanie danego pokoju do danego gościa itp.
- wyświetlanie dostępnej ilości pokoi (zadbanie o to aby nie przekraczac liczby rezerwacji ponad dostępne pokoje)

Do zrobienia:

- stworzenie okna aplikacji
- dopracowanie detali wizualnych
- stworzenie bazy danych 

II RAPORT (03.11.2020):

Używane technologie (modyfikacja - dodane):

- SFML (do stworzenia okna aplikacji oraz efektów wizualnych)
- XCode 11.7 (zintegrowane środkowisko programistyczne, dzięki któremu mogłam użyć bibilioteki SFML)
- SQLite 12.0 

Zrobione:

- zainstalowanie framweorków SFML (https://www.youtube.com/watch?v=H7g20Xit8lI)
- zapoznanie się z funkcjonalnością oraz możliwościami biblioteki SFML
- utworzenie projektu w XCode
- zainstalowanie oraz zapoznanie się z SQLite (https://www.youtube.com/watch?v=SkXxnasbrFY)
- zapoznanie się z komendami, możliwościami SQLite (https://www.w3schools.com/sql/)
- utworzone 3 bazy danych: pokoje, goście oraz rezerwacja
- stworzenie ikon oraz elementów graficznych programu (folder - logo)
- stworzenie strony startowej wraz z ikonami (plik strona startowa - zrzut ekranu z pokazanym wyglądem)

Do zrobienia:

- dodanie eventów onclick
- połączenie baz danych z przyciskami


IV RAPORT (01.12.2020):

Zrobione:

- modyfikacja grafiki (zmiana pól)
- dodanie eventu onclick
- skonfigurowanie XCode pod dodatkowe biblioteki SFML
- https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm tutorial
- skonfigurowanie XCode pod sqlite3
- optymalizacja kodu - zmniejszenie ilości wierszy
- dodanie konkretnego eventu po kliknięciu na daną ikonę
- otwieranie baz danych z poziomu c++
- podjęłam również próbę zrobienia text boxu, natomiast nie udało mi się tego wykonać

Do zrobienia:

- text box lub znalezienie alternatywy
- opracowanie wyglądu poszczególnych podstron

V RAPORT (15.12.2020):

Napotkane problemy:

- brak możliwości stworzenia text boxu, kluczowego elementu w aplikacji z poziomu SFML,
- chęć zaistalowania dodatkowej bibilioteki tgui, natomiast przy kompilacji program nie działał

Zrobione:
 - instalacja i zapozanie się z QT Creator
 - przygotowanie takiej samej aplikacji w QT Creator, przenoszenie całości projektu do nowego środowiska
 



 
