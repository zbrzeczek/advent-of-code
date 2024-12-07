#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Day1 {
public:
    vector<int> table1;
    vector<int> table2;

    int part1(string fileName){
        fstream plik;
        int number;
        bool toggle = true; // Alternates between true and false
        string line;


        plik.open(fileName, ios::in);
        if (plik.good()){
            while (plik >> number) {
                if (toggle) {
                    table1.push_back(number); // Add to the first table
                }
                else {
                    table2.push_back(number); // Add to the second table
                }
                toggle = !toggle; // Switch toggle
            }
        }
        else cout << "Dostep do pliku zostal zabroniony!" << endl;

        plik.close();

        sort(table1.begin(), table1.end());
        sort(table2.begin(), table2.end());

        int sum = 0;
        for (int i = 0; i < table1.size(); i++){
            sum += abs(table2[i] - table1[i]);
        }

        return sum;
    }

    int part2(){
        int sum = 0;
        for (int i : table1){
            for (int j : table2){
                if (i == j) sum += j;
            }
        }
        return sum;
    }
};


int main() {
    Day1 day1;

    cout << day1.part1("input.txt") << endl;
    cout << day1.part2();

    return 0;
}