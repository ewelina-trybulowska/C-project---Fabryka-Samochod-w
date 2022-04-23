-liczba fabryk ograniczona jest do 4, fabryke wybiera się po nazwie.
Są 4 fabryki: BMW, Audi, Scoda, Tesla

-klasą bazową jest klasa pojazd, pochodną od niej są klasa rower i pojazd silnikowy, klasa pojazd silnikowy jest
klasą bazową dla klasy samochod i motocykl

-Wykorzystałam w moim projekcie hierarchię dziedziczenia i możliwość rzutowania, więc umieściłam wszystkie
 pojazdy wyprodukowane przez fabrykę w wektorze wskaźników na obiekt typu Pojazd. Każdy samochód, rower, 
czy motocykl jest przecież pojazdem.Konwersja w górę(z klasy pochodnej na bazową) zachodzi automatycznie,
ale w sytuacji kiedy potrzebna była konwersja w dół skorzystałam z dynamic_cast.

-żebym konwersja zachodziła automatycznie klasa pojazd musiała być dziedziczona przez pojazd silnikowy publicznie,
ale te składniki które mogłam udostępniłam wybiórczo do protected( użyłam using), chciałam żeby projekt
był "zhermetyzowany", następne dziedziczenia są privat, a z fabryką zaprzyjaźniam już tylko klasy
samochod, rower i motocykl

-w projekcie korzystam z polimorfizmu

-meoda ładowność, drukowanie i jedź są funkcami wirtualnymi

-Stworzyłam dodatkowo klase owner, w której przechowuje w wektorze wskaźników pojazdy, które mają właściciela,
jak również metody które są wykorzystywane w projekcie przez tą klasę

-komis, lakiernik i właściciel są "odrębnymi instancjami"

-METODA JEDŹ- metoda oprócz zmieniania kilometrów zmieniam też stan paliwa, pojazdy silnikowe na start dostają pełen 
bag- samochod 100 l , motocykl 50 l. Ilośc paliwa zmniejsza się z odpowiednim przeliczeniem w zależności od przebytych
kilometrów. Kiedy poziom paliwa osiągnie rezerwę, następuje tankowanie do pełna. W funkcji zliczam tez 
ilość tankowań w czasie tej podróży.

-ŁADOWNOŚĆ- uzależniłam ją od marki pojazdu, wszystkie pojazdy tej samej marki mają taki sam bagażnik
(rozróżniam w tej metodzie pojazdy), wyznacznikiem ładowności roweru jest koszyk, który albo ktoś zamontuje
albo nie - czy jest koszyk czy nie sprawdzam typem logicznym bool

-skoro komis posiada plac na Pojazdy Silnikowe to sprzedaje do niego samochody i motory

-CENA SKUPU- w komisie stworzyłam do tego funkcję pomocniczą, która wylicza wartość według algorytmu. Na 
start pojazd dostaje pewną cenę zależną od marki, ta cena jest pomniejszana o przejechane 
kilometry z odpowiednim przelicznikiem(każdy kilometr obniża wartość pojazdu), dodatkowo ostateczna cena 
jeżeli pojazdem jest motocykl pomniejszana jest o połowę, bo motocykle są tańsze od samochodów

-PRZEBIEG- komis dzieli przebieg pojazdów marek BMW i Audi, przebieg Scody i Tesli nie jest przekręcany

-CENA SPRZEDAŻY- marża to 10% ceny zakupu
