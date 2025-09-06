from collections import Counter

class Skiplist:
    def __init__(self):
        self.freq = Counter()  

    def search(self, target: int) -> bool:
        return self.freq[target] > 0

    def add(self, num: int) -> None:
        self.freq[num] += 1

    def erase(self, num: int) -> bool:
        if self.freq[num] > 0:
            self.freq[num] -= 1
            if self.freq[num] == 0:
                del self.freq[num]  
            return True
        return False
