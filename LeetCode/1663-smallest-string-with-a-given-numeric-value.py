from typing import List

INT_a = ord("a")
INT_base_lower = ord("a")


class Solution:
    def getSmallestString_reverse(self, n: int, k: int) -> str:
        res: List[int] = [0] * n

        while n:
            res[n - 1] = min(
                k - (n - 1),  # assume other LSBs are 1s
                26,
            )
            k -= res[n - 1]
            n -= 1

        return "".join(map(lambda c: chr(INT_base_lower + c), res))

    def getSmallestString_reverse_optimized(self, n: int, k: int) -> str:
        res: List[str] = ["a"] * n
        k -= n  # all filled "a" initially

        for i in range(n - 1, -1, -1):
            if k <= 25:
                res[i] = chr(INT_a + k)
                break
            res[i] = "z"
            k -= 25

        return "".join(res)

    getSmallestString = getSmallestString_reverse_optimized


s = Solution()

res = s.getSmallestString(5, 73)
print(f"{res = }")
