class Solution:
    def numDecodings_dp(self, s: str) -> int:
        sLen = len(s)

        # dp[i] = numbers of ways to decode s[:i]
        dp = [0] * (sLen + 1)
        dp[0] = 1  # there is only one way to decode s[:0] == ''

        for i in range(sLen):
            if "1" <= s[i] <= "9":
                dp[i + 1] += dp[i]
            if i >= 1 and (s[i - 1] == "1" or s[i - 1] == "2" and "0" <= s[i] <= "6"):
                dp[i + 1] += dp[i - 1]

        return dp[sLen]

    def numDecodings_dp_optimized(self, s: str) -> int:
        sLen = len(s)

        prev, curr = 0, 1
        for i in range(sLen):
            nxt = 0
            if "1" <= s[i] <= "9":
                nxt += curr
            if i >= 1 and (s[i - 1] == "1" or s[i - 1] == "2" and "0" <= s[i] <= "6"):
                nxt += prev
            prev, curr = curr, nxt

        return curr

    numDecodings = numDecodings_dp_optimized


s = Solution()

res = s.numDecodings("226")
print(f"{res = }")
