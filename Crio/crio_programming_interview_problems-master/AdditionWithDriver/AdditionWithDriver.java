import java.util.Scanner;

class AdditionWithDriver {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        scanner.close();

        int result = new solution().add(a,b);
        System.out.println(result);
    }
}
