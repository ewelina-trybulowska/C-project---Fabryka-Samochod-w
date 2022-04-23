-naglowki funkcji pomocniczych do maina umiesciłam w naglowki.h, żeby trochę bardziej czytelniejszy był ten main
-stworzyłam 2 szablony klasy - Fabryke i Własciciela
dzięki temu tworze fabryke do każdego rodzaju pojazdu i np.Po stworzeniu fabryki samochodow 
Samochody przechowuje w wektorze wskaźników na obiekty klasy samochod, wyodrebniam 
rodzaje pojazdów na różne fabryki i dana fabryka specjalizuje się tylko w produkowaniu jedego rodzaju pojazdow.
Taki sam zamysł miałam robiąc szablon klasy
właściciel, dzięki czemu pogrupowałam pojazdy sprzedne na sprzedane samochody, rowery i 
motocykle, a nie jak w poprzednim etapie że wszystkie pojazdy zmieniłam na obiekty klasy Pojazd i trzymam 
w jednym kontenerze bez możliwości wyodrępnienia samochodów, motocykli i rowerow;)
-stworzyłam szablon funkcji służącej do lakierowania pojazdow, funkcja lakieruje wszystkie typy pojazdow


-rzucanie wyjątków
-struktury z wyjątkami są w oddzielnym pliku nagłowkowym Exception.h
-rzucanie wyjątków jest:
	- w funkcji lakiernik jest przy wyborze koloru czerwonego, złego indeksu, probie sprzedazy roweru jezeli
jeszcze zaden nie zostal sprzedany 
	-przy sprawdzaniu pojemnosci, wybranie zlego indeksu, jezeli kontener z pojazdami jest
pusty
	-przy probie sprzedania roweru do komisu, wybranie złego indeksu, probie sprzedazy jezeli kontener z pojazdami jest
pusty
	-dla sprawdzania przebiegu pojazdów z fabryki:wpisanie ujemnej liczby kilometrow, wpisane zlego nr pojazdu
