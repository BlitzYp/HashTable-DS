using System;
using System.Collections.Generic;
using System.Collections;

class Hashmap {
    ArrayList data;
    int length;

    public Hashmap()
    {
        data = new ArrayList();
        length = 1;
    }

    private int Hash(string key) 
    {
        int hashed = 0;
        for (int i = 1; i < key.Length; i++)
        {
            hashed = (hashed + key[i].GetHashCode() * i) % length;
        }
        return hashed;
    } 

    public void Add(string key, string value)
    {
        int index = Hash(key);
        data.Insert(index, value); 
        length++;
    }

    public string Get(string key)
    {
        return (string)data[Hash(key)];
    }
}
