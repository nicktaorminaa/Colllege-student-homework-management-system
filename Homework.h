#pragma once
#include <iostream>
#include <vector>
#include <map> 
#include <sstream>
#include <string> 
#include <iomanip> 
#include <algorithm>

class Assignment {
private:
    int id;
    std::string name;
    std::string course;
    std::string dueDate;
    std::string dueTime;
    int estimatedTime;
    float weight;

public:
   string assignments(int id, std::string name, std::string course, std::string dueDate, std::string dueTime, int estimatedTime, float weight) {
        this->id = id;
        this->name = name;
        this->course = course;
        this->dueDate = dueDate;
        this->dueTime = dueTime;
        this->estimatedTime = estimatedTime;
        this->weight = weight;
    }

    // Setters and getters for Homework attributes
   void setId(int id) {
       this->id = id;
   } 

   int getId() const { return id; }

   
   void setName(std::string name) {
        this->name = name;
    }

    std::string getName() const {
        return name;
    }

    void setCourse(std::string course) {
        this->course = course;
    }

    string getCourse() const {
        return course;
    }

    void setDueDate(std::string dueDate) {
        this->dueDate = dueDate;
    }

    std::string getDueDate() {
        return dueDate;
    }

    void setDueTime(std::string dueTime) {
        this->dueTime = dueTime;
    }

    std::string getDueTime() {
        return dueTime;
    }

    void setEstimatedTime(int estimatedTime) {
        this->estimatedTime = estimatedTime;
    }

    int getEstimatedTime() {
        return estimatedTime;
    }

    void setWeight(float weight) {
        this->weight = weight;
    }

    float getWeight() {
        return weight;
    }
};