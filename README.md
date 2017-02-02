# CenterOfMass
Aplikacja do analizy postawy ciała.

UWAGA! Specyfikacja nie jest kompletna, będzie uzupełniana na bieżąco w trakcie rozwijania aplikacji.

## Scenariusz użycia:

Pacjent z nieprawidłową postawą ciała zgłasza się do fizjoterapeuty w celu jej poprawienia.
Fizjoteraputa robi zdjęcia pacjentowi przed i po korekcji postawy.
Oba zdjęcia załadowuje do aplikacji, zaznacza oś ciała oraz punkty pomocniczne na każdym zdjęciu.
Następnie konsultuje zdjęcia z pacjentem.

### Nowy pacjent
Fizjoterapeuta wybiera z menu opcję "Dodaj pacjenta", program prosi o podanie imienia i nazwiska oraz opcjonalnie dodatkowych danych o pacjencie.
Po zatwierdzeniu danych, w przeglądarce wpisów pojawia się nowy wpis.
Następnie klikając na wspis PPM i wybierając opcję "Dodaj zdjęcie" uruchomiona zostaje przeglądarka obrazów. Fizjoterapeuta wybiera zdjęcie z dysku, które zostaje przekopiowane do folderu "połączonego" z danym wpisem, w folderze roboczym aplikacji.
Dalsze postępowanie uzależnione jest od wyboru użytkownika.

### Stały pacjent
Fizjoterapeuta wybiera z przeglądarki wpisów danego pacjenta, teraz w przeglądarce obrazów (lewej oraz prawej) poprzez opcję "Załaduj zdjęcie" ładuje kolejne zdjęcia z folderu przypisanego pacjentowi.
Obrazy załadowane zostają do przeglądarek wraz z osią i punktami pomocniczymi (jeśli istnieją).
Dalsze postępowanie uzależnione jest od wyboru użytkownika.

## Obecna wersja nie przewiduje:

- automatycznego ustawiania punktów do obliczeń środka ciężkości;
- aplikacji na urządzenia mobilne;


## Opis aplikacji:

Aplikacja ma wspomagać ocenę postawy pacjenta oraz archwizować oceny wraz ze zdjęciami.
Ma umożliwiać dodawanie, edytowanie i usuwanie wpisów  z danymi pacjentów.
Wpis składa się ze zdjęć oraz danych pomocniczych w formie osi symetrii ciała i punktów pomocniczych.
Zdjęcia dla danego pacjenta zapisywane są w formie daty wykonania zdjęcia, przechowywane w folderach z imieniem i nazwiskiem.

Aplikacja składa się z:
- menu główne w górnym lewym rogu, umożliwiającego dodawanie oraz usuwanie pacjentów
- przeglądarki wpisów z pacjentami
- dwóch przeglądarek(lewej i prawej) obrazów z dedykowanym menu

Menu główne zawiera opcje:
-Dodaj pacjenta
-Usuń pacjenta
-Zmień folder roboczy
-Pomoc
-O programie
-Zamknij

Menu pojedynczego wpisu:
-Usuń zdjęcie

Menu przeglądarek zawiera opcje:
-Załaduj zdjęcie
-Zapisz zdjęcie
-Wyczyść zdjęcie
-Dodaj oś
-Dodaj punkt pomocniczy

Przeglądarki obrazów są umiejscowione wertykalnie względem siebie oraz przeglądarki plików.
Poniższy obraz, przedstawia pierwszą wersję programu:
![alt text](/home/mszadkox/git/CenterOfMass/resources/app_gui.png "Wygląd aplikacji" "Rysunek 1. Wygląd aplikacji")

Rysunek 1. Wygląd aplikacji.

Każda z przeglądarek ma identyczną mechanikę to znaczy, że punkty i oś są interaktywne, można je przemieszczać po dodaniu oraz usuwać poprzez wybranie opcji "Usuń" przy pomocy PPM.

## Szczegóły techniczne:

Aplikacja napisana jest w języku C++ przy użyciu biblioteki Qt.

Ustawianie folderu roboczego:
- ścieżka do folderu roboczego znajduje się w ukrytym pliku o nazwie ".workspace" katalogu z plikiem tekstowym
- jeśli podany plik nie istnieje, jest tworzony przy starcie aplikacji, domyślna ścieżka wskazuje na bieżący katalog
- zmiana folderu roboczego odbywa się wyłącznie poprzez wywołanie opcji "Wybierz folder roboczy" w menu głównym
- wybór nowego folderu zostaje zapisany w pliku ".workspace"



## Otwarte punkty:

 - Stosowanie obrazu z wieloma warstawmi lub osobny plik z dodatkowymi informacjami.



## Kolejne fazy aplikacji:

1. Aplikacja okienkowa ze wszystkimi widgetami na miejscu - patrz Rysunek 1.
Wszystkie opcje menu głównego aktywne.
Możliwe jest dodawanie i usuwanie wpisów z pacjentami oraz wybór folderu roboczego.
Wyświetlenie pomocy, krótkiej notki o programie oraz zamknięcie aplikacji.

2.Aktywne opcje menu przeglądarek oraz menu wpisu.




##Do zrobienia:

 - walidacja ścieżki worskspace, wczytanej z pliku
