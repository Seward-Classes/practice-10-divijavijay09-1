// Author: Divija Vijay
// Date: 04/14/2026

// AI Disclaimer: This code was written with moderate AI assistance.
// Used AI for: code structure suggestions and algorithm guidance.
// I implemented the solutions and modified the AI suggestions to fit the requirements.

#include "Shape.h"
#include "Shape.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>   
#include <string>
#include <iomanip>


void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        shape->display();
        std::cout << "\nArea: " << std::fixed << std::setprecision(4) 
                  << shape->getArea() << "\n" << std::endl;
    }
}

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    std::ifstream file("shapes.txt");

    if (!file) {
        std::cerr << "Error: Could not open shapes.txt" << std::endl;
        return 1;
    }

    std::string type;
    int lineNumber = 0;

    while (file >> type) {
        lineNumber++;
        if (type == "rectangle") {
            double w, h;
            if (file >> w >> h) {
                shapes.push_back(std::make_unique<Rectangle>(w, h));
            } else {
                std::cerr << "Line " << lineNumber << ": Invalid rectangle data." << std::endl;
            }
        } 
        else if (type == "circle") {
            double r;
            if (file >> r) {
                shapes.push_back(std::make_unique<Circle>(r));
            } else {
                std::cerr << "Line " << lineNumber << ": Invalid circle data." << std::endl;
            }
        } 
        else {
            std::cerr << "Line " << lineNumber << ": Unknown shape type '" << type << "'" << std::endl;
            std::string dummy;
            std::getline(file, dummy);
        }
    }

    file.close();

    printAllAreas(shapes);

    return 0;
}

