# C-project---Fabryka-Samochodow

Fabryka samochodów
Etap 1:
Program oferujący następujące funkcjonalności:
1. Klasa reprezentująca Fabrykę posiada unikalną nazwę określającą markę i produkuje
obiekty klasy Samochód i dodaje je do prywatnej tablicy.
2. Metoda tworząca nowy samochód przyjmuje kolor oraz liczbę drzwi jako argumenty.
Właściciel jest ustawiany na “fabryka”, marka zgodnie z nazwą fabryki).
3. Samochód posiada pola: właściciel, kolor, marka (ustalana zgodnie z fabryką), liczba
drzwi, przebieg oraz metody jedź z argumentem mówiącym o liczbie przejechanych
kilometrów (zwiększa przebieg).
4. Fabryka posiada metodę sprzedaj, która zmienia właściciela na osobą kupującą i usuwa
auto z fabryki.
5. Program powinien udostępniać interfejs pozwalający na wywołania poszczególnych
metod.
Etap 2:
Dodajemy klasy Motocykl i Rower (z opcjonalnym koszykiem). Klasa Samochód i Motocykl mają
dodatkowo pole ‘ilość_paliwa’, które jest zmniejszane przez metodę jedź. Wprowadzamy klasy
Pojazd i PojazdSilnikowy. Zaproponuj sposób dziedziczenia oraz sposób rozmieszczenia pól
składowych w tych klasach. Wszystkie Pojazdy posiadają daną ładowność, w przypadku roweru
jest do zależne od posiadanego koszyka, a w klasie Samochodu czy motocyklu jest to
określone rozmiarem bagażnika w danej marce. Klasa Pojazd posiada metodę ‘ładowność’
która zwraca ładowność danego pojazdu.
Dodajemy klasę Komis, która posiada plac (np. vector) na PojazdySilnikowe. Komis może
odkupić auto od właściciela, lub mu je sprzedać. Cena skupu jest funkcją zależną od marki i
przebiegu, a cena sprzedaży jest ceną zakupu z marżą. Przy zakupie przez komis przebieg
niektórych marek jest dzielony przez 2.
Dodajemy klasę Lakiernik, która przyjmuje Pojazd do lakierowania i zmienia mu kolor
Etap 3:
Rozszerzenie o szblony i rzucanie wyjątków
