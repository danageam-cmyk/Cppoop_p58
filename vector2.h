#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <format>

template <typename T>
class vector2_t {
private:
    T x;
    T y;
    char* name;

public:
    T get_x() const { return x; }
    T get_y() const { return y; }
    char* get_name() const { return name; }

    void set_x(T new_x) { x = new_x; }
    void set_y(T new_y) { y = new_y; }

    void set_name(const char* new_name) {
        char* temp_name = nullptr;
        if (new_name != nullptr) {
            size_t len = strlen(new_name);
            temp_name = new char[len + 1];
            strcpy_s(temp_name, len + 1, new_name);
        }
        delete[] name;
        name = temp_name;
    }

    std::string to_string() const {
        if (name != nullptr && name[0] != '\0') {
            return std::format("{}: ({}, {})", name, x, y);
        }
        return std::format("({}, {})", x, y);
    }

    
    vector2_t() : x(0), y(0), name(nullptr) {}

    vector2_t(T x_val) : x(x_val), y(0), name(nullptr) {}

    vector2_t(T x_val, T y_val) : x(x_val), y(y_val), name(nullptr) {}

    vector2_t(T x_val, T y_val, const char* name_val) : x(x_val), y(y_val) {
        if (name_val != nullptr) {
            size_t len = strlen(name_val);
            name = new char[len + 1];
            strcpy_s(name, len + 1, name_val);
        }
        else {
            name = nullptr;
        }
    }

    vector2_t(const vector2_t& other) : x(other.x), y(other.y) {
        if (other.name != nullptr) {
            size_t len = strlen(other.name);
            name = new char[len + 1];
            strcpy_s(name, len + 1, other.name);
        }
        else {
            name = nullptr;
        }
        std::cout << "Copy constructor" << std::endl;
    }

    vector2_t(vector2_t&& other) noexcept : x(other.x), y(other.y), name(other.name) {
        other.x = 0;
        other.y = 0;
        other.name = nullptr;
        std::cout << "Move constructor" << std::endl;
    }

    ~vector2_t() {
        delete[] name;
    }

    vector2_t operator+(const vector2_t& other) const {
        return vector2_t(x + other.x, y + other.y);
    }

    vector2_t operator-(const vector2_t& other) const {
        return vector2_t(x - other.x, y - other.y);
    }

    vector2_t operator*(T number) const {
        return vector2_t(x * number, y * number);
    }

    vector2_t operator/(T number) const {
        if (number == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return vector2_t(x / number, y / number);
    }

    vector2_t& operator+=(const vector2_t& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    vector2_t& operator-=(const vector2_t& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    vector2_t& operator=(const vector2_t& other) {
        if (this != &other) {
            char* new_name = nullptr;
            if (other.name != nullptr) {
                size_t len = strlen(other.name);
                new_name = new char[len + 1];
                strcpy_s(new_name, len + 1, other.name);
            }
            delete[] name;
            x = other.x;
            y = other.y;
            name = new_name;
        }
        std::cout << "Copy assignment operator" << std::endl;
        return *this;
    }

    vector2_t& operator=(vector2_t&& other) noexcept {
        if (this != &other) {
            delete[] name;
            x = other.x;
            y = other.y;
            name = other.name;
            other.x = 0;
            other.y = 0;
            other.name = nullptr;
        }
        std::cout << "Move assignment operator" << std::endl;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const vector2_t<T>& v) {
        if (v.name != nullptr && v.name[0] != '\0') {
            out << v.name << ": ";
        }
        out << "(" << v.x << ", " << v.y << ")";
        return out;
    }
};