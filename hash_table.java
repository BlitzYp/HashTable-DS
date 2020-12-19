import java.util.*;

public class Dict {
    ArrayList<Integer> data = new ArrayList<>();
    int size = 0;
    ArrayList<String> keys = new ArrayList<>();

    private int hash(String key) {
        int hash = 0;

        for (int i = 0; i < key.length(); i++) {
            hash = (hash + key.charAt(i)) % size;
        }

        return hash;
    }

    public void add(String key, int value) {
        size++;
        int hashedKey = hash(key);
        data.add(hashedKey, value);
        keys.add(key);
    }

    public int get(String key) {
        int res = data.get(hash(key));
        System.out.println(res);
        return res;
    }

    public ArrayList<String> getKeys() {
        return keys;
    }
}
