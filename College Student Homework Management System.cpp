// College Student Homework Management System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map> 
#include <sstream>
#include <fstream>
#include <string> 
#include <iomanip> 
#include <algorithm>
#include "HomeworkManager.h"
#include "Homework.h"


using namespace std;

int main()
{
    HomeworkManager hm;

    // Load assignments from file
    hm.loadAssignmentsFromFile("assignments.bin");

    int choice;
    do {
        cout << "\n**** Homework Manager ****\n"
            << "1. Add an assignment\n"
            << "2. Update an assignment\n"
            << "3. Search assignments\n"
            << "4. Delete a completed assignment or mark an assignment as complete\n"
            << "5. Display all assignments\n"
            << "6. Save assignments to file\n"
            << "7. Quit\n"
            << "Enter your choice: ";

        cin >> choice;

        Assignment assignments; 

// Obtain the values from the Assignment object
        int id = assignments.getId();
        string name = assignments.getName();
        string course = assignments.getCourse();
        string dueDate = assignments.getDueDate();
        string dueTime = assignments.getDueTime();
        int estimatedTime = assignments.getEstimatedTime();
        float weight = assignments.getWeight();
        int days = 0; 

        switch (choice) {
        case 1:
            hm.addAssignment(id, name, course, dueDate, dueTime, estimatedTime, weight);
            break;
        case 2:
            hm.updateAssignment(id, name, course, dueDate, dueTime, estimatedTime, weight);
            break;
        case 3:
            hm.searchHomeworkByDays(days);
            break;
        case 4: 
            hm.searchByCourse(); 
            break;
        case 5:
            hm.deleteAssignment();
            break;
        case 6:
            hm.displayAllAssignments();
            break;
        case 7:
            hm.saveAssignmentsToFile("assignments.bin");
            break;
        case 8:
            cout << "Exiting Homework Manager. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != 8);

    return 0;
}







