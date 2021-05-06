interface hashNode<T> {
    value: T;
    key: string;
    next?: hashNode<T>;
};

interface hashMap<T> {
    values: hashNode<T>[];
    keys: string[];
    maxSize: number;
}

const hash = (key: string, size: number): number => {
    let res = 0;
    for (let i = 0; i < key.length; i++) {
        res += key.charCodeAt(i);
    }
    return res % size;
}

const add = <T>(key: string, value: T, table: hashMap<T>) => {
    const index = hash(key, table.maxSize);
    console.log(index);
    const newNode: hashNode<T> = {key, value, next: table.values[index]};
    table.values[index] = newNode;
    table.keys.push(key);
}

const getValue = <T>(key: string, table: hashMap<T>): T | void => {
    const index = hash(key, table.maxSize);
    if (table.values[index] === undefined) return;
    let res = table.values[index];
    for (; res.key != key && res.next != undefined; res = res.next);
    return res.value;
}

const table: hashMap<string> = {values: [], keys: [], maxSize: 10};
add<string>("Pizza", "Blitz", table);
add<string>("123", "Jesus", table);
console.log(getValue<string>("123", table));
console.log(table.keys);
