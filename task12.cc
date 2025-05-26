#include <iostream>
#include <limits>
#include <string>
#include "puzzleSolver.h"

using namespace std;
/*----------------------------------------------------------------<Header>-
 Name: task12.cc
 Title: Японський кросворд з човнами
 Group: ТВ-43
 Student: Матвієнко
 Written: 2025-05-22
 Revised: 2025-05-23
 Description: Основний файл, 
 ------------------------------------------------------------------</Header>-*/
  /* ---------------------------------------------------------------------[<]-
 Function: readInput()
 Synopsis: Функція зчитування з консолі
 TODO: додати перевірки, користувацького вводу
 ---------------------------------------------------------------------[>]-*/
vector<int> readInput(const string& message, int count) {
    vector<int> result(count);
    cout << message << endl;
    for (int i = 0; i < count; ++i) {
        cin >> result[i];
    }
    return result;
}
 /* ---------------------------------------------------------------------[<]-
 Function: result()
 Synopsis: Функція перевірки чи виконано завдання
 ---------------------------------------------------------------------[>]-*/
void result(ShipsPlacement &placement) {
	PuzzleSolver solver(placement);
	cout << "Розв’язання головоломки..." << endl;
    if (solver.solve(0)) {
        cout << "Головоломку розв’язано!" << endl;
        solver.printConsoleFile("solution.txt");
    } else {
        cout << "Не вдалося розв’язати головоломку!" << endl;
    }
}
 /* ---------------------------------------------------------------------[<]-
 Function: main()
 Synopsis: Головна функція, яка виводить інтерфейс в консоль і проводить операції за написаним числом
 ---------------------------------------------------------------------[>]-*/
int main() {
    int choice;
    cout << "=== Японський кросворд з човнами ===" << endl;
    cout << "1) Ввести умови головоломки та розв’язати її" << endl;
	cout << "2) Використати умови з програми та розв'язати головоломку" << endl;
    cout << "3) Вийти" << endl;

    while (true) {
        cout << "Ваш вибір: ";
        if (!(cin >> choice) || choice < 1 || choice > 3) {
            cout << "Невірний вибір! Спробуйте ще раз." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    if (choice == 3) {
        cout << "Завершення програми." << endl;
        return 0;
    } else if(choice == 2){
		ShipsPlacement placement;
		result(placement);
	} else if(choice == 1) {
		vector<int> whiteRows = readInput("Введіть верхній ряд (білі клітинки):", 9);
		vector<int> blackRows = readInput("Введіть нижній ряд (чорні клітинки):", 9);
		vector<int> whiteCols = readInput("Введіть лівий стовпець (білі клітинки):", 9);
		vector<int> blackCols = readInput("Введіть правий стовпець (чорні клітинки):", 9);
		ShipsPlacement placement(whiteRows, blackRows, whiteCols, blackCols);
		result(placement);
	} else {
		cout << "Такої операції не існує!";
		return 1;
	}
    return 0;
}

