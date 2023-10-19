import java.util.HashMap;
import java.util.Scanner;
class User {
    private String username;
    private String password;

    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }
}

class ReservationSystem {
    private HashMap<String, User> users;

    public ReservationSystem() {
        users = new HashMap<>();
        // Initialize some users (you can add more)
        users.put("user1", new online("user1", "password1"));
        users.put("user2", new online("user2", "password2"));
    }

    public boolean login(String username, String password) {
        User user = users.get(username);
        if (user != null && user.getPassword().equals(password)) {
            return true;
        }
        return false;
    }

    public void makeReservation(String username, String reservationDetails) {
        // Implement reservation logic here
        System.out.println("Reservation made for user: " + username);
        System.out.println("Reservation details: " + reservationDetails);
    }

    public void cancelReservation(String username, String reservationDetails) {
        // Implement cancellation logic here
        System.out.println("Reservation cancelled for user: " + username);
        System.out.println("Cancelled reservation details: " + reservationDetails);
    }
}public class OnlineReservationSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ReservationSystem reservationSystem = new ReservationSystem();

        System.out.println("Welcome to the Online Reservation System!");

        // Login Page
        System.out.print("Enter your username: ");
        String username = scanner.nextLine();
        System.out.print("Enter your password: ");
        String password = scanner.nextLine();

        if (reservationSystem.login(username, password)) {
            System.out.println("Login successful!");
            boolean exit = false;
            while (!exit) {
                // Reservation Menu
                System.out.println("\nSelect an option:");
                System.out.println("1. Make a reservation");
                System.out.println("2. Cancel a reservation");
                System.out.println("3. Exit");

                System.out.print("Enter your choice: ");
                int choice = scanner.nextInt();
                scanner.nextLine(); // Consume the newline character

                switch (choice) {
                    case 1:
                        // Reservation Page
                        System.out.print("Enter reservation details: ");
                        String reservationDetails = scanner.nextLine();
                        reservationSystem.makeReservation(username, reservationDetails);
                        break;
                    case 2:
                        // Cancellation Page
                        System.out.print("Enter reservation details to cancel: ");
                        String cancellationDetails = scanner.nextLine();
                        reservationSystem.cancelReservation(username, cancellationDetails);
                        break;
                    case 3:
                        exit = true;
                        break;
                    default:
                        System.out.println("Invalid choice. Please try again.");
                        break;
                }
            }
        } else {
            System.out.println("Invalid username or password. Login failed.");
        }

        System.out.println("Thank you for using the Online Reservation System!");
    }
}

