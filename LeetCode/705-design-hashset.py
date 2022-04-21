from typing import List


class MyHashSet:
    def __init__(self):
        self.items: List[int] = []

    def add(self, key: int) -> None:
        if key not in self.items:
            self.items.append(key)

    def remove(self, key: int) -> None:
        if key in self.items:
            self.items.remove(key)

    def contains(self, key: int) -> bool:
        return key in self.items
