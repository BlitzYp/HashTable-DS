using System;

class Node {
    public string key;
    public string value;
    public Node next = null;
    public Node(string key, string value) {
        this.key = key;
        this.value = value;
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

    private int hash(string key) {
        int res = 0;
        for (int i = 0; i < key.Length; i++) {
            res = res + (key[i].GetHashCode() * i);
        }
        return res % maxSize;
    }

    public void add(string key, string value) {
        try {
            Node newNode = new Node(key, value);
            int index = hash(key);
            newNode.next = data[index];
            data[index] = newNode;
        } catch(Exception) {
            Console.Error.Write("Could not add key and value\n");
        }
    }

    public string get(string key) { 
        try {
            int index = hash(key);
            Node res = data[index];
            while (res.key != key && res.next != null)
                res = res.next;
            return res.value;
        } catch(Exception) {
            Console.Error.Write("Could not get key and value\n");
            return null;
        }
    }
}
