#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<vector<double>> read_csv(string filename) {
    vector<vector<double>> data;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        vector<double> row;
        stringstream ss(line);
        double cell;
        while (ss >> cell) {
            row.push_back(cell);
            if (ss.peek() == ',') {
                ss.ignore();
            }
        }
        data.push_back(row);
    }
    return data;
}

double calculate_average(vector<double> v) {
    double sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return sum / v.size();
}

int main() {
    vector<vector<double>> data = read_csv("Netflix_Stock.csv");
    int n = data.size();
    vector<double> last_3_days, last_21_days;
    for (int i = n - 1; i >= n - 21; i--) {
        last_21_days.push_back(data[i][3]);
    }
    for (int i = n - 1; i >= n - 3; i--) {
        last_3_days.push_back(data[i][3]);
    }
    double avg_last_21_days = calculate_average(last_21_days);
    double avg_last_3_days = calculate_average(last_3_days);
    if (avg_last_3_days > avg_last_21_days) {
        cout << "UP" << endl;
        double highest_so_far = *max_element(last_21_days.begin(), last_21_days.end());
        cout << "Current price: " << data[n-1][3] << endl;
        cout << "Expected target: " << highest_so_far << endl;
    } else {
        cout << "DOWN" << endl;
        double lowest_so_far = *min_element(last_21_days.begin(), last_21_days.end());
        cout << "Current price: " << data[n-1][3] << endl;
        cout << "Expected target: " << lowest_so_far << endl;
    }
    return 0;
}