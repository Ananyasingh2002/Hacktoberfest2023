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

    public boolean authenticate(String username, String password) {
        return this.username.equals(username) && this.password.equals(password);
    }
}

class UserProfile {
    private String name;
    private String email;

    public UserProfile(String name, String email) {
        this.name = name;
        this.email = email;
    }

    public void updateProfile(String name, String email) {
        this.name = name;
        this.email = email;
        System.out.println("***Profile updated successfully***");
    }

    public void displayProfile() {
        System.out.println("Name: " + name);
        System.out.println("Email: " + email);
    }
}

class Question {
    private String question;
    private String[] options;
    private int correctAnswer;

    public Question(String question, String[] options, int correctAnswer) {
        this.question = question;
        this.options = options;
        this.correctAnswer = correctAnswer;
    }

    public void displayQuestion() {
        System.out.println(question);
        for (int i = 0; i < options.length; i++) {
            System.out.println((i + 1) + ". " + options[i]);
        }
    }

    public boolean isCorrectAnswer(int answer) {
        return answer == correctAnswer;
    }
}
public class OnlineExamSystem {
    public static void main(String[] args) {
        // Sample user and profile
        online user = new online("RUPA", "2003");
        UserProfile userProfile = new UserProfile("RUPA VEERALA", "rupa@gmail.com");

        // Sample questions
        Question[] questions = {
                new Question("What is the capital of India?", new String[]{"New Delhi", "London", "Paris", "France"}, 1),
                new Question("Who is the PM of India?", new String[]{"Modi", "Draupadi murmu", "Jagan", "Pspk"}, 1),
                new Question("Where is VIT-AP university located?", new String[]{"Amaravati", "kavali", "chennai", "guntur"}, 1)
        };

        Scanner scanner = new Scanner(System.in);

        // Login
        System.out.println("**Welcome to the Online Examination System!**");
        System.out.print("Username: ");
        String username = scanner.nextLine();
        System.out.print("Password: ");
        String password = scanner.nextLine();

        if (!online.authenticate(username, password)) {
            System.out.println("Invalid username or password. Exiting the program.");
            return;
        }

        // Update profile
        System.out.println("\nProfile Information:");
        userProfile.displayProfile();
        System.out.println("\nDo you want to update your profile? (yes/no)");
        String updateProfileChoice = scanner.nextLine();

        if (updateProfileChoice.equalsIgnoreCase("yes")) {
            System.out.print("Enter your name: ");
            String name = scanner.nextLine();
            System.out.print("Enter your email: ");
            String email = scanner.nextLine();
            userProfile.updateProfile(name, email);
        }

        // MCQs
        System.out.println("\nMCQs - Please select the correct answers:");
        int score = 0;

        for (int i = 0; i < questions.length; i++) {
            System.out.println("\nQuestion " + (i + 1));
            questions[i].displayQuestion();
            System.out.print("Your answer: ");
            int answer = scanner.nextInt();

            if (questions[i].isCorrectAnswer(answer)) {
                score++;
            }
        }

        // Display final score
        System.out.println("\nYour Exam Score: " + score + " out of " + questions.length);

        // Closing session and logout
        System.out.println("\n***Thank you for using the Online Examination System. Logging out...***");
    }
}


