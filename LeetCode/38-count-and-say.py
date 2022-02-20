class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"

        res = ""
        prev = self.countAndSay(n - 1)
        prevLen = len(prev)

        cursor = 0
        for i in range(1, prevLen + 1):
            if i == prevLen or prev[i] != prev[cursor]:
                res += f"{i-cursor}{prev[cursor]}"
                cursor = i

        return res


s = Solution()
res = s.countAndSay(4)

print(f"{res = }")
