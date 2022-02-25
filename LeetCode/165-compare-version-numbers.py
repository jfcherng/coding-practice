from typing import Tuple


class Solution:
    def compareVersion(self, v1: str, v2: str) -> int:
        def parseSubVersionAt(s: str, p: int) -> Tuple[int, int]:
            if p >= len(s):
                return 0, p
            end = p
            while end < len(s) and s[end] != ".":
                end += 1
            return int(s[p:end]), end

        def compareAt(i1: int, i2: int) -> int:
            if i1 >= len(v1) and i2 >= len(v2):
                return 0
            sub_v1, p1 = parseSubVersionAt(v1, i1)
            sub_v2, p2 = parseSubVersionAt(v2, i2)
            if sub_v1 > sub_v2:
                return 1
            if sub_v1 < sub_v2:
                return -1
            return compareAt(p1 + 1, p2 + 1)

        return compareAt(0, 0)


s = Solution()


res = s.compareVersion("1.01", "1.001")
print(f"{res = } (0)")

res = s.compareVersion("0.1", "1.1")
print(f"{res = } (-1)")

res = s.compareVersion("1.0.0", "1.0")
print(f"{res = } (0)")
