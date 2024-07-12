#include <iostream>
#include<string>
using namespace std;

class Process {
public:
    int processID;
    int burstTime;

    Process(int processID, int burstTime) {
        this->processID = processID;
        this->burstTime = burstTime;
    }
};

class Node {
public:
    Process* process;
    Node* next;

    Node(Process* process) {
        this->process = process;
        this->next = nullptr;
    }
};

class RoundRobinScheduler {
private:
    Node* head;

public:
    RoundRobinScheduler() {
        head = nullptr;
    }

    // Add a process to the scheduler
    void addProcess(Process* process) {
        Node* newNode = new Node(process);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Simulate the round-robin scheduling
    void simulate(int timeSlice) {
        if (head == nullptr) {
            cout << "No processes in the scheduler." << endl;
            return;
        }

        Node* temp = head;
        while (true) {
            if (temp->process->burstTime > 0) {
                if (temp->process->burstTime > timeSlice) {
                    cout << "Process " << temp->process->processID << " executed for " << timeSlice << " units." << std::endl;
                    temp->process->burstTime -= timeSlice;
                } else {
                    cout << "Process " << temp->process->processID << " executed for " << temp->process->burstTime << " units and finished." << std::endl;
                    temp->process->burstTime = 0;
                }
            }

            temp = temp->next;
            // Check if all processes are completed
            Node* check = head;
            bool allDone = true;
            do {
                if (check->process->burstTime > 0) {
                    allDone = false;
                    break;
                }
                check = check->next;
            } while (check != head);

            if (allDone) {
                break;
            }
        }
    }

    // Destructor to free memory
    ~RoundRobinScheduler() {
        if (head == nullptr) {
            return;
        }
        Node* current = head;
        Node* next = nullptr;
        while (current->next != head) {
            next = current->next;
            delete current;
            current = next;
        }
        delete current;
        head = nullptr;
    }
};

int main() {
    RoundRobinScheduler scheduler;

    // Add processes to the scheduler
    scheduler.addProcess(new Process(1, 10));
    scheduler.addProcess(new Process(2, 5));
    scheduler.addProcess(new Process(3, 8));

    // Simulate round-robin scheduling with a time slice of 3 units
    cout << "Simulating Round Robin Scheduling:" << endl;
    scheduler.simulate(3);

    return 0;
}
