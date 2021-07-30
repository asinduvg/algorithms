public class LinearSearch {
    public static void main(String[] args) {

        int[] arr = { 2, 1, 89, 12, 1, 0, 7, 4 };
        int index = linearSearch(arr, 9);
        System.out.println(index);

    }

    private static int linearSearch(int[] arr, int num) {
        for (var i = 0; i < arr.length; i++) {
            if (arr[i] == num) {
                return i;
            }
        }
        return -1;
    }

}
