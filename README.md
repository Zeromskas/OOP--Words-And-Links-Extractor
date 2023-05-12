# OOP-egzaminas

Programa, iš duoto teksto išrenkanti internetines nuorodas (prasidedančias "https://", "http://" arba "www.") ir randanti visus pasikartojančius žodžius.
Rezultatas: failas su nuorodomis ir lentele, su skiltimis "žodis", "kiekis" (kiek kartų pasikartojo tekste), eilutės (kuriose teksto eilutėse žodis pasikartojo)

# Programos pasileidimas
1. Norint paleisti programą, terminale rašykite: _make_
2. Nurodykite tekstinio failo, kurį norėsite apdoroti, pavadinimą
3. Rezultatai bus surašyti į _rezultatai.txt_ failą

# Pradinio failo pavyzdys _example.txt_
- - - - - - - - - - - - - - - - - - - - - - - - - - - - -

If you're interested in learning more about artificial intelligence, 
you can check out the OpenAI website at https://openai.com/. For a 
comprehensive overview of computer science topics, including 
algorithms, data structures, and more, visit the Computer Science 
Field Guide at https://www.csfieldguide.org.nz/. And if you want to 
keep up with the latest technology news and trends, be sure to 
follow TechCrunch at https://techcrunch.com/.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Rezultato pavyzdys _rezultatai.txt_
- - - - - - - - - - - - - - - - - - - - - - - - - - - - -

example.txt 

NUORODOS (3)
https://openai.com/
https://www.csfieldguide.org.nz/
https://techcrunch.com/

PASIKARTOJANTYS ŽODŽIAI
Žodis              | Kiekis  | Eilutėse
--------------------------------------------------------------
and                 3         4  5  6  
--------------------------------------------------------------
at                  3         2  5  7  
--------------------------------------------------------------
computer            2         3  4  
--------------------------------------------------------------
if                  2         1  5  
--------------------------------------------------------------
more                2         1  4  
--------------------------------------------------------------
science             2         3  4  
--------------------------------------------------------------
the                 3         2  4  6  
--------------------------------------------------------------
to                  2         5  6  
--------------------------------------------------------------
you                 3         1  2  5  
--------------------------------------------------------------

- - - - - - - - - - - - - - - - - - - - - - - - - - - - -
