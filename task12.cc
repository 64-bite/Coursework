#include "puzzle_solver.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

vector<int> readInput(const string& message, int count) {
    vector<int> result(count);
    cout << message << endl;
    for (int i = 0; i < count; ++i) {
        cin >> result[i];
    }
    return result;
}

int main() {
    int choice;
    string fileName;

    cout << "=== Японський кросворд з човнами ===" << endl;
    cout << "1) Ввести умови головоломки та розв’язати її" << endl;
    cout << "2) Вийти" << endl;

    while (true) {
        cout << "Ваш вибір: ";
        if (!(cin >> choice) || choice < 1 || choice > 2) {
            cout << "Невірний вибір! Спробуйте ще раз." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    if (choice == 2) {
        cout << "Завершення програми." << endl;
        return 0;
    }

    vector<int> whiteRows = readInput("Введіть верхній ряд (білі клітинки):", 9);
    vector<int> blackRows = readInput("Введіть нижній ряд (чорні клітинки):", 9);
    vector<int> whiteCols = readInput("Введіть лівий стовпець (білі клітинки):", 9);
    vector<int> blackCols = readInput("Введіть правий стовпець (чорні клітинки):", 9);

    ShipsPlacement placement(whiteRows, blackRows, whiteCols, blackCols);
    PuzzleSolver solver(placement);

    cout << "Розв’язання головоломки..." << endl;
    if (solver.solve()) {
        cout << "Головоломку розв’язано!" << endl;
        solver.printConsoleFile("solution.txt");
    } else {
        cout << "Не вдалося розв’язати головоломку!" << endl;
    }

    return 0;
}
