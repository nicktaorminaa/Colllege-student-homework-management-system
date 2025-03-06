#pragma once
#include <iostream>
#include <vector>
#include <map> 
#include <sstream>
#include <fstream>
#include <string> 
#include <iomanip> 
#include <algorithm>
#include "Homework.h"
using namespace std; 
class HomeworkManager {
private:
    std::vector<Assignment> homeworkList;
    int nextId;

public:

    int getNextId()
    {
        int id = nextId;
        nextId++;
        return id;
    }
    void addAssignment(int id, string name, string course, string dueDate, string dueTime, int estimatedTime, float weight)
    {
        int id1 = getNextId(); // get the next available ID
        Assignment newAssignment(id, name, course, dueDate, dueTime, estimatedTime, weight);
        homeworkList.push_back(newAssignment); // add the new assignment to the vector
        cout << "Assignment added successfully. ID: " << id << endl;
    }

    void updateAssignment(int id, string name, string course, string dueDate, string dueTime, double estimatedTime, double weight)
    {
        auto it = find_if(homeworkList.begin(), homeworkList.end(), [&](const Assignment& assignment) {
            return assignment.getId() == id;
            });
        if (it != homeworkList.end()) {
            it->setName(name);
            it->setCourse(course);
            it->setDueDate(dueDate);
            it->setDueTime(dueTime);
            it->setEstimatedTime(estimatedTime);
            it->setWeight(weight);
            cout << "Assignment updated successfully. ID: " << id << endl;
        }
        else {
            cout << "Assignment not found. ID: " << id << endl;
        }
    }


    void searchHomeworkByDays(int days) {
        std::time_t currentTime = std::time(nullptr);
        std::tm tm = *std::localtime(&currentTime);
        std::tm dueTm;

        for (int i = 0; i < homeworkList.size(); i++) {
            std::string dueDate = homeworkList[i].getDueDate();
            std::string dueTime = homeworkList[i].getDueTime();
            std::istringstream dstream(dueDate + " " + dueTime);

            dstream >> std::get_time(&dueTm, "%d/%m/%Y %H:%M");

            std::time_t dueTime_t = std::mktime(&dueTm);
            int diff = std::difftime(dueTime_t, currentTime) / (24 * 60 * 60);

            if (diff <= days) {
                std::cout << "Name: " << homeworkList[i].getName() << std::endl;
                std::cout << "Course: " << homeworkList[i].getCourse() << std::endl;
                std::cout << "Due: " << homeworkList[i].getDueDate() << std::endl;

            }

        }
   
    }
   
    void searchByCourse()
    {
        string course;
        cout << "Enter course name: ";
        cin >> course;
        cout << endl;

        HomeworkManager hm; // create an instance of HomeworkManager
        cout << "Assignments for course " << course << ":" << endl;
        hm.displayAllAssignments(course); // call the displayAllAssignments method with the course parameter
    }

    void deleteAssignment()
    {
        int id;
        cout << "Enter the ID of the assignment you want to delete or mark as complete: ";
        cin >> id;

        auto it = find_if(homeworkList.begin(), homeworkList.end(), [id](const Assignment& a) { return a.getId() == id; });

        if (it != homeworkList.end()) {
            char choice;
            cout << "Do you want to delete this assignment (D)? ";
            cin >> choice;

            if (choice == 'D' || choice == 'd') {
                homeworkList.erase(it);
                cout << "Assignment deleted successfully." << endl;
            }
            else {
                cout << "Invalid choice. Assignment was not deleted." << endl;
            }
        }
        else {
            cout << "Assignment not found with ID " << id << endl;
        }
    }

    void displayAllAssignments()
    {
        if (homeworkList.empty()) {
            cout << "No assignments to display." << endl;
        }
        else {
            cout << "All Assignments:" << endl;
            for (const auto& assignment : homeworkList) {
                cout << "ID: " << assignment.getId() << endl;
                cout << "Name: " << assignment.getName() << endl;
                cout << "Course: " << assignment.getCourse() << endl;
                cout << "Due date: " << assignment.getDueDate() << endl;
                cout << "Due time: " << assignment.getDueTime() << endl;
                cout << "Estimated time: " << assignment.getEstimatedTime() << " hours" << endl;
                cout << "Weight: " << assignment.getWeight() << "%" << endl;
            }
        }
    }
    void saveAssignmentsToFile(const string& assignments)
    {
        ofstream file(assignments, ios::binary);
        if (!file) {
            cerr << "Error: Could not open file \"" << assignments << "\" for writing." << endl;
            return;
        }

        int numAssignments = homeworkList.size();
        file.write((char*)&numAssignments, sizeof(int));

        vector<Assignment>::iterator it;
        for (it = homeworkList.begin(); it != homeworkList.end(); ++it) {
            file.write((char*)&(*it), sizeof(Assignment));
        }

        file.close();

        cout << "Assignments saved to file \"" << assignments << "\"." << endl;
    }

    void loadAssignmentsFromFile(string assignments, vector<Assignment>& homeworkList) {
        // Open the binary file for reading
        ifstream file(assignments, ios::binary);

        if (!file) {
            // Handle error if file cannot be opened
            cerr << "Error: Could not open file." << endl;
            return;
        }

        // Read the number of assignments stored in the file
        int numAssignments;
        file.read(reinterpret_cast<char*>(&numAssignments), sizeof(int));

        // Read the assignments from the file and add them to the vector
        for (int i = 0; i < numAssignments; i++) {
            Assignment assignment;
            file.read(reinterpret_cast<char*>(&assignment), sizeof(Assignment));
            homeworkList.push_back(assignment);
        }

        // Close the file
        file.close();
    }

};