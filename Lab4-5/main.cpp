#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int ALL_NUMBERS;

    string input;

    cout << "Enter combinations(N=1,Y=0):" << endl;
    cin >> input;

    ALL_NUMBERS = input.size();

    int NUMBER_OF_COMMUNICATIONS = sqrt(ALL_NUMBERS);
    int servers[NUMBER_OF_COMMUNICATIONS][NUMBER_OF_COMMUNICATIONS];

    int row = 0, column = 0;
    for (int rowIndex = 0; rowIndex < ALL_NUMBERS; rowIndex++) {
        if (row >= NUMBER_OF_COMMUNICATIONS) {
            break;
        }
        if (column < NUMBER_OF_COMMUNICATIONS) {
            if (input.at(rowIndex) == '0')
                servers[row][column] = 0;
            else
                servers[row][column] = 1;
            column++;
        }
        if (column == NUMBER_OF_COMMUNICATIONS) {
            column = 0;
            row++;
        }
    }

    for (int i = 0; i < NUMBER_OF_COMMUNICATIONS; i++) {
        for (int j = 0; j < NUMBER_OF_COMMUNICATIONS; j++) {
            cout << servers[i][j] << " ";
        }
        cout << endl;
    }

    int numberOfServers = 0;
    int highNumberOfServers = 0;

    //1000001111011110111101111     2
    //1000001111011100111001001     4
    for (int iServer = 1; iServer <= NUMBER_OF_COMMUNICATIONS - 1; iServer++) {
        for (int jServer = 1; jServer <= NUMBER_OF_COMMUNICATIONS - iServer; jServer++) {
            numberOfServers = 0;

            for (int row = 0; row < NUMBER_OF_COMMUNICATIONS; row++) {
                if (servers[row][iServer - 1] == 1
                    && servers[row][iServer + jServer - 1] == 0) {
                    numberOfServers += 2;
                }
                if (highNumberOfServers < numberOfServers)
                    highNumberOfServers = numberOfServers;
            }
        }
    }

    cout << "Number of servers in simultaneous communication is " << highNumberOfServers << endl;

    return 0;
}
