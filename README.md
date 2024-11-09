# BankProject
Queuing system
#include <iostream>
#include <queue>

class BankQueueSystem {
private:
    std::queue<int> customerQueue; // Queue to store customer ticket numbers
    int nextTicketNumber;          // Next ticket number to assign

public:
    BankQueueSystem() : nextTicketNumber(1) {}

    // Function to add a new customer to the queue
    void addCustomer() {
        if (nextTicketNumber > 700) {
            std::cout << "Queue is full! No more tickets available." << std::endl;
            return;
        }
        customerQueue.push(nextTicketNumber);
        std::cout << "Customer " << nextTicketNumber << " added to the queue." << std::endl;
        nextTicketNumber++;
        showQueueStatus();
    }

    // Function to serve the next customer in the queue
    void serveCustomer() {
        if (customerQueue.empty()) {
            std::cout << "No customers in the queue to serve." << std::endl;
        } else {
            std::cout << "Serving customer " << customerQueue.front() << "." << std::endl;
            customerQueue.pop();
        }
        showQueueStatus();
    }

    // Function to show the number of customers in the queue
    void showQueueStatus() const {
        std::cout << "Number of customers in the queue: " << customerQueue.size() << std::endl;
    }
};

int main() {
    BankQueueSystem bankQueue;
    int choice;

    do {
        std::cout << "\n--- Bank Queue System ---\n";
        std::cout << "1. Add Customer\n";
        std::cout << "2. Serve Customer\n";
        std::cout << "3. Show Queue Status\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                bankQueue.addCustomer();
                break;
            case 2:
                bankQueue.serveCustomer();
                break;
            case 3:
                bankQueue.showQueueStatus();
                break;
            case 4:
                std::cout << "Exiting the system.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

