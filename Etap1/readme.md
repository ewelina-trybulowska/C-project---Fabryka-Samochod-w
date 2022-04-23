W klasie Fabryka stworzyłam wektor o nazwie Samochody, w którym przechowuję 
wskaźniki na obiekty klasy Samochod.
Tworząc nowe samochody wykorzystuje operator new(definiuje 
wskaźnik samochod wskazujący na obiekt klasy Samochod, 
a następnie za pomocą new kreuje nowy obiekt klasy Samochod.
W nowo tworzonych samochodach właściciel jest wpisany jako
fabryka, a przebieg przyjmuje wartość 0).
Samochody są sprzedawane po indeksie, dzięki czemu można 
sprzedać dowolnie wybrany samochód,pozbyc sie go z fabryki-wykorzystuje do tego 
nazwa_tablicy.erase(nazwa_tablicy.begin() + index).
W funkcji sprzedaj, zmieniam właściciela: do pola właściciel wpisuje imię i nazwisko kupującego.
Fabryka, ktora sprzeda samochod kopiuje najpierw ten obiekt do wektora, w ktorym są przechowywane obiekty 
"sprzedane", nastepnie usuwa samochód ze swojego asortymentu.
 Zrobilam tak, ponieważ utworzyłam nową metode, ktora wyswietla jakie samochody z utworzonych
 fabryk zostały sprzedane. Chciałam stworzyc coś na zasadzie historii fabryki, do ktorej są
 wpisywane obiekty sprzedane, to jest troche zbędne, ale mysle że tak jak zrobiłam jest o wiele ciekawiej.
Stworzyłam funkcję wybierania konkretnego samochodu(przez index) i drukującą atrybuty samochodu w fabryce.
Zmienne klasy Samochod umieszczam w private, dzięki czemu mam do
nich dostęp tylko z poziomu klasy. Te zmienne są wykorzystywane przez klasę Fabryka, 
dlatego zaprzyjaźniam klasę Fabryka z klasą Samochód.
W plikach Samochod stworzyłam konstruktor, konstruktor kopiujący i destruktor.
W metodzie jedz, zwiększam przebieg dla samochodów, które są własnością fabryki, samochód
przemieszcza sie po fabyce, pokonuje trase od fabryki do salonu sprzedazy,
fabryka moze uzywac samochodu do celow słóżbowych, a kiedy zdecyduje o sprzedaży
kupujacy powinien znac przebieg auta.Uważam, że z perspektywy fabryki bez sensu jest zwiększać przebieg 
samochodom sprzedanym, kiedy są własnością kupującego i to pokonuje nimi jakąś trase. Fabyka zwieksza przebieg tylko dla samochodow posiadanych.
W pliku main.cpp stworzyłam sobie funkcje pomocnicze z których korzystam w interfejsie przy wybieraniu metod,
dzięki czemu main jest przejrzysty. Po zakończeniu programu, następuje czyszczenie pamięci, usuwam samochody 
które pozostały niesprzedane i te przechowywane jako sprzedane i zwalniam pamiec. 
W moim programie można stworzyć kilka fabryk, nie ogarniczam się do jednej.
