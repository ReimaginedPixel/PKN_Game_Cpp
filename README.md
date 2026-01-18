# 🎮 Papier - Kamień - Nożyce (PKN)

Konsolowa gra w Papier-Kamień-Nożyce napisana w C++ z systemem statystyk i zapisem do pliku.

## 📋 Opis

Klasyczna gra PKN, w której gracz rywalizuje z komputerem. Przed rozpoczęciem rozgrywki wybierasz liczbę wygranych potrzebnych do zakończenia meczu. Gra śledzi Twoje statystyki i zapisuje je do pliku.

## ✨ Funkcje

- **Rozgrywka vs Komputer** - komputer losowo wybiera swój ruch
- **Konfigurowalny cel** - wybierz od 1 do 100 wygranych potrzebnych do zwycięstwa
- **System statystyk** - śledzenie wygranych i przegranych zapisywanych do pliku
- **ASCII Art** - estetyczne logo i grafiki ruchów w konsoli
- **Walidacja danych** - obsługa błędnych danych wejściowych
- **Menu główne** - nawigacja między grą, statystykami i ustawieniami

## 🎯 Zasady gry

| Ruch | Wygrywa z | Przegrywa z |
|------|-----------|-------------|
| 📄 Papier | Kamień | Nożyce |
| 🪨 Kamień | Nożyce | Papier |
| ✂️ Nożyce | Papier | Kamień |

## 🚀 Uruchomienie

### Wymagania
- Kompilator C++ (g++, MSVC, clang)
- System Windows (używa `system("cls")`)

### Kompilacja

```bash
g++ -o pkn main.cpp
```

### Uruchomienie

```bash
./pkn
```

## 📁 Struktura plików

```
├── main.cpp          # Główny kod źródłowy
├── statystyki.txt    # Plik ze statystykami (tworzony automatycznie)
└── README.md
```

## 🎮 Sterowanie

### Menu główne
1. **Nowa gra** - rozpocznij nową rozgrywkę
2. **Statystyki** - wyświetl historię wygranych/przegranych
3. **Ustawienia** - resetuj statystyki
4. **Wyjdź** - zakończ program

### W grze
- Wpisz `1` dla Papieru
- Wpisz `2` dla Kamienia
- Wpisz `3` dla Nożyc

## 📊 Statystyki

Gra automatycznie zapisuje wyniki do pliku `statystyki.txt`:
- Liczba wygranych meczów
- Liczba przegranych meczów

Statystyki można zresetować w menu Ustawienia.

## 🛠️ Technologie

- **Język:** C++
- **Biblioteki:** iostream, fstream, cstdlib, ctime, string, locale, limits

## 📝 Licencja

Projekt edukacyjny - do dowolnego użytku. (MIT)
