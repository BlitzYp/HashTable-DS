class Node {
    public String key;
    public String value;
    public Node next;
    public Node(String key, String value) {
        this.key = key;
        this.value = value;
    }
}

class hashTable {
    public int maxSize;
    public Node[] data;
    public hashTable(int maxSize) {
        this.maxSize = maxSize;
        data = new Node[maxSize];
    }

    private int hash(String key) {
        int res = 0;
        for (int i = 0; i < key.length(); i++) {
            res = res + (key.charAt(i) * i);
        }
        return res % maxSize;
    }

    public void add(String key, String value) {
        int index = hash(key);
        Node newNode = new Node(key, value);
        newNode.next = data[index];
        data[index] = newNode;
    }

    public String get(String key) {
        int index = hash(key);
        Node res = data[index];
        while (res.key != key && res.next != null) res = res.next;
        return res.value;
    }

    public void keys() {
        for (int i = 0; i < maxSize; i++) {
            Node curr = data[i];
            if (curr == null) continue;
            while (curr != null) {
                System.out.println(curr.key);
                curr = curr.next;
            }
        }
    }

    public void values() {
        for (int i = 0; i < maxSize; i++) {
            Node curr = data[i];
            if (curr == null) continue;
            while (curr != null) {
                System.out.println(curr.value);
                curr = curr.next;
            }
        }
    }
}
