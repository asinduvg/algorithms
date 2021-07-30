import java.util.Arrays;

public class BinarySearch {
    public static void main(String[] args) {

        int[] arr = { 1, 2, 4, 7, 10, 20, 30 };

        int index = binarySearch(arr, 1);
        System.out.println(index);

    }

    private static int binarySearch(int[] arr, int number) {

        System.out.println(Arrays.toString(arr));

        int start = 0;
        int end = arr.length - 1;
        int middle = (start + end) / 2;

        if (arr[middle] == number) {
            return middle;
        }

        // base case
        if (arr.length == 1) {
            return -1;
        }

        if (number < arr[middle]) {
            return binarySearch(Arrays.copyOfRange(arr, start, middle), number);
        }

        int semiIndex = binarySearch(Arrays.copyOfRange(arr, middle + 1, end + 1), number);
        if (semiIndex > -1) {
            return semiIndex + middle + 1;
        }
        return semiIndex;

    }

}
