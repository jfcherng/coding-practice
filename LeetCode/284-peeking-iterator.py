from typing import List


class Iterator:
    def __init__(self, nums: List[int]):
        """Initializes an iterator object to the beginning of a list."""
        ...

    def hasNext(self) -> bool:
        """Returns true if the iteration has more elements."""
        ...

    def next(self) -> int:
        """Returns the next element in the iteration."""
        ...


class PeekingIterator:
    def __init__(self, iterator: Iterator) -> None:
        self.iterator = iterator
        self._fetch()

    def peek(self) -> int:
        assert self._buf
        return self._buf

    def next(self) -> int:
        assert self._buf
        tmp = self._buf
        self._fetch()
        return tmp

    def hasNext(self) -> bool:
        return self._buf is not None

    def _fetch(self) -> None:
        """Move the next element to the buffer."""
        self._buf = self.iterator.next() if self.iterator.hasNext() else None
