import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class QuickSort {

    static int pivot = 0;
    static int sortedPivot = -1;

    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<>(Arrays.asList(4, 3, 1, 9, 0, 3, 5, 2));
        List<Integer> sortedArr = quickSort(arr);
        System.out.println(sortedArr);
    }

    public static List<Integer> quickSort(List<Integer> arr) {
        int arrLength = arr.size();

        // base case
        if (arrLength <= 1) {
            return arr;
        }

        pivot = arrLength - 1;

        // rearranging the array based on pivot
        List<Integer> pivotSortedList = rearrange(arr, pivot, 0);

        // new pivot position
        pivot = sortedPivot;
        sortedPivot = -1;

        // divide
        int middleValue = pivotSortedList.get(pivot);
        List<Integer> leftArr = pivotSortedList.subList(0, pivot);
        List<Integer> rightArr = pivotSortedList.subList(pivot + 1, arrLength);

        List<Integer> newLeftArr = quickSort(leftArr);
        List<Integer> newRightArr = quickSort(rightArr);

        // conquer
        List<Integer> sortedArr = new ArrayList<>(newLeftArr);
        sortedArr.add(middleValue);
        sortedArr.addAll(newRightArr);

        return sortedArr;

    }

    public static List<Integer> rearrange(List<Integer> arrWithPivot, int pivot, int index) {

        // base case
        if (index >= pivot) {
            return arrWithPivot;
        }

        if (arrWithPivot.get(index) >= arrWithPivot.get(pivot)) {
            List<Integer> arrangedList = new ArrayList<>(arrWithPivot);
            arrangedList.set(index, arrWithPivot.get(pivot - 1));
            arrangedList.set((pivot - 1), arrWithPivot.get(pivot));
            arrangedList.set(pivot, arrWithPivot.get(index));

            sortedPivot = pivot - 1;
            return rearrange(arrangedList, pivot - 1, index);
        } else {
            sortedPivot = pivot;
            return rearrange(arrWithPivot, pivot, index + 1);
        }
    }
}