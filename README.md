# 🍽 Sistem de Gestionare a Rezervărilor pentru Restaurante

Acest proiect C++ implementează un sistem simplu de gestionare a rezervărilor într-un restaurant, folosind conceptele de moștenire, polimorfism și clase abstracte.

## 🎯 Scopul proiectului

Proiectul are ca scop consolidarea cunoștințelor despre programarea orientată pe obiect (POO), mai ales despre:
- Interfețe (clase abstracte)
- Moștenire
- Polimorfism
- Gestionarea dinamică a memoriei
- Lucrul cu fișiere text

## 📂 Structura proiectului

- `IRezervare` – Interfață abstractă care definește metode pentru calculul duratei și prețului.
- `Rezervare` – Clasa de bază, comună tuturor rezervărilor.
- `RezervareZilnica`, `RezervareEvenimentSpecial`, `RezervareGrupMare` – Clase derivate cu logica specifică.
- `rezervari.txt` – Fișier text care conține datele rezervărilor.
- `main()` – Citește datele din fișier, creează obiecte și afișează detaliile rezervărilor.
