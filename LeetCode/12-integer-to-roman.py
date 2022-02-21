m = [
    (1, "I"),
    (5, "V"),
    (10, "X"),
    (50, "L"),
    (100, "C"),
    (500, "D"),
    (1000, "M"),
    # special cases
    (4, "IV"),
    (9, "IX"),
    (40, "XL"),
    (90, "XC"),
    (400, "CD"),
    (900, "CM"),
]

m.sort(reverse=True)


class Solution:
    def intToRoman(self, num: int) -> str:
        res = ""

        for dec, rom in m:
            while num >= dec:
                res += rom
                num -= dec

        return res


s = Solution()
res = s.intToRoman(1994)

print(f"{res = }")
