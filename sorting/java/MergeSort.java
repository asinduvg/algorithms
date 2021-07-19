import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

public class MergeSort {

    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<>(Arrays.asList(4, 3, 1, 8, 5, 10, 0, 1, 4, 11, 8, 9));
        List<Integer> arrSorted = merge(arr);
        System.out.println(arrSorted);
    }

    public static List<Integer> merge(List<Integer> arr) {

        // base condition
        if (arr.size() <= 1) {
            return arr;
        }

        int arrLength = arr.size();
        int half = arrLength / 2;
        List<Integer> arrA = arr.subList(0, half);
        List<Integer> arrB = arr.subList(half, arr.size());

        // recursion
        arrA = merge(arrA);
        arrB = merge(arrB);

        return sort(arrA, arrB);
    }

    public static List<Integer> sort(List<Integer> unsortedA, List<Integer> unsortedB) {
        if (unsortedA.size() <= 0 && unsortedB.size() <= 0) {
            return new ArrayList<>();
        }
        if (unsortedA.size() <= 0) {
            return unsortedB;
        }
        if (unsortedB.size() <= 0) {
            return unsortedA;
        }
        if (unsortedA.get(0) <= unsortedB.get(0)) {
            List<Integer> newAl = new ArrayList<>() {
                {
                    add(unsortedA.get(0));
                }
            };
            newAl.addAll(sort(unsortedA.subList(1, unsortedA.size()), unsortedB));
            return newAl;
        } else {
            ArrayList<Integer> newAl = new ArrayList<>() {
                {
                    add(unsortedB.get(0));
                }
            };
            newAl.addAll(sort(unsortedA, unsortedB.subList(1, unsortedB.size())));
            return newAl;
        }
    }

}