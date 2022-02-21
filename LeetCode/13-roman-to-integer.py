m = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000,
}

# special cases
sp = {
    "I": set("VX"),
    "X": set("LC"),
    "C": set("DM"),
}


class Solution:
    def romanToInt(self, s: str) -> int:
        res = 0

        i, l = 0, len(s)
        while i < l:
            is_sp = False
            for cur, nxt in sp.items():
                if s[i] == cur:
                    if i + 1 < l and s[i + 1] in nxt:
                        is_sp = True
                        res += m[s[i + 1]] - m[s[i]]
                        i += 2
                    break
            if not is_sp:
                res += m[s[i]]
                i += 1

        return res


s = Solution()
res = s.romanToInt("MCMXCIV")

print(f"{res = }")
