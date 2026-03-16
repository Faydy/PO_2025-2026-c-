#include "elev.h"
#include "profesor.h"
#include "parent.h"

int main() {
    Elev elevi[100];      // array static pentru stocare
    int numarElevi = 0;
    int optiune;

    do {
        cout << "\n===== MENIU =====\n";
        cout << "1. Adauga elev (Create)\n";
        cout << "2. Afiseaza toti elevii (Read)\n";
        cout << "3. Modifica elev (Update)\n";
        cout << "4. Sterge elev (Delete)\n";
        cout << "0. Iesire\n";
        cout << "Optiune: ";
        cin >> optiune;
        cin.ignore();

        switch(optiune) {
            case 1: // CREATE
                if (numarElevi < 100) {
                    cin >> elevi[numarElevi];
                    numarElevi++;
                    cout << "Elev adaugat!\n";
                } else cout << "Lista plina!\n";
                break;

            case 2: // READ
                if (numarElevi == 0)
                    cout << "Nu exista elevi!\n";
                for (int i = 0; i < numarElevi; ++i) {
                    cout << i+1 << ". " << elevi[i];
                }
                break;

            case 3: // UPDATE
                int index;
                cout << "Index elev de modificat (1-" << numarElevi << "): ";
                cin >> index; cin.ignore();
                if (index >= 1 && index <= numarElevi) {
                    cout << "Date noi:\n";
                    cin >> elevi[index-1];
                } else cout << "Index invalid!\n";
                break;

            case 4: // DELETE
                int idx;
                cout << "Index elev de sters (1-" << numarElevi << "): ";
                cin >> idx; cin.ignore();
                if (idx >= 1 && idx <= numarElevi) {
                    // Muta elementele la stanga
                    for (int i = idx-1; i < numarElevi-1; ++i)
                        elevi[i] = elevi[i+1];
                    numarElevi--;
                    cout << "Elev sters!\n";
                } else cout << "Index invalid!\n";
                break;

            case 0:
                cout << "La revedere!\n";
                break;

            default:
                cout << "Optiune invalida!\n";
        }
    } while(optiune != 0);

    return 0;
}