class hash_table:
    def __init__(self, size):
        self.data = []
        self.size = size
        self.sizeStatus = 0

    def _hash(self, key):
        hash = 0
        for i in range(len(key)):
            hash = (hash + ord(key[i]) * i) % self.size
        return hash

    def put(self, key, value=None):
        if self.sizeStatus <= self.size:
            location = self._hash(key)
            if not self.data[location]:
                self.data[location] = []
            self.data[location] = [key, value]
            self.sizeStatus += 1
            return self.data
        else:
            raise IndexError("Too many values in the hash table")
        
    def get(self, key):
        res = self._hash(key)
        if res:
            return self.data[res]
        else:
            raise ValueError(f"Could not find {key} in the hash table")

    def keys(self):
        return [i[0] for i in self.data if len(i)]


table = hash_table(3)
table.put("grape", 10)
table.put("grapess", 1011)
table.put("melons", 3)
print(table.keys())
