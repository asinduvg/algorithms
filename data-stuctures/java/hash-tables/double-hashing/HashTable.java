public class HashTable {

    String[] hashArray;
    int arraySize;
    int size = 0; // counter for number elements in the hash table (no of slots used)

    public HashTable(int noOfSlots) {
        if (isPrime(noOfSlots)) {
            hashArray = new String[noOfSlots];
            arraySize = noOfSlots;
        } else {
            int primeCount = getNextPrime(noOfSlots);
            hashArray = new String[primeCount];
            arraySize = primeCount;

            System.out.println("Hash table size given " + noOfSlots + " is not a prime");
            System.out.println("Hash table size changed to " + primeCount);
        }
    }

    private boolean isPrime(int number) {
        for (var i = 2; i * i <= number; i++) {
            if (number % 2 == 0) {
                return false;
            }
        }

        return true;
    }

    private int getNextPrime(int minNumber) {
        for (int i = minNumber; true; i++) {
            if (isPrime(i)) {
                return i;
            }
        }
    }

    // returns preferred index position
    private int hashFunc1(String word) {
        int hashVal = word.hashCode();
        hashVal %= arraySize;
        if (hashVal < 0) {
            hashVal += arraySize;
        }
        return hashVal; // ideal index position we'd like to insert or search
    }

    // return step size greater than 0
    private int hashFunc2(String word) {
        int hashVal = word.hashCode();
        hashVal %= arraySize;
        if (hashVal < 0) {
            hashVal += arraySize;
        }
        return 3 - hashVal % 3; // 3 -> lesser prime number than array size
    }

    public void insert(String word) {
        int hashVal = hashFunc1(word);
        int stepSize = hashFunc2(word);

        while (hashArray[hashVal] != null) {
            hashVal += stepSize;
            hashVal %= arraySize;
        }

        hashArray[hashVal] = word;
        System.out.println("inserted word: " + word);
        size++;
    }

    public String find(String word) {
        int hashVal = hashFunc1(word);
        int stepSize = hashFunc2(word);

        while (hashArray[hashVal] != null) {

            if (hashArray[hashVal].equals(word)) {
                return hashArray[hashVal];
            }

            hashVal += stepSize;
            hashVal %= arraySize;
        }

        return hashArray[hashVal];
    }

    public void displayTable() {
        System.out.println("Table: ");
        for (var i = 0; i < arraySize; i++) {
            if (hashArray[i] != null) {
                System.out.print(hashArray[i] + " ");
            } else {
                System.out.print("** ");
            }
        }
        System.out.println(" ");
    }

}

class App {
    public static void main(String[] args) {
        HashTable hashTable = new HashTable(19);
        hashTable.insert("Apple");
        hashTable.insert("Orange");
        hashTable.insert("Milk");
        hashTable.insert("Banana");
        hashTable.insert("Strawberry");
        hashTable.insert("Berry");
        hashTable.insert("Guava");
        hashTable.insert("Dragon fruit");

        hashTable.displayTable();

        System.out.println(hashTable.find("Orange"));
        System.out.println(hashTable.find("Apple"));
        System.out.println(hashTable.find("Dragon fruit"));
        System.out.println(hashTable.find("Kite"));
        System.out.println(hashTable.find("Banana"));

    }
}
