class HashTable {
    constructor(size) {
        this.data = new Array(size);
        this.sizeStatus = 0;
    }
    _hash(key) {
        let hash = 0;
        for (let i = 0; i < key.length; i++) {
            hash = (hash + key.charCodeAt(i) * i) % this.data.length;
        }
        return hash;
    }
    set(key, value = undefined) {
        if (this.sizeStatus < this.data.length) {
            const hash = this._hash(key);
            if (!this.data[hash]) { this.data[hash] = []; }
            this.data[hash] = [key, value];
            this.sizeStatus++;
            return;
        }
        throw new Error("Hash table size is full!");
    }
    get(key) {
        const location = this._hash(key);
        if (this.data[location]) { return this.data[location]; }
        throw new Error(`${key}: Could not be found`);
    }
    keys() {
        if (this.sizeStatus) {
            let res = [];
            for (let i = 0; i < this.data.length; i++) {
                if (this.data[i]) { res.push(this.data[i][0]); }
            }
            return res;
        }
    }
}

const table = new HashTable(23);
table.set("grapess", 1011);
table.set("melons", 3);
table.set("oranges", 10);
const keys = table.keys();
console.log(keys);
const data = table.get("oranges");
console.log(data);