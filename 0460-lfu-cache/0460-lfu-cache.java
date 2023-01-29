class LFUCache {
    
    int capacity;
    private Map<Integer, CacheRecord> recordsCache;
    private TreeMap<Integer, LinkedList<Integer>> frequencyCounters;

    public LFUCache(int capacity) {
        this.recordsCache = new HashMap<>(capacity);
        this.capacity = capacity;
        this.frequencyCounters = new TreeMap<>();
    }

    public int get(int key) {
        if (!recordsCache.containsKey(key)) return -1;

        var record = recordsCache.get(key);
        updateCounters(record, key);
        return record.value;
    }

    public void put(int key, int value) {
        if (capacity == 0) return;

        boolean isUpdate = recordsCache.containsKey(key);
        if (!isUpdate && recordsCache.size() == capacity) {
            freeSpace();
        }

        CacheRecord record;
        if (isUpdate) {
			// update an existing value
            record = recordsCache.get(key);
            record.value = value;
        } else {
			// add a new record to the cache
            record = new CacheRecord(value);
        }
        recordsCache.put(key, record);
        updateCounters(record, key);
    }

    private void freeSpace() {
        if (frequencyCounters.isEmpty()) return;
		
        // get the smallest counter and remove the first element from its list
        Integer floorKey = frequencyCounters.firstKey();
        Integer removed = frequencyCounters.get(floorKey).removeFirst();
        removeEmptyUseCounterList(floorKey);
        // also clear the record from the cache
        recordsCache.remove(removed);
    }

    private void updateCounters(CacheRecord record, Integer key) {
        record.incrementCounter();

		// we update the frequency of this key in the frequencyCounters
        LinkedList<Integer> keysWithSameCounter = frequencyCounters.getOrDefault(record.counter, new LinkedList<>());
        keysWithSameCounter.add(key);
        frequencyCounters.put(record.counter, keysWithSameCounter);

        // if it's not the first time we saw this key, we must remove its old counter
        if (record.counter > 1) {
            frequencyCounters.get(record.counter - 1).remove(key);
            removeEmptyUseCounterList(record.counter - 1);
        }
    }

    private void removeEmptyUseCounterList(Integer floorKey) {
        // make sure you don't keep any empty lists
        if (frequencyCounters.get(floorKey).isEmpty()) frequencyCounters.remove(floorKey);
    }
}

class CacheRecord {
     int value;
     int counter = 0;

    CacheRecord(int value) {
        this.value = value;
    }

    void incrementCounter() {
        this.counter++;
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */