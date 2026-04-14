// Author: Divija Vijay
// Date: 04/14/2026

// AI Disclaimer: This code was written with moderate AI assistance.
// Used AI for: code structure suggestions and algorithm guidance.
// I implemented the solutions and modified the AI suggestions to fit the requirements.

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

class Shape {
public:
    virtual double getArea() const = 0;
    
    virtual void display() const {
        std::cout << "Base Shape";
    }

    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override { return width * height; }
    void display() const override {
        std::cout << "Rectangle (" << width << " x " << height << ")";
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getArea() const override { 
        return 3.14159265358979323846 * radius * radius; 
    }
    void display() const override {
        std::cout << "Circle (radius: " << radius << ")";
    }
};

#endif


