import java.util.*;

public class AppointmentScheduler {
    private static PriorityQueue<Appointment> appointments = new PriorityQueue<>(Comparator.comparing(Appointment::getTime));

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("\n--- Appointment Scheduler ---\n");
            System.out.println("1. Book Appointment\n2. View Appointments\n3. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    bookAppointment(scanner);
                    break;
                case 2:
                    viewAppointments();
                    break;
                case 3:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice!");
            }
        }
    }

    private static void bookAppointment(Scanner scanner) {
        System.out.print("Enter patient name: ");
        String name = scanner.next();
        System.out.print("Enter appointment time (HH:mm): ");
        String time = scanner.next();
        appointments.add(new Appointment(name, time));
        System.out.println("Appointment booked successfully!");
    }

    private static void viewAppointments() {
        System.out.println("\n--- Appointments ---\n");
        for (Appointment appt : appointments) {
            System.out.println(appt);
        }
    }
}

class Appointment {
    private String patientName;
    private String time;

    public Appointment(String patientName, String time) {
        this.patientName = patientName;
        this.time = time;
    }

    public String getTime() {
        return time;
    }

    @Override
    public String toString() {
        return "Patient: " + patientName + ", Time: " + time;
    }
}
