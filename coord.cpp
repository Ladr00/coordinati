#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

struct Coordinate {
    double coordinatX;
    double coordinatY;
};

bool isInSquare(const Coordinate& coord) {
    return coord.coordinatX >= 50.000000 && coord.coordinatX <= 80.999999
        && coord.coordinatY >= 20.000000 && coord.coordinatY <= 45.999999;
}

int main() {
    std::string filename = "coordinates.txt";
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return 1;
    }

    std::vector<Coordinate> coordinates;
    char left_bracket, right_bracket, comma;
    double lat, lon;
    while (file >> left_bracket >> lat >> comma >> lon >> right_bracket) {
        coordinates.push_back({ lat, lon });
    }

    for (const auto& coord : coordinates) {
        if (isInSquare(coord)) {
            std::cout << std::fixed << std::setprecision(6) << "(" << coord.coordinatX << ", " << coord.coordinatY << ")" << std::endl;
        }
    }

    return 0;
}
