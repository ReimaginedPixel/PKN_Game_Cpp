#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <locale>
#include <limits>

using namespace std;

// forward declaration for functions used before definition
void ModyfikacjaStatystyk(string metoda, string jaka_statystyka, int wartosc);

//Projekt 2
//Zaprogramuj grę w „papier - kamień - nożyce”.W pierwszym kroku, program pyta użytkownika, 
//do ilu wygranych chce grać.Kolejno potem następują rundy, w których może wygrać komputer, 
//użytkownik lub może być remis.Po osiągnięciu limitu wygranych przez któregokolwiek z graczy – 
//następuje zakończenie programu i wyświetlenie wyników.Dopisuj wynik do pliku.Wczytaj z pliku stan 
//gry(kto częściej wygrywał) lub wyczyść plik.


//   //_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-\\
//   ||										  ||
//   ||         Funkcje Wyświetlające         ||
//   ||										  ||
//   \\_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-//

void Pozegnanie()
{
	cout << R"(
  ___        ____    _                         _      _ 
 |   \ ___  |_  /___| |__  __ _ __ ______ _ _ (_)__ _| |
 | |) / _ \  / // _ \ '_ \/ _` / _|_ / -_) ' \| / _` |_|
 |___/\___/ /___\___/_.__/\__,_\__/__\___|_||_|_\__,_(_)
                                                        )" << endl;
}

void Logo()
{
	cout << R"(
 .----------------.  .----------------.  .-----------------.
| .--------------. || .--------------. || .--------------. |
| |   ______     | || |  ___  ____   | || | ____  _____  | |
| |  |_   __ \   | || | |_  ||_  _|  | || ||_   \|_   _| | |
| |    | |__) |  | || |   | |_/ /    | || |  |   \ | |   | |
| |    |  ___/   | || |   |  __'.    | || |  | |\ \| |   | |
| |   _| |_      | || |  _| |  \ \_  | || | _| |_\   |_  | |
| |  |_____|     | || | |____||____| | || ||_____|\____| | |
| |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------' 

	)" << endl;
}

void PodTytul()
{
	cout << "=+--==--==--==--==--==--==--==--==--==--==--==--==--==--=+" << endl;
	cout << "=+            Gra w Papier - Kamień - Nożyce            =+" << endl;
	cout << "=+--==--==--==--==--==--==--==--==--==--==--==--==--==--=+" << endl;
}

void Statystyki()
{
	cout << R"(
 ___  ____   __   ____  _  _  ___  ____  _  _  _  _  ____ 
/ __)(_  _) /__\ (_  _)( \/ )/ __)(_  _)( \/ )( )/ )(_  _)
\__ \  )(  /(__)\  )(   \  / \__ \  )(   \  /  )  (  _)(_ 
(___/ (__)(__)(__)(__)  (__) (___/ (__)  (__) (_)\_)(____))" << endl;


	ifstream statystyki_odczyt("statystyki.txt");
	if (statystyki_odczyt.is_open())
	{
		string linia;

		cout << "\n          +- --- -+   Statystyki gier:   +- --- -+\n";
		cout << endl;

		while (getline(statystyki_odczyt, linia))
		{
			cout << "            ||> " << linia << endl;
		}

		cout << endl;
		cout << "          +- --- -+  Kliknij Cokolwiek  +- --- -+\n";
		cout << "                     Aby Przejsc Dalej\n" << endl;

		statystyki_odczyt.close();
		cin.get();
	}
}

void ustawienia()
{
	cout << R"(
 __  __  ___  ____   __    _    _  ____  ____  _  _  ____    __   
(  )(  )/ __)(_  _) /__\  ( \/\/ )(_  _)( ___)(\( )(_  _)  /__\  
 )(__)( \__ \  )(  /(__)\  )    (  _)(_  )__)  )  (  _)(_  /(__)\ 
(______)(___/ (__)(__)(__)(__/\__)(____)(____)(_)\_)(____)(__)(__)

               // ==================== \\
               ||  1. Reset Statystyk  ||
               ||                      ||
               ||  2. Menu - Wyjdź     ||
               \\ ==================== //
)";

}

void menu()
{
	cout << R"(
                 _  _  ____  __ _  _  _ 
                ( \/ )(  __)(  ( \/ )( \
                / \/ \ ) _) /    /) \/ (
                \_)(_/(____)\_)__)\____/

               // ==================== \\
               ||    1. Nowa gra       ||
               ||    2. Statystyki     ||
               ||    3. Ustawienia     ||
               ||    4. Wyjdź          ||
               \\ ==================== //
)";

}


//   //_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-\\
//   ||										  ||
//   ||                  Widok                ||
//   ||										  ||
//   \\_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-//

void ResetWidokuMenu()
{
	system("cls");
	Logo();
	PodTytul();
	menu();

}

//   //_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-\\
//   ||										  ||
//   ||         Funkcje Walidujące            ||
//   ||										  ||
//   \\_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-//

int WybiezOpcje()
{
	string error = " ";
	int wybor;

	while (true)
	{
		cout << R"(                || )" << error << endl;
		cout << R"(                \\<><><> -> )";
		cin >> wybor;

		//sprawdza czy litera
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			error = "Błąd! Podaj liczbę, nie literę.";
			ResetWidokuMenu();
		}

		//sprawdza czy w zakresie
		else if (wybor < 1 || wybor > 4)
		{
			error = "Błąd! Wybierz liczbę od 1 do 4.";
			ResetWidokuMenu();
		}

		//jeśli wszystko ok
		else
		{
			cin.ignore(1000, '\n');
			error = " ";
			return wybor;
		}
	}
}

int WybiezOpcje_Ustawienia()
{
	string error = "";
	int wybor;

	while (true)
	{
		system("cls");
		Logo();
		PodTytul();
		ustawienia();

		if (!error.empty())
			cout << "               || " << error << endl;

		cout << R"(                \\<><><> -> )";
		cin >> wybor;

		// jeśli wpisano literę
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			error = "Błąd! Podaj liczbę, nie literę.";
			continue;
		}

		// jeśli poza zakresem
		if (wybor < 1 || wybor > 2)
		{
			error = "Błąd! Wybierz liczbę od 1 do 2.";
			continue;
		}

		// specjalna akcja dla 1
		if (wybor == 1)
		{
			ModyfikacjaStatystyk("reset", "", 0); // wykonaj akcję
			error = "Usunięto Statystyki Poprawnie.";
			continue; // wróć do menu ustawień
		}

		// poprawny wybór → wyjście z funkcji
		return wybor;

	}
}

//   //_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-\\
//   ||										  ||
//   ||         Funkcje Elementow             ||
//   ||										  ||
//   \\_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-//

void UstawieniaFunkcjonalnosc()
{
	int ustawienia_wybor = WybiezOpcje_Ustawienia();
	switch (ustawienia_wybor)
	{
	case 1:
	{
		ModyfikacjaStatystyk("reset", "", 0);
		break;
	}
	case 2:
	{
		//wyjscie do menu
		break;
	}
	default:
		break;
	}
}

void ModyfikacjaStatystyk(string metoda, string jaka_statystyka, int wartosc)
{
	int wygrane = 0;
	int przegrane = 0;

	// --- ODCZYT AKTUALNYCH DANYCH ---
	ifstream zapisz("statystyki.txt");
	if (zapisz.is_open())
	{
		string label;
		zapisz >> label >> wygrane;     // Wygrane: X
		zapisz >> label >> przegrane;   // Przegrane: Y
		zapisz.close();
	}

	// --- LOGIKA ---
	if (metoda == "reset")
	{
		wygrane = 0;
		przegrane = 0;
	}

	else if (metoda == "dodaj")
	{
		if (jaka_statystyka == "Wygrane")
			wygrane += wartosc;
		else if (jaka_statystyka == "Przegrane")
			przegrane += wartosc;
	}

	else if (metoda == "odczyt")
	{
		cout << "Wygrane: " << wygrane << endl;
		cout << "Przegrane: " << przegrane << endl;
		return;
	}

	// --- ZAPIS (CZYŚCI PLIK) ---
	ofstream out("statystyki.txt", ios::trunc);
	if (out.is_open())
	{
		out << "Wygrane: " << wygrane << endl;
		out << "Przegrane: " << przegrane << endl;
		out.close();
	}
}

//   //_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-\\
//   ||										  ||
//   ||                  Gra                  ||
//   ||										  ||
//   \\_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-//


void LogoGry()
{
	cout << R"(
   ___               __                                   _        
  / _ \_ __ __ _    /__\ ___ _____ __   ___   ___ _______| |_ __ _ 
 / /_\/ '__/ _` |  / \/// _ \_  / '_ \ / _ \ / __|_  / _ \ __/ _` |
/ /_\\| | | (_| | / _  \ (_) / /| |_) | (_) | (__ / /  __/ || (_| |
\____/|_|  \__,_| \/ \_/\___/___| .__/ \___/ \___/___\___|\__\__,_|
                                |_|                                )" << endl;
}

void LogoRuchu(int Ruch)
{
	switch (Ruch)
	{
	case 1: // papier
		cout << R"(
                         _______
====================||---'   ____)____
                    ||          ______)
     PAPIER         ||          _______)
                    ||         _______)
====================||---.__________))" << endl;

		break;
	case 2: // kamień
		cout << R"(
                          _______
====================||---'   ____)
                    ||      (_____)
       KAMIEŃ       ||      (_____)
                    ||      (____)
====================||---.__(___))" << endl;
		break;
	case 3: // nożyce
		cout << R"(

                          _______
====================||---'   ____)____
                    ||          ______)
       NOŻYCE       ||       __________)
                    ||      (____)
====================||---.__(___))" << endl;
		break;

	default:
		break;
	}
}
int WalidacjaWygranych()
{
	int liczba_wygranych;
	string error = " ";
	cout << endl;

	while (true)
	{


		system("cls");
		LogoGry();

		cout << "                 " << error << endl << R"(
                         { Ustawienia Gry }
                    Tryb Gry: Komputer vs Gracz
                    (Podaj) Ilość Wygranych: > )";
		cin >> liczba_wygranych;
		//sprawdza czy litera
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			//error
			error = "[X] Błąd! Podaj liczbę, nie literę.";
		}
		//sprawdza czy w zakresie
		else if (liczba_wygranych < 1 || liczba_wygranych > 100)
		{
			// error
			error = "[X] Błąd! Wybierz liczbę od 1 do 100.";
		}
		//jeśli wszystko ok
		else
		{
			//cout << endl;
			//cout << "               Kliknij Cokolwiek, Aby Rozpocząć Grę!" << endl;
			cin.ignore(1000, '\n');
			return liczba_wygranych;
		}
	}
}


int WalidacjaRuchu()
{
	int ruch;
	string error = " ";
	while (true)
	{
		system("cls");
		LogoGry();
		cout << "                 " << error << endl << R"(
			    { Wybierz Swoj Ruch }
			   // ==================== \\
			   ||    1. Papier         ||
			   ||    2. Kamień         ||
			   ||    3. Nożyce         ||
			   \\ ==================== //
			   Wybierz Ruch > )";
		cin >> ruch;
		//sprawdza czy litera
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			error = "      [X] Błąd! Podaj liczbę, nie literę.";
		}
		//sprawdza czy w zakresie
		else if (ruch < 1 || ruch > 3)
		{
			error = "      [X] Błąd! Wybierz liczbę od 1 do 3.";
		}
		//jeśli wszystko ok
		else
		{
			cin.ignore(1000, '\n');
			error = " ";
			return ruch;
		}
	}
}

void ObliczaneWygranej(int ruch, int komputer_ruch, int& twoje_wygrane, int& komputer_wygrane)
{
	// sprawdzanie wyniku
	if (ruch == komputer_ruch)
	{
		cout << "\n               Remis! Nikt Nie Zdobywa Punktu!" << endl;
	}
	else if ((ruch == 1 && komputer_ruch == 2) || (ruch == 2 && komputer_ruch == 3) || (ruch == 3 && komputer_ruch == 1))
	{
		cout << "\n               Wygrałeś Rundę! Zdobywasz Punkt!" << endl;
		twoje_wygrane++;
	}
	else
	{
		cout << "\n               Przegrałeś Rundę! Komputer Zdobywa Punkt!" << endl;
		komputer_wygrane++;
	}
}

void Gra_Poczatek(int liczba_wygranych)
{
	//ruch 1 = papier
	//ruch 2 = kamień
	//ruch 3 = nożyce
	bool gra_dziala = true;

	int twoje_wygrane = 0;
	int komputer_wygrane = 0;

	int ruch = 0;
	int komputer_ruch = 0;


	// tutaj będzie kod gry


	while (gra_dziala = true)
	{
		system("cls");
		LogoGry();
		cout << "\n      Gra W Trakcie! Liczba Wygranych Do Zaknoczenia Gry: " << liczba_wygranych << endl;
		cout << "            Twoje Wygrane: " << twoje_wygrane << "  |  Wygrane Komputera: " << komputer_wygrane << endl;
		cout << endl;
		cout << "\n            [i] Twoj Przciwnik Juz Wybrał Ruch! " << endl;

		// komputer wybiera ruch
		komputer_ruch = rand() % 3 + 1;

		cout << "\n                  Teraz Twoja Kolej! ";
		cout << "\n             Kliknij Cokolwiek Aby Wybrac Ruch ";
		cin.get();
		ruch = WalidacjaRuchu();

		system("cls");
		LogoGry();

		ObliczaneWygranej(ruch, komputer_ruch, twoje_wygrane, komputer_wygrane);

		cout << "\n      Gra W Trakcie! Liczba Wygranych Do Zaknoczenia Gry: " << liczba_wygranych << endl;
		cout << "            Twoje Wygrane: " << twoje_wygrane << "  |  Wygrane Komputera: " << komputer_wygrane << endl;

		cout << "\n        Twój Ruch to: " << endl;
		LogoRuchu(ruch);

		cout << "\n        Ruch Komputera to: " << endl;
		LogoRuchu(komputer_ruch);

		if (twoje_wygrane >= liczba_wygranych)
		{

			cout << R"(
                                _              _     
__      ___   _  __ _ _ __ __ _| | ___  ___   / \    
\ \ /\ / / | | |/ _` | '__/ _` | |/ _ \/ __| /  /    
 \ V  V /| |_| | (_| | | | (_| | |  __/\__ \/\_/     
  \_/\_/  \__, |\__, |_|  \__,_|_|\___||___/\/       
          |___/ |___/  )";
			cout << "\n\n       Gratulacje! Wygrałeś Całą Grę! " << endl;
			cout << "\n           Wspaniale Jeszcze Raz?! " << endl;
			ModyfikacjaStatystyk("dodaj", "Wygrane", 1);

			cout << endl;
			cout << "\n\n       Kliknij Cokolwiek, Aby Powrócić Do Menu Głównego! " << endl;
			break;
		}
		else if (komputer_wygrane >= liczba_wygranych)
		{
			cout << R"(
   ___                              _              _ 
  / _ \_ __ _______  __ _ _ __ __ _| | ___  ___   / \
 / /_)/ '__|_  / _ \/ _` | '__/ _` | |/ _ \/ __| /  /
/ ___/| |   / /  __/ (_| | | | (_| | |  __/\__ \/\_/ 
\/    |_|  /___\___|\__, |_|  \__,_|_|\___||___/\/   
                    |___/                           )";

			cout << "\n\n       Niestety, Przegrałeś Całą Grę! " << endl;
			cout << "\n       Powodzenia Nastepnym Razem! " << endl;

			ModyfikacjaStatystyk("dodaj", "Przegrane", 1);
			cout << endl;
			cout << "       Kliknij Cokolwiek, Aby Powrócić Do Menu Głównego! " << endl;
			break;
		}

		cout << "\n\n        Kliknij Cokolwiek, Aby Kontynuować Grę! " << endl;
		cin.get();
	}


	cin.get();
}

int main()
{
	int menu_wybor;
	bool dzialanie_gry = true;

	srand(time(NULL));
	setlocale(LC_ALL, "");

	while (dzialanie_gry)
	{
		ResetWidokuMenu();

		menu_wybor = WybiezOpcje();

		switch (menu_wybor)
		{
		case 1:
			int liczba_wygranych;
			system("cls");
			LogoGry();
			liczba_wygranych = WalidacjaWygranych();
			Gra_Poczatek(liczba_wygranych);

			break;
		case 2:
			system("cls");
			Logo();
			PodTytul();

			Statystyki();
			break;
		case 3:
			system("cls");
			Logo();
			PodTytul();

			ustawienia();
			UstawieniaFunkcjonalnosc();

			system("cls");
			cin.get();

			break;

		case 4:
			system("cls");
			Logo();
			PodTytul();
			Pozegnanie();

			dzialanie_gry = false;
			break;

		default:
			break;
		}

	} //while dzialanie_gry

	return 0;
}