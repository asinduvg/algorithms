import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class BubbleSort {

    public static void main(String[] args) {

        List<Integer> arr = new ArrayList<>(Arrays.asList(1, 9, 2, 0, 4, 3));

        bubbleSort(arr);

        System.out.println(arr);

    }

    public static void bubbleSort(List<Integer> arr) {
        for (int i = 0; i < arr.size() - i; i++) {
            for (int j = 0; j < arr.size() - i - 1; j++) {
                if (arr.get(j) > arr.get(j + 1)) {
                    int temp = arr.get(j);
                    arr.set(j, arr.get(j + 1));
                    arr.set(j + 1, temp);
                }
            }
        }
    }


}
