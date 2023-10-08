import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

public class CustomMap {
    public static <T, R> List<R> map(List<T> list, Function<T, R> func) {
        List<R> result = new ArrayList<>();
        for (T item : list) {
            result.add(func.apply(item));
        }
        return result;
    }

    public static void main(String[] args) {
        List<Integer> numbers = new ArrayList<>();
        numbers.add(1);
        numbers.add(2);
        numbers.add(3);
        numbers.add(4);
        numbers.add(5);

        // Using custom map function to square each element
        List<Integer> squared = map(numbers, x -> x * x);

        System.out.println(squared); // Output: [1, 4, 9, 16, 25]
    }
}
