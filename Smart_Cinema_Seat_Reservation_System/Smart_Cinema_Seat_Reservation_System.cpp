#include <iostream>
#include <cstring>
using namespace std;

// Define global variables to track reserved seats in each cinema
int s = 95, s1 = 25, s2 = 0, s3 = 0;

// Arrays to store reserved seats for each cinema
int cinemaASeats[100] = { 0 };  // Initialize all elements to 0
int cinemaBSeats[80] = { 0 };   // Initialize all elements to 0
int cinemaCSeats[70] = { 0 };   // Initialize all elements to 0
int cinemaDSeats[90] = { 0 };   // Initialize all elements to 0

// Function to clear the screen
void cls() {
    system("cls");
}

// Function to print table of details including cinema specs
void printTable(int s, int s1, int s2, int s3) {
    cout << "CINEMAS:\tCINEMA A\tCINEMA B\tCINEMA C\tCINEMA D\n\n";
    cout << "TOTAL SEATS:\t100\t\t80\t\t70\t\t90\n\n";
    cout << "MOVIE NAME:\tNUN\t\tPLAY\t\tLEO\t\tLIFE\n\n";
    cout << "TIME SLOT:\t1. (5 TO 6)\t2. (6 TO 7)\t3. (7 TO 8)\t4. (8 TO 9)\n\n";
    cout << "RESERVED SEATS:\t" << s << "\t\t" << s1 << "\t\t" << s2 << "\t\t" << s3 << "\n\n";
}

// Function to reserve seats and check for seat availability
int addSeatsInArray(int userinp, char cinema_name) {
    bool seatAlreadyBooked = false; // Flag to indicate if the seat is already booked

    // Select the appropriate cinema array based on input
    int* selectedCinemaSeats = nullptr;
    int cinemaSize = 0;

    if (cinema_name == 'a' || cinema_name == 'A') {
        selectedCinemaSeats = cinemaASeats;
        cinemaSize = 100;
    }
    else if (cinema_name == 'b' || cinema_name == 'B') {
        selectedCinemaSeats = cinemaBSeats;
        cinemaSize = 80;
    }
    else if (cinema_name == 'c' || cinema_name == 'C') {
        selectedCinemaSeats = cinemaCSeats;
        cinemaSize = 70;
    }
    else if (cinema_name == 'd' || cinema_name == 'D') {
        selectedCinemaSeats = cinemaDSeats;
        cinemaSize = 90;
    }

    // Check if seat is already reserved
    for (int i = 0; i < cinemaSize; i++) {
        if (selectedCinemaSeats[i] == userinp) {
            seatAlreadyBooked = true;
            break;
        }
    }

    // If seat is already booked, print message and return error code
    if (seatAlreadyBooked) {
        cout << "This Seat is already Reserved" << endl;
        return 1; // Error code indicating seat is already booked
    }
    else {
        // Book the seat
        selectedCinemaSeats[userinp - 1] = userinp;
        cout << "Seat " << userinp << " reserved successfully in Cinema ";
        if (cinema_name == 'a' || cinema_name == 'A') {
            cout << "A" << endl;
        }
        else if (cinema_name == 'b' || cinema_name == 'B') {
            cout << "B" << endl;
        }
        else if (cinema_name == 'c' || cinema_name == 'C') {
            cout << "C" << endl;
        }
        else if (cinema_name == 'd' || cinema_name == 'D') {
            cout << "D" << endl;
        }
        return 0; // Seat booked successfully
    }
}

// Function to validate movie input
int movieValidation(char movie[10], int seat, char cinema_name) {
    // Check if movie name is valid
    if (!(strcmp(movie, "NUN") == 0 || strcmp(movie, "PLAY") == 0 ||
        strcmp(movie, "LEO") == 0 || strcmp(movie, "LIFE") == 0 ||
        strcmp(movie, "nun") == 0 || strcmp(movie, "leo") == 0 ||
        strcmp(movie, "play") == 0 || strcmp(movie, "life") == 0)) {
        cout << "Movie Not Available\n";
        return 1; // Error code indicating movie is not available
    }

    // Prompt user to choose seat number
    cout << "Choose Seat Number : ";
    cin >> seat;
    if (addSeatsInArray(seat, cinema_name)) {
        return 1; // Error code indicating seat reservation failed
    }
    if (seat <= 0) {
        cout << "Invalid seat number\n";
        return 1; // Error code indicating invalid seat number
    }
    return 0; // Movie validation successful
}

// Function to validate cinema selection
int cinemaValidation(char cinema_name) {
    // Validate if cinema name is A, B, C, or D
    if (cinema_name == 'A' || cinema_name == 'a' ||
        cinema_name == 'B' || cinema_name == 'b' ||
        cinema_name == 'C' || cinema_name == 'c' ||
        cinema_name == 'D' || cinema_name == 'd') {
        return 0; // Cinema validation successful
    }
    else {
        cout << "Invalid Input Cinema Not Available" << endl;
        return 1; // Error code indicating invalid cinema selection
    }
}

// Function to check if cinema is almost full or full
void CheckForCinema(char movie[10], int seat, char cinema_name) {
    // Update reserved seat count based on selected cinema and movie
    if (cinema_name == 'a' || cinema_name == 'A') {
        if (s >= 99) {
            cout << "House Full for this time slot\n";
        }
        else {
            cout << "Reservation successful\n";
            s++;
        }
    }
    else if (cinema_name == 'b' || cinema_name == 'B') {
        if (s1 >= 79) {
            cout << "House Full for this time slot\n";
        }
        else {
            cout << "Reservation successful\n";
            s1++;
        }
    }
    else if (cinema_name == 'c' || cinema_name == 'C') {
        if (s2 >= 69) {
            cout << "House Full for this time slot\n";
        }
        else {
            cout << "Reservation successful\n";
            s2++;
        }
    }
    else if (cinema_name == 'd' || cinema_name == 'D') {
        if (s3 >= 89) {
            cout << "House Full for this time slot\n";
        }
        else {
            cout << "Reservation successful\n";
            s3++;
        }
    }
}
int main() {
    char movie[10], choice;
    int seat = 0;

    const int total_seats_c1 = 100;
    const int total_seats_c2 = 80;
    const int total_seats_c3 = 70;
    const int total_seats_c4 = 90;

    while (true) {
        char cinema_name;
        printTable(s, s1, s2, s3);

        cout << "Choose Cinema (A, B, C, D): ";
        cin >> cinema_name;

        // Validate cinema selection
        if (cinemaValidation(cinema_name)) {
            continue; // Ask again instead of exiting
        }

        cout << "\nChoose Your Favorite Movie Name: ";
        cin >> movie;
        cout << endl;

        // Validate movie selection
        if (movieValidation(movie, seat, cinema_name)) {
            continue; // Ask again instead of exiting
        }

        // Check for cinema availability and update reservation
        if (strcmp(movie, "NUN") == 0 || strcmp(movie, "nun") == 0) {
            CheckForCinema(movie, seat, cinema_name);
        }
        else if (strcmp(movie, "PLAY") == 0 || strcmp(movie, "play") == 0) {
            CheckForCinema(movie, seat, cinema_name);
        }
        else if (strcmp(movie, "LEO") == 0 || strcmp(movie, "leo") == 0) {
            CheckForCinema(movie, seat, cinema_name);
        }
        else if (strcmp(movie, "LIFE") == 0 || strcmp(movie, "life") == 0) {
            CheckForCinema(movie, seat, cinema_name);
        }

        cout << "\nPress (n/y) to continue or to exit: ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            cout << "Exited.... ." << endl;
            break; // Exit the program
        }

        cls(); // Clear screen for next iteration
    }

    return 0;
}


