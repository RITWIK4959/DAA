#include <iostream>
using namespace std;

// Recursive function to solve the Towers of Hanoi problem
void towersOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        // Base case: Move one disk directly from source to destination
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    // Move n-1 disks from source to auxiliary using destination as helper
    towersOfHanoi(n - 1, source, destination, auxiliary);

    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // Move the n-1 disks from auxiliary to destination using source as helper
    towersOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n; // Number of disks
    cout << "Enter the number of disks: ";
    cin >> n;

    // Call the function to solve the problem
    cout << "Steps to solve the Towers of Hanoi:\n";
    towersOfHanoi(n, 'A', 'B', 'C'); // A, B, C are names of the rods

    return 0;
}
